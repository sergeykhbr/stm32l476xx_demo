#include <stm32l4xx.h>
#include <stdlib.h>
#include "display.h"
#include "font.h"

#define INIT_SEQUENCE_LENGTH 78

#define RST_SET() (GPIOA->ODR |= Reset_Pin)
#define RST_CLEAR() (GPIOA->ODR &= ~Reset_Pin)
#define RD_SET() (GPIOA->ODR |= RD_Pin)
#define RD_CLEAR() (GPIOA->ODR &= ~RD_Pin)
#define WR_SET() (GPIOA->ODR |= WR_Pin)
#define WR_CLEAR() (GPIOA->ODR &= ~WR_Pin)
#define DC_SET() (GPIOA->ODR |= DC_Pin)
#define DC_CLEAR() (GPIOA->ODR &= ~DC_Pin)
#define CS_SET() (GPIOA->ODR |= CS_Pin)
#define CS_CLEAR() (GPIOA->ODR &= ~CS_Pin)

const InitSequenceRecord DisplayInitSequence[INIT_SEQUENCE_LENGTH] = {
{INIT_SEQ_CMD, 0x11},
{INIT_SEQ_CMD, 0x3A},
{INIT_SEQ_DATA, 0x05},
{INIT_SEQ_CMD, 0x36},
{INIT_SEQ_DATA, 0x00},
{INIT_SEQ_CMD, 0xb2},
{INIT_SEQ_DATA, 0x00},
{INIT_SEQ_DATA, 0x00},
{INIT_SEQ_DATA, 0x00},
{INIT_SEQ_DATA, 0x33},
{INIT_SEQ_DATA, 0x33},
{INIT_SEQ_CMD, 0xb7},
{INIT_SEQ_DATA, 0x35},
{INIT_SEQ_CMD, 0xb8},
{INIT_SEQ_DATA, 0x2f},
{INIT_SEQ_DATA, 0x2b},
{INIT_SEQ_DATA, 0x2f},
{INIT_SEQ_CMD, 0xbb},
{INIT_SEQ_DATA, 0x24},
{INIT_SEQ_CMD, 0xc0},
{INIT_SEQ_DATA, 0x2C},
{INIT_SEQ_CMD, 0xc3},
{INIT_SEQ_DATA, 0x0b},
{INIT_SEQ_CMD, 0xc4},
{INIT_SEQ_DATA, 0x20},
{INIT_SEQ_CMD, 0xc6},
{INIT_SEQ_DATA, 0x11},
{INIT_SEQ_CMD, 0xd0},
{INIT_SEQ_DATA, 0xa4},
{INIT_SEQ_DATA, 0xa1},
{INIT_SEQ_CMD, 0xe8},
{INIT_SEQ_DATA, 0x03},
{INIT_SEQ_CMD, 0xe9},
{INIT_SEQ_DATA, 0x0d},
{INIT_SEQ_DATA, 0x12},
{INIT_SEQ_DATA, 0x00},
{INIT_SEQ_CMD, 0xe0},
{INIT_SEQ_DATA, 0xd0},
{INIT_SEQ_DATA, 0x00},
{INIT_SEQ_DATA, 0x00},
{INIT_SEQ_DATA, 0x08},
{INIT_SEQ_DATA, 0x11},
{INIT_SEQ_DATA, 0x1a},
{INIT_SEQ_DATA, 0x2b},
{INIT_SEQ_DATA, 0x33},
{INIT_SEQ_DATA, 0x42},
{INIT_SEQ_DATA, 0x26},
{INIT_SEQ_DATA, 0x12},
{INIT_SEQ_DATA, 0x21},
{INIT_SEQ_DATA, 0x2f},
{INIT_SEQ_DATA, 0x11},
{INIT_SEQ_CMD, 0xe1},
{INIT_SEQ_DATA, 0xd0},
{INIT_SEQ_DATA, 0x02},
{INIT_SEQ_DATA, 0x09},
{INIT_SEQ_DATA, 0x0d},
{INIT_SEQ_DATA, 0x0d},
{INIT_SEQ_DATA, 0x27},
{INIT_SEQ_DATA, 0x2b},
{INIT_SEQ_DATA, 0x33},
{INIT_SEQ_DATA, 0x42},
{INIT_SEQ_DATA, 0x17},
{INIT_SEQ_DATA, 0x12},
{INIT_SEQ_DATA, 0x11},
{INIT_SEQ_DATA, 0x2f},
{INIT_SEQ_DATA, 0x31},
{INIT_SEQ_CMD, 0x21},
{INIT_SEQ_CMD, 0x2A},
{INIT_SEQ_DATA, 0x00},
{INIT_SEQ_DATA, 0x00},
{INIT_SEQ_DATA, 0x00},
{INIT_SEQ_DATA, 0xEF},
{INIT_SEQ_CMD, 0x2B},
{INIT_SEQ_DATA, 0x00},
{INIT_SEQ_DATA, 0x00},
{INIT_SEQ_DATA, 0x01},
{INIT_SEQ_DATA, 0x3F},
{INIT_SEQ_CMD, 0x29}};

