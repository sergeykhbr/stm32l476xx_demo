/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include "cortexm/ExceptionHandlers.h"

// ----------------------------------------------------------------------------
void WWDG_IRQHandler();
void PVD_PVM_IRQHandler();
void TAMP_STAMP_IRQHandler();
void RTC_WKUP_IRQHandler();
void FLASH_IRQHandler();
void RCC_IRQHandler();
void EXTI0_IRQHandler();
void EXTI1_IRQHandler();
void EXTI2_IRQHandler();
void EXTI3_IRQHandler();
void EXTI4_IRQHandler();
void DMA1_Channel1_IRQHandler();
void DMA1_Channel2_IRQHandler();
void DMA1_Channel3_IRQHandler();
void DMA1_Channel4_IRQHandler();
void DMA1_Channel5_IRQHandler();
void DMA1_Channel6_IRQHandler();
void DMA1_Channel7_IRQHandler();
void ADC1_2_IRQHandler();
void CAN1_TX_IRQHandler();
void CAN1_RX0_IRQHandler();
void CAN1_RX1_IRQHandler();
void CAN1_SCE_IRQHandler();
void EXTI9_5_IRQHandler();
void TIM1_BRK_TIM15_IRQHandler();
void TIM1_UP_TIM16_IRQHandler();
void TIM1_TRG_COM_TIM17_IRQHandler();
void TIM1_CC_IRQHandler();
void TIM2_IRQHandler();
void TIM3_IRQHandler();
void TIM4_IRQHandler();
void I2C1_EV_IRQHandler();
void I2C1_ER_IRQHandler();
void I2C2_EV_IRQHandler();
void I2C2_ER_IRQHandler();
void SPI1_IRQHandler();
void SPI2_IRQHandler();
void USART1_IRQHandler();
void USART2_IRQHandler();
void USART3_IRQHandler();
void EXTI15_10_IRQHandler();
void RTC_Alarm_IRQHandler();
void DFSDM1_FLT3_IRQHandler();
void TIM8_BRK_IRQHandler();
void TIM8_UP_IRQHandler();
void TIM8_TRG_COM_IRQHandler();
void TIM8_CC_IRQHandler();
void ADC3_IRQHandler();
void FMC_IRQHandler();
void SDMMC1_IRQHandler();
void TIM5_IRQHandler();
void SPI3_IRQHandler();
void UART4_IRQHandler();
void UART5_IRQHandler();
void TIM6_DAC_IRQHandler();
void TIM7_IRQHandler();
void DMA2_Channel1_IRQHandler();
void DMA2_Channel2_IRQHandler();
void DMA2_Channel3_IRQHandler();
void DMA2_Channel4_IRQHandler();
void DMA2_Channel5_IRQHandler();
void DFSDM1_FLT0_IRQHandler();
void DFSDM1_FLT1_IRQHandler();
void DFSDM1_FLT2_IRQHandler();
void COMP_IRQHandler();
void LPTIM1_IRQHandler();
void LPTIM2_IRQHandler();
void OTG_FS_IRQHandler();
void DMA2_Channel6_IRQHandler();
void DMA2_Channel7_IRQHandler();
void LPUART1_IRQHandler();
void QUADSPI_IRQHandler();
void I2C3_EV_IRQHandler();
void I2C3_ER_IRQHandler();
void SAI1_IRQHandler();
void SAI2_IRQHandler();
void SWPMI1_IRQHandler();
void TSC_IRQHandler();
void LCD_IRQHandler();
void RNG_IRQHandler();
void FPU_IRQHandler();
// ----------------------------------------------------------------------------

extern unsigned int _estack;

typedef void
(* const pHandler)(void);

// ----------------------------------------------------------------------------

// The vector table.
// This relies on the linker script to place at correct location in memory.

