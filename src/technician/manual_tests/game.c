#include "game.h"
#include <stm32l4xx.h>
#include <sound.h>
#include "display.h"
#include <stdlib.h>

const gameLoc tetrominos[7][4][4] = {
  // I
  {{{1, 0}, {1, 1}, {1, 2}, {1, 3}},
   {{0, 2}, {1, 2}, {2, 2}, {3, 2}},
   {{3, 0}, {3, 1}, {3, 2}, {3, 3}},
   {{0, 1}, {1, 1}, {2, 1}, {3, 1}}},
  // J
  {{{0, 0}, {1, 0}, {1, 1}, {1, 2}},
   {{0, 1}, {0, 2}, {1, 1}, {2, 1}},
   {{1, 0}, {1, 1}, {1, 2}, {2, 2}},
   {{0, 1}, {1, 1}, {2, 0}, {2, 1}}},
  // L
  {{{0, 2}, {1, 0}, {1, 1}, {1, 2}},
   {{0, 1}, {1, 1}, {2, 1}, {2, 2}},
   {{1, 0}, {1, 1}, {1, 2}, {2, 0}},
   {{0, 0}, {0, 1}, {1, 1}, {2, 1}}},
  // O
  {{{0, 1}, {0, 2}, {1, 1}, {1, 2}},
   {{0, 1}, {0, 2}, {1, 1}, {1, 2}},
   {{0, 1}, {0, 2}, {1, 1}, {1, 2}},
   {{0, 1}, {0, 2}, {1, 1}, {1, 2}}},
  // S
  {{{0, 1}, {0, 2}, {1, 0}, {1, 1}},
   {{0, 1}, {1, 1}, {1, 2}, {2, 2}},
   {{1, 1}, {1, 2}, {2, 0}, {2, 1}},
   {{0, 0}, {1, 0}, {1, 1}, {2, 1}}},
  // T
  {{{0, 1}, {1, 0}, {1, 1}, {1, 2}},
   {{0, 1}, {1, 1}, {1, 2}, {2, 1}},
   {{1, 0}, {1, 1}, {1, 2}, {2, 1}},
   {{0, 1}, {1, 0}, {1, 1}, {2, 1}}},
  // Z
  {{{0, 0}, {0, 1}, {1, 1}, {1, 2}},
   {{0, 2}, {1, 1}, {1, 2}, {2, 1}},
   {{1, 0}, {1, 1}, {2, 1}, {2, 2}},
   {{0, 1}, {1, 0}, {1, 1}, {2, 0}}},
};

// Keeping track of the game state
char board[20][10] = {0};
tet currentTet;
tet nextTet;
unsigned char firstTet;
unsigned int score = 0;
unsigned char speed = 1;
int tick = 1;

void newTet(gameLoc origin, char orientation, SHAPE type, tet *t);
void drawGameBorder(void);
void drawSquare(gameLoc *loc, uint16_t colour);
void drawTet(tet *tet, uint16_t colour);
void rotateTet(tet *t);
void mvLeft(tet *t);
void mvRight(tet *t);
void mvDown(tet *t);
char downCollision(tet *t);
char leftCollision(tet *t);
char rightCollision(tet *t);
char rotCollision(tet *t);
char clearGoal(void);
void compress(char line);
char isGameover(void);
void gameOver(void);

void gameMoveLeft(void) {
    mvLeft(&currentTet);
}

void gameMoveRight(void) {
    mvRight(&currentTet);
}

void gameMoveDown(void) {
    mvDown(&currentTet);
}

void gameRotate(void) {
    rotateTet(&currentTet);
}

void gameRestart() {
    int i, j;

    score = 0;
    firstTet = true;
    gameDisplay();
    showScores(0);
    drawGameBorder();
    srand(SysTick->VAL);
    tick = 1;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 10; j++) {
            board[i][j] = 0;
        }
    }
}
void gameTick() {
    mvDown(&currentTet);
    if (downCollision(&currentTet)) {
        for (int i = 0; i < 4; i++) {
            volatile gameLoc offset;
            offset.column = tetrominos[currentTet.type][currentTet.orientation][i].column;
            offset.row = tetrominos[currentTet.type][currentTet.orientation][i].row;
            gameLoc origin = currentTet.origin;
            board[origin.row + offset.row][origin.column + offset.column] = true;
        }
        if (tick == -1)
            while(1);
        tick = 1;
    }
}
/*
 * Game drawing functions for drawing the game border and the tetrominos
 */
void drawGameBorder(void)
{
	for (int x = X_MIN; x < X_MAX; x++) {
		pixel(x, Y_MIN, color_white);
		pixel(x, Y_MAX, color_white);
	}
	for (int y = Y_MIN; y <= Y_MAX; y++) {
		pixel(X_MIN, y, color_white);
		pixel(X_MAX, y, color_white);
	}
}

void drawSquare(gameLoc *loc, uint16_t colour)
{
	unsigned char y = Y_MIN + loc->row * PIXEL_SCALE_FACTOR;
	unsigned char x = X_MIN + loc->column * PIXEL_SCALE_FACTOR;
	block(x, y, colour);
}

void drawNextTet(uint16_t colour)
{
    for (char i = 0; i < 4; i++) {
        gameLoc offset = tetrominos[nextTet.type][nextTet.orientation][i];
        gameLoc draw;
        draw.column = COL_MAX + 2 + offset.column;
        draw.row = ROW_MAX / 2 + 2 + offset.row;
        drawSquare(&draw, colour);
    }
}

