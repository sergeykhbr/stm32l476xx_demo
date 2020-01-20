#ifndef FONT_H
#define FONT_H

#include <inttypes.h>
#include <button_config.h>

/**
    \brief This structure describes one particular character image
*/
typedef struct {
    uint8_t charWidth; ///< Number of columns
    const void *charData; ///< pointer to array with raw columns data
} FontCharacter;

/**
    \brief This structure describes whole font
*/
typedef struct {
    uint8_t charHeight; ///< Number of pixels in one column
    uint8_t elemSize;   ///< Number of pixels contained in one image element
    const FontCharacter *chars[224];    ///< Describe images starting from 0x20 (Space)
} Font;

typedef struct {
    uint16_t bgColor;
    uint16_t fgColor;
    const FontCharacter *startCap;
    const FontCharacter *keyCharacter;
    const FontCharacter *endCap;
} KeyCharacter;

const KeyCharacter *getButtonCharacter(buttonName_t button);
const Font *getCurrentFont();
void initFonts();
void setFontSize(uint8_t fontSize);
uint8_t getFontSize();
uint32_t getFontScale();

#endif // FONT_H