static uint16_t currentPage, currentColumn;
static uint16_t fgColor, bgColor;

void initDisplay() {
    RST_SET();
    //Wait to leave reset
    //TODO: implement delay by using tasks
    for (int i = 0; i < 1000; i++);
    RD_SET();
    CS_CLEAR();

    for (uint32_t i = 0; i < INIT_SEQUENCE_LENGTH; i++) {
        switch (DisplayInitSequence[i].type) {
            case INIT_SEQ_CMD:
                WR_CLEAR();
                DC_CLEAR();
                GPIOD->ODR = DisplayInitSequence[i].data;
                WR_SET();
                break;
            case INIT_SEQ_DATA:
                WR_CLEAR();
                DC_SET();
                GPIOD->ODR = DisplayInitSequence[i].data;
                WR_SET();
                break;
        }
    }
    start_display();
}

static void cmdWrite(uint16_t cmd) {
    WR_CLEAR();
    DC_CLEAR();
    GPIOD->ODR = cmd;
    WR_SET();
}

static void dataWrite(uint16_t data) {
    WR_CLEAR();
    DC_SET();
    GPIOD->ODR = data;
    WR_SET();
}

void setFgColor(uint16_t color) {
    fgColor = color;
}

void setBgColor(uint16_t color) {
    bgColor = color;
}

//column -> x
//page -> y
void graflocat(uint16_t page, uint16_t column) {
    cmdWrite(0x2A);
    dataWrite(0x00);
    dataWrite(240 - page - getFontSize());
    dataWrite(0x00);
    dataWrite(240);
    cmdWrite(0x2B);
    dataWrite(column >> 8);
    dataWrite(column & 0xFF);
    dataWrite(0x01);
    dataWrite(0x3F);

    currentPage = page;
    currentColumn = column;
}

void fillhx(uint16_t column) {
    uint16_t lastCol;

    lastCol = column;
    if (column > 320) {
        lastCol = 320;
    }
    graflocat(currentPage, currentColumn);
    for (int i = currentColumn; i < lastCol; i++) {
        cmdWrite(0x2C);
        for (int j = 0; j < getFontSize(); j++) {
            dataWrite(bgColor);
        }
        graflocat(currentPage, currentColumn + 1);
    }
}

void enterxxx() {
    fillhx(320);
    currentColumn = 0;
    currentPage += getFontSize();
}

void start_display() {
    currentPage = 0;
    currentColumn = 0;
    fgColor = color_datatitle;
    bgColor = color_defback;
    setFontSize(8);
}