void drawTet(tet *t, uint16_t colour)
{
	for (char i = 0; i < 4; i++) {
		gameLoc offset = tetrominos[t->type][t->orientation][i];
		gameLoc draw;
		draw.column = t->origin.column + offset.column;
		draw.row = t->origin.row + offset.row;
		drawSquare(&draw, colour);
	}
}

/*
 * Tetromino Movement Functions
 * These are triggered on interrupt and not called manually.
 */
void rotateTet(tet *t)
{
	drawTet(t, color_defback);
	if (!rotCollision(t))
		t->orientation = (t->orientation + 1) % 4;
	drawTet(t, color_white);
}

void mvLeft(tet *t)
{
	drawTet(t, color_defback);
	if (!leftCollision(t))
		t->origin.column--;
	drawTet(t, color_white);
}

void mvRight(tet *t)
{
	drawTet(t, color_defback);
	if (!rightCollision(t))
		t->origin.column++;
	drawTet(t, color_white);
}

void mvDown(tet *t)
{
	drawTet(t, color_defback);
	if (!downCollision(t))
		t->origin.row++;
	drawTet(t, color_white);
}

void newTet(gameLoc origin, char orientation, SHAPE type, tet *t)
{
	t->type = type;
	t->origin = origin;
	t->orientation = orientation;
}

/*
 * Boundary and collision checking code
 */

char downCollision(tet *t)
{
	for (char i = 0; i < 4; i++) {
		gameLoc offset = tetrominos[t->type][t->orientation][i];
		gameLoc origin = t->origin;
		if (board[origin.row + offset.row + 1][origin.column + offset.column]) { //Checking against other blocks
			return true;
		}
		if (origin.row + offset.row + 1 >= ROW_MAX) { // Checking against game boundaries
			return true;
		}
	}
	return false;
}

char leftCollision(tet *t)
{
	for (char i = 0; i < 4; i++) {
		gameLoc offset = tetrominos[t->type][t->orientation][i];
		gameLoc origin = t->origin;
		if (board[origin.row + offset.row][origin.column + offset.column - 1]) //Checking against other blocks
			return true;
		if (origin.column + offset.column - 1 < COL_MIN) // Checking against game boundaries
			return true;
	}
	return false;
}

char rightCollision(tet *t)
{
	for (char i = 0; i < 4; i++) {
		gameLoc offset = tetrominos[t->type][t->orientation][i];
		gameLoc origin = t->origin;
		if (board[origin.row + offset.row][origin.column + offset.column + 1]) //Checking against other blocks
			return true;
		if (origin.column + offset.column + 1 >= COL_MAX) // Checking against game boundaries
			return true;
	}
	return false;
}

char rotCollision(tet *t)
{
	gameLoc orig = t->origin;
	for (int i = 0; i < 4; i++) {
		gameLoc offset = tetrominos[t->type][(t->orientation + 1) % 4][i];
		if (offset.column + orig.column >= COL_MAX || offset.column + orig.column < COL_MIN) //Check out of bounds horizontally
			return 1;
		if (offset.row + orig.row >= ROW_MAX || offset.row + orig.row < COL_MIN) // Check out of bounds vertically
			return 1;
		if (board[orig.row + offset.row][orig.column + offset.column]) // Check for other blocks
			return 1;
	}
	return 0;
}

/*
 * Goal check and board compress algorithms
 */

char clearGoal(void)
{
	char goalCount = 0;
	char start = 0;
	for (char i = ROW_MAX - 1; i >= ROW_MIN; i--) {
		char goal = true;
		for(char j = COL_MIN; j < COL_MAX; j++) {
			if (!board[i][j]) {
				goal = false;
				break; // Don't Clear the row
			}
		}
		if (goal) { // Clear it!
			goalCount++;
			if (i > start)
				start = i;
			for (char k = COL_MIN; k < COL_MAX; k++) {
				board[i][k] = false;
				gameLoc clear;
				clear.row = i;
				clear.column = k;
				drawSquare(&clear, color_defback);
			}
            compress(i);
            i += 1;
		}
	}
	if (goalCount) {
		soundBeep();
	}
	return goalCount;
}

void compress(char line)
{
	for (char i = line - 1; i >= ROW_MIN; i--) {
		for (char j = COL_MIN; j < COL_MAX; j++) {
			if (board[i][j]) {
				board[i][j] = false;
				board[i + 1][j] = true;
				gameLoc move;
				move.row = i;
				move.column = j;
				drawSquare(&move, color_defback);
				move.row = i + 1;
				drawSquare(&move, color_white);
			}
		}
	}
}

char isgameOver()
{
	char row = ROW_MIN + 1;
	for (int col = COL_MIN; col < COL_MAX; col++) {
		if (board[row][col])
			return true;
	}
	return false;
}

/*
 * Main game loop
 */

void gameLoop(void)
{
		gameLoc origin = {5, 1};
		if (isgameOver()) {
		    showScores(-1);
		    soundHiAlarm();
		} else {
		    if (tick) {
		        tick = 0;
		        if (firstTet) {
		            newTet(origin, 0, (SHAPE)(rand() % 7), &currentTet);
		            newTet(origin, 0, (SHAPE)(rand() % 7), &nextTet);
		            drawNextTet(color_white);
		            firstTet = false;
		        } else {
		            currentTet = nextTet;
                    drawNextTet(color_defback);
		            newTet(origin, 0, (SHAPE)(rand() % 7), &nextTet);
                    drawNextTet(color_white);
		        }
		        drawTet(&currentTet, color_white);
		        score += clearGoal();
		        showScores(score);
		    } else {
		        gameTick();
		    }
		}
}
