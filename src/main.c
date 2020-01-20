#include <stdio.h>
#include <stdlib.h>

#include "diag/Trace.h"
#include "taskmgr.h"
#include "display.h"
#include "leds.h"
#include "motor.h"
#include "buttons.h"
#include "button_hal.h"
#include "button_config.h"
#include "sound.h"
#include <buttons_test.h>
#include <manual_tests_menu.h>
#include <stm32l4xx.h>
#include <math.h>

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

void initGPIO() {
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN |
                    RCC_AHB2ENR_GPIOBEN |
                    RCC_AHB2ENR_GPIOCEN |
                    RCC_AHB2ENR_GPIODEN |
                    RCC_AHB2ENR_GPIOEEN;

    GPIOA->MODER &= ~(GPIO_MODER_MODE8_Msk |
                      GPIO_MODER_MODE9_Msk |
                      GPIO_MODER_MODE10_Msk |
                      GPIO_MODER_MODE11_Msk |
                      GPIO_MODER_MODE12_Msk);
    GPIOA->MODER |= (1 << GPIO_MODER_MODE8_Pos) |
                    (1 << GPIO_MODER_MODE9_Pos) |
                    (1 << GPIO_MODER_MODE10_Pos) |
                    (1 << GPIO_MODER_MODE11_Pos) |
                    (1 << GPIO_MODER_MODE12_Pos);

    GPIOB->MODER = (1 << GPIO_MODER_MODE3_Pos) |
                   (1 << GPIO_MODER_MODE4_Pos) |
                   (1 << GPIO_MODER_MODE8_Pos) |
                   (1 << GPIO_MODER_MODE9_Pos) |
                   (1 << GPIO_MODER_MODE12_Pos) |
                   (1 << GPIO_MODER_MODE14_Pos);

    GPIOB->MODER &= ~(GPIO_MODER_MODE5_Msk);
    GPIOB->PUPDR = (1 < GPIO_PUPDR_PUPD5_Pos);  //KEYS3 with pull-up

    GPIOE->MODER = 0xFFFB0000UL;				//PORTE[9] is alternate function
    GPIOE->PUPDR = 0x5555;                      //PORTE[7:0] with pull up
    GPIOE->AFR[1] = 1 << GPIO_AFRH_AFSEL9_Pos;	//TIM1_CH1 is an alternate function AF1 for PE9

    GPIOC->MODER &= ~(GPIO_MODER_MODE0_Msk |
                      GPIO_MODER_MODE2_Msk |
                      GPIO_MODER_MODE3_Msk |
                      GPIO_MODER_MODE9_Msk);
    GPIOC->MODER |= (1 << GPIO_MODER_MODE2_Pos) |
                    (1 << GPIO_MODER_MODE3_Pos) |
                    (2 << GPIO_MODER_MODE9_Pos);
    GPIOC->AFR[1] = 2 << GPIO_AFRH_AFSEL9_Pos;  //TIM3_CH4 is an alternate function AF2 for PC9
    GPIOC->ODR |= (1 << 2);
    GPIOC->PUPDR = 1 << GPIO_PUPDR_PUPD0_Pos;

    GPIOD->MODER = 0x55555555;
}

void max706_toggle(uint32_t parameter) {
    GPIOC->ODR ^= (1 << 3);

    osTaskAdd(max706_toggle, 0, 500);
}

void initClocks() {
    //Enable HSE oscillator and wait for ready
    RCC->CR |= RCC_CR_HSEON;
    while ((RCC->CR & RCC_CR_HSERDY) == 0);

    //Enable Main PLL
    //Configure PLL output to 30 MHZ
    //Wait for ready
    RCC->PLLCFGR = (0x3 << RCC_PLLCFGR_PLLSRC_Pos) | //Main PLL Clock source -> HSE (8 MHz)
                   (0xF << RCC_PLLCFGR_PLLN_Pos) |   //VCO multiplication factor = 15 (120 MHz)
				   (0x1 << RCC_PLLCFGR_PLLR_Pos) |   //R division factor = 4 (30 MHz)
                   RCC_PLLCFGR_PLLREN;               //Enable Main PLL PLLCLK output

    RCC->CR |= RCC_CR_PLLON;
    while ((RCC->CR & RCC_CR_PLLRDY) == 0);

    //Switch system clock to PLLCLK and wait for being switched
    RCC->CFGR = RCC_CFGR_SW_PLL << RCC_CFGR_SW_Pos;
    while ((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_PLL);

    SystemCoreClockUpdate();
}

void initializationTask(uint32_t parameter) {
    static uint32_t time;

    if (time == 0) {
        display00();
        osTaskAdd(initializationTask, 0, 50);
    } else if (time < 5) {
        display01();
        osTaskAdd(initializationTask, 0, 1000);
    } else {
        showManualTestsScreen();
    }
    time++;
}

int main (int argc, char* argv[]) {
    initClocks();
    osInit(1000, timerInit, timerElapseSinceLastTime);

    initGPIO();
    initSound();
    initMotor();
    initLeds();
    initDisplay();

    osTaskAdd(max706_toggle, 0, 500);
    buttonInit(getButtonsConfig(), Button_Last);
    osTaskAdd(buttonsPollTask, 0, 5);
    osTaskAdd(initializationTask, 0, 100);
    osRun();
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