void grafchar(char c) {
    Font *font;
    FontCharacter *charImage;
    uint32_t charPixels = 0;
    uint32_t pixelMask = 0;
    uint32_t charSize;
    uint32_t fontScale, scaleW;
    uint32_t i = 0;

    font = (Font*)getCurrentFont();
    charImage = (FontCharacter*)font->chars[c - 0x20];
    charSize = charImage->charWidth * font->charHeight / font->elemSize;
    fontScale = getFontScale();

    scaleW = fontScale;

    graflocat(currentPage, currentColumn);
    cmdWrite(0x2C);
    while (i < charSize) {
        switch (font->elemSize) {
        case 8:
            charPixels = *((uint8_t*)charImage->charData + i);
            pixelMask = 0x80;
            break;
        case 16:
            charPixels = *((uint16_t*)charImage->charData + i);
            pixelMask = 0x8000;
            break;
        case 32:
            charPixels = *((uint32_t*)charImage->charData + i);
            pixelMask = 0x80000000;
            break;
        }

        for (int j = 0; j < font->elemSize; j++) {
            if ((charPixels & pixelMask) != 0) {
                for (uint32_t scaleH = 0; scaleH < fontScale; scaleH++) {
                    dataWrite(fgColor);
                }
            } else {
                for (uint32_t scaleH = 0; scaleH < fontScale; scaleH++) {
                    dataWrite(bgColor);
                }
            }
            charPixels <<= 1;
        }

        i++;
        if (i % (font->charHeight / font->elemSize) == 0) {
            graflocat(currentPage, currentColumn + 1);
            cmdWrite(0x2C);
            if (scaleW > 1) {
                scaleW--;
                i = i - font->charHeight / font->elemSize;
            } else {
                scaleW = fontScale;
            }
        }
    }
}

void keyshow(uint8_t key) {
    KeyCharacter *keyCharacter = getKeyCharacter(key);
    const FontCharacter *currentImage;
    uint8_t charPixels;
    uint8_t pixelMask;
    uint32_t i = 0;

    currentImage = keyCharacter->startCap;
    graflocat(currentPage, currentColumn);
    cmdWrite(0x2C);
    while (i < currentImage->charWidth * 3) {
        charPixels = *((uint8_t*)currentImage->charData + i);
        pixelMask = 0x80;
        for (int j = 0; j < 8; j++) {
            if ((charPixels & pixelMask) != 0) {
                dataWrite(keyCharacter->bgColor);
            } else {
                dataWrite(bgColor);
            }
            charPixels <<= 1;
        }
        i++;
        if (i % 3 == 0) {
            graflocat(currentPage, currentColumn + 1);
            cmdWrite(0x2C);
        }
    }
    i = 0;
    currentImage = keyCharacter->keyCharacter;
    graflocat(currentPage, currentColumn);
    cmdWrite(0x2C);
    while (i < currentImage->charWidth * 3) {
        charPixels = *((uint8_t*)currentImage->charData + i);
        pixelMask = 0x80;
        for (int j = 0; j < 8; j++) {
            if ((charPixels & pixelMask) != 0) {
                dataWrite(keyCharacter->fgColor);
            } else {
                dataWrite(keyCharacter->bgColor);
            }
            charPixels <<= 1;
        }
        i++;
        if (i % 3 == 0) {
            graflocat(currentPage, currentColumn + 1);
            cmdWrite(0x2C);
        }
    }
    i = 0;
    currentImage = keyCharacter->endCap;
    graflocat(currentPage, currentColumn);
    cmdWrite(0x2C);
    while (i < currentImage->charWidth * 3) {
        charPixels = *((uint8_t*)currentImage->charData + i);
        pixelMask = 0x80;
        for (int j = 0; j < 8; j++) {
            if ((charPixels & pixelMask) != 0) {
                dataWrite(keyCharacter->bgColor);
            } else {
                dataWrite(bgColor);
            }
            charPixels <<= 1;
        }
        i++;
        if (i % 3 == 0) {
            graflocat(currentPage, currentColumn + 1);
            cmdWrite(0x2C);
        }
    }
}

void putstr(const char *s) {
    while (*s) {
        grafchar(*(s++));
    }
}

void filldisplay() {
    setFontSize(8);
    while (currentPage < 240) {
        enterxxx();
    }
}

void enteremtystr() {
    enterxxx();
    setFontSize(8);
    enterxxx();
}

void display00() {
    start_display();
    filldisplay();
}

