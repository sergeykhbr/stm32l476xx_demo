/** \addtogroup timers
 *  @{
 */
#include "preinclude.h"
#include "timers.h"
#include "stm32l4xx.h"

typedef struct
{
	TIME_T         ticks;
	TIME_T         lastAskTime;
	uint32_t       resolution;
	timerState_t   state;
	timerHandler_t handler;
}timer_t;

static timer_t timer_data;

void timerInit(uint32_t resolution, timerHandler_t handler)
{
	timer_data.resolution = 0;
	timer_data.ticks = 0;
	timer_data.lastAskTime = 0;
	timer_data.state = tsActive;
	timer_data.handler = handler;
	SysTick_Config(SystemCoreClock/resolution);
}

void timerDeinit(void)
{
	SysTick->CTRL &= ~(SysTick_CTRL_ENABLE_Msk);
	timer_data.state = tsOff;
}


void timerReset(uint32_t interval)
{

}


//returns raw timer value
uint32_t timerValue(void)
{
    return 0;
}

uint32_t timerElapse(void)
{
    return 0;
}

uint32_t timerRemain(void)
{
    return 0;
}

/**
 * Функция требует использования только при внешнем отключении прерываний!
*/
TIME_T timerElapseSinceLastTime(void)
{
	TIME_T result = timer_data.ticks - timer_data.lastAskTime;
	timer_data.lastAskTime = timer_data.ticks;
	return result;
}


void SysTick_Handler(void)
{
	// Check operation. Is it atomic?
	timer_data.ticks++;
	timer_data.handler();
}

/**
 * @}
 */
