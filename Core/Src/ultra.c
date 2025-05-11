/*
 * ultra.c
 *
 *  Created on: Mar 2, 2025
 *      Author: user
 */
#include "ultra.h"

float distance = 0.0f;
float distance2 = 0.0f;
void microDelay(uint16_t us)
{
    __HAL_TIM_SET_COUNTER(&htim5, 0);
    while (__HAL_TIM_GET_COUNTER(&htim5) < us);
}

int _write(int file, char *ptr, int len)
{
    HAL_UART_Transmit(&huart3, (uint8_t *)ptr, len, HAL_MAX_DELAY);
    return len;
}

void Distance()
{
	HAL_GPIO_WritePin(Trig_GPIO_Port, Trig_Pin, GPIO_PIN_SET);
	 microDelay(10);  // 10µs ??�?
	 HAL_GPIO_WritePin(Trig_GPIO_Port, Trig_Pin, GPIO_PIN_RESET);

	 // Echo ?? HIGH 감�? (초음?�� 발사 ?��?��)
	 while (HAL_GPIO_ReadPin(Echo_GPIO_Port, Echo_Pin) == GPIO_PIN_RESET);
	 uint32_t startTime = __HAL_TIM_GET_COUNTER(&htim5);  // Echo ?��?�� ?���? ?���? 기록

	 // Echo ?? LOW 감�? (초음?�� 반사 ?��?�� ?���?)
	 while (HAL_GPIO_ReadPin(Echo_GPIO_Port, Echo_Pin) == GPIO_PIN_SET);
	 uint32_t endTime = __HAL_TIM_GET_COUNTER(&htim5);

	 // ?���? 차이 계산
	 uint32_t timeElapsed = endTime - startTime;

	 // 거리 계산 (?��?�� 343m/s -> 0.0343 cm/µs)
	 distance = (timeElapsed * 0.0343f) / 2;

	 // 결과 출력
	 printf("Distance: %.2f cm\r\n", distance);

	 HAL_Delay(50);



}

float GetDistance(GPIO_TypeDef* TRIG_PORT, uint16_t TRIG_PIN, GPIO_TypeDef* ECHO_PORT, uint16_t ECHO_PIN)
{

    // Trigger 핀 HIGH
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);
    microDelay(10);
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);

    // Echo 핀 올라갈 때까지 대기
    while (HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN) == GPIO_PIN_RESET)
    {

    }
   	 uint32_t startTime = __HAL_TIM_GET_COUNTER(&htim5);  // Echo ?��?�� ?���? ?���? 기록

   	 // Echo ?? LOW 감�? (초음?�� 반사 ?��?�� ?���?)
   	 while (HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN) == GPIO_PIN_SET)
   	 {

   	 }
   	 uint32_t endTime = __HAL_TIM_GET_COUNTER(&htim5);

   	uint32_t timeElapsed = endTime - startTime;
    // 시간 -> 거리 변환 (초음파 340m/s)
   	float distance = (timeElapsed * 0.0343f) / 2;

    return distance;
}