void display01() {
    uint16_t column1, column2;

    start_display();
    setFontSize(8);
    setFgColor(color_white);
    enterxxx();
    setFontSize(32);
    fillhx(16);
    //grafchar(0x5B); // 5b
    //grafchar(0x7E);
    putstr("Sergey Khabarov");
    grafchar(' ');
    column1 = currentColumn;
    putstr("Sim");
    column2 = currentColumn;
    setFontSize(8);
    putstr("R");
    setFontSize(32);
    enterxxx();
    setFontSize(8);
    enterxxx();
    setFontSize(32);
    putstr(" ARM Cortex-M4 inside");
    enterxxx();
    enterxxx();
    setFontSize(16);
    fillhx(16);
    putstr("Software Version: ");
    enterxxx();
    setFontSize(12);
    enterxxx();
    setFontSize(16);
    fillhx(16);
    setFgColor(0xf483);
    putstr("STM32L4xx Demo firmware");
    enterxxx();
    setFontSize(12);
    enterxxx();
    setFontSize(16);
    fillhx(16);
    setFgColor(color_white);
    putstr("Library");
    fillhx(150);
    putstr("-----------");
    enterxxx();
    setFontSize(12);
    enterxxx();
    setFontSize(16);
    fillhx(16);
    putstr("Serial Number: ");
    fillhx(150);
    putstr("T     1    ");
    enterxxx();
    setFontSize(12);
    enterxxx();
    setFontSize(16);
    fillhx(16);
    putstr("Production Date: ");
    fillhx(150);
    putstr("24-Jan-2020");
    enterxxx();
    enterxxx();
}

void display65(uint8_t level) {
    char *buf[8];

    start_display();
    setFontSize(32);
    putstr("Sound alarm test");
    enterxxx();
    setFontSize(24);
    enterxxx();
    putstr("Current sound level: ");
    itoa(level, buf, 10);
    putstr(buf);
    enterxxx();
    filldisplay();
}

void display66() {
	start_display();
	setFontSize(32);
	putstr("Door Sensor Test ");
    enterxxx();
    enterxxx();

	setFontSize(72);
    setFgColor(color_warnfont);
    if ((GPIOC->IDR & 0x01UL) != 0) {
        putstr("Open");
    } else {
        putstr("Close");
    }
    enterxxx();
    setFontSize(24);
    enterxxx();
    enterxxx();
    enterxxx();
    putstr("Press ");
    keyshow(Button_Ok);
    putstr(" Key to Continue");
    enterxxx();
    filldisplay();
}

void display68() {
    start_display();
    setFontSize(32);
    putstr("Motor rotation test");
    enterxxx();
    setFontSize(24);
    enterxxx();
    enterxxx();
    putstr("Please check motor rotation");
    enterxxx();
    putstr("Press ");
    keyshow(Button_5);
    putstr(" to increase and ");
    keyshow(Button_0);
    enterxxx();
    putstr("to decrease the motor speed");
    enterxxx();
    enterxxx();
    enterxxx();
    putstr("Press ");
    keyshow(Button_No);
    putstr(" to exit");
    enterxxx();
    filldisplay();
}

void display64(uint8_t currentKey) {
    start_display();
    setFontSize(32);
    putstr("Keypad Test ");
    enteremtystr();
    setFontSize(24);
    keyshow(Button_Power);
    fillhx(250);
    keyshow(Button_No);
    enteremtystr();
    setFontSize(24);
    keyshow(Button_Lock);
    fillhx(250);
    keyshow(Button_Ok);
    enteremtystr();
    setFontSize(24);
    keyshow(Button_Info);
    fillhx(250);
    keyshow(Button_Prime);
    enterxxx();
    setFontSize(16);
    enterxxx();
    setFontSize(24);
    keyshow(Button_1);
    fillhx(50);
    keyshow(Button_2);
    fillhx(100);
    keyshow(Button_3);
    fillhx(150);
    keyshow(Button_4);
    fillhx(200);
    keyshow(Button_5);
    fillhx(250);
    keyshow(Button_Point);
    enteremtystr();
    setFontSize(24);
    keyshow(Button_6);
    fillhx(50);
    keyshow(Button_7);
    fillhx(100);
    keyshow(Button_8);
    fillhx(150);
    keyshow(Button_9);
    fillhx(200);
    keyshow(Button_0);
    enterxxx();
    setFontSize(16);
    enterxxx();
    setFontSize(24);
    setFgColor(color_white);
    if (currentKey != Button_Last) {
        putstr("Press ");
        keyshow(currentKey);
        putstr(" Key");
    } else {
        putstr("Test OK! Press ");
        keyshow(Button_Ok);
        putstr(" to continue.");
    }
    enterxxx();
    filldisplay();
};

