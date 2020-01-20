#include <font.h>

const uint8_t FontKey_StartCap[] = {
    0x1F,0xFF,0xF8,
    0x7F,0xFF,0xFE
};

const uint8_t FontKey_EndCap[] = {
    0x7F,0xFF,0xFE,
    0x1F,0xFF,0xF8
};

const uint8_t FontKey_Prime[] = {
    0x00,0x00,0x00,
    0x0F,0xFF,0xE0,
    0x07,0xFF,0xC0,
    0x03,0xFF,0x80,
    0x01,0xFF,0x00,
    0x00,0xFE,0x00,
    0x00,0x7C,0x00,
    0x00,0x38,0x00,
    0x00,0x10,0x00,
    0x00,0x00,0x00,
    0x0F,0xFF,0xE0,
    0x07,0xFF,0xC0,
    0x03,0xFF,0x80,
    0x01,0xFF,0x00,
    0x00,0xFE,0x00,
    0x00,0x7C,0x00,
    0x00,0x38,0x00,
    0x00,0x10,0x00,
    0x00,0x00,0x00,
    0x0F,0xFF,0xE0,
    0x07,0xFF,0xC0,
    0x03,0xFF,0x80,
    0x01,0xFF,0x00,
    0x00,0xFE,0x00,
    0x00,0x7C,0x00,
    0x00,0x38,0x00,
    0x00,0x10,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00
};

const uint8_t FontKey_0[] = {
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x1C,
    0x00,0x00,0x7E,
    0x00,0x01,0xE6,
    0x00,0x07,0x86,
    0x00,0x1F,0x0C,
    0x00,0x3C,0x0C,
    0x00,0xF0,0x0C,
    0x03,0xC0,0x18,
    0x0F,0x00,0x18,
    0x3C,0x3E,0x18,
    0x78,0x41,0x30,
    0x60,0x49,0x30,
    0x78,0x41,0x30,
    0x3C,0x3E,0x18,
    0x0F,0x00,0x18,
    0x03,0xC0,0x18,
    0x00,0xF0,0x0C,
    0x00,0x3C,0x0C,
    0x00,0x1F,0x0C,
    0x00,0x07,0x86,
    0x00,0x01,0xE6,
    0x00,0x00,0x7E,
    0x00,0x00,0x1C,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
};

const uint8_t FontKey_1[] = {
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x42,0x00,
    0x00,0x7F,0x00,
    0x00,0x40,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
};

const uint8_t FontKey_2[] = {
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x42,0x00,
    0x00,0x61,0x00,
    0x00,0x51,0x00,
    0x00,0x49,0x00,
    0x00,0x46,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
};

const uint8_t FontKey_3[] = {
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x21,0x00,
    0x00,0x41,0x00,
    0x00,0x45,0x00,
    0x00,0x4B,0x00,
    0x00,0x31,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
};

const uint8_t FontKey_4[] = {
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x1C,0x00,
    0x00,0x3E,0x00,
    0x00,0x36,0x00,
    0x00,0x77,0x00,
    0x00,0x63,0x00,
    0x00,0xC1,0x80,
    0x00,0xC1,0x80,
    0x01,0x80,0xC0,
    0x01,0x80,0xC0,
    0x03,0x18,0x60,
    0x07,0x14,0x70,
    0x06,0x12,0x30,
    0x0E,0x7F,0x38,
    0x0C,0x10,0x18,
    0x1C,0x00,0x1C,
    0x18,0x00,0x0C,
    0x30,0x00,0x06,
    0x30,0x1C,0x06,
    0x60,0xFF,0x83,
    0x67,0xE3,0xF3,
    0x7F,0x00,0x7F,
    0x38,0x00,0x0E,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
};

