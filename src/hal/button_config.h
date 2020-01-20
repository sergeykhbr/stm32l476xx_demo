#ifndef BUTTON_CONFIG_H_
#define BUTTON_CONFIG_H_

#include "buttons.h"

typedef enum{
    Button_6,
    Button_7,
    Button_8,
    Button_9,
    Button_0,
    Button_Info,
    Button_Prime,
    Button_Lock,

    Button_1,
    Button_2,
    Button_3,
    Button_4,
    Button_5,
    Button_Point,
    Button_Ok,
    Button_No,

    Button_Power,
    Button_Last
} buttonName_t;

const buttonInitStruct_t *getButtonsConfig(void);

#endif /* BUTTON_CONFIG_H_ */
