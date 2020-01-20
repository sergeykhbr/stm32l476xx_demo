#include <inttypes.h>
#include <font.h>

const uint8_t fonts8_20[] =
{ 0x00, 0x00, 0x00, 0x00};   //20 = ' '
const uint8_t fonts8_21[] =
{ 0x00, 0x00, 0x00, 0x4F, 0x00, 0x00};   //21 = '!'
const uint8_t fonts8_22[] =
{ 0x00, 0x00, 0x07, 0x00, 0x07, 0x00};   //22 = '"'
const uint8_t fonts8_23[] =
{ 0x00, 0x14, 0x7F, 0x14, 0x7F, 0x14};   //23 = '#'
const uint8_t fonts8_24[] =
{ 0x00, 0x24, 0x2A, 0x7F, 0x2A, 0x12};   //24 = '$'
const uint8_t fonts8_25[] =
{ 0x00, 0x23, 0x13, 0x08, 0x64, 0x62};   //25 = '%'
const uint8_t fonts8_26[] =
{ 0x00, 0x36, 0x49, 0x55, 0x22, 0x50};   //26 = '&'
const uint8_t fonts8_27[] =
{ 0x00, 0x00, 0x05, 0x03, 0x00, 0x00};   //27 = '''
const uint8_t fonts8_28[] =
{ 0x00, 0x00, 0x1C, 0x22, 0x41, 0x00};   //28 = '('
const uint8_t fonts8_29[] =
{ 0x00, 0x00, 0x41, 0x22, 0x1C, 0x00};   //29 = ')'
const uint8_t fonts8_2A[] =
{ 0x00, 0x14, 0x08, 0x3E, 0x08, 0x14};   //2a = '*'
const uint8_t fonts8_2B[] =
{ 0x00, 0x08, 0x08, 0x3E, 0x08, 0x08};   //2b = '+'
const uint8_t fonts8_2C[] =
{ 0x00, 0x00, 0x50, 0x30, 0x00, 0x00};   //2c = ','
const uint8_t fonts8_2D[] =
{ 0x00, 0x08, 0x08, 0x08, 0x08, 0x08};   //2d = '-'
const uint8_t fonts8_2E[] =
{ 0x00, 0x00, 0x60, 0x60, 0x00, 0x00};   //2e = '.'
const uint8_t fonts8_2F[] =
{ 0x00, 0x20, 0x10, 0x08, 0x04, 0x02};   //2f = '/'
const uint8_t fonts8_30[] =
{ 0x00, 0x3E, 0x41, 0x49, 0x41, 0x3E};   //30 = '0'
const uint8_t fonts8_31[] =
{ 0x00, 0x00, 0x42, 0x7F, 0x40, 0x00};   //31 = '1'
const uint8_t fonts8_32[] =
{ 0x00, 0x42, 0x61, 0x51, 0x49, 0x46};   //32 = '2'
const uint8_t fonts8_33[] =
{ 0x00, 0x21, 0x41, 0x45, 0x4B, 0x31};   //33 = '3'
const uint8_t fonts8_34[] =
{ 0x00, 0x18, 0x14, 0x12, 0x7F, 0x10};   //34 = '4'
const uint8_t fonts8_35[] =
{ 0x00, 0x27, 0x45, 0x45, 0x45, 0x39};   //35 = '5'
const uint8_t fonts8_36[] =
{ 0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30};   //36 = '6'
const uint8_t fonts8_37[] =
{ 0x00, 0x01, 0x71, 0x09, 0x05, 0x03};   //37 = '7'
const uint8_t fonts8_38[] =
{ 0x00, 0x36, 0x49, 0x49, 0x49, 0x36};   //38 = '8'
const uint8_t fonts8_39[] =
{ 0x00, 0x06, 0x49, 0x49, 0x29, 0x1E};   //39 = '9'
const uint8_t fonts8_3A[] =
{ 0x00, 0x00, 0x36, 0x36, 0x00, 0x00};   //3a = ':'
const uint8_t fonts8_3B[] =
{ 0x00, 0x00, 0x56, 0x36, 0x00, 0x00};   //3b = ';'
const uint8_t fonts8_3C[] =
{ 0x00, 0x08, 0x14, 0x22, 0x41, 0x08};   //3c = '<'
const uint8_t fonts8_3D[] =
{ 0x00, 0x14, 0x14, 0x14, 0x14, 0x14};   //3d = '='
const uint8_t fonts8_3E[] =
{ 0x00, 0x00, 0x41, 0x22, 0x14, 0x08};   //3e = '>'
const uint8_t fonts8_3F[] =
{ 0x00, 0x02, 0x01, 0x51, 0x09, 0x06};   //3f = '?'
const uint8_t fonts8_40[] =
{ 0x00, 0xFE, 0x20, 0x20, 0x10, 0x3E};   //40 = '@'
const uint8_t fonts8_41[] =
{ 0x00, 0x7E, 0x11, 0x11, 0x11, 0x7E};   //41 = 'A'
const uint8_t fonts8_42[] =
{ 0x00, 0x7F, 0x49, 0x49, 0x49, 0x36};   //42 = 'B'
const uint8_t fonts8_43[] =
{ 0x00, 0x3E, 0x41, 0x41, 0x41, 0x22};   //43 = 'C'
const uint8_t fonts8_44[] =
{ 0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C};   //44 = 'D'
const uint8_t fonts8_45[] =
{ 0x00, 0x7F, 0x49, 0x49, 0x49, 0x41};   //45 = 'E'
const uint8_t fonts8_46[] =
{ 0x00, 0x7F, 0x09, 0x09, 0x09, 0x01};   //46 = 'F'
const uint8_t fonts8_47[] =
{ 0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A};   //47 = 'G'
const uint8_t fonts8_48[] =
{ 0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F};   //48 = 'H'
const uint8_t fonts8_49[] =
{ 0x00, 0x00, 0x41, 0x7F, 0x41, 0x00};   //49 = 'I'
const uint8_t fonts8_4A[] =
{ 0x00, 0x20, 0x40, 0x41, 0x3F, 0x01};   //4a = 'J'
const uint8_t fonts8_4B[] =
{ 0x00, 0x7F, 0x08, 0x14, 0x22, 0x41};   //4b = 'K'
const uint8_t fonts8_4C[] =
{ 0x00, 0x7F, 0x40, 0x40, 0x40, 0x40};   //4c = 'L'
const uint8_t fonts8_4D[] =
{ 0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F};   //4d = 'M'
const uint8_t fonts8_4E[] =
{ 0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F};   //4e = 'N'
const uint8_t fonts8_4F[] =
{ 0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E};   //4f = 'O'
const uint8_t fonts8_50[] =
{ 0x00, 0x7F, 0x09, 0x09, 0x09, 0x06};   //50 = 'P'
const uint8_t fonts8_51[] =
{ 0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E};   //51 = 'Q'
const uint8_t fonts8_52[] =
{ 0x00, 0x7F, 0x09, 0x19, 0x29, 0x46};   //52 = 'R'
const uint8_t fonts8_53[] =
{ 0x00, 0x46, 0x49, 0x49, 0x49, 0x31};   //53 = 'S'
const uint8_t fonts8_54[] =
{ 0x00, 0x01, 0x01, 0x7F, 0x01, 0x01};   //54 = 'T'
const uint8_t fonts8_55[] =
{ 0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F};   //55 = 'U'
const uint8_t fonts8_56[] =
{ 0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F};   //56 = 'V'
const uint8_t fonts8_57[] =
{ 0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F};   //57 = 'W'
const uint8_t fonts8_58[] =
{ 0x00, 0x63, 0x14, 0x08, 0x14, 0x63};   //58 = 'X'
const uint8_t fonts8_59[] =
{ 0x00, 0x07, 0x08, 0x70, 0x08, 0x07};   //59 = 'Y'
const uint8_t fonts8_5A[] =
{ 0x00, 0x61, 0x51, 0x49, 0x45, 0x43};   //5a = 'Z'
const uint8_t fonts8_5B[] =
{ 0x00, 0xFE, 0x83, 0x81, 0x83, 0xFE};   //5b = BATT1
const uint8_t fonts8_5C[] =
{ 0x00, 0x02, 0x04, 0x08, 0x10, 0x20};   //5c = '\'
const uint8_t fonts8_5D[] =
{ 0x00, 0xFE, 0xF3, 0xF9, 0xFF, 0xFE};   //5d = BATT3
const uint8_t fonts8_5E[] =
{ 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0xFE};   //5e = BATT4
const uint8_t fonts8_5F[] =
{ 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0};   //5f = '_'
const uint8_t fonts8_60[] =
{ 0x00, 0xFE, 0xC3, 0xE1, 0xF3, 0xFE};   //60 = BATT2
const uint8_t fonts8_61[] =
{ 0x00, 0x20, 0x54, 0x54, 0x54, 0x78};   //61 = 'a'
const uint8_t fonts8_62[] =
{ 0x00, 0x7F, 0x48, 0x44, 0x44, 0x38};   //62 = 'b'
const uint8_t fonts8_63[] =
{ 0x00, 0x38, 0x44, 0x44, 0x44, 0x20};   //63 = 'c'
const uint8_t fonts8_64[] =
{ 0x00, 0x38, 0x44, 0x44, 0x48, 0x7F};   //64 = 'd'
const uint8_t fonts8_65[] =
{ 0x00, 0x38, 0x54, 0x54, 0x54, 0x18};   //65 = 'e'
const uint8_t fonts8_66[] =
{ 0x00, 0x08, 0x7E, 0x09, 0x01, 0x02};   //66 = 'f'
const uint8_t fonts8_67[] =
{ 0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C};   //67 = 'g'
const uint8_t fonts8_68[] =
{ 0x00, 0x7F, 0x08, 0x04, 0x04, 0x78};   //68 = 'h'
const uint8_t fonts8_69[] =
{ 0x00, 0x00, 0x44, 0x7D, 0x40};   //69 = 'i'
const uint8_t fonts8_6A[] =
{ 0x00, 0x20, 0x40, 0x44, 0x3D, 0x00};   //6a = 'j'
const uint8_t fonts8_6B[] =
{ 0x00, 0x7F, 0x10, 0x28, 0x44, 0x00};   //6b = 'k'
const uint8_t fonts8_6C[] =
{ 0x00, 0x00, 0x41, 0x7F, 0x40};   //6c = 'l'
const uint8_t fonts8_6D[] =
{ 0x00, 0x7C, 0x04, 0x18, 0x04, 0x78};   //6d = 'm'
const uint8_t fonts8_6E[] =
{ 0x00, 0x7C, 0x08, 0x04, 0x04, 0x78};   //6e = 'n'
const uint8_t fonts8_6F[] =
{ 0x00, 0x38, 0x44, 0x44, 0x44, 0x38};   //6f = 'o'
const uint8_t fonts8_70[] =
{ 0x00, 0x7C, 0x14, 0x14, 0x14, 0x08};   //70 = 'p'
const uint8_t fonts8_71[] =
{ 0x00, 0x08, 0x14, 0x14, 0x18, 0x7C};   //71 = 'q'
const uint8_t fonts8_72[] =
{ 0x00, 0x7C, 0x08, 0x04, 0x04, 0x08};   //72 = 'r'
const uint8_t fonts8_73[] =
{ 0x00, 0x48, 0x54, 0x54, 0x54, 0x20};   //73 = 's'
const uint8_t fonts8_74[] =
{ 0x00, 0x04, 0x3F, 0x44, 0x40, 0x20};   //74 = 't'
const uint8_t fonts8_75[] =
{ 0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C};   //75 = 'u'
const uint8_t fonts8_76[] =
{ 0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C};   //76 = 'v'
const uint8_t fonts8_77[] =
{ 0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C};   //77 = 'w'
const uint8_t fonts8_78[] =
{ 0x00, 0x44, 0x28, 0x10, 0x28, 0x44};   //78 = 'x'
const uint8_t fonts8_79[] =
{ 0x00, 0x0C, 0x50, 0x50, 0x50, 0x3C};   //79 = 'y'
const uint8_t fonts8_7A[] =
{ 0x00, 0x44, 0x64, 0x54, 0x4C, 0x44};   //7a = 'z'
const uint8_t fonts8_7B[] =
{ 0x00, 0x04, 0x02, 0x7F, 0x02, 0x04};   //7b = '{'
const uint8_t fonts8_7C[] =
{ 0x00, 0x00, 0xFF, 0x00};   //7c = '|'
const uint8_t fonts8_7D[] =
{ 0x00, 0x10, 0x20, 0x7F, 0x20, 0x10};   //7d = '}'
const uint8_t fonts8_7E_C1[] =
{ 0x00, 0x7E, 0x11, 0x11, 0x11, 0x7E};
const uint8_t fonts8_C2_C4[] =
{ 0x00, 0x7E, 0x11, 0x11, 0x11, 0x7E};
const uint8_t fonts8_C5[] =
{ 0x00, 0x7E, 0x11, 0x11, 0x11, 0x7E};
const uint8_t fonts8_C6_E1[] =
{ 0x00, 0x20, 0x54, 0x55, 0x54, 0x78};
const uint8_t fonts8_E2_E4[] =
{ 0x00, 0x38, 0x54, 0x54, 0x54, 0x18};
const uint8_t fonts8_E5_E9[] =
{ 0x00, 0x38, 0x54, 0x55, 0x54, 0x18};
const uint8_t fonts8_EA_ED[] =
{ 0x00, 0x00, 0x44, 0x7D, 0x40, 0x00};
const uint8_t fonts8_EE_F1[] =
{ 0x00, 0x7C, 0x09, 0x05, 0x05, 0x78};
const uint8_t fonts8_F2_F3[] =
{ 0x00, 0x38, 0x44, 0x45, 0x44, 0x38};
const uint8_t fonts8_F4_F6[] =
{ 0x00, 0x38, 0x45, 0x44, 0x45, 0x38};
const uint8_t fonts8_F7_FA[] =
{ 0x00, 0x3C, 0x40, 0x41, 0x20, 0x7C};
const uint8_t fonts8_FB_FC[] =
{ 0x00, 0x3C, 0x41, 0x40, 0x21, 0x7C};   //75 = 'u'
const uint8_t fonts8_FD_FF[] =
{ 0x00, 0x00, 0x00, 0x00};   //20 = ' '