const uint8_t FontKey_5[] = {
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x38,0x00,0x00,
    0x7E,0x00,0x00,
    0x67,0x80,0x00,
    0x61,0xE0,0x00,
    0x30,0xF8,0x00,
    0x30,0x3C,0x00,
    0x30,0x0F,0x00,
    0x18,0x03,0xC0,
    0x18,0x00,0xF0,
    0x18,0x27,0x3C,
    0x0C,0x45,0x1E,
    0x0C,0x45,0x06,
    0x0C,0x45,0x1E,
    0x18,0x39,0x3C,
    0x18,0x00,0xF0,
    0x18,0x03,0xC0,
    0x30,0x0F,0x00,
    0x30,0x3C,0x00,
    0x30,0xF8,0x00,
    0x61,0xE0,0x00,
    0x67,0x80,0x00,
    0x7E,0x00,0x00,
    0x38,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
};

const uint8_t FontKey_6[] = {
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x3C,0x00,
    0x00,0x4A,0x00,
    0x00,0x49,0x00,
    0x00,0x49,0x00,
    0x00,0x30,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
};

const uint8_t FontKey_7[] = {
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x01,0x00,
    0x00,0x71,0x00,
    0x00,0x09,0x00,
    0x00,0x05,0x00,
    0x00,0x03,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
};

const uint8_t FontKey_8[] = {
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x36,0x00,
    0x00,0x49,0x00,
    0x00,0x49,0x00,
    0x00,0x49,0x00,
    0x00,0x36,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
};

const uint8_t FontKey_9[] = {
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x06,0x00,
    0x00,0x49,0x00,
    0x00,0x49,0x00,
    0x00,0x29,0x00,
    0x00,0x1E,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
};

const uint8_t FontKey_Lock[] = {
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x0F,0xF8,0x00,
    0x0F,0xF8,0x00,
    0x0F,0xFE,0x00,
    0x0F,0xFF,0x80,
    0x0F,0xF9,0xC0,
    0x0F,0xF8,0x60,
    0x0F,0xF8,0x60,
    0x0F,0xF8,0x60,
    0x0F,0xF8,0x60,
    0x0F,0xF9,0xC0,
    0x0F,0xFF,0x80,
    0x0F,0xFE,0x00,
    0x0F,0xF8,0x00,
    0x0F,0xF8,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
};

const uint8_t FontKey_On[] = {
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x7E,0x00,
    0x01,0xFF,0x80,
    0x03,0x81,0xC0,
    0x06,0x00,0x60,
    0x0C,0x00,0x30,
    0x18,0x00,0x00,
    0x18,0x00,0x00,
    0x30,0x00,0x00,
    0x30,0x00,0x00,
    0x30,0x03,0xFE,
    0x30,0x03,0xFE,
    0x30,0x00,0x00,
    0x30,0x00,0x00,
    0x18,0x00,0x00,
    0x18,0x00,0x00,
    0x0C,0x00,0x30,
    0x06,0x00,0x60,
    0x03,0x81,0xC0,
    0x01,0xFF,0x80,
    0x00,0x7E,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
};

const uint8_t FontKey_Point[] = {
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x38,0x00,0x0E,
    0x7F,0x00,0x7F,
    0x67,0xE3,0xF3,
    0x60,0xFF,0x83,
    0x30,0x1C,0x06,
    0x30,0x00,0x06,
    0x18,0x00,0x0C,
    0x1C,0x00,0x1C,
    0x0C,0x60,0x18,
    0x06,0x60,0x30,
    0x06,0x00,0x30,
    0x03,0x00,0x60,
    0x03,0x00,0x60,
    0x03,0x00,0x60,
    0x01,0x80,0xC0,
    0x01,0x80,0xC0,
    0x00,0xC1,0x80,
    0x00,0xC1,0x80,
    0x00,0x63,0x00,
    0x00,0x77,0x00,
    0x00,0x36,0x00,
    0x00,0x3E,0x00,
    0x00,0x1C,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
};

const uint8_t FontKey_No[] = {
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x03,0xFF,0xC0,
    0x07,0xFF,0xE0,
    0x07,0xFF,0xE0,
    0x07,0xFF,0xE0,
    0x07,0xFF,0xE0,
    0x07,0xFF,0xE0,
    0x07,0xFF,0xE0,
    0x07,0xFF,0xE0,
    0x07,0xFF,0xE0,
    0x07,0xFF,0xE0,
    0x07,0xFF,0xE0,
    0x07,0xFF,0xE0,
    0x07,0xFF,0xE0,
    0x07,0xFF,0xE0,
    0x03,0xFF,0xC0,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00
};

