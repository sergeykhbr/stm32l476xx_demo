#include <inttypes.h>
#include <font.h>

const uint16_t fonts16_20[] =
{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};   //20=' '
const uint16_t fonts16_21[] =
{ 0x0000, 0x0000, 0x0000, 0x33FE, 0x33FE, 0x0000, 0x0000, 0x0000};   //21='!'
const uint16_t fonts16_22[] =
{ 0x0000, 0x0000, 0x0007, 0x0000, 0x0000, 0x0007, 0x0000, 0x0000};   //22='"'
const uint16_t fonts16_23[] =
{ 0x0000, 0x0410, 0x3FFE, 0x0410, 0x0410, 0x3FFE, 0x0410, 0x0000};   //23='#'
const uint16_t fonts16_24[] =
{ 0x0000, 0x0470, 0x0888, 0x0888, 0x3FFE, 0x0888, 0x0888, 0x0710};   //24='$'
const uint16_t fonts16_25[] =
{ 0x0000, 0x301C, 0x0C22, 0x0322, 0x1C9C, 0x2260, 0x2218, 0x1C06};   //25='%'
const uint16_t fonts16_26[] =
{ 0x0000, 0x1E00, 0x217C, 0x2082, 0x2142, 0x163C, 0x0800, 0x1600};   //26='&'
const uint16_t fonts16_27[] =
{ 0x0000, 0x0000, 0x0000, 0x0004, 0x0002, 0x0001, 0x0000, 0x0000};   //27='''
const uint16_t fonts16_28[] =
{ 0x0000, 0x0000, 0x0000, 0x07F0, 0x180C, 0x2002, 0x4001, 0x0000};   //28='('
const uint16_t fonts16_29[] =
{ 0x0000, 0x0000, 0x4001, 0x2002, 0x180C, 0x07F0, 0x0000, 0x0000};   //29=')'
const uint16_t fonts16_2A[] =
{ 0x0000, 0x0110, 0x00A0, 0x0040, 0x07FC, 0x0040, 0x00A0, 0x0110};   //2a='*'
const uint16_t fonts16_2B[] =
{ 0x0000, 0x0040, 0x0040, 0x0040, 0x07FC, 0x0040, 0x0040, 0x0040};   //2b='+'
const uint16_t fonts16_2C[] =
{ 0x0000, 0x0000, 0x4C00, 0x3C00, 0x0000, 0x0000, 0x0000, 0x0000};   //2c=','
const uint16_t fonts16_2D[] =
{ 0x0000, 0x0040, 0x0040, 0x0040, 0x0040, 0x0040, 0x0040, 0x0040};   //2d='-'
const uint16_t fonts16_2E[] =
{ 0x0000, 0x0000, 0x0000, 0x3000, 0x3000, 0x0000, 0x0000, 0x0000};   //2e='.'
const uint16_t fonts16_2F[] =
{ 0x0000, 0x6000, 0x1800, 0x0600, 0x0180, 0x0060, 0x0018, 0x0006};   //2f='/'
const uint16_t fonts16_30[] =
{ 0x0000, 0x07F0, 0x180C, 0x2002, 0x2002, 0x2002, 0x180C, 0x07F0};   //30='0'
const uint16_t fonts16_31[] =
{ 0x0000, 0x0000, 0x2008, 0x200C, 0x3FFE, 0x2000, 0x2000, 0x0000};   //31='1'
const uint16_t fonts16_32[] =
{ 0x0000, 0x3008, 0x2C04, 0x2202, 0x2102, 0x2082, 0x2044, 0x2038};   //32='2'
const uint16_t fonts16_33[] =
{ 0x0000, 0x2008, 0x2004, 0x2082, 0x2082, 0x2082, 0x1144, 0x0E38};   //33='3'
const uint16_t fonts16_34[] =
{ 0x0000, 0x0400, 0x0700, 0x04C0, 0x0430, 0x240C, 0x3FFE, 0x2400};   //34='4'
const uint16_t fonts16_35[] =
{ 0x0000, 0x20FE, 0x2042, 0x2022, 0x1022, 0x1022, 0x0842, 0x0782};   //35='5'
const uint16_t fonts16_36[] =
{ 0x0000, 0x0FE0, 0x1098, 0x2044, 0x2042, 0x2042, 0x1082, 0x0F00};   //36='6'
const uint16_t fonts16_37[] =
{ 0x0000, 0x001E, 0x0002, 0x0002, 0x3C02, 0x03C2, 0x003A, 0x0006};   //37='7'
const uint16_t fonts16_38[] =
{ 0x0000, 0x0E38, 0x1144, 0x2082, 0x2082, 0x2082, 0x1144, 0x0E38};   //38='8'
const uint16_t fonts16_39[] =
{ 0x0000, 0x0078, 0x0084, 0x2102, 0x2102, 0x1102, 0x0C84, 0x03F8};   //39='9'
const uint16_t fonts16_3A[] =
{ 0x0000, 0x0000, 0x0000, 0x1860, 0x1860, 0x0000, 0x0000, 0x0000};   //3a=':'
const uint16_t fonts16_3B[] =
{ 0x0000, 0x0000, 0x0000, 0x4C60, 0x3C60, 0x0000, 0x0000, 0x0000};   //3b=';'
const uint16_t fonts16_3C[] =
{ 0x0000, 0x0080, 0x0140, 0x0220, 0x0410, 0x0808, 0x1004, 0x2002};   //3c='<'
const uint16_t fonts16_3D[] =
{ 0x0000, 0x0120, 0x0120, 0x0120, 0x0120, 0x0120, 0x0120, 0x0120};   //3d='='
const uint16_t fonts16_3E[] =
{ 0x0000, 0x4004, 0x2008, 0x1010, 0x0820, 0x0440, 0x0280, 0x0100};   //3e='>'
const uint16_t fonts16_3F[] =
{ 0x0000, 0x0008, 0x0004, 0x0002, 0x3302, 0x0082, 0x0044, 0x0038};   //3f='?'
const uint16_t fonts16_40[] =
{ 0x0000, 0x4000, 0x3FE0, 0x0400, 0x0400, 0x0400, 0x03E0, 0x0400};   //40='@'
const uint16_t fonts16_41[] =
{ 0x0000, 0x3800, 0x0780, 0x0270, 0x020E, 0x0270, 0x0780, 0x3800};   //41='A'
const uint16_t fonts16_42[] =
{ 0x0000, 0x3FFE, 0x2082, 0x2082, 0x2082, 0x2082, 0x1144, 0x0E38};   //42='B'
const uint16_t fonts16_43[] =
{ 0x0000, 0x0FF8, 0x1004, 0x2002, 0x2002, 0x2002, 0x1004, 0x0808};   //43='C'
const uint16_t fonts16_44[] =
{ 0x0000, 0x3FFE, 0x2002, 0x2002, 0x2002, 0x1004, 0x0808, 0x07F0};   //44='D'
const uint16_t fonts16_45[] =
{ 0x0000, 0x3FFE, 0x2082, 0x2082, 0x2082, 0x2082, 0x2082, 0x2002};   //45='E'
const uint16_t fonts16_46[] =
{ 0x0000, 0x3FFE, 0x0082, 0x0082, 0x0082, 0x0082, 0x0082, 0x0002};   //46='F'
const uint16_t fonts16_47[] =
{ 0x0000, 0x0FF8, 0x1004, 0x2002, 0x2082, 0x2082, 0x1084, 0x3F88};   //47='G'
const uint16_t fonts16_48[] =
{ 0x0000, 0x3FFE, 0x0080, 0x0080, 0x0080, 0x0080, 0x0080, 0x3FFE};   //48='H'
const uint16_t fonts16_49[] =
{ 0x0000, 0x0000, 0x0000, 0x2002, 0x3FFE, 0x2002, 0x0000, 0x0000};   //49='I'
const uint16_t fonts16_4A[] =
{ 0x0000, 0x0800, 0x1000, 0x2000, 0x2000, 0x2000, 0x1000, 0x0FFE};   //4a='J'
const uint16_t fonts16_4B[] =
{ 0x0000, 0x3FFE, 0x0180, 0x0240, 0x0420, 0x0810, 0x1008, 0x2004};   //4b='K'
const uint16_t fonts16_4C[] =
{ 0x0000, 0x3FFE, 0x2000, 0x2000, 0x2000, 0x2000, 0x2000, 0x2000};   //4c='L'
const uint16_t fonts16_4D[] =
{ 0x0000, 0x3FFE, 0x0018, 0x0060, 0x0180, 0x0060, 0x0018, 0x3FFE};   //4d='M'
const uint16_t fonts16_4E[] =
{ 0x0000, 0x3FFE, 0x000C, 0x0030, 0x00C0, 0x0300, 0x0C00, 0x3FFE};   //4e='N'
const uint16_t fonts16_4F[] =
{ 0x0000, 0x0FF8, 0x1004, 0x2002, 0x2002, 0x2002, 0x1004, 0x0FF8};   //4f='O'
const uint16_t fonts16_50[] =
{ 0x0000, 0x3FFE, 0x0102, 0x0102, 0x0102, 0x0102, 0x0084, 0x0078};   //50='P'
const uint16_t fonts16_51[] =
{ 0x0000, 0x0FF8, 0x1004, 0x2802, 0x2402, 0x2802, 0x1004, 0x2FF8};   //51='Q'
const uint16_t fonts16_52[] =
{ 0x0000, 0x3FFE, 0x0102, 0x0102, 0x0102, 0x0302, 0x0C84, 0x3078};   //52='R'
const uint16_t fonts16_53[] =
{ 0x0000, 0x0838, 0x1044, 0x2082, 0x2082, 0x2082, 0x1104, 0x0E08};   //53='S'
const uint16_t fonts16_54[] =
{ 0x0000, 0x0002, 0x0002, 0x0002, 0x3FFE, 0x0002, 0x0002, 0x0002};   //54='T'
const uint16_t fonts16_55[] =
{ 0x0000, 0x0FFE, 0x1000, 0x2000, 0x2000, 0x2000, 0x1000, 0x0FFE};   //55='U'
const uint16_t fonts16_56[] =
{ 0x0000, 0x001E, 0x01E0, 0x0E00, 0x3000, 0x0E00, 0x01E0, 0x001E};   //56='V'
const uint16_t fonts16_57[] =
{ 0x0000, 0x0FFE, 0x3000, 0x0E00, 0x01C0, 0x0E00, 0x3000, 0x0FFE};   //57='W'
const uint16_t fonts16_58[] =
{ 0x0000, 0x3002, 0x0C0C, 0x0330, 0x00C0, 0x0330, 0x0C0C, 0x3002};   //58='X'
const uint16_t fonts16_59[] =
{ 0x0000, 0x000E, 0x0030, 0x00C0, 0x3F00, 0x00C0, 0x0030, 0x000E};   //59='Y'
const uint16_t fonts16_5A[] =
{ 0x0000, 0x3002, 0x2C02, 0x2302, 0x20C2, 0x2032, 0x200A, 0x2006};   //5a='Z'
const uint16_t fonts16_5B[] =
{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};   //5b=BATT1
const uint16_t fonts16_5C[] =
{ 0x0000, 0x0006, 0x0018, 0x0060, 0x0180, 0x0600, 0x1800, 0x6000};   //5c='\'
const uint16_t fonts16_5D[] =
{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};   //5d=BATT3
const uint16_t fonts16_5E[] =
{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};   //5e=BATT4
const uint16_t fonts16_5F[] =
{ 0x0000, 0x4000, 0x4000, 0x4000, 0x4000, 0x4000, 0x4000, 0x4000};   //5f='_'
const uint16_t fonts16_60[] =
{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};   //60=BATT2
const uint16_t fonts16_61[] =
{ 0x0000, 0x1880, 0x2440, 0x2240, 0x2240, 0x1240, 0x3F80, 0x0000};   //61='a'
const uint16_t fonts16_62[] =
{ 0x0000, 0x3FFC, 0x1080, 0x2040, 0x2040, 0x2040, 0x1F80, 0x0000};   //62='b'
const uint16_t fonts16_63[] =
{ 0x0000, 0x1F80, 0x2040, 0x2040, 0x2040, 0x2040, 0x1080, 0x0000};   //63='c'
const uint16_t fonts16_64[] =
{ 0x0000, 0x1F80, 0x2040, 0x2040, 0x2040, 0x1080, 0x3FFC, 0x0000};   //64='d'
const uint16_t fonts16_65[] =
{ 0x0000, 0x1F80, 0x2240, 0x2240, 0x2240, 0x2240, 0x1380, 0x0000};   //65='e'
const uint16_t fonts16_66[] =
{ 0x0000, 0x0040, 0x0040, 0x3FF8, 0x0044, 0x0044, 0x0044, 0x0000};   //66='f'
const uint16_t fonts16_67[] =
{ 0x0000, 0x2780, 0x4840, 0x4840, 0x4840, 0x4480, 0x3FC0, 0x0000};   //67='g'
const uint16_t fonts16_68[] =
{ 0x0000, 0x3FFC, 0x0080, 0x0040, 0x0040, 0x0040, 0x3F80, 0x0000};   //68='h'
const uint16_t fonts16_69[] =
{ 0x0000, 0x0000, 0x0000, 0x2040, 0x3FCC, 0x2000, 0x0000, 0x0000};   //69='i'
const uint16_t fonts16_6A[] =
{ 0x0000, 0x2000, 0x4000, 0x4000, 0x4040, 0x3FCC, 0x0000, 0x0000};   //6a='j'
const uint16_t fonts16_6B[] =
{ 0x0000, 0x3FFC, 0x0200, 0x0500, 0x0880, 0x1040, 0x2000, 0x0000};   //6b='k'
const uint16_t fonts16_6C[] =
{ 0x0000, 0x0000, 0x0000, 0x0004, 0x3FFC, 0x2000, 0x0000, 0x0000};   //6c='l'
const uint16_t fonts16_6D[] =
{ 0x0000, 0x3FC0, 0x0040, 0x0040, 0x3F80, 0x0040, 0x0040, 0x3F80};   //6d='m'
const uint16_t fonts16_6E[] =
{ 0x0000, 0x3FC0, 0x0080, 0x0040, 0x0040, 0x0040, 0x3F80, 0x0000};   //6e='n'
const uint16_t fonts16_6F[] =
{ 0x0000, 0x1F80, 0x2040, 0x2040, 0x2040, 0x2040, 0x1F80, 0x0000};   //6f='o'
const uint16_t fonts16_70[] =
{ 0x0000, 0x7FC0, 0x0840, 0x0840, 0x0840, 0x0840, 0x0780, 0x0000};   //70='p'
const uint16_t fonts16_71[] =
{ 0x0000, 0x0780, 0x0840, 0x0840, 0x0840, 0x0840, 0x7FC0, 0x0000};   //71='q'
const uint16_t fonts16_72[] =
{ 0x0000, 0x0000, 0x3FC0, 0x0100, 0x0080, 0x0080, 0x0040, 0x0040};   //72='r'
const uint16_t fonts16_73[] =
{ 0x0000, 0x1180, 0x2240, 0x2240, 0x2440, 0x2440, 0x1880, 0x0000};   //73='s'
const uint16_t fonts16_74[] =
{ 0x0000, 0x0040, 0x0040, 0x1FF8, 0x2040, 0x2040, 0x2040, 0x0000};   //74='t'
const uint16_t fonts16_75[] =
{ 0x0000, 0x1FC0, 0x2000, 0x2000, 0x2000, 0x1000, 0x3FC0, 0x0000};   //75='u'
const uint16_t fonts16_76[] =
{ 0x0000, 0x00C0, 0x0300, 0x0C00, 0x3000, 0x0C00, 0x0300, 0x00C0};   //76='v'
const uint16_t fonts16_77[] =
{ 0x0000, 0x0FC0, 0x3000, 0x0C00, 0x0300, 0x0C00, 0x3000, 0x0FC0};   //77='w'
const uint16_t fonts16_78[] =
{ 0x0000, 0x2040, 0x1080, 0x0900, 0x0600, 0x0900, 0x1080, 0x2040};   //78='x'
const uint16_t fonts16_79[] =
{ 0x0000, 0x0040, 0x4180, 0x2600, 0x1800, 0x0600, 0x0180, 0x0040};   //79='y'
const uint16_t fonts16_7A[] =
{ 0x0000, 0x3040, 0x2840, 0x2440, 0x2240, 0x2140, 0x20C0, 0x0000};   //7a='z'
const uint16_t fonts16_7B[] =
{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};   //7b='{'
const uint16_t fonts16_7C[] =
{ 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000};   //7c='|'
const uint16_t fonts16_7D[] =
{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};   //7d='}'
const uint16_t fonts16_7E_92[] =
{ 0x0000, 0x0000, 0x0000, 0x0004, 0x0002, 0x0001, 0x0000, 0x0000};
const uint16_t fonts16_93_B0[] =
{ 0x0000, 0x0006, 0x0009, 0x0009, 0x0006, 0x0000, 0x0000, 0x0000};
const uint16_t fonts16_B1_BF[] =
{ 0x0000, 0x1C00, 0x2200, 0x4100, 0x40CC, 0x4000, 0x2000, 0x1000};
const uint16_t fonts16_C0_C1[] =
{ 0x0000, 0x3800, 0x0780, 0x0274, 0x020E, 0x0271, 0x0780, 0x3800};   //41='A'
const uint16_t fonts16_C2_C4[] =
{ 0x0000, 0x3800, 0x0782, 0x0270, 0x020E, 0x0270, 0x0782, 0x3800};
const uint16_t fonts16_C5[] =
{ 0x0000, 0x3800, 0x0780, 0x0273, 0x020F, 0x0273, 0x0780, 0x3800};
const uint16_t fonts16_C6_E0[] =
{ 0x0000, 0x1880, 0x2440, 0x2244, 0x2248, 0x1240, 0x3F80, 0x0000};   //61='a'
const uint16_t fonts16_E1[] =
{ 0x0000, 0x1880, 0x2440, 0x2248, 0x2244, 0x1242, 0x3F80, 0x0000};
const uint16_t fonts16_E2_E4[] =
{ 0x0000, 0x1880, 0x244C, 0x2240, 0x2240, 0x124C, 0x3F80, 0x0000};   //61='a'
const uint16_t fonts16_E5_E9[] =
{ 0x0000, 0x1F80, 0x2240, 0x2248, 0x2244, 0x2242, 0x1380, 0x0000};
const uint16_t fonts16_EA_ED[] =
{ 0x0000, 0x0000, 0x0000, 0x2048, 0x3FC4, 0x2002, 0x0000, 0x0000};
const uint16_t fonts16_EE_F1[] =
{ 0x0000, 0x3FC0, 0x0084, 0x0042, 0x0044, 0x0042, 0x3F80, 0x0000};
const uint16_t fonts16_F2_F3[] =
{ 0x0000, 0x1F80, 0x2040, 0x2048, 0x2044, 0x2042, 0x1F80, 0x0000};
const uint16_t fonts16_F4_F6[] =
{ 0x0000, 0x1F80, 0x204C, 0x2040, 0x2040, 0x204C, 0x1F80, 0x0000};
const uint16_t fonts16_F7_F9[] =
{ 0x0000, 0x1FC0, 0x2000, 0x2004, 0x2002, 0x1000, 0x3FC0, 0x0000};   //75='u'
const uint16_t fonts16_FA[] =
{ 0x0000, 0x1FC0, 0x2000, 0x2008, 0x2004, 0x1002, 0x3FC0, 0x0000};
const uint16_t fonts16_FB_FC[] =
{ 0x0000, 0x1FC0, 0x200C, 0x2000, 0x2000, 0x100C, 0x3FC0, 0x0000};
const uint16_t fonts16_FD_FF[] =
{ 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};   //20=' '

