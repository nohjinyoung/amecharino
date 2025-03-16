/*
 * motor.h
 *
 *  Created on: Mar 2, 2025
 *      Author: user
 */
#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "main.h"
#include "tim.h"

#define SPEED 800

typedef enum {
	STOP,
	FORWARD,
	RIGHT,
	BACKWARD,
	LEFT,
	CW,
	CCW
}CONTROLLER_SIGNAL;

void Move(int controlcmd);
void Forward();
void Backward();
void Right();
void Left();
void Cw();
void Ccw();
void Stop();
void Motor_Init();



#endif /* INC_MOTOR_H_ */