const FontCharacter fonts8_20_char = {
    sizeof(fonts8_20),
    fonts8_20};
const FontCharacter fonts8_21_char = {
    sizeof(fonts8_21),
    fonts8_21};
const FontCharacter fonts8_22_char = {
    sizeof(fonts8_22),
    fonts8_22};
const FontCharacter fonts8_23_char = {
    sizeof(fonts8_23),
    fonts8_23};
const FontCharacter fonts8_24_char = {
    sizeof(fonts8_24),
    fonts8_24};
const FontCharacter fonts8_25_char = {
    sizeof(fonts8_25),
    fonts8_25};
const FontCharacter fonts8_26_char = {
    sizeof(fonts8_26),
    fonts8_26};
const FontCharacter fonts8_27_char = {
    sizeof(fonts8_27),
    fonts8_27};
const FontCharacter fonts8_28_char = {
    sizeof(fonts8_28),
    fonts8_28};
const FontCharacter fonts8_29_char = {
    sizeof(fonts8_29),
    fonts8_29};
const FontCharacter fonts8_2A_char = {
    sizeof(fonts8_2A),
    fonts8_2A};
const FontCharacter fonts8_2B_char = {
    sizeof(fonts8_2B),
    fonts8_2B};
const FontCharacter fonts8_2C_char = {
    sizeof(fonts8_2C),
    fonts8_2C};