const FontCharacter fonts16_20_char = {
    sizeof(fonts16_20)/2,
    fonts16_20};
const FontCharacter fonts16_21_char = {
    sizeof(fonts16_21)/2,
    fonts16_21};
const FontCharacter fonts16_22_char = {
    sizeof(fonts16_22)/2,
    fonts16_22};
const FontCharacter fonts16_23_char = {
    sizeof(fonts16_23)/2,
    fonts16_23};
const FontCharacter fonts16_24_char = {
    sizeof(fonts16_24)/2,
    fonts16_24};
const FontCharacter fonts16_25_char = {
    sizeof(fonts16_25)/2,
    fonts16_25};
const FontCharacter fonts16_26_char = {
    sizeof(fonts16_26)/2,
    fonts16_26};
const FontCharacter fonts16_27_char = {
    sizeof(fonts16_27)/2,
    fonts16_27};
const FontCharacter fonts16_28_char = {
    sizeof(fonts16_28)/2,
    fonts16_28};
const FontCharacter fonts16_29_char = {
    sizeof(fonts16_29)/2,
    fonts16_29};
const FontCharacter fonts16_2A_char = {
    sizeof(fonts16_2A)/2,
    fonts16_2A};
const FontCharacter fonts16_2B_char = {
    sizeof(fonts16_2B)/2,
    fonts16_2B};
