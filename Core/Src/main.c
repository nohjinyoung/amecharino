/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "motor.h"
#include <MPUXX50.h>
#include "servo.h"
#include "ultra.h"
#include "string.h"
#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define TRUE  1
#define FALSE 0
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t serialBuf[100];
char buf[50];
uint8_t rx_data;
uint8_t gyro_flag;
uint8_t Forward_flag;
uint8_t turn_flag;
uint8_t Left_turn_flag;
uint8_t Right_turn_flag;
uint8_t Uart_flag;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_USART3_UART_Init();
  MX_I2C1_Init();
  MX_TIM5_Init();
  MX_TIM3_Init();
  MX_TIM11_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

  //MPU6050_Initialization();
  Motor_Init();
  HAL_UART_Receive_IT(&huart3, &rx_data, 1); //아르코 마커러 부터 인덱스 값 받아오는거임
  HAL_TIM_Base_Start(&htim5);




//  if (MPU_begin(&hi2c1, AD0_LOW, AFSR_4G, GFSR_500DPS, 0.98, 0.004) == TRUE)
//    {
//      sprintf((char *)serialBuf, "Succeed!\r\n");
//      HAL_UART_Transmit(&huart3, serialBuf, strlen((char *)serialBuf), HAL_MAX_DELAY);
//    }
//    else
//    {
//      sprintf((char *)serialBuf, "ERROR!\r\n");
//      HAL_UART_Transmit(&huart3, serialBuf, strlen((char *)serialBuf), HAL_MAX_DELAY);
//    }
//   sprintf((char *)serialBuf, "CALIBRATING...\r\n");
//   HAL_UART_Transmit(&huart3, serialBuf, strlen((char *)serialBuf), HAL_MAX_DELAY);
//   MPU_calibrateGyro(&hi2c1, 1500);


   //MPU interrupt 전용
   //HAL_TIM_Base_Start_IT(&htim11);
   //HAL_PWR_EnableSleepOnExit();
   //HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
  		   //1.5ms Pwm - Servo motor arm rotates to 90 degree
  			   //1.5ms Pwm - Servo motor arm rotates to 90 degree

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  //자이로 센서 확인 코드
//	  	  MPU_calcAttitude(&hi2c1);
//	  	  //생략가능
//		  sprintf((char *)serialBuf, "yaw: %.1f\r\n",  attitude.y);
//		  HAL_UART_Transmit(&huart3, serialBuf, strlen((char *)serialBuf), HAL_MAX_DELAY);
//		  HAL_Delay(100);
		  //
	  if(Uart_flag == 1)
	  {
		  sprintf((char *)serialBuf, "1");
		  HAL_UART_Transmit(&huart3, serialBuf, strlen((char *)serialBuf), HAL_MAX_DELAY);
		  HAL_UART_Transmit(&huart2, serialBuf, strlen((char *)serialBuf), HAL_MAX_DELAY);
		  HAL_Delay(1000);

	  }
		  if (Forward_flag == 1)
		  {
		      Forward();

		      if (attitude.y > 0)
		      {
		          Right_turn();
		      }
		      else if (attitude.y < 0)
		      {
		          Left_turn();
		      }

		      if (attitude.y == 0)
		      {
		          Forward();
		      }
		  }

		  else if(turn_flag == 1 && Left_turn_flag == 1)
	  	  {
	  		Left_turn();
	  		if(attitude.y >= 3.5)
	  		{
	  			Stop();
	  			turn_flag = 0;
	  			Left_turn_flag = 0;
	  		}
	  	  }
	  	  else if(turn_flag == 1 && Right_turn_flag == 1)
	  	  {
	  		Right_turn();
			if(attitude.y <= -3.5)
			{
				Stop();
				turn_flag = 0;
				Left_turn_flag = 0;
			}
	  	  }




//	  float distance1 = GetDistance(Trig_GPIO_Port, Trig_Pin, Echo_GPIO_Port, Echo_Pin);
//	  float distance2 = GetDistance(Trig2_GPIO_Port, Trig2_Pin, Echo2_GPIO_Port, Echo2_Pin);
//	  float distance3 = GetDistance(Trig3_GPIO_Port, Trig3_Pin, Echo3_GPIO_Port, Echo3_Pin);
//	  float distance4 = GetDistance(Trig4_GPIO_Port, Trig4_Pin, Echo4_GPIO_Port, Echo4_Pin);
//	  sprintf(buf, "D1: %.2f cm\r\n", distance1);
//	  HAL_UART_Transmit(&huart3, (uint8_t*)buf, strlen(buf), HAL_MAX_DELAY);
//	  HAL_Delay(100);

	  //Forward();
	 //HAL_Delay(1000);
	  //Backward();
	  //HAL_Delay(1000);


	  //HAL_Delay(5000);


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  // Check if timer has triggered and update attitude
  if (htim == &htim11)
  {
    HAL_ResumeTick();
//    MPU_calcAttitude(&hi2c1);
//    sprintf((char *)serialBuf, "yaw: %.1f\r\n",  attitude.y);
//    HAL_UART_Transmit(&huart3, serialBuf, strlen((char *)serialBuf), HAL_MAX_DELAY);

//    float mag_yaw = readMagYaw(&hi2c1);
//	sprintf((char *)serialBuf, "Mag Yaw: %.2f deg\r\n", mag_yaw);
//	HAL_UART_Transmit(&huart3, serialBuf, strlen((char *)serialBuf), HAL_MAX_DELAY);

    HAL_SuspendTick();
  }
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART3)
  {
    if (rx_data == '1')
    {

    	Uart_flag = 1;

    }
    else if (rx_data == '2') {

    	Backward();

    }
    else if (rx_data == '3') {
    	//Left_turn();
		Left_turn_flag = 1;
		turn_flag = 1;
    	attitude.y = 0;
	}
    else if (rx_data == '4') {
    	//Right_turn();
    	Right_turn_flag = 1;
    	turn_flag = 1;
		attitude.y = 0;

	}
    else if (rx_data == '5') {
    	Left();

	}
    else if (rx_data == '6') {
    	Right();

	}

    else
    {
    	Stop();
    }

    // 다음 수신 대기
    HAL_UART_Receive_IT(&huart3, &rx_data, 1);
  }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
