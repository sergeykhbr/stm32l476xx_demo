/*
 * button_hal.c
 *
 *  Created on: 7 нояб. 2019 г.
 *      Author: vasiliy.tsarevskiy
 */
#include <stm32l4xx.h>
#include <stdint.h>
#include <buttons.h>
#include "button_config.h"
#include "button_hal.h"

static uint32_t buttonsState;

uint32_t buttonsGetState(void) {
    return buttonsState;
}

uint32_t getRawButtonsState() {
    volatile uint32_t tmp = GPIOE->IDR & 0xFF;
    return tmp;
}

uint32_t getPwrButtonState() {
    if ((GPIOB->IDR & (1 << 5)) != 0) {
        return 0;
    } else {
        return 1;
    }
}

void activateButtonColumn(uint8_t column) {
    switch (column) {
    case 0:
        //Activate KEYS2
        GPIOB->BSRR = (1 << (4 + 16)) | (1 << 3); //Set PB3 clear PB4
        break;
    case 1:
        //Activate KEYS1
        GPIOB->BSRR = (1 << (3 + 16)) | (1 << 4); //Set PB4 clear PB3;
        break;
    }
}

void handleChangedButtons(uint32_t newButtonsState) {
    uint32_t changes = buttonsState ^ newButtonsState;

    buttonsState = newButtonsState;
    for (buttonName_t btn = Button_6; btn < Button_Last; btn++) {
        if (changes & (1 << btn)) {
            buttonInterruptHandler(btn);
        }
    }
}

void buttonsPollTask(uint32_t parameter) {
    static uint8_t btn_poll_stage = 0;
    static uint32_t rawButtonState;

    switch (btn_poll_stage) {
    case 0:
        rawButtonState = 0;
        activateButtonColumn(0);
        btn_poll_stage++;
        osTaskAdd(buttonsPollTask, 0, 5);
        break;
    case 1:
        rawButtonState = getRawButtonsState();
        activateButtonColumn(1);
        btn_poll_stage++;
        osTaskAdd(buttonsPollTask, 0, 5);
        break;
    case 2:
        rawButtonState |= getRawButtonsState() << 8;
        rawButtonState |= getPwrButtonState() << 16;
        handleChangedButtons((~rawButtonState) & 0x1FFFF);
        btn_poll_stage = 0;
        osTaskAdd(buttonsPollTask, 0, 5);
        break;
    }
}