const FontCharacter fonts16_2C_char = {
    sizeof(fonts16_2C)/2,
    fonts16_2C};
const FontCharacter fonts16_2D_char = {
    sizeof(fonts16_2D)/2,
    fonts16_2D};
const FontCharacter fonts16_2E_char = {
    sizeof(fonts16_2E)/2,
    fonts16_2E};
const FontCharacter fonts16_2F_char = {
    sizeof(fonts16_2F)/2,
    fonts16_2F};
const FontCharacter fonts16_30_char = {
    sizeof(fonts16_30)/2,
    fonts16_30};
const FontCharacter fonts16_31_char = {
    sizeof(fonts16_31)/2,
    fonts16_31};
const FontCharacter fonts16_32_char = {
    sizeof(fonts16_32)/2,
    fonts16_32};
const FontCharacter fonts16_33_char = {
    sizeof(fonts16_33)/2,
    fonts16_33};
const FontCharacter fonts16_34_char = {
    sizeof(fonts16_34)/2,
    fonts16_34};
const FontCharacter fonts16_35_char = {
    sizeof(fonts16_35)/2,
    fonts16_35};
const FontCharacter fonts16_36_char = {
    sizeof(fonts16_36)/2,
    fonts16_36};
const FontCharacter fonts16_37_char = {
    sizeof(fonts16_37)/2,
    fonts16_37};
