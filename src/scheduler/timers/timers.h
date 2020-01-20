#ifndef TIMERS_H
#define TIMERS_H 

#include "stdint.h"
#include "preinclude.h"

typedef enum{
  tsOff,
  tsActive,
} timerState_t;

typedef void (*timerHandler_t)(void);


void timerInit		(uint32_t resolution, timerHandler_t handler);
void timerDeinit    (void);

TIME_T timerElapseSinceLastTime(void);

void timerReset		(uint32_t interval);
uint32_t timerDelete	(void);
uint32_t timerValue		(void);
uint32_t timerElapse 	(void);
uint32_t timerRemain(void);

#endif //TIMERS