void display48(char *items[], int32_t count, int32_t selected) {
    int32_t startItem, endItem;

    start_display();
    setFontSize(32);
    putstr("Technician options: ");
    enteremtystr();
    if (selected < 4) {
        startItem = 0;
        if (count > 7) {
            endItem = 7;
        } else {
            endItem = count;
        }
    } else if (selected > count - 4) {
        if (count >= 7) {
            startItem = count - 7;
        } else {
            startItem = 0;
        }
        endItem = count;
    } else {
        startItem = selected - 3;
        endItem = selected + 4;
    }

    for (int i = startItem; i < endItem; i++) {
        if (i != selected) {
            setFgColor(color_selnotsel);
            setBgColor(color_defback);
            setFontSize(24);
            putstr(items[i]);
            setFgColor(color_white);
            enterxxx();
        } else {
            setFgColor(color_white);
            setBgColor(color_green);
            setFontSize(32);
            putstr(items[i]);
            setBgColor(color_defback);
            enterxxx();
        }
    }

    setFontSize(24);
    for (int i = 0; i < 7 - (endItem - startItem); i++) {
        enterxxx();
    }

    setFgColor(color_white);
    setFontSize(24);
    putstr("Select ");
    keyshow(Button_5);
    putstr(", ");
    keyshow(Button_0);
    putstr(" and press ");
    keyshow(Button_Ok);
    enterxxx();
    filldisplay();
}

void colorfill(uint16_t color) {
    int x, y;

    start_display();
    setFontSize(8);
    graflocat(240 - 8, 0);
    cmdWrite(0x2C);
    for (x = 0; x < 320; x++) {
        for (y = 0; y < 240; y++) {
            dataWrite(color);
        }
    }
}

void pixel(int x, int y, uint16_t color) {
    setFontSize(0);
    graflocat(y, x);
    cmdWrite(0x2C);
    dataWrite(color);
}

void block(int x, int y, uint16_t color) {
    if (color == color_defback) {
        for (int i = x + 1; i < x + 9; i++) {
            for (int j = y + 1; j < y + 9; j++) {
                pixel(i, j, color);
            }
        }
    } else {
        for (int i = x + 2; i < x + 8; i++) {
            for (int j = y + 2; j < y + 8; j++) {
                pixel(i, j, color);
            }
        }
        for (int i = x + 1; i < x + 9; i++) {
            pixel(i, y + 1, color_white);
            pixel(i, y + 8, color_gray);
        }
        for (int j = y + 1; j < y + 9; j++) {
            pixel(x + 1, j, color_white);
            pixel(x + 8, j, color_gray);
        }

    }
}

void showScores(int scores) {
    char buf[8];

    start_display();
    setFontSize(24);
    graflocat(0, 235);
    enterxxx();
    graflocat(currentPage, 235);
    if (scores >= 0) {
        itoa(scores, buf, 10);
        putstr("Scores");
        enterxxx();
        graflocat(currentPage, 235);
        putstr(buf);
    } else {
        putstr("Game");
        enterxxx();
        graflocat(currentPage, 235);
        putstr("Over");
    }
    graflocat(4 * getFontSize(), 235);
    putstr("Next:");
    enterxxx();

}

void gameDisplay() {
    colorfill(color_defback);
    start_display();
    setFontSize(24);
    enterxxx();
    keyshow(Button_4);
    putstr(" - Left");
    enterxxx();
    setFontSize(8);
    enterxxx();
    setFontSize(24);
    keyshow(Button_Point);
    putstr(" - Right");
    enterxxx();
    setFontSize(8);
    enterxxx();
    setFontSize(24);
    keyshow(Button_5);
    putstr(" - Rotate");
    enterxxx();
    setFontSize(8);
    enterxxx();
    setFontSize(24);
    keyshow(Button_Prime);
    putstr(" - Down");
    enterxxx();
    setFontSize(8);
    enterxxx();
    setFontSize(24);
    keyshow(Button_Ok);
    putstr(" - New");
    enterxxx();
}

void displayAlarmTest() {
    start_display();
    setFontSize(32);
    putstr("High priority alarm");
    enterxxx();
    filldisplay();
}