const FontCharacter fonts8_2D_char = {
    sizeof(fonts8_2D),
    fonts8_2D};
const FontCharacter fonts8_2E_char = {
    sizeof(fonts8_2E),
    fonts8_2E};
const FontCharacter fonts8_2F_char = {
    sizeof(fonts8_2F),
    fonts8_2F};
const FontCharacter fonts8_30_char = {
    sizeof(fonts8_30),
    fonts8_30};
const FontCharacter fonts8_31_char = {
    sizeof(fonts8_31),
    fonts8_31};
const FontCharacter fonts8_32_char = {
    sizeof(fonts8_32),
    fonts8_32};
const FontCharacter fonts8_33_char = {
    sizeof(fonts8_33),
    fonts8_33};
const FontCharacter fonts8_34_char = {
    sizeof(fonts8_34),
    fonts8_34};
const FontCharacter fonts8_35_char = {
    sizeof(fonts8_35),
    fonts8_35};
const FontCharacter fonts8_36_char = {
    sizeof(fonts8_36),
    fonts8_36};
const FontCharacter fonts8_37_char = {
    sizeof(fonts8_37),
    fonts8_37};
const FontCharacter fonts8_38_char = {
    sizeof(fonts8_38),
    fonts8_38};
const FontCharacter fonts8_39_char = {
    sizeof(fonts8_39),
    fonts8_39};
