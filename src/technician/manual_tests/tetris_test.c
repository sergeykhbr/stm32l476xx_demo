#include "tetris_test.h"
#include <button_config.h>
#include <taskmgr.h>
#include <display.h>
#include <game.h>

static void testTask(uint32_t parameters);

static void dummyButtonHandler() {
}

static void buttonNoHandler(uint32_t pressType) {
    soundStopAlarm();
    osTaskDelHandler(testTask);
    showManualTestsScreen();
}

static void buttonPointHandler(uint32_t pressType) {
    gameMoveRight();
}

static void button5Handler(uint32_t pressType) {
    gameRotate();
}

static void button4Handler(uint32_t pressType) {
    gameMoveLeft();
}

static void buttonPrimeHandler(uint32_t pressType) {
    gameMoveDown();
}

static void buttonOkHandler(uint32_t pressType) {
    soundStopAlarm();
    gameRestart();
}

static const task_t handlers[Button_Last] = {
    dummyButtonHandler,         //Button_6
    dummyButtonHandler,         //Button_7
    dummyButtonHandler,         //Button_8
    dummyButtonHandler,         //Button_9
    dummyButtonHandler,         //Button_0
    dummyButtonHandler,         //Button_Info
    buttonPrimeHandler,         //Button_Prime
    dummyButtonHandler,         //Button_Lock
    dummyButtonHandler,         //Button_1
    dummyButtonHandler,         //Button_2
    dummyButtonHandler,         //Button_3
    button4Handler,             //Button_4
    button5Handler,             //Button_5
    buttonPointHandler,         //Button_Point
    buttonOkHandler,            //Button_Ok
    buttonNoHandler,            //Button_No
    dummyButtonHandler          //Button_Power
};

static void testTask(uint32_t parameters) {
    gameLoop();
    osTaskAdd(testTask, 0, 400);
}

void startTetrisTest(void) {
    for (buttonName_t btn = 0; btn < Button_Last; btn++) {
        setButtonHandler(btn, handlers[btn]);
    }
    gameRestart();
    osTaskAdd(testTask, 0, 200);
}
