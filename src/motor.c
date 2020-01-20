#include "motor.h"
#include <stm32l4xx.h>

#define MOTOR_TIMER_FREQ (78125)
#define MOTOR_TIMER_PERIOD (SystemCoreClock / MOTOR_TIMER_FREQ)

static void initMotorTimer() {
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

	TIM1->CCMR1 = 0x6 << TIM_CCMR1_OC1M_Pos;    //PWM Mode 1

	TIM1->CCER = TIM_CCER_CC1E;                 //Enable Channel1 output
	TIM1->PSC = 0;
	TIM1->ARR = MOTOR_TIMER_PERIOD - 1;
	TIM1->CCR1 = 10;
	TIM1->BDTR |= TIM_BDTR_MOE;
}

void initMotor() {
	initMotorTimer();
}

void increaseMotorSpeed(uint16_t step) {
    uint16_t tmp = TIM1->CCR1;
    uint16_t maxDuty = 100;

    if (step > (maxDuty - tmp)) {
        tmp = maxDuty;
    } else {
        tmp += step;
    }
    TIM1->CCR1 = tmp;
}

void decreaseMotorSpeed(uint16_t step) {
    uint16_t tmp = TIM1->CCR1;

    if (step > tmp) {
        tmp = 0;
    } else {
        tmp -= step;
    }
    TIM1->CCR1 = tmp;
}

void enableMotor() {
    GPIOB->ODR |= (1 << 12);
    TIM1->CR1 |= TIM_CR1_CEN;
}

void disableMotor() {
	TIM1->CR1 &= ~TIM_CR1_CEN;
    GPIOB->ODR &= ~(1 << 12);
}