const FontCharacter fonts16_38_char = {
    sizeof(fonts16_38)/2,
    fonts16_38};
const FontCharacter fonts16_39_char = {
    sizeof(fonts16_39)/2,
    fonts16_39};
const FontCharacter fonts16_3A_char = {
    sizeof(fonts16_3A)/2,
    fonts16_3A};
const FontCharacter fonts16_3B_char = {
    sizeof(fonts16_3B)/2,
    fonts16_3B};
const FontCharacter fonts16_3C_char = {
    sizeof(fonts16_3C)/2,
    fonts16_3C};
const FontCharacter fonts16_3D_char = {
    sizeof(fonts16_3D)/2,
    fonts16_3D};
const FontCharacter fonts16_3E_char = {
    sizeof(fonts16_3E)/2,
    fonts16_3E};
const FontCharacter fonts16_3F_char = {
    sizeof(fonts16_3F)/2,
    fonts16_3F};
const FontCharacter fonts16_40_char = {
    sizeof(fonts16_40)/2,
    fonts16_40};
const FontCharacter fonts16_41_char = {
    sizeof(fonts16_41)/2,
    fonts16_41};
const FontCharacter fonts16_42_char = {
    sizeof(fonts16_42)/2,
    fonts16_42};
const FontCharacter fonts16_43_char = {
    sizeof(fonts16_43)/2,
    fonts16_43};
