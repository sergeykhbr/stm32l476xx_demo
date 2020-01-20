#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>

void initMotor();
void enableMotor();
void disableMotor();
void increaseMotorSpeed(uint16_t step);
void decreaseMotorSpeed(uint16_t step);

#endif //MOTOR_H