const uint8_t FontKey_I[] = {
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x03,0xFF,0xC0,
    0x07,0xFF,0xE0,
    0x0E,0x00,0x70,
    0x0C,0x00,0x30,
    0x18,0x00,0x18,
    0x18,0x00,0x18,
    0x30,0x00,0x0C,
    0x33,0xFE,0xCC,
    0x33,0xFE,0xCC,
    0x30,0x00,0x0C,
    0x30,0x00,0x0C,
    0x30,0x18,0x0C,
    0x30,0x18,0x0C,
    0x30,0x18,0x0C,
    0x30,0x18,0x0C,
    0x31,0xFF,0x8C,
    0x31,0xFF,0x8C,
    0x30,0x18,0x0C,
    0x30,0x18,0x0C,
    0x18,0x18,0x18,
    0x18,0x18,0x18,
    0x0C,0x00,0x30,
    0x0E,0x00,0x70,
    0x07,0xFF,0xE0,
    0x03,0xFF,0xC0,
    0x00,0x00,0x00,
    0x00,0x00,0x00
};

const uint8_t FontKey_Ok[] = {
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x0F,0xFF,0xE0,
    0x07,0xFF,0xC0,
    0x07,0xFF,0xC0,
    0x03,0xFF,0x80,
    0x03,0xFF,0x80,
    0x01,0xFF,0x00,
    0x01,0xFF,0x00,
    0x00,0xFE,0x00,
    0x00,0xFE,0x00,
    0x00,0x7C,0x00,
    0x00,0x7C,0x00,
    0x00,0x38,0x00,
    0x00,0x38,0x00,
    0x00,0x10,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00,
    0x00,0x00,0x00
};


const FontCharacter fontKey_StartCap_char = {
    sizeof(FontKey_StartCap)/3,
    FontKey_StartCap
};

const FontCharacter fontKey_EndCap_char = {
    sizeof(FontKey_EndCap)/3,
    FontKey_EndCap
};

const FontCharacter fontKey_Prime_char = {
    sizeof(FontKey_Prime)/3,
    FontKey_Prime
};

const FontCharacter fontKey_0_char = {
    sizeof(FontKey_0)/3,
    FontKey_0
};

const FontCharacter fontKey_1_char = {
    sizeof(FontKey_1)/3,
    FontKey_1
};

const FontCharacter fontKey_2_char = {
    sizeof(FontKey_2)/3,
    FontKey_2
};

const FontCharacter fontKey_3_char = {
    sizeof(FontKey_3)/3,
    FontKey_3
};

const FontCharacter fontKey_4_char = {
    sizeof(FontKey_4)/3,
    FontKey_4
};

const FontCharacter fontKey_5_char = {
    sizeof(FontKey_5)/3,
    FontKey_5
};

const FontCharacter fontKey_6_char = {
    sizeof(FontKey_6)/3,
    FontKey_6
};

const FontCharacter fontKey_7_char = {
    sizeof(FontKey_7)/3,
    FontKey_7
};

const FontCharacter fontKey_8_char = {
    sizeof(FontKey_8)/3,
    FontKey_8
};

const FontCharacter fontKey_9_char = {
    sizeof(FontKey_9)/3,
    FontKey_9
};

const FontCharacter fontKey_Lock_char = {
    sizeof(FontKey_Lock)/3,
    FontKey_Lock
};

const FontCharacter fontKey_On_char = {
    sizeof(FontKey_On)/3,
    FontKey_On
};

const FontCharacter fontKey_Point_char = {
    sizeof(FontKey_Point)/3,
    FontKey_Point
};

const FontCharacter fontKey_No_char = {
    sizeof(FontKey_No)/3,
    FontKey_No
};

const FontCharacter fontKey_I_char = {
    sizeof(FontKey_I)/3,
    FontKey_I
};

