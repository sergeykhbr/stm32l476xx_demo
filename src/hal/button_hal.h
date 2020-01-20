/*
 * button_hal.h
 *
 *  Created on: 7 нояб. 2019 г.
 *      Author: vasiliy.tsarevskiy
 */

#ifndef BUTTON_HAL_H_
#define BUTTON_HAL_H_

void buttonsPollTask(uint32_t parameter);
uint32_t buttonsGetState(void);

#endif /* BUTTON_HAL_H_ */
