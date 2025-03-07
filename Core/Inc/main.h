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
#define A_MOTOR_FI_Pin GPIO_PIN_5
#define A_MOTOR_FI_GPIO_Port GPIOE
#define A_MOTOR_BI_Pin GPIO_PIN_6
#define A_MOTOR_BI_GPIO_Port GPIOE
#define B_ENCODER_3_Pin GPIO_PIN_0
#define B_ENCODER_3_GPIO_Port GPIOA
#define B_ENCODER_4_Pin GPIO_PIN_1
#define B_ENCODER_4_GPIO_Port GPIOA
#define B_MOTOR_BI_Pin GPIO_PIN_9
#define B_MOTOR_BI_GPIO_Port GPIOE
#define B_MOTOR_FI_Pin GPIO_PIN_11
#define B_MOTOR_FI_GPIO_Port GPIOE
#define C_MOTOR_BI_Pin GPIO_PIN_13
#define C_MOTOR_BI_GPIO_Port GPIOE
#define C_MOTOR_FI_Pin GPIO_PIN_14
#define C_MOTOR_FI_GPIO_Port GPIOE
#define C_ENCODER_3_Pin GPIO_PIN_15
#define C_ENCODER_3_GPIO_Port GPIOA
#define C_ENCODER_4_Pin GPIO_PIN_3
#define C_ENCODER_4_GPIO_Port GPIOB
#define D_ENCODER_3_Pin GPIO_PIN_4
#define D_ENCODER_3_GPIO_Port GPIOB
#define D_ENCODER_4_Pin GPIO_PIN_5
#define D_ENCODER_4_GPIO_Port GPIOB
#define A_ENCODER_3_Pin GPIO_PIN_6
#define A_ENCODER_3_GPIO_Port GPIOB
#define A_ENCODER_4_Pin GPIO_PIN_7
#define A_ENCODER_4_GPIO_Port GPIOB
#define D_MOTOR_BI_Pin GPIO_PIN_8
#define D_MOTOR_BI_GPIO_Port GPIOB
#define D_MOTOR_FI_Pin GPIO_PIN_9
#define D_MOTOR_FI_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
