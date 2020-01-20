#include "font.h"
#include "fonts8.c"
#include "fonts16.c"
#include "fonts24.c"
#include "fonts32.c"
#include "fontkeys.c"

static uint8_t currentFontSize;
static uint32_t fontScale;

void initFonts() {
    currentFontSize = 8;
    fontScale = 1;
}

void setFontSize(uint8_t fontSize) {
    currentFontSize = fontSize;

    switch (fontSize) {
    case 8:
    case 16:
    case 32:
    case 24:
        fontScale = 1;
        break;
    case 64:
    case 48:
        fontScale = 2;
        break;
    case 72:
        fontScale = 3;
        break;
    case 96:
        fontScale = 4;
        break;
    }
}

uint8_t getFontSize() {
    return currentFontSize;
}

const Font *getCurrentFont() {
    switch (currentFontSize) {
    case 8:
        return &font8;
    case 16:
        return &font16;
    case 32:
        return &font32;
    case 24:
    case 48:
    case 72:
    case 96:
        return &font24;
    default:
        return &font8;
    }
}

uint32_t getFontScale() {
    return fontScale;
}

const KeyCharacter *getKeyCharacter(buttonName_t button) {
    return FontKeys[button];
}
