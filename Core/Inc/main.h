/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "stm32f3xx_hal.h"

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
#define BTN_USER_Pin GPIO_PIN_13
#define BTN_USER_GPIO_Port GPIOC
#define CURR_FDBK3_Pin GPIO_PIN_0
#define CURR_FDBK3_GPIO_Port GPIOC
#define CURR_FDBK2_Pin GPIO_PIN_1
#define CURR_FDBK2_GPIO_Port GPIOC
#define TEMP_SENSE_Pin GPIO_PIN_2
#define TEMP_SENSE_GPIO_Port GPIOC
#define CURR_FDBK1_Pin GPIO_PIN_0
#define CURR_FDBK1_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define SPEED_IN_Pin GPIO_PIN_1
#define SPEED_IN_GPIO_Port GPIOB
#define LED_RED_Pin GPIO_PIN_2
#define LED_RED_GPIO_Port GPIOB
#define ENC_Z_Pin GPIO_PIN_10
#define ENC_Z_GPIO_Port GPIOB
#define LED_GREEN_Pin GPIO_PIN_13
#define LED_GREEN_GPIO_Port GPIOB
#define PH1_PWM_Pin GPIO_PIN_8
#define PH1_PWM_GPIO_Port GPIOA
#define PH2_PWM_Pin GPIO_PIN_9
#define PH2_PWM_GPIO_Port GPIOA
#define PH3_PWM_Pin GPIO_PIN_10
#define PH3_PWM_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define ENC_A_Pin GPIO_PIN_15
#define ENC_A_GPIO_Port GPIOA
#define PH1_EN_Pin GPIO_PIN_10
#define PH1_EN_GPIO_Port GPIOC
#define PH2_EN_Pin GPIO_PIN_11
#define PH2_EN_GPIO_Port GPIOC
#define PH3_EN_Pin GPIO_PIN_12
#define PH3_EN_GPIO_Port GPIOC
#define ENC_B_Pin GPIO_PIN_3
#define ENC_B_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