const FontCharacter fonts8_3A_char = {
    sizeof(fonts8_3A),
    fonts8_3A};
const FontCharacter fonts8_3B_char = {
    sizeof(fonts8_3B),
    fonts8_3B};
const FontCharacter fonts8_3C_char = {
    sizeof(fonts8_3C),
    fonts8_3C};
const FontCharacter fonts8_3D_char = {
    sizeof(fonts8_3D),
    fonts8_3D};
const FontCharacter fonts8_3E_char = {
    sizeof(fonts8_3E),
    fonts8_3E};
const FontCharacter fonts8_3F_char = {
    sizeof(fonts8_3F),
    fonts8_3F};
const FontCharacter fonts8_40_char = {
    sizeof(fonts8_40),
    fonts8_40};
const FontCharacter fonts8_41_char = {
    sizeof(fonts8_41),
    fonts8_41};
const FontCharacter fonts8_42_char = {
    sizeof(fonts8_42),
    fonts8_42};
const FontCharacter fonts8_43_char = {
    sizeof(fonts8_43),
    fonts8_43};
const FontCharacter fonts8_44_char = {
    sizeof(fonts8_44),
    fonts8_44};
const FontCharacter fonts8_45_char = {
    sizeof(fonts8_45),
    fonts8_45};
const FontCharacter fonts8_46_char = {
    sizeof(fonts8_46),
    fonts8_46};
