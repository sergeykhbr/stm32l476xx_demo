#include <motor_test.h>
#include <motor.h>
#include <taskmgr.h>
#include <display.h>
#include <button_config.h>

static void testTask(uint32_t parameters);

static void dummyButtonHandler() {
    soundKeyBeep();
}

static void button5Handler(uint32_t pressType) {
    soundKeyBeep();
    increaseMotorSpeed(5);
}

static void button0Handler(uint32_t pressType) {
    soundKeyBeep();
    decreaseMotorSpeed(5);
}

static void buttonNoHandler(uint32_t pressType) {
    soundKeyBeep();
    disableMotor();
    osTaskDelHandler(testTask);
    showManualTestsScreen();
}

static const task_t handlers[Button_Last] = {
    dummyButtonHandler, dummyButtonHandler, dummyButtonHandler, dummyButtonHandler,
    button0Handler, dummyButtonHandler, dummyButtonHandler, dummyButtonHandler,
    dummyButtonHandler, dummyButtonHandler, dummyButtonHandler, dummyButtonHandler,
    button5Handler, dummyButtonHandler, dummyButtonHandler, buttonNoHandler,
    dummyButtonHandler
};

static void testTask(uint32_t parameters) {
    display68();
    osTaskAdd(testTask, 0, 200);
}

void startMotorTest() {
    for (buttonName_t btn = 0; btn < Button_Last; btn++) {
        setButtonHandler(btn, handlers[btn]);
    }

    enableMotor();
    osTaskAdd(testTask, 0, 200);
}
