#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>

#define MAKE_COLOR(r, g, b) ( \
                             (r << (5 + 6)) | \
                             (g << 5) | \
                             (b))
typedef enum {
    INIT_SEQ_CMD,
    INIT_SEQ_DATA
} InitSequenceRecordType;

typedef struct {
    InitSequenceRecordType type;
    uint8_t data;
} InitSequenceRecord;

typedef union {
    uint16_t raw;
    struct {
        uint16_t b : 5;
        uint16_t g : 6;
        uint16_t r : 5;
    } rgb;
} color;

typedef enum {
    color_defback   = 0x0000,
    color_deffont   = 0x07FF,
    color_datatitle = 0x07FF,
    color_datashow  = 0x07E0,
    color_datainput = 0xFFE0,
    color_instuct   = 0xFFFF,
    color_seltitle  = 0x07FF,
    color_selnotsel = 0x7BEF,
    color_selsel    = 0xFFFF,
    color_selback   = 0x03E0,
    color_channel1  = 0x07E0,
    color_channel2  = 0x07FF,
    color_label     = 0xFFFF,
    color_alarback  = 0x7800,
    color_alarfont  = 0x7FE0,
    color_warnfont  = 0xFFE0,
    color_lightred  = 0xF800,
    color_white     = 0xFFFF,
    color_gray      = 0x8410,
    color_green     = 0x0400,
    color_lightgreen = 0x07E0,
    color_lightblue = 0x001F,
    color_lightgray = 0xC618,
    color_pca       = 0x07FF,
    color_epidural  = 0xFFE0,
    color_regional  = 0x07E0,
    color_lpca      = 0x0618,
    color_lepidural = 0xC600,
    color_lregional = 0x0600,
    color_dataedit  = 0xFFFF,
    color_orange    = 0xFBE7,
    color_blue      = 0x841F
} predefined_colors;

#define DC_Pin (1 << 10)
#define Reset_Pin (1 << 12)
#define CS_Pin (1 << 11)
#define RD_Pin (1 << 9)
#define WR_Pin (1 << 8)

void initDisplay();
void gameDisplay();
void grafchar(char c);
void keyshow(uint8_t key);
void display00();
void display01();
void display65(uint8_t level);
void display66();
void display64(uint8_t currentKey);
void display48(char *items[], int32_t count, int32_t selected);
void display68();
void displayAlarmTest();
void setFgColor(uint16_t col);
void setBgColor(uint16_t col);
void start_display();
void colorfill(uint16_t color);
void showScores(int scores);

void pixel(int x, int y, uint16_t color);
void block(int x, int y, uint16_t color);
#endif // DISPLAY_H
