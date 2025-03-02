/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Trig_Pin GPIO_PIN_2
#define Trig_GPIO_Port GPIOE
#define Cw2_Pin GPIO_PIN_7
#define Cw2_GPIO_Port GPIOF
#define Cw1_Pin GPIO_PIN_8
#define Cw1_GPIO_Port GPIOF
#define Cw3_Pin GPIO_PIN_9
#define Cw3_GPIO_Port GPIOF
#define Echo_Pin GPIO_PIN_0
#define Echo_GPIO_Port GPIOA
#define Cw4_Pin GPIO_PIN_1
#define Cw4_GPIO_Port GPIOG
#define Echo2_Pin GPIO_PIN_11
#define Echo2_GPIO_Port GPIOD
#define Trig2_Pin GPIO_PIN_12
#define Trig2_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
