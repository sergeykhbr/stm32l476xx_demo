#include "manual_tests_menu.h"
#include <buttons.h>
#include <taskmgr.h>
#include <button_config.h>
#include <sound.h>
#include <buttons_test.h>
#include <door_test.h>
#include <display_test.h>
#include <motor_test.h>
#include <tetris_test.h>
#include <sound_test.h>
#include <power_hal.h>
#include <alarm_test.h>

static void manualTestsTask(uint32_t parameters);

static ManualTest_t currentTest;

static char *manualTests[ManualTestLast] = {
    "Door test",
    "Keyboard test",
    "Tetris",
    "Display test",
    "Motor test",
    "Sound test",
    "Alarm test"
};

static manualTestHandler manualTestsHandlers[ManualTestLast] = {
    startDoorTest,
    startButtonsTest,
    startTetrisTest,
    startDisplayTest,
    startMotorTest,
    startSoundTest,
    startAlarmTest
};

static void dummyButtonHandler() {
    soundKeyBeep();
}

static void button0Handler(uint32_t pressType) {
    soundKeyBeep();
    if (currentTest < ManualTestLast - 1) {
        currentTest++;
    } else {
        currentTest = 0;
    }
}

static void button5Handler(uint32_t pressType) {
    soundKeyBeep();
    if (currentTest > 0) {
        currentTest--;
    } else {
        currentTest = ManualTestLast - 1;
    }
}

static void buttonOkHandler(uint32_t pressType) {
    soundKeyBeep();
    if (manualTestsHandlers[currentTest] != 0) {
        osTaskDelHandler(manualTestsTask);
        manualTestsHandlers[currentTest]();
    }
}

static void buttonPowerHandler(uint32_t pressType) {
    if ((pressType == BUTTON_PRESS_LONG) ||
        (pressType == BUTTON_PRESS_STICK)) {
        powerOff();
    }
}

static const task_t handlers[Button_Last] = {
    dummyButtonHandler, dummyButtonHandler, dummyButtonHandler, dummyButtonHandler,
    button0Handler, dummyButtonHandler, dummyButtonHandler, dummyButtonHandler,
    dummyButtonHandler, dummyButtonHandler, dummyButtonHandler, dummyButtonHandler,
    button5Handler, dummyButtonHandler, buttonOkHandler, dummyButtonHandler,
    buttonPowerHandler
};

static void manualTestsTask(uint32_t parameters) {
    display48(manualTests, ManualTestLast, currentTest);
    osTaskAdd(manualTestsTask, 0, 200);
}

void showManualTestsScreen(void) {
    currentTest = 0;
    for (buttonName_t btn = 0; btn < Button_Last; btn++) {
        setButtonHandler(btn, handlers[btn]);
    }
    osTaskAdd(manualTestsTask, 0, 100);
}
