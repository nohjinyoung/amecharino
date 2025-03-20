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
    __HAL_TIM_SET_COUNTER(&htim5, 0);  // ???���? 카운?�� 초기?��
    while (__HAL_TIM_GET_COUNTER(&htim5) < us);  // �??��?�� us ?��?�� ??�?
}

int _write(int file, char *ptr, int len)
{
    HAL_UART_Transmit(&huart3, (uint8_t *)ptr, len, HAL_MAX_DELAY);
    return len;
}
void Distance()
{
	// --- 초음파 1 ---
	HAL_GPIO_WritePin(Trig_GPIO_Port, Trig_Pin, GPIO_PIN_SET);
	microDelay(10);
	HAL_GPIO_WritePin(Trig_GPIO_Port, Trig_Pin, GPIO_PIN_RESET);

	while (HAL_GPIO_ReadPin(Echo_GPIO_Port, Echo_Pin) == GPIO_PIN_RESET);
	uint32_t startTime = __HAL_TIM_GET_COUNTER(&htim5);
	while (HAL_GPIO_ReadPin(Echo_GPIO_Port, Echo_Pin) == GPIO_PIN_SET);
	uint32_t endTime = __HAL_TIM_GET_COUNTER(&htim5);

	uint32_t timeElapsed = endTime - startTime;
	distance = (timeElapsed * 0.0343f) / 2;

	// **초음파 1 끝난 후 약간 대기 (중요)**
	microDelay(10);

	// --- 초음파 2 ---
	HAL_GPIO_WritePin(Trig2_GPIO_Port, Trig2_Pin, GPIO_PIN_SET);
	microDelay(10);
	HAL_GPIO_WritePin(Trig2_GPIO_Port, Trig2_Pin, GPIO_PIN_RESET);

	while (HAL_GPIO_ReadPin(Echo2_GPIO_Port, Echo2_Pin) == GPIO_PIN_RESET);
	uint32_t startTime2 = __HAL_TIM_GET_COUNTER(&htim5);
	while (HAL_GPIO_ReadPin(Echo2_GPIO_Port, Echo2_Pin) == GPIO_PIN_SET);
	uint32_t endTime2 = __HAL_TIM_GET_COUNTER(&htim5);

	uint32_t timeElapsed2 = endTime2 - startTime2;
	distance2 = (timeElapsed2 * 0.0343f) / 2;

	// 두 값 출력
	printf("%.2f, %.2f\r\n", distance, distance2);
	HAL_Delay(50);  // 100ms 대기



}