const FontCharacter fonts16_44_char = {
    sizeof(fonts16_44)/2,
    fonts16_44};
const FontCharacter fonts16_45_char = {
    sizeof(fonts16_45)/2,
    fonts16_45};
const FontCharacter fonts16_46_char = {
    sizeof(fonts16_46)/2,
    fonts16_46};
const FontCharacter fonts16_47_char = {
    sizeof(fonts16_47)/2,
    fonts16_47};
const FontCharacter fonts16_48_char = {
    sizeof(fonts16_48)/2,
    fonts16_48};
const FontCharacter fonts16_49_char = {
    sizeof(fonts16_49)/2,
    fonts16_49};
const FontCharacter fonts16_4A_char = {
    sizeof(fonts16_4A)/2,
    fonts16_4A};
const FontCharacter fonts16_4B_char = {
    sizeof(fonts16_4B)/2,
    fonts16_4B};
const FontCharacter fonts16_4C_char = {
    sizeof(fonts16_4C)/2,
    fonts16_4C};
const FontCharacter fonts16_4D_char = {
    sizeof(fonts16_4D)/2,
    fonts16_4D};
const FontCharacter fonts16_4E_char = {
    sizeof(fonts16_4E)/2,
    fonts16_4E};
const FontCharacter fonts16_4F_char = {
    sizeof(fonts16_4F)/2,
    fonts16_4F};
