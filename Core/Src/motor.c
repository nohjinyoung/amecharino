/*
 * motor.c
 *
 *  Created on: Mar 2, 2025
 *      Author: user
 */

#include "motor.h"

void Move(int controlcmd){



	switch(controlcmd){
		case FORWARD:
			Forward();
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 0);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1);
			break;
		case BACKWARD:
			Backward();
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 1);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);
			break;
		case RIGHT:
			Right();
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 0);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);
			break;
		case LEFT:
			Left();
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 1);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1);
			break;
		case CW:
			Cw();
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 1);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);
			break;
		case CCW:
			Ccw();
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 1);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 1);
			break;
		case STOP:
			Stop();
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 0);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);
			break;
		default:
			Stop();
			break;
		}
}

void Forward()
{
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8,GPIO_PIN_SET); //1 앞쪽 좌
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7,GPIO_PIN_RESET);// 2 앞쪽 우
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9,GPIO_PIN_SET); //3 뒤쪽 좌
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1,GPIO_PIN_RESET); //4 뒤쪽 우

	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); //1
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); //2
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); //3
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4); //4
}

void Backward()
{
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8,GPIO_PIN_RESET); //1 앞쪽 좌
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7,GPIO_PIN_SET);// 2 앞쪽 우
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9,GPIO_PIN_RESET); //3 뒤쪽 좌
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1,GPIO_PIN_SET); //4 뒤쪽 우

	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); //1
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); //2
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); //3
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4); //4
}

void Right()
{
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8,GPIO_PIN_SET); //1 앞쪽 좌
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7,GPIO_PIN_SET);// 2 앞쪽 우
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9,GPIO_PIN_SET); //3 뒤쪽 좌
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1,GPIO_PIN_SET); //4 뒤쪽 우

	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); //1
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); //2
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); //3
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4); //4
}

void Left()
{
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8,GPIO_PIN_RESET); //1 앞쪽 좌
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7,GPIO_PIN_RESET);// 2 앞쪽 우
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9,GPIO_PIN_SET); //3 뒤쪽 좌
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1,GPIO_PIN_SET); //4 뒤쪽 우

	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); //1
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); //2
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); //3
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4); //4
}

void Cw()
{
	//HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1,GPIO_PIN_SET);
	//HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7,GPIO_PIN_SET);

	//HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	//HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
}

void Ccw()
{
	//HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1,GPIO_PIN_RESET);
	//HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7,GPIO_PIN_RESET);


	//HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	//HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
}

void Stop()
{

	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_4);


}

void Motor_Init(){
	TIM2->CCR1 = SPEED;
	TIM2->CCR2 = SPEED;
	TIM2->CCR3 = SPEED;
	TIM2->CCR4 = SPEED;
}
