#include "button_config.h"
#include "button_hal.h"
#include <taskmgr.h>

static void button6Handler(uint32_t pressType);
static void button7Handler(uint32_t pressType);
static void button8Handler(uint32_t pressType);
static void button9Handler(uint32_t pressType);
static void button0Handler(uint32_t pressType);
static void buttonInfoHandler(uint32_t pressType);
static void buttonPrimeHandler(uint32_t pressType);
static void buttonLockHandler(uint32_t pressType);
static void button1Handler(uint32_t pressType);
static void button2Handler(uint32_t pressType);
static void button3Handler(uint32_t pressType);
static void button4Handler(uint32_t pressType);
static void button5Handler(uint32_t pressType);
static void buttonPointHandler(uint32_t pressType);
static void buttonOkHandler(uint32_t pressType);
static void buttonNoHandler(uint32_t pressType);
static void buttonPowerHandler(uint32_t pressType);

static void button6Init(buttonInitState_t state);
static void button7Init(buttonInitState_t state);
static void button8Init(buttonInitState_t state);
static void button9Init(buttonInitState_t state);
static void button0Init(buttonInitState_t state);
static void buttonInfoInit(buttonInitState_t state);
static void buttonPrimeInit(buttonInitState_t state);
static void buttonLockInit(buttonInitState_t state);
static void button1Init(buttonInitState_t state);
static void button2Init(buttonInitState_t state);
static void button3Init(buttonInitState_t state);
static void button4Init(buttonInitState_t state);
static void button5Init(buttonInitState_t state);
static void buttonPointInit(buttonInitState_t state);
static void buttonOkInit(buttonInitState_t state);
static void buttonNoInit(buttonInitState_t state);
static void buttonPowerInit(buttonInitState_t state);

static buttonState_t button6GetState(void);
static buttonState_t button7GetState(void);
static buttonState_t button8GetState(void);
static buttonState_t button9GetState(void);
static buttonState_t button0GetState(void);
static buttonState_t buttonInfoGetState(void);
static buttonState_t buttonPrimeGetState(void);
static buttonState_t buttonLockGetState(void);
static buttonState_t button1GetState(void);
static buttonState_t button2GetState(void);
static buttonState_t button3GetState(void);
static buttonState_t button4GetState(void);
static buttonState_t button5GetState(void);
static buttonState_t buttonPointGetState(void);
static buttonState_t buttonOkGetState(void);
static buttonState_t buttonNoGetState(void);
static buttonState_t buttonPowerGetState(void);

static const buttonInitStruct_t buttonsConfig[Button_Last] = {
    {button6Init, button6GetState, button6Handler, Button_6},
    {button7Init, button7GetState, button7Handler, Button_7},
    {button8Init, button8GetState, button8Handler, Button_8},
    {button9Init, button9GetState, button9Handler, Button_9},
    {button0Init, button0GetState, button0Handler, Button_0},
    {buttonInfoInit, buttonInfoGetState, buttonInfoHandler, Button_Info},
    {buttonPrimeInit, buttonPrimeGetState, buttonPrimeHandler, Button_Prime},
    {buttonLockInit, buttonLockGetState, buttonLockHandler, Button_Lock},
    {button1Init, button1GetState, button1Handler, Button_1},
    {button2Init, button2GetState, button2Handler, Button_2},
    {button3Init, button3GetState, button3Handler, Button_3},
    {button4Init, button4GetState, button4Handler, Button_4},
    {button5Init, button5GetState, button5Handler, Button_5},
    {buttonPointInit, buttonPointGetState, buttonPointHandler, Button_Point},
    {buttonOkInit, buttonOkGetState, buttonOkHandler, Button_Ok},
    {buttonNoInit, buttonNoGetState, buttonNoHandler, Button_No},
    {buttonPowerInit, buttonPowerGetState, buttonPowerHandler, Button_Power},
};

const buttonInitStruct_t *getButtonsConfig(void) {
    return buttonsConfig;
}

static void buttonInitCommon(buttonInitState_t state, buttonName_t buttonId) {
/*    switch (state) {
    case btOFF:
        buttonsState &= ~(1 << buttonId);
        break;
    case btON:
        buttonsState |= 1 << buttonId;
        break;
    }*/
}

static buttonState_t buttonGetState(buttonName_t buttonId) {
    return (buttonsGetState() & (1 << buttonId))? BUTTON_PRESSED: BUTTON_NOT_PRESSED;
}

static void button6Init(buttonInitState_t state) {
    buttonInitCommon(state, Button_6);
}

static void button7Init(buttonInitState_t state) {
    buttonInitCommon(state, Button_7);
}

static void button8Init(buttonInitState_t state) {
    buttonInitCommon(state, Button_8);
}

