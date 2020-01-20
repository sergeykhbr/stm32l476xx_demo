#ifndef LEDS_H
#define LEDS_H

typedef enum {
    ledRed,
    ledGreen
} led_t;

void initLeds();
void ledOn(led_t led);
void ledOff(led_t led);
void ledToggle(led_t led);

#endif //LEDS_H
