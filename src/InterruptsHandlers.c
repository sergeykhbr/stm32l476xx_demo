#include <sound.h>
#include <stm32l4xx.h>

void TIM6_DAC_IRQHandler() {
    if (TIM6->SR & TIM_SR_UIF) {
        TIM6->SR &= ~TIM_SR_UIF;
        soundControlHandler();
    }
}

void TIM3_IRQHandler() {
    if (TIM3->SR & TIM_SR_UIF) {
        TIM3->SR &= ~TIM_SR_UIF;
        soundWaveformHandler();
    }
}