const FontCharacter fonts8_47_char = {
    sizeof(fonts8_47),
    fonts8_47};
const FontCharacter fonts8_48_char = {
    sizeof(fonts8_48),
    fonts8_48};
const FontCharacter fonts8_49_char = {
    sizeof(fonts8_49),
    fonts8_49};
const FontCharacter fonts8_4A_char = {
    sizeof(fonts8_4A),
    fonts8_4A};
const FontCharacter fonts8_4B_char = {
    sizeof(fonts8_4B),
    fonts8_4B};
const FontCharacter fonts8_4C_char = {
    sizeof(fonts8_4C),
    fonts8_4C};
const FontCharacter fonts8_4D_char = {
    sizeof(fonts8_4D),
    fonts8_4D};
const FontCharacter fonts8_4E_char = {
    sizeof(fonts8_4E),
    fonts8_4E};
const FontCharacter fonts8_4F_char = {
    sizeof(fonts8_4F),
    fonts8_4F};
const FontCharacter fonts8_50_char = {
    sizeof(fonts8_50),
    fonts8_50};
const FontCharacter fonts8_51_char = {
    sizeof(fonts8_51),
    fonts8_51};
const FontCharacter fonts8_52_char = {
    sizeof(fonts8_52),
    fonts8_52};
const FontCharacter fonts8_53_char = {
    sizeof(fonts8_53),
    fonts8_53};
const FontCharacter fonts8_54_char = {
    sizeof(fonts8_54),
    fonts8_54};
const FontCharacter fonts8_55_char = {
    sizeof(fonts8_55),
    fonts8_55};
const FontCharacter fonts8_56_char = {
    sizeof(fonts8_56),
    fonts8_56};
const FontCharacter fonts8_57_char = {
    sizeof(fonts8_57),
    fonts8_57};
const FontCharacter fonts8_58_char = {
    sizeof(fonts8_58),
    fonts8_58};
const FontCharacter fonts8_59_char = {
    sizeof(fonts8_59),
    fonts8_59};
const FontCharacter fonts8_5A_char = {
    sizeof(fonts8_5A),
    fonts8_5A};
const FontCharacter fonts8_5B_char = {
    sizeof(fonts8_5B),
    fonts8_5B};
const FontCharacter fonts8_5C_char = {
    sizeof(fonts8_5C),
    fonts8_5C};
const FontCharacter fonts8_5D_char = {
    sizeof(fonts8_5D),
    fonts8_5D};
const FontCharacter fonts8_5E_char = {
    sizeof(fonts8_5E),
    fonts8_5E};
const FontCharacter fonts8_5F_char = {
    sizeof(fonts8_5F),
    fonts8_5F};
const FontCharacter fonts8_60_char = {
    sizeof(fonts8_60),
    fonts8_60};
const FontCharacter fonts8_61_char = {
    sizeof(fonts8_61),
    fonts8_61};
const FontCharacter fonts8_62_char = {
    sizeof(fonts8_62),
    fonts8_62};
const FontCharacter fonts8_63_char = {
    sizeof(fonts8_63),
    fonts8_63};
const FontCharacter fonts8_64_char = {
    sizeof(fonts8_64),
    fonts8_64};
