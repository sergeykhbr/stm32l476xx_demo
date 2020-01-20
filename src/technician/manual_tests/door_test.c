#include "door_test.h"
#include <button_config.h>
#include <taskmgr.h>
#include <display.h>

static void testTask(uint32_t parameters);

static void dummyButtonHandler() {
    soundKeyBeep();
}

static void buttonOkHandler(uint32_t pressType) {
    soundKeyBeep();
    osTaskDelHandler(testTask);
    showManualTestsScreen();
}

static const task_t handlers[Button_Last] = {
    dummyButtonHandler, dummyButtonHandler, dummyButtonHandler, dummyButtonHandler,
    dummyButtonHandler, dummyButtonHandler, dummyButtonHandler, dummyButtonHandler,
    dummyButtonHandler, dummyButtonHandler, dummyButtonHandler, dummyButtonHandler,
    dummyButtonHandler, dummyButtonHandler, buttonOkHandler, dummyButtonHandler,
    dummyButtonHandler
};

static void testTask(uint32_t parameters) {
    display66();
    osTaskAdd(testTask, 0, 200);
}

void startDoorTest() {
    for (buttonName_t btn = 0; btn < Button_Last; btn++) {
        setButtonHandler(btn, handlers[btn]);
    }

    osTaskAdd(testTask, 0, 200);
}
