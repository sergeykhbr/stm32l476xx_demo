#include "power_hal.h"
#include <stm32l4xx.h>

void powerOff() {
    GPIOC->ODR &= ~(1 << 2);
}