static void button9Init(buttonInitState_t state) {
    buttonInitCommon(state, Button_9);
}

static void button0Init(buttonInitState_t state) {
    buttonInitCommon(state, Button_0);
}

static void buttonInfoInit(buttonInitState_t state) {
    buttonInitCommon(state, Button_Info);
}

static void buttonPrimeInit(buttonInitState_t state) {
    buttonInitCommon(state, Button_Prime);
}

static void buttonLockInit(buttonInitState_t state) {
    buttonInitCommon(state, Button_Lock);
}

static void button1Init(buttonInitState_t state) {
    buttonInitCommon(state, Button_1);
}

static void button2Init(buttonInitState_t state) {
    buttonInitCommon(state, Button_2);
}

static void button3Init(buttonInitState_t state) {
    buttonInitCommon(state, Button_3);
}

static void button4Init(buttonInitState_t state) {
    buttonInitCommon(state, Button_4);
}

static void button5Init(buttonInitState_t state) {
    buttonInitCommon(state, Button_5);
}

static void buttonPointInit(buttonInitState_t state) {
    buttonInitCommon(state, Button_Point);
}

static void buttonOkInit(buttonInitState_t state) {
    buttonInitCommon(state, Button_Ok);
}

static void buttonNoInit(buttonInitState_t state) {
    buttonInitCommon(state, Button_No);
}

static void buttonPowerInit(buttonInitState_t state) {
    buttonInitCommon(state, Button_Power);
}

static buttonState_t button6GetState(void) {
    return buttonGetState(Button_6);
}

static buttonState_t button7GetState(void) {
    return buttonGetState(Button_7);
}

static buttonState_t button8GetState(void) {
    return buttonGetState(Button_8);
}

static buttonState_t button9GetState(void) {
    return buttonGetState(Button_9);
}

static buttonState_t button0GetState(void) {
    return buttonGetState(Button_0);
}

static buttonState_t buttonInfoGetState(void) {
    return buttonGetState(Button_Info);
}

static buttonState_t buttonPrimeGetState(void) {
    return buttonGetState(Button_Prime);
}

static buttonState_t buttonLockGetState(void) {
    return buttonGetState(Button_Lock);
}

static buttonState_t button1GetState(void) {
    return buttonGetState(Button_1);
}

static buttonState_t button2GetState(void) {
    return buttonGetState(Button_2);
}

static buttonState_t button3GetState(void) {
    return buttonGetState(Button_3);
}

static buttonState_t button4GetState(void) {
    return buttonGetState(Button_4);
}

static buttonState_t button5GetState(void) {
    return buttonGetState(Button_5);
}

static buttonState_t buttonPointGetState(void) {
    return buttonGetState(Button_Point);
}

static buttonState_t buttonOkGetState(void) {
    return buttonGetState(Button_Ok);
}

static buttonState_t buttonNoGetState(void) {
    return buttonGetState(Button_No);
}

static buttonState_t buttonPowerGetState(void) {
    return buttonGetState(Button_Power);
}

static void button6Handler(uint32_t pressType) {
    osTaskDelHandler(button6Handler);
}

static void button7Handler(uint32_t pressType) {
    osTaskDelHandler(button7Handler);
}

static void button8Handler(uint32_t pressType) {
    osTaskDelHandler(button8Handler);
}

static void button9Handler(uint32_t pressType) {
    osTaskDelHandler(button9Handler);
}

static void button0Handler(uint32_t pressType) {
    osTaskDelHandler(button0Handler);
}

static void buttonInfoHandler(uint32_t pressType) {
    osTaskDelHandler(buttonInfoHandler);
}

static void buttonPrimeHandler(uint32_t pressType) {
    osTaskDelHandler(buttonPrimeHandler);
}

static void buttonLockHandler(uint32_t pressType) {
    osTaskDelHandler(buttonLockHandler);
}

static void button1Handler(uint32_t pressType) {
    osTaskDelHandler(button1Handler);
}

static void button2Handler(uint32_t pressType) {
    osTaskDelHandler(button2Handler);
}

static void button3Handler(uint32_t pressType) {
    osTaskDelHandler(button3Handler);
}

static void button4Handler(uint32_t pressType) {
    osTaskDelHandler(button4Handler);
}

static void button5Handler(uint32_t pressType) {
    osTaskDelHandler(button5Handler);
}

static void buttonPointHandler(uint32_t pressType) {
    osTaskDelHandler(buttonPointHandler);
}

static void buttonOkHandler(uint32_t pressType) {
    osTaskDelHandler(buttonOkHandler);
}

static void buttonNoHandler(uint32_t pressType) {
    osTaskDelHandler(buttonNoHandler);
}

static void buttonPowerHandler(uint32_t pressType) {
    osTaskDelHandler(buttonPowerHandler);
}