const FontCharacter fonts8_65_char = {
    sizeof(fonts8_65),
    fonts8_65};
const FontCharacter fonts8_66_char = {
    sizeof(fonts8_66),
    fonts8_66};
const FontCharacter fonts8_67_char = {
    sizeof(fonts8_67),
    fonts8_67};
const FontCharacter fonts8_68_char = {
    sizeof(fonts8_68),
    fonts8_68};
const FontCharacter fonts8_69_char = {
    sizeof(fonts8_69),
    fonts8_69};
const FontCharacter fonts8_6A_char = {
    sizeof(fonts8_6A),
    fonts8_6A};
const FontCharacter fonts8_6B_char = {
    sizeof(fonts8_6B),
    fonts8_6B};
const FontCharacter fonts8_6C_char = {
    sizeof(fonts8_6C),
    fonts8_6C};
const FontCharacter fonts8_6D_char = {
    sizeof(fonts8_6D),
    fonts8_6D};
const FontCharacter fonts8_6E_char = {
    sizeof(fonts8_6E),
    fonts8_6E};
const FontCharacter fonts8_6F_char = {
    sizeof(fonts8_6F),
    fonts8_6F};
const FontCharacter fonts8_70_char = {
    sizeof(fonts8_70),
    fonts8_70};
const FontCharacter fonts8_71_char = {
    sizeof(fonts8_71),
    fonts8_71};
const FontCharacter fonts8_72_char = {
    sizeof(fonts8_72),
    fonts8_72};
const FontCharacter fonts8_73_char = {
    sizeof(fonts8_73),
    fonts8_73};
const FontCharacter fonts8_74_char = {
    sizeof(fonts8_74),
    fonts8_74};
const FontCharacter fonts8_75_char = {
    sizeof(fonts8_75),
    fonts8_75};
const FontCharacter fonts8_76_char = {
    sizeof(fonts8_76),
    fonts8_76};
const FontCharacter fonts8_77_char = {
    sizeof(fonts8_77),
    fonts8_77};
const FontCharacter fonts8_78_char = {
    sizeof(fonts8_78),
    fonts8_78};
const FontCharacter fonts8_79_char = {
    sizeof(fonts8_79),
    fonts8_79};
const FontCharacter fonts8_7A_char = {
    sizeof(fonts8_7A),
    fonts8_7A};
const FontCharacter fonts8_7B_char = {
    sizeof(fonts8_7B),
    fonts8_7B};
const FontCharacter fonts8_7C_char = {
    sizeof(fonts8_7C),
    fonts8_7C};
const FontCharacter fonts8_7D_char = {
    sizeof(fonts8_7D),
    fonts8_7D};
const FontCharacter fonts8_7E_C1_char = {
    sizeof(fonts8_7E_C1),
    fonts8_7E_C1};
const FontCharacter fonts8_C2_C4_char = {
    sizeof(fonts8_C2_C4),
    fonts8_C2_C4};
const FontCharacter fonts8_C5_char = {
    sizeof(fonts8_C5),
    fonts8_C5};
const FontCharacter fonts8_C6_E1_char = {
    sizeof(fonts8_C6_E1),
    fonts8_C6_E1};
const FontCharacter fonts8_E2_E4_char = {
    sizeof(fonts8_E2_E4),
    fonts8_E2_E4};
const FontCharacter fonts8_E5_E9_char = {
    sizeof(fonts8_E5_E9),
    fonts8_E5_E9};
const FontCharacter fonts8_EA_ED_char = {
    sizeof(fonts8_EA_ED),
    fonts8_EA_ED};
const FontCharacter fonts8_EE_F1_char = {
    sizeof(fonts8_EE_F1),
    fonts8_EE_F1};
const FontCharacter fonts8_F2_F3_char = {
    sizeof(fonts8_F2_F3),
    fonts8_F2_F3};
const FontCharacter fonts8_F4_F6_char = {
    sizeof(fonts8_F4_F6),
    fonts8_F4_F6};
const FontCharacter fonts8_F7_FA_char = {
    sizeof(fonts8_F7_FA),
    fonts8_F7_FA};
const FontCharacter fonts8_FB_FC_char = {
    sizeof(fonts8_FB_FC),
    fonts8_FB_FC};
const FontCharacter fonts8_FD_FF_char = {
    sizeof(fonts8_FD_FF),
    fonts8_FD_FF};