const FontCharacter fonts16_50_char = {
    sizeof(fonts16_50)/2,
    fonts16_50};
const FontCharacter fonts16_51_char = {
    sizeof(fonts16_51)/2,
    fonts16_51};
const FontCharacter fonts16_52_char = {
    sizeof(fonts16_52)/2,
    fonts16_52};
const FontCharacter fonts16_53_char = {
    sizeof(fonts16_53)/2,
    fonts16_53};
const FontCharacter fonts16_54_char = {
    sizeof(fonts16_54)/2,
    fonts16_54};
const FontCharacter fonts16_55_char = {
    sizeof(fonts16_55)/2,
    fonts16_55};
const FontCharacter fonts16_56_char = {
    sizeof(fonts16_56)/2,
    fonts16_56};
const FontCharacter fonts16_57_char = {
    sizeof(fonts16_57)/2,
    fonts16_57};
const FontCharacter fonts16_58_char = {
    sizeof(fonts16_58)/2,
    fonts16_58};
const FontCharacter fonts16_59_char = {
    sizeof(fonts16_59)/2,
    fonts16_59};
const FontCharacter fonts16_5A_char = {
    sizeof(fonts16_5A)/2,
    fonts16_5A};
const FontCharacter fonts16_5B_char = {
    sizeof(fonts16_5B)/2,
    fonts16_5B};
const FontCharacter fonts16_5C_char = {
    sizeof(fonts16_5C)/2,
    fonts16_5C};
const FontCharacter fonts16_5D_char = {
    sizeof(fonts16_5D)/2,
    fonts16_5D};
const FontCharacter fonts16_5E_char = {
    sizeof(fonts16_5E)/2,
    fonts16_5E};
const FontCharacter fonts16_5F_char = {
    sizeof(fonts16_5F)/2,
    fonts16_5F};
const FontCharacter fonts16_60_char = {
    sizeof(fonts16_60)/2,
    fonts16_60};
const FontCharacter fonts16_61_char = {
    sizeof(fonts16_61)/2,
    fonts16_61};
const FontCharacter fonts16_62_char = {
    sizeof(fonts16_62)/2,
    fonts16_62};
const FontCharacter fonts16_63_char = {
    sizeof(fonts16_63)/2,
    fonts16_63};
const FontCharacter fonts16_64_char = {
    sizeof(fonts16_64)/2,
    fonts16_64};
const FontCharacter fonts16_65_char = {
    sizeof(fonts16_65)/2,
    fonts16_65};
const FontCharacter fonts16_66_char = {
    sizeof(fonts16_66)/2,
    fonts16_66};
const FontCharacter fonts16_67_char = {
    sizeof(fonts16_67)/2,
    fonts16_67};
const FontCharacter fonts16_68_char = {
    sizeof(fonts16_68)/2,
    fonts16_68};
const FontCharacter fonts16_69_char = {
    sizeof(fonts16_69)/2,
    fonts16_69};
const FontCharacter fonts16_6A_char = {
    sizeof(fonts16_6A)/2,
    fonts16_6A};
const FontCharacter fonts16_6B_char = {
    sizeof(fonts16_6B)/2,
    fonts16_6B};
