#include <stm32l4xx.h>
#include <leds.h>

void initLeds() {
    ledOff(ledRed);
    ledOff(ledGreen);
}

void ledOff(led_t led) {
    switch (led) {
    case ledRed:
        GPIOB->ODR &= ~(1 << 9);
        break;
    case ledGreen:
        GPIOB->ODR &= ~(1 << 8);
        break;
    }
}

void ledOn(led_t led) {
    switch (led) {
    case ledRed:
        GPIOB->ODR |= 1 << 9;
        break;
    case ledGreen:
        GPIOB->ODR |= 1 << 8;
        break;
    }
}

void ledToggle(led_t led) {
    switch (led) {
    case ledRed:
        GPIOB->ODR ^= (1 << 9);
        break;
    case ledGreen:
        GPIOB->ODR ^= (1 << 8);
        break;
    }
}
