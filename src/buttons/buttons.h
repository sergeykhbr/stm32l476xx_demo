#ifndef BUTTONS_H_
#define BUTTONS_H_
#include "stdint.h"
#include "taskmgr.h"

typedef enum{
	btOFF = 0,
	btON,
}buttonInitState_t;

typedef enum{
  BUTTON_PRESS_NONE,
  BUTTON_PRESS_SHORT,
  BUTTON_PRESS_LONG,
  BUTTON_PRESS_STICK,
}buttonPress_t;

typedef enum {
  BUTTON_NOT_PRESSED,                                                           /**< кнопка не нажата */
  BUTTON_PRESSED,                                                               /**< кнопка нажата */
  BUTTON_STATE_UNDEFINED // OFF or breaked
}buttonState_t;

typedef void (*buttonInit_t)(buttonInitState_t); // функция инициализации кнопки
typedef buttonState_t (*buttonGetState_t)(void);

typedef struct{
	buttonInit_t init;
	buttonGetState_t getState;
	task_t callBack;
	uint8_t name;
} buttonInitStruct_t;

typedef enum{
	antiBounceOk,
	antiBounceFail,
	antiBounceNext,
} antiBounse_t;

void setButtonHandler(uint8_t buttonId, task_t callBack);
void buttonInit(const buttonInitStruct_t *buttonInitData, uint8_t buttonNumber);
void buttonInterruptHandler(uint8_t buttonId);

#endif /* BUTTONS_H_ */