__attribute__ ((section(".isr_vector"),used))
pHandler __isr_vectors[] =
  { //
    (pHandler) &_estack,                          // The initial stack pointer
        Reset_Handler,                            // The reset handler

        NMI_Handler,                              // The NMI handler
        HardFault_Handler,                        // The hard fault handler

#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
        MemManage_Handler,                        // The MPU fault handler
        BusFault_Handler,// The bus fault handler
        UsageFault_Handler,// The usage fault handler
#else
        0, 0, 0,				  // Reserved
#endif
        0,                                        // Reserved
        0,                                        // Reserved
        0,                                        // Reserved
        0,                                        // Reserved
        SVC_Handler,                              // SVCall handler
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
        DebugMon_Handler,                         // Debug monitor handler
#else
        0,					  // Reserved
#endif
        0,                                        // Reserved
        PendSV_Handler,                           // The PendSV handler
        SysTick_Handler,                          // The SysTick handler

        // ----------------------------------------------------------------------
        // DEVICE vectors
        WWDG_IRQHandler,
        PVD_PVM_IRQHandler,
        TAMP_STAMP_IRQHandler,
        RTC_WKUP_IRQHandler,
        FLASH_IRQHandler,
        RCC_IRQHandler,
        EXTI0_IRQHandler,
        EXTI1_IRQHandler,
        EXTI2_IRQHandler,
        EXTI3_IRQHandler,
        EXTI4_IRQHandler,
        DMA1_Channel1_IRQHandler,
        DMA1_Channel2_IRQHandler,
        DMA1_Channel3_IRQHandler,
        DMA1_Channel4_IRQHandler,
        DMA1_Channel5_IRQHandler,
        DMA1_Channel6_IRQHandler,
        DMA1_Channel7_IRQHandler,
        ADC1_2_IRQHandler,
        CAN1_TX_IRQHandler,
        CAN1_RX0_IRQHandler,
        CAN1_RX1_IRQHandler,
        CAN1_SCE_IRQHandler,
        EXTI9_5_IRQHandler,
        TIM1_BRK_TIM15_IRQHandler,
        TIM1_UP_TIM16_IRQHandler,
        TIM1_TRG_COM_TIM17_IRQHandler,
        TIM1_CC_IRQHandler,
        TIM2_IRQHandler,
        TIM3_IRQHandler,
        TIM4_IRQHandler,
        I2C1_EV_IRQHandler,
        I2C1_ER_IRQHandler,
        I2C2_EV_IRQHandler,
        I2C2_ER_IRQHandler,
        SPI1_IRQHandler,
        SPI2_IRQHandler,
        USART1_IRQHandler,
        USART2_IRQHandler,
        USART3_IRQHandler,
        EXTI15_10_IRQHandler,
        RTC_Alarm_IRQHandler,
        DFSDM1_FLT3_IRQHandler,
        TIM8_BRK_IRQHandler,
        TIM8_UP_IRQHandler,
        TIM8_TRG_COM_IRQHandler,
        TIM8_CC_IRQHandler,
        ADC3_IRQHandler,
        FMC_IRQHandler,
        SDMMC1_IRQHandler,
        TIM5_IRQHandler,
        SPI3_IRQHandler,
        UART4_IRQHandler,
        UART5_IRQHandler,
        TIM6_DAC_IRQHandler,
        TIM7_IRQHandler,
        DMA2_Channel1_IRQHandler,
        DMA2_Channel2_IRQHandler,
        DMA2_Channel3_IRQHandler,
        DMA2_Channel4_IRQHandler,
        DMA2_Channel5_IRQHandler,
        DFSDM1_FLT0_IRQHandler,
        DFSDM1_FLT1_IRQHandler,
        DFSDM1_FLT2_IRQHandler,
        COMP_IRQHandler,
        LPTIM1_IRQHandler,
        LPTIM2_IRQHandler,
        OTG_FS_IRQHandler,
        DMA2_Channel6_IRQHandler,
        DMA2_Channel7_IRQHandler,
        LPUART1_IRQHandler,
        QUADSPI_IRQHandler,
        I2C3_EV_IRQHandler,
        I2C3_ER_IRQHandler,
        SAI1_IRQHandler,
        SAI2_IRQHandler,
        SWPMI1_IRQHandler,
        TSC_IRQHandler,
        LCD_IRQHandler,
        0,
        RNG_IRQHandler,
        FPU_IRQHandler
    // TODO: rename and add more vectors here
    };

// ----------------------------------------------------------------------------

// Processor ends up here if an unexpected interrupt occurs or a specific
// handler is not present in the application code.

void __attribute__ ((section(".after_vectors")))
Default_Handler(void) {
    while (1) {
    }
}

void __attribute__ ((weak, section(".after_vectors"))) WWDG_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) PVD_PVM_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) TAMP_STAMP_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) RTC_WKUP_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) FLASH_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) RCC_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) EXTI0_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) EXTI1_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) EXTI2_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) EXTI3_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) EXTI4_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DMA1_Channel1_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DMA1_Channel2_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DMA1_Channel3_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DMA1_Channel4_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DMA1_Channel5_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DMA1_Channel6_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DMA1_Channel7_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) ADC1_2_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) CAN1_TX_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) CAN1_RX0_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) CAN1_RX1_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) CAN1_SCE_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) EXTI9_5_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) TIM1_BRK_TIM15_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) TIM1_UP_TIM16_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) TIM1_TRG_COM_TIM17_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) TIM1_CC_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) TIM2_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) TIM3_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) TIM4_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) I2C1_EV_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) I2C1_ER_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) I2C2_EV_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) I2C2_ER_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) SPI1_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) SPI2_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) USART1_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) USART2_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) USART3_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) EXTI15_10_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) RTC_Alarm_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DFSDM1_FLT3_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) TIM8_BRK_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) TIM8_UP_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) TIM8_TRG_COM_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) TIM8_CC_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) ADC3_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) FMC_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) SDMMC1_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) TIM5_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) SPI3_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) UART4_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) UART5_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) TIM6_DAC_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) TIM7_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DMA2_Channel1_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DMA2_Channel2_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DMA2_Channel3_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DMA2_Channel4_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DMA2_Channel5_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DFSDM1_FLT0_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DFSDM1_FLT1_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DFSDM1_FLT2_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) COMP_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) LPTIM1_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) LPTIM2_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) OTG_FS_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DMA2_Channel6_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) DMA2_Channel7_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) LPUART1_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) QUADSPI_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) I2C3_EV_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) I2C3_ER_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) SAI1_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) SAI2_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) SWPMI1_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) TSC_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) LCD_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) RNG_IRQHandler() {
                          Default_Handler();
                      };

void __attribute__ ((weak, section(".after_vectors"))) FPU_IRQHandler() {
                          Default_Handler();
                      };

// ----------------------------------------------------------------------------