const FontCharacter fonts16_6C_char = {
    sizeof(fonts16_6C)/2,
    fonts16_6C};
const FontCharacter fonts16_6D_char = {
    sizeof(fonts16_6D)/2,
    fonts16_6D};
const FontCharacter fonts16_6E_char = {
    sizeof(fonts16_6E)/2,
    fonts16_6E};
const FontCharacter fonts16_6F_char = {
    sizeof(fonts16_6F)/2,
    fonts16_6F};
const FontCharacter fonts16_70_char = {
    sizeof(fonts16_70)/2,
    fonts16_70};
const FontCharacter fonts16_71_char = {
    sizeof(fonts16_71)/2,
    fonts16_71};
const FontCharacter fonts16_72_char = {
    sizeof(fonts16_72)/2,
    fonts16_72};
const FontCharacter fonts16_73_char = {
    sizeof(fonts16_73)/2,
    fonts16_73};
const FontCharacter fonts16_74_char = {
    sizeof(fonts16_74)/2,
    fonts16_74};
const FontCharacter fonts16_75_char = {
    sizeof(fonts16_75)/2,
    fonts16_75};
const FontCharacter fonts16_76_char = {
    sizeof(fonts16_76)/2,
    fonts16_76};
const FontCharacter fonts16_77_char = {
    sizeof(fonts16_77)/2,
    fonts16_77};
const FontCharacter fonts16_78_char = {
    sizeof(fonts16_78)/2,
    fonts16_78};
const FontCharacter fonts16_79_char = {
    sizeof(fonts16_79)/2,
    fonts16_79};
const FontCharacter fonts16_7A_char = {
    sizeof(fonts16_7A)/2,
    fonts16_7A};
const FontCharacter fonts16_7B_char = {
    sizeof(fonts16_7B)/2,
    fonts16_7B};
const FontCharacter fonts16_7C_char = {
    sizeof(fonts16_7C)/2,
    fonts16_7C};
const FontCharacter fonts16_7D_char = {
    sizeof(fonts16_7D)/2,
    fonts16_7D};
const FontCharacter fonts16_7E_92_char = {
    sizeof(fonts16_7E_92)/2,
    fonts16_7E_92};
const FontCharacter fonts16_93_B0_char = {
    sizeof(fonts16_93_B0)/2,
    fonts16_93_B0};
const FontCharacter fonts16_B1_BF_char = {
    sizeof(fonts16_B1_BF)/2,
    fonts16_B1_BF};
const FontCharacter fonts16_C0_C1_char = {
    sizeof(fonts16_C0_C1)/2,
    fonts16_C0_C1};
const FontCharacter fonts16_C2_C4_char = {
    sizeof(fonts16_C2_C4)/2,
    fonts16_C2_C4};
const FontCharacter fonts16_C5_char = {
    sizeof(fonts16_C5)/2,
    fonts16_C5};
const FontCharacter fonts16_C6_E0_char = {
    sizeof(fonts16_C6_E0)/2,
    fonts16_C6_E0};
const FontCharacter fonts16_E1_char = {
    sizeof(fonts16_E1)/2,
    fonts16_E1};
const FontCharacter fonts16_E2_E4_char = {
    sizeof(fonts16_E2_E4)/2,
    fonts16_E2_E4};
const FontCharacter fonts16_E5_E9_char = {
    sizeof(fonts16_E5_E9)/2,
    fonts16_E5_E9};
const FontCharacter fonts16_EA_ED_char = {
    sizeof(fonts16_EA_ED)/2,
    fonts16_EA_ED};
const FontCharacter fonts16_EE_F1_char = {
    sizeof(fonts16_EE_F1)/2,
    fonts16_EE_F1};
const FontCharacter fonts16_F2_F3_char = {
    sizeof(fonts16_F2_F3)/2,
    fonts16_F2_F3};
const FontCharacter fonts16_F4_F6_char = {
    sizeof(fonts16_F4_F6)/2,
    fonts16_F4_F6};
const FontCharacter fonts16_F7_F9_char = {
    sizeof(fonts16_F7_F9)/2,
    fonts16_F7_F9};
const FontCharacter fonts16_FA_char = {
    sizeof(fonts16_FA)/2,
    fonts16_FA};
const FontCharacter fonts16_FB_FC_char = {
    sizeof(fonts16_FB_FC)/2,
    fonts16_FB_FC};
const FontCharacter fonts16_FD_FF_char = {
    sizeof(fonts16_FD_FF)/2,
    fonts16_FD_FF};

