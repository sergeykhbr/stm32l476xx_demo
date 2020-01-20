#ifndef GAME_H
#define GAME_H
#include "display.h"
#include <stdint.h>

#define COL_MAX 10
#define ROW_MAX 20
#define COL_MIN 0
#define ROW_MIN 0
#define TETROMINO_TYPES 7
#define ORIENTATIONS 3
#define TETROMINO_CELLS 4
#define PIXEL_SCALE_FACTOR 10

#define Y_MIN 10
#define X_MIN 125
#define Y_MAX 210
#define X_MAX 225

#define false 0
#define true (!false)

typedef enum {
	I = 0, J, L, O, S, T, Z
} SHAPE;

typedef struct {
    char column;
    char row;
} gameLoc;

typedef struct {
	SHAPE type;
	char orientation;
	gameLoc origin;
} tet;

// Global, current and next tetrominos at all times
extern tet currentTet;
extern tet nextTet;
extern unsigned int score;
extern unsigned char speed; // Ticks per second

void gameLoop(void);
void gameMoveLeft(void);
void gameMoveRight(void);
void gameMoveDown(void);
void gameRotate(void);
void gameRestart(void);

#endif
