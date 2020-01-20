#include "display_test.h"
#include <button_config.h>
#include <taskmgr.h>
#include <display.h>
#include <game.h>

static void testTask(uint32_t parameters);
static uint32_t testStep;

static void dummyButtonHandler() {
    soundKeyBeep();
}

static void buttonNoHandler(uint32_t pressType) {
    soundKeyBeep();
    osTaskDelHandler(testTask);
    showManualTestsScreen();
}

static const task_t handlers[Button_Last] = {
    dummyButtonHandler,         //Button_6
    dummyButtonHandler,         //Button_7
    dummyButtonHandler,         //Button_8
    dummyButtonHandler,         //Button_9
    dummyButtonHandler,         //Button_0
    dummyButtonHandler,         //Button_Info
    dummyButtonHandler,         //Button_Prime
    dummyButtonHandler,         //Button_Lock
    dummyButtonHandler,         //Button_1
    dummyButtonHandler,         //Button_2
    dummyButtonHandler,         //Button_3
    dummyButtonHandler,         //Button_4
    dummyButtonHandler,         //Button_5
    dummyButtonHandler,         //Button_Point
    dummyButtonHandler,         //Button_Ok
    buttonNoHandler,            //Button_No
    dummyButtonHandler          //Button_Power
};

static void testTask(uint32_t parameters) {
    testStep = (testStep + 1) % 3;

    switch (testStep) {
    case 0:
        colorfill(color_lightred);
        break;
    case 1:
        colorfill(color_lightgreen);
        break;
    case 2:
        colorfill(color_lightblue);
        break;
    }
    osTaskAdd(testTask, 0, 1000);
}

void startDisplayTest() {
    testStep = 0;
    for (buttonName_t btn = 0; btn < Button_Last; btn++) {
        setButtonHandler(btn, handlers[btn]);
    }

    osTaskAdd(testTask, 0, 200);
}
