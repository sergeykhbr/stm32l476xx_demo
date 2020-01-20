#include "buttons.h"
#include "button_config.h"
#include "taskmgr.h"
#include "string.h"
#include "preinclude.h"


#define BUTTON_PRESS_TIME 400u
#define BUTTON_LONG_PRESS_TIME 1500u
#define BUTTON_STICK_PRESS_TIME 5000u

const uint8_t normalAntiBounceAttempts = 5;
const uint8_t maxAntiBounceAttempt = 20;
const uint8_t timeBetweenChecks = 5; // ms



typedef struct{
	buttonState_t state;
	buttonState_t tempState;
	buttonPress_t pressType;
	uint8_t antiBounceAttempts;
	uint8_t antiBounceSummary;
	task_t callBack;
	buttonInit_t init;
	buttonGetState_t getState;
	taskId_t taskId;
}buttonData_t;

static buttonData_t button[Button_Last];

static void buttonTaskProcess(uint32_t parameter);
static void buttonPressTask(uint32_t parameter);

// Функция инциализации модуля
void buttonInit(const buttonInitStruct_t *buttonInitData, uint8_t buttonNumber){
	memset(button, 0, sizeof(button));

	for(uint8_t i = 0; i < buttonNumber; ++i)
	{
		uint8_t buttonId = buttonInitData[i].name;
		if(button[buttonId].callBack == 0)
		{
			button[buttonId].state = BUTTON_STATE_UNDEFINED;
			button[buttonId].tempState = BUTTON_STATE_UNDEFINED;
			button[buttonId].pressType = BUTTON_PRESS_NONE;
			button[buttonId].antiBounceAttempts = 0;
			button[buttonId].antiBounceSummary = 0;

			button[buttonId].callBack = buttonInitData[i].callBack;
			button[buttonId].init = buttonInitData[i].init;
			button[buttonId].getState = buttonInitData[i].getState;

			// Вопрос корректности. Надо подумать, что должно быть при включении устройства.
			//
			button[buttonId].init(btON);
			button[buttonId].state = button[buttonId].getState();
		}
		else
		{
			// TODO generate assert
		}
	}
}

void setButtonHandler(uint8_t buttonId, task_t callBack) {
    if (callBack) {
        button[buttonId].callBack = callBack;
    }
}
void buttonInterruptHandler(uint8_t buttonId){
// Выключили прерывания кнопочки
  button[buttonId].init(btOFF);
  // С отлюченными прерываниями можно и обработать антидребезг. Сделано для уменьшения сработки прерываний
  osTaskAdd(buttonTaskProcess, buttonId, 0);
}


static antiBounse_t antiBounce(uint8_t buttonId) {
	antiBounse_t result = antiBounceFail;
	buttonState_t state = button[buttonId].getState();

	if(button[buttonId].tempState == BUTTON_STATE_UNDEFINED)
	{
		button[buttonId].antiBounceSummary = 0;
		button[buttonId].tempState = state;
	}
	//TODO check current state and compare

	if(state == button[buttonId].tempState){
		button[buttonId].antiBounceAttempts++;
		button[buttonId].antiBounceSummary++;
		if(button[buttonId].antiBounceAttempts >= normalAntiBounceAttempts){
			result = antiBounceOk;
			button[buttonId].antiBounceAttempts = 0;
			button[buttonId].state = button[buttonId].tempState;
			button[buttonId].tempState = BUTTON_STATE_UNDEFINED;
		}
		else{
			result = antiBounceNext;
		}
		if(button[buttonId].antiBounceSummary >= maxAntiBounceAttempt){
			// TODO add assert for mechanical noise
		}
	}
	else{
		button[buttonId].antiBounceAttempts = 0;
	}
	return result;
}


static void buttonTaskProcess(uint32_t parameter){
	uint8_t buttonId = (uint8_t)parameter;

	antiBounse_t antiBounceState = antiBounce(buttonId);
	if(antiBounceState == antiBounceNext){
		osTaskAdd(buttonTaskProcess, buttonId, timeBetweenChecks);
	}
	else if(antiBounceState == antiBounceOk){
		//Зафиксировали нажатие или отжатие
		// Нужно анализировать
		// Включаем кнопку
		button[buttonId].init(btON);
		if(button[buttonId].state == BUTTON_PRESSED){
			// Кнопку нажали
			button[buttonId].pressType = BUTTON_PRESS_SHORT;
			// Варианты Нажатие до 500 мс
			// Длинное нажатие от 500 до 1500 мс
			// Залипание более 1500мс
			// Ждем
			TIME_T taskTime = BUTTON_PRESS_TIME - (button[buttonId].antiBounceSummary * timeBetweenChecks); // TODO check validity
			osTaskAdd(buttonPressTask, buttonId, taskTime);
		}
		else{
			// Кнопку отжали
			// Нажатие окончилось
			if(button[buttonId].pressType != BUTTON_PRESS_NONE){
				osTaskDelId(button[buttonId].taskId, buttonPressTask);
			}
			// Generate event
			osTaskAdd(button[buttonId].callBack, (uint32_t)button[buttonId].pressType, 0);
			button[buttonId].pressType = BUTTON_PRESS_NONE;

		}
	}
}

static void buttonPressTask(uint32_t parameter){
	uint8_t buttonId = (uint8_t)parameter;
	if(button[buttonId].pressType == BUTTON_PRESS_SHORT){
		button[buttonId].pressType = BUTTON_PRESS_LONG;
		TIME_T taskTime = BUTTON_LONG_PRESS_TIME - BUTTON_PRESS_TIME;
		button[buttonId].taskId = osTaskAdd(buttonPressTask, buttonId, taskTime);
	}
	else if(button[buttonId].pressType == BUTTON_PRESS_LONG){
		button[buttonId].pressType = BUTTON_PRESS_STICK;
		TIME_T taskTime = BUTTON_LONG_PRESS_TIME - BUTTON_PRESS_TIME;
		button[buttonId].taskId = osTaskAdd(buttonPressTask, buttonId, taskTime);

		osTaskAdd(button[buttonId].callBack, (uint32_t)button[buttonId].pressType, 0);
	}
}