const Font font16 = {
    .charHeight = 16,
    .elemSize = 16,
    .chars = {
        &fonts16_20_char,
        &fonts16_21_char,
        &fonts16_22_char,
        &fonts16_23_char,
        &fonts16_24_char,
        &fonts16_25_char,
        &fonts16_26_char,
        &fonts16_27_char,
        &fonts16_28_char,
        &fonts16_29_char,
        &fonts16_2A_char,
        &fonts16_2B_char,
        &fonts16_2C_char,
        &fonts16_2D_char,
        &fonts16_2E_char,
        &fonts16_2F_char,
        &fonts16_30_char,
        &fonts16_31_char,
        &fonts16_32_char,
        &fonts16_33_char,
        &fonts16_34_char,
        &fonts16_35_char,
        &fonts16_36_char,
        &fonts16_37_char,
        &fonts16_38_char,
        &fonts16_39_char,
        &fonts16_3A_char,
        &fonts16_3B_char,
        &fonts16_3C_char,
        &fonts16_3D_char,
        &fonts16_3E_char,
        &fonts16_3F_char,
        &fonts16_40_char,
        &fonts16_41_char,
        &fonts16_42_char,
        &fonts16_43_char,
        &fonts16_44_char,
        &fonts16_45_char,
        &fonts16_46_char,
        &fonts16_47_char,
        &fonts16_48_char,
        &fonts16_49_char,
        &fonts16_4A_char,
        &fonts16_4B_char,
        &fonts16_4C_char,
        &fonts16_4D_char,
        &fonts16_4E_char,
        &fonts16_4F_char,
        &fonts16_50_char,
        &fonts16_51_char,
        &fonts16_52_char,
        &fonts16_53_char,
        &fonts16_54_char,
        &fonts16_55_char,
        &fonts16_56_char,
        &fonts16_57_char,
        &fonts16_58_char,
        &fonts16_59_char,
        &fonts16_5A_char,
        &fonts16_5B_char,
        &fonts16_5C_char,
        &fonts16_5D_char,
        &fonts16_5E_char,
        &fonts16_5F_char,
        &fonts16_60_char,
        &fonts16_61_char,
        &fonts16_62_char,
        &fonts16_63_char,
        &fonts16_64_char,
        &fonts16_65_char,
        &fonts16_66_char,
        &fonts16_67_char,
        &fonts16_68_char,
        &fonts16_69_char,
        &fonts16_6A_char,
        &fonts16_6B_char,
        &fonts16_6C_char,
        &fonts16_6D_char,
        &fonts16_6E_char,
        &fonts16_6F_char,
        &fonts16_70_char,
        &fonts16_71_char,
        &fonts16_72_char,
        &fonts16_73_char,
        &fonts16_74_char,
        &fonts16_75_char,
        &fonts16_76_char,
        &fonts16_77_char,
        &fonts16_78_char,
        &fonts16_79_char,
        &fonts16_7A_char,
        &fonts16_7B_char,
        &fonts16_7C_char,
        &fonts16_7D_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_7E_92_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_93_B0_char,
        &fonts16_B1_BF_char,
        &fonts16_B1_BF_char,
        &fonts16_B1_BF_char,
        &fonts16_B1_BF_char,
        &fonts16_B1_BF_char,
        &fonts16_B1_BF_char,
        &fonts16_B1_BF_char,
        &fonts16_B1_BF_char,
        &fonts16_B1_BF_char,
        &fonts16_B1_BF_char,
        &fonts16_B1_BF_char,
        &fonts16_B1_BF_char,
        &fonts16_B1_BF_char,
        &fonts16_B1_BF_char,
        &fonts16_B1_BF_char,
        &fonts16_C0_C1_char,
        &fonts16_C0_C1_char,
        &fonts16_C2_C4_char,
        &fonts16_C2_C4_char,
        &fonts16_C2_C4_char,
        &fonts16_C5_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_C6_E0_char,
        &fonts16_E1_char,
        &fonts16_E2_E4_char,
        &fonts16_E2_E4_char,
        &fonts16_E2_E4_char,
        &fonts16_E5_E9_char,
        &fonts16_E5_E9_char,
        &fonts16_E5_E9_char,
        &fonts16_E5_E9_char,
        &fonts16_E5_E9_char,
        &fonts16_EA_ED_char,
        &fonts16_EA_ED_char,
        &fonts16_EA_ED_char,
        &fonts16_EA_ED_char,
        &fonts16_EE_F1_char,
        &fonts16_EE_F1_char,
        &fonts16_EE_F1_char,
        &fonts16_EE_F1_char,
        &fonts16_EE_F1_char,
        &fonts16_F2_F3_char,
        &fonts16_F2_F3_char,
        &fonts16_F4_F6_char,
        &fonts16_F4_F6_char,
        &fonts16_F4_F6_char,
        &fonts16_F7_F9_char,
        &fonts16_F7_F9_char,
        &fonts16_F7_F9_char,
        &fonts16_FA_char,
        &fonts16_FB_FC_char,
        &fonts16_FB_FC_char,
        &fonts16_FD_FF_char,
        &fonts16_FD_FF_char,
        &fonts16_FD_FF_char,
    }
};
