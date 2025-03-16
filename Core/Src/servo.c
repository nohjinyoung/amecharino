/*
 * servo.c
 *
 *  Created on: Mar 4, 2025
 *      Author: user
 */


#include "servo.h"

void servo_right_left()
{
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 100);
	 __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 100);
	 __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_3, 50);
	 __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_4, 50);

    HAL_Delay(1000); // 1000ms

	       //1.5ms Pwm - Servo motor arm rotates to 90 degree
		       //1.5ms Pwm - Servo motor arm rotates to 90 degree
    __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 50);
   	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 50);
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_3, 100);
	 __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_4, 100);


}

void servo_left_right()
{


    HAL_Delay(1000); // 1000ms


		       //1.5ms Pwm - Servo motor arm rotates to 90 degree
		HAL_Delay(1000); // 1000ms



}