const FontCharacter fontKey_Ok_char = {
    sizeof(FontKey_Ok)/3,
    FontKey_Ok
};

const KeyCharacter fontKey_Prime = {
    0xFAE0,
    0xFFFF,
    &fontKey_StartCap_char,
    &fontKey_Prime_char,
    &fontKey_EndCap_char
};

const KeyCharacter fontKey_0 = {
    0xFFFF,
    0x32AE,
    &fontKey_StartCap_char,
    &fontKey_0_char,
    &fontKey_EndCap_char
};

const KeyCharacter fontKey_1 = {
    0xFFFF,
    0x32AE,
    &fontKey_StartCap_char,
    &fontKey_1_char,
    &fontKey_EndCap_char
};

const KeyCharacter fontKey_2 = {
    0xFFFF,
    0x32AE,
    &fontKey_StartCap_char,
    &fontKey_2_char,
    &fontKey_EndCap_char
};

const KeyCharacter fontKey_3 = {
    0xFFFF,
    0x32AE,
    &fontKey_StartCap_char,
    &fontKey_3_char,
    &fontKey_EndCap_char
};

const KeyCharacter fontKey_4 = {
    0xFFFF,
    0x32AE,
    &fontKey_StartCap_char,
    &fontKey_4_char,
    &fontKey_EndCap_char
};

const KeyCharacter fontKey_5 = {
    0xFFFF,
    0x32AE,
    &fontKey_StartCap_char,
    &fontKey_5_char,
    &fontKey_EndCap_char
};

const KeyCharacter fontKey_6 = {
    0xFFFF,
    0x32AE,
    &fontKey_StartCap_char,
    &fontKey_6_char,
    &fontKey_EndCap_char
};

const KeyCharacter fontKey_7 = {
    0xFFFF,
    0x32AE,
    &fontKey_StartCap_char,
    &fontKey_7_char,
    &fontKey_EndCap_char
};

const KeyCharacter fontKey_8 = {
    0xFFFF,
    0x32AE,
    &fontKey_StartCap_char,
    &fontKey_8_char,
    &fontKey_EndCap_char
};

const KeyCharacter fontKey_9 = {
    0xFFFF,
    0x32AE,
    &fontKey_StartCap_char,
    &fontKey_9_char,
    &fontKey_EndCap_char
};

const KeyCharacter fontKey_Lock = {
    0xFFFF,
    0x32AE,
    &fontKey_StartCap_char,
    &fontKey_Lock_char,
    &fontKey_EndCap_char
};

const KeyCharacter fontKey_On = {
    0x32AE,
    0xFFFF,
    &fontKey_StartCap_char,
    &fontKey_On_char,
    &fontKey_EndCap_char
};

const KeyCharacter fontKey_Point = {
    0xFFFF,
    0x32AE,
    &fontKey_StartCap_char,
    &fontKey_Point_char,
    &fontKey_EndCap_char
};

const KeyCharacter fontKey_No = {
    0xD086,
    0xFFFF,
    &fontKey_StartCap_char,
    &fontKey_No_char,
    &fontKey_EndCap_char
};

const KeyCharacter fontKey_I = {
    0xFFFF,
    0x32AE,
    &fontKey_StartCap_char,
    &fontKey_I_char,
    &fontKey_EndCap_char
};

const KeyCharacter fontKey_Ok = {
    0x1565,
    0xFFFF,
    &fontKey_StartCap_char,
    &fontKey_Ok_char,
    &fontKey_EndCap_char
};

const KeyCharacter *FontKeys[Button_Last] = {
    &fontKey_6,
    &fontKey_7,
    &fontKey_8,
    &fontKey_9,
    &fontKey_0,
    &fontKey_I,
    &fontKey_Prime,
    &fontKey_Lock,
    &fontKey_1,
    &fontKey_2,
    &fontKey_3,
    &fontKey_4,
    &fontKey_5,
    &fontKey_Point,
    &fontKey_Ok,
    &fontKey_No,
    &fontKey_On
};