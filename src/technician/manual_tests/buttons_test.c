#include <buttons_test.h>
#include <buttons.h>
#include <button_config.h>
#include <taskmgr.h>
#include <manual_tests_menu.h>

static void testTask(uint32_t parameter);

static buttonName_t testStage;
static const buttonName_t buttonsTestOrder[Button_Last + 1] = {
    Button_1, Button_6, Button_2, Button_7,
    Button_3, Button_8, Button_4, Button_9,
    Button_5, Button_0, Button_Point, Button_Lock,
    Button_Info, Button_No, Button_Ok, Button_Prime,
    Button_Power, Button_Last
};

static void button6Handler(uint32_t pressType) {

    if (buttonsTestOrder[testStage] == Button_6) {
        testStage++;
    }
}

static void button7Handler(uint32_t pressType) {
    if (buttonsTestOrder[testStage] == Button_7) {
        testStage++;
    }
}

static void button8Handler(uint32_t pressType) {
    if (buttonsTestOrder[testStage] == Button_8) {
        testStage++;
    }
}

static void button9Handler(uint32_t pressType) {
    if (buttonsTestOrder[testStage] == Button_9) {
        testStage++;
    }
}

static void button0Handler(uint32_t pressType) {
    if (buttonsTestOrder[testStage] == Button_0) {
        testStage++;
    }
}

static void buttonInfoHandler(uint32_t pressType) {
    if (buttonsTestOrder[testStage] == Button_Info) {
        testStage++;
    }
}

static void buttonPrimeHandler(uint32_t pressType) {
    if (buttonsTestOrder[testStage] == Button_Prime) {
        testStage++;
    }
}

static void buttonLockHandler(uint32_t pressType) {
    if (buttonsTestOrder[testStage] == Button_Lock) {
        testStage++;
    }
}

static void button1Handler(uint32_t pressType) {
    if (buttonsTestOrder[testStage] == Button_1) {
        testStage++;
    }
}

static void button2Handler(uint32_t pressType) {
    if (buttonsTestOrder[testStage] == Button_2) {
        testStage++;
    }
}

static void button3Handler(uint32_t pressType) {
    if (buttonsTestOrder[testStage] == Button_3) {
        testStage++;
    }
}

static void button4Handler(uint32_t pressType) {
    if (buttonsTestOrder[testStage] == Button_4) {
        testStage++;
    }
}

static void button5Handler(uint32_t pressType) {
    if (buttonsTestOrder[testStage] == Button_5) {
        testStage++;
    }
}

static void buttonPointHandler(uint32_t pressType) {
    if (buttonsTestOrder[testStage] == Button_Point) {
        testStage++;
    }
}

static void buttonOkHandler(uint32_t pressType) {
    if (buttonsTestOrder[testStage] == Button_Ok) {
        testStage++;
    } else if (testStage == Button_Last) {
        osTaskDelHandler(testTask);
        showManualTestsScreen();
    }
}

static void buttonNoHandler(uint32_t pressType) {
    if (buttonsTestOrder[testStage] == Button_No) {
        testStage++;
    }
}

static void buttonPowerHandler(uint32_t pressType) {
    if (buttonsTestOrder[testStage] == Button_Power) {
        testStage++;
    }
}

static const task_t handlers[Button_Last] = {
    button6Handler, button7Handler, button8Handler, button9Handler,
    button0Handler, buttonInfoHandler, buttonPrimeHandler, buttonLockHandler,
    button1Handler, button2Handler, button3Handler, button4Handler,
    button5Handler, buttonPointHandler, buttonOkHandler, buttonNoHandler,
    buttonPowerHandler
};

static void testTask(uint32_t parameter) {
    display64(buttonsTestOrder[testStage]);
    if (testStage <= Button_Last) {
        osTaskAdd(testTask, 0, 200);
    }
}

void startButtonsTest() {
    testStage = 0;

    for (buttonName_t btn = 0; btn < Button_Last; btn++) {
        setButtonHandler(btn, handlers[btn]);
    }
    osTaskAdd(testTask, 0, 200);
}
