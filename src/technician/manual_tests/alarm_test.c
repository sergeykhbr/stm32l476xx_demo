#include <alarm_test.h>
#include <taskmgr.h>
#include <display.h>
#include <button_config.h>
#include <sound.h>

static void testTask(uint32_t parameters);
static uint8_t firstStart;

static void dummyButtonHandler() {
    soundKeyBeep();
}

static void buttonNoHandler(uint32_t pressType) {
    soundKeyBeep();
    soundStopAlarm();
    soundSetLevel(3);
    osTaskDelHandler(testTask);
    showManualTestsScreen();
}

static const task_t handlers[Button_Last] = {
    dummyButtonHandler, dummyButtonHandler, dummyButtonHandler, dummyButtonHandler,
    dummyButtonHandler, dummyButtonHandler, dummyButtonHandler, dummyButtonHandler,
    dummyButtonHandler, dummyButtonHandler, dummyButtonHandler, dummyButtonHandler,
    dummyButtonHandler, dummyButtonHandler, dummyButtonHandler, buttonNoHandler,
    dummyButtonHandler
};

static void testTask(uint32_t parameters) {
    displayAlarmTest();
    if (firstStart) {
        firstStart = 0;
    } else {
        soundHiAlarm();
    }
    osTaskAdd(testTask, 0, 1000);
}

void startAlarmTest() {
    for (buttonName_t btn = 0; btn < Button_Last; btn++) {
        setButtonHandler(btn, handlers[btn]);
    }

    firstStart = 1;
    osTaskAdd(testTask, 0, 200);
}
