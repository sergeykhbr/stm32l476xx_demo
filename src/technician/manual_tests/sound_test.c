#include <motor_test.h>
#include <motor.h>
#include <taskmgr.h>
#include <display.h>
#include <button_config.h>

static void testTask(uint32_t parameters);
static uint8_t currentSoundLevel;
static uint8_t firstStart;

static void dummyButtonHandler() {
    soundKeyBeep();
}

static void buttonNoHandler(uint32_t pressType) {
    soundKeyBeep();
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
    if (firstStart) {
        currentSoundLevel = 1;
        display65(soundGetLevel());
        firstStart = 0;
    } else {
        soundSetLevel(currentSoundLevel);
        display65(soundGetLevel());
        soundKeyBeep();

        currentSoundLevel++;
        if (currentSoundLevel > 7) {
            currentSoundLevel = 1;
        }
    }
    osTaskAdd(testTask, 0, 1000);
}

void startSoundTest() {
    for (buttonName_t btn = 0; btn < Button_Last; btn++) {
        setButtonHandler(btn, handlers[btn]);
    }

    firstStart = 1;
    osTaskAdd(testTask, 0, 200);
}