const Font font8 = {
    .charHeight = 8,
    .elemSize = 8,
    .chars = {
        &fonts8_20_char,
        &fonts8_21_char,
        &fonts8_22_char,
        &fonts8_23_char,
        &fonts8_24_char,
        &fonts8_25_char,
        &fonts8_26_char,
        &fonts8_27_char,
        &fonts8_28_char,
        &fonts8_29_char,
        &fonts8_2A_char,
        &fonts8_2B_char,
        &fonts8_2C_char,
        &fonts8_2D_char,
        &fonts8_2E_char,
        &fonts8_2F_char,
        &fonts8_30_char,
        &fonts8_31_char,
        &fonts8_32_char,
        &fonts8_33_char,
        &fonts8_34_char,
        &fonts8_35_char,
        &fonts8_36_char,
        &fonts8_37_char,
        &fonts8_38_char,
        &fonts8_39_char,
        &fonts8_3A_char,
        &fonts8_3B_char,
        &fonts8_3C_char,
        &fonts8_3D_char,
        &fonts8_3E_char,
        &fonts8_3F_char,
        &fonts8_40_char,
        &fonts8_41_char,
        &fonts8_42_char,
        &fonts8_43_char,
        &fonts8_44_char,
        &fonts8_45_char,
        &fonts8_46_char,
        &fonts8_47_char,
        &fonts8_48_char,
        &fonts8_49_char,
        &fonts8_4A_char,
        &fonts8_4B_char,
        &fonts8_4C_char,
        &fonts8_4D_char,
        &fonts8_4E_char,
        &fonts8_4F_char,
        &fonts8_50_char,
        &fonts8_51_char,
        &fonts8_52_char,
        &fonts8_53_char,
        &fonts8_54_char,
        &fonts8_55_char,
        &fonts8_56_char,
        &fonts8_57_char,
        &fonts8_58_char,
        &fonts8_59_char,
        &fonts8_5A_char,
        &fonts8_5B_char,
        &fonts8_5C_char,
        &fonts8_5D_char,
        &fonts8_5E_char,
        &fonts8_5F_char,
        &fonts8_60_char,
        &fonts8_61_char,
        &fonts8_62_char,
        &fonts8_63_char,
        &fonts8_64_char,
        &fonts8_65_char,
        &fonts8_66_char,
        &fonts8_67_char,
        &fonts8_68_char,
        &fonts8_69_char,
        &fonts8_6A_char,
        &fonts8_6B_char,
        &fonts8_6C_char,
        &fonts8_6D_char,
        &fonts8_6E_char,
        &fonts8_6F_char,
        &fonts8_70_char,
        &fonts8_71_char,
        &fonts8_72_char,
        &fonts8_73_char,
        &fonts8_74_char,
        &fonts8_75_char,
        &fonts8_76_char,
        &fonts8_77_char,
        &fonts8_78_char,
        &fonts8_79_char,
        &fonts8_7A_char,
        &fonts8_7B_char,
        &fonts8_7C_char,
        &fonts8_7D_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_7E_C1_char,
        &fonts8_C2_C4_char,
        &fonts8_C2_C4_char,
        &fonts8_C2_C4_char,
        &fonts8_C5_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_C6_E1_char,
        &fonts8_E2_E4_char,
        &fonts8_E2_E4_char,
        &fonts8_E2_E4_char,
        &fonts8_E5_E9_char,
        &fonts8_E5_E9_char,
        &fonts8_E5_E9_char,
        &fonts8_E5_E9_char,
        &fonts8_E5_E9_char,
        &fonts8_EA_ED_char,
        &fonts8_EA_ED_char,
        &fonts8_EA_ED_char,
        &fonts8_EA_ED_char,
        &fonts8_EE_F1_char,
        &fonts8_EE_F1_char,
        &fonts8_EE_F1_char,
        &fonts8_EE_F1_char,
        &fonts8_F2_F3_char,
        &fonts8_F2_F3_char,
        &fonts8_F4_F6_char,
        &fonts8_F4_F6_char,
        &fonts8_F4_F6_char,
        &fonts8_F7_FA_char,
        &fonts8_F7_FA_char,
        &fonts8_F7_FA_char,
        &fonts8_F7_FA_char,
        &fonts8_FB_FC_char,
        &fonts8_FB_FC_char,
        &fonts8_FD_FF_char,
        &fonts8_FD_FF_char,
        &fonts8_FD_FF_char
    }
};
