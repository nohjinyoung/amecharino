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
			break;
		case BACKWARD:
			Backward();
			break;
		case RIGHT:
			Right();
			break;
		case LEFT:
			Left();
			break;
		case CW:
			Cw();
			break;
		case CCW:
			Ccw();
			break;
		case STOP:
			Stop();
			break;
		default:
			Stop();
			break;
		}
}

void Forward()
{
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8,GPIO_PIN_SET); //1 뒤쪽 우
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7,GPIO_PIN_RESET);// 2 뒤쪽 좌
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9,GPIO_PIN_SET); //3 앞쪽 우
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1,GPIO_PIN_RESET); //4 앞쪽 좌

	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); //1
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); //2
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); //3
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4); //4

}

void Backward()
{
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8,GPIO_PIN_RESET); //1 뒤쪽 우
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7,GPIO_PIN_SET);// 2 뒤쪽 좌
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9,GPIO_PIN_RESET); //3 앞쪽 우
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1,GPIO_PIN_SET); //4 앞쪽 좌

	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); //1
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); //2
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); //3
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4); //4
}

void Left()
{
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8,GPIO_PIN_SET); //1 뒤쪽 우
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7,GPIO_PIN_SET);// 2 뒤쪽 좌
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9,GPIO_PIN_RESET); //3 앞쪽 우
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1,GPIO_PIN_RESET); //4 앞쪽 좌

	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); //1
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); //2
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); //3
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4); //4
}

void Right()
{
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8,GPIO_PIN_RESET); //1 뒤쪽 우
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7,GPIO_PIN_RESET);// 2 뒤쪽 좌
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9,GPIO_PIN_SET); //3 앞쪽 우
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1,GPIO_PIN_SET); //4 앞쪽 좌

	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); //1
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); //2
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); //3
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4); //4
}

void Right_turn()
{

	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8,GPIO_PIN_SET); //1 뒤쪽 우
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7,GPIO_PIN_SET);// 2 뒤쪽 좌
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9,GPIO_PIN_SET); //3 앞쪽 우
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1,GPIO_PIN_SET); //4 앞쪽 좌
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
}

void Left_turn()
{


	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8,GPIO_PIN_RESET); //1 뒤쪽 우
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7,GPIO_PIN_RESET);// 2 뒤쪽 좌
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9,GPIO_PIN_RESET); //3 앞쪽 우
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_1,GPIO_PIN_RESET); //4 앞쪽 좌
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
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
    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);	//BLDC모터 구동 준비
    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);

	TIM2->CCR1 = SPEED;
	TIM2->CCR2 = SPEED;
	TIM2->CCR3 = SPEED;
	TIM2->CCR4 = SPEED;
}
