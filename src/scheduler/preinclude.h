/*
 * preinclude.h
 *
 *  Created on: 1 нояб. 2019 г.
 *      Author: vasiliy.tsarevskiy
 */

#ifndef PREINCLUDE_H_
#define PREINCLUDE_H_
#include "stdbool.h"
#include "stddef.h"
#include "stdint.h"

#include "stm32l4xx.h"

typedef unsigned long int TIME_T;

#define ENTER_CRITICAL_SECTION() __disable_irq()
#define EXIT_CRITICAL_SECTION()  __enable_irq()

#endif /* PREINCLUDE_H_ */
