/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    tim.h
  * @brief   This file contains all the function prototypes for
  *          the tim.c file
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
#ifndef __TIM_H__
#define __TIM_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern TIM_HandleTypeDef htim1;

extern TIM_HandleTypeDef htim2;

extern TIM_HandleTypeDef htim3;

extern TIM_HandleTypeDef htim4;

extern TIM_HandleTypeDef htim5;

extern TIM_HandleTypeDef htim9;

extern TIM_HandleTypeDef htim10;

extern TIM_HandleTypeDef htim11;

/* USER CODE BEGIN Private defines */
  //define motors
#define A_MOTOR_TIM htim2
#define A_MOTOR_CHANNEL_BI TIM_CHANNEL_2
#define A_MOTOR_CHANNEL_FI TIM_CHANNEL_1

#define B_MOTOR_TIM htim2
#define B_MOTOR_CHANNEL_BI TIM_CHANNEL_2
#define B_MOTOR_CHANNEL_FI TIM_CHANNEL_1

#define C_MOTOR_TIM htim2
#define C_MOTOR_CHANNEL_BI TIM_CHANNEL_2
#define C_MOTOR_CHANNEL_FI TIM_CHANNEL_1

#define D_MOTOR_TIM htim2
#define D_MOTOR_CHANNEL_BI TIM_CHANNEL_2
#define D_MOTOR_CHANNEL_FI TIM_CHANNEL_1
/* USER CODE END Private defines */

void MX_TIM1_Init(void);
void MX_TIM2_Init(void);
void MX_TIM3_Init(void);
void MX_TIM4_Init(void);
void MX_TIM5_Init(void);
void MX_TIM9_Init(void);
void MX_TIM10_Init(void);
void MX_TIM11_Init(void);

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __TIM_H__ */

