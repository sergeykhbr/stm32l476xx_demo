#ifndef SOUND_H_
#define SOUND_H_

#include <inttypes.h>

typedef enum {
    sound_silence,
    sound_beep,
    sound_keybeep,
    sound_alarm,
    sound_hialarm,
    sound_state_last
} sound_state_t;

typedef struct {
    uint8_t phase;
    uint32_t *duty;
} wavestep_t;

void initSound();
void soundSetLevel(uint8_t level);
void soundBeep();
void soundKeyBeep();
void soundAlarm();
void soundHiAlarm();
void soundStopAlarm();
void soundControlHandler();
void soundWaveformHandler();

#endif /* SOUND_H_ */
