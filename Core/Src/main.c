/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define STOP_HERE()    while(1);
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

const uint16_t sine[360] = {
     512, 521, 530, 539, 548, 557, 565, 574, 583, 592, 601, 610, 618, 627, 636, 644,
     653, 661, 670, 678, 687, 695, 703, 712, 720, 728, 736, 744, 752, 760, 768, 775,
     783, 790, 798, 805, 812, 820, 827, 834, 840, 847, 854, 861, 867, 873, 880, 886,
     892, 898, 903, 909, 915, 920, 925, 931, 936, 941, 945, 950, 955, 959, 963, 967,
     971, 975, 979, 982, 986, 989, 992, 995, 998,1001,1003,1006,1008,1010,1012,1014,
    1015,1017,1018,1019,1020,1021,1022,1022,1023,1023,1023,1023,1023,1022,1022,1021,
    1020,1019,1018,1017,1015,1014,1012,1010,1008,1006,1003,1001, 998, 995, 992, 989,
     986, 982, 979, 975, 971, 967, 963, 959, 955, 950, 945, 941, 936, 931, 925, 920,
     915, 909, 903, 898, 892, 886, 880, 873, 867, 861, 854, 847, 840, 834, 827, 820,
     812, 805, 798, 790, 783, 775, 768, 760, 752, 744, 736, 728, 720, 712, 703, 695,
     687, 678, 670, 661, 653, 644, 636, 627, 618, 610, 601, 592, 583, 574, 565, 557,
     548, 539, 530, 521, 512, 503, 494, 485, 476, 467, 459, 450, 441, 432, 423, 414,
     406, 397, 388, 380, 371, 363, 354, 346, 337, 329, 321, 312, 304, 296, 288, 280,
     272, 264, 256, 249, 241, 234, 226, 219, 212, 204, 197, 190, 184, 177, 170, 163,
     157, 151, 144, 138, 132, 126, 121, 115, 109, 104,  99,  93,  88,  83,  79,  74,
      69,  65,  61,  57,  53,  49,  45,  42,  38,  35,  32,  29,  26,  23,  21,  18,
      16,  14,  12,  10,   9,   7,   6,   5,   4,   3,   2,   2,   1,   1,   1,   1,
       1,   2,   2,   3,   4,   5,   6,   7,   9,  10,  12,  14,  16,  18,  21,  23,
      26,  29,  32,  35,  38,  42,  45,  49,  53,  57,  61,  65,  69,  74,  79,  83,
      88,  93,  99, 104, 109, 115, 121, 126, 132, 138, 144, 151, 157, 163, 170, 177,
     184, 190, 197, 204, 212, 219, 226, 234, 241, 249, 256, 264, 272, 280, 288, 296,
     304, 312, 321, 329, 337, 346, 354, 363, 371, 380, 388, 397, 406, 414, 423, 432,
     441, 450, 459, 467, 476, 485, 494, 503
};



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
  MX_USART2_UART_Init();
  MX_TIM2_Init();
  MX_ADC1_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
  printf("\r\nReset.\r\n");
  printf(__DATE__ " " __TIME__ "\r\n");

  printf("Starting Timers...\r\n");

  /* Start PWM channels on TIM1 */
  if (HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1) != HAL_OK)
   {
     printf("HAL_ERROR TIM1 Ch1 Start\r\n");
     STOP_HERE();
   }
  if (HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2) != HAL_OK)
   {
      printf("HAL_ERROR TIM1 Ch3 Start\r\n");
      STOP_HERE();
   }
  if (HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3) != HAL_OK)
   {
      printf("HAL_ERROR TIM1 Ch3 Start\r\n");
      STOP_HERE();
   }

  /* start encoder on TIM2 */
  if (HAL_TIM_Encoder_Start_IT(&htim2, TIM_CHANNEL_ALL) != HAL_OK)
  {
      printf("HAL_ERROR TIM2 start\r\n");
      STOP_HERE();
  }

  /* enable all 3 channels on motor driver IC */
  HAL_GPIO_WritePin(GPIOC, PH1_EN_Pin|PH2_EN_Pin|PH3_EN_Pin, GPIO_PIN_SET);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//  uint32_t last = 0xDEADBEEF;
//  uint32_t delay = 100;
  uint32_t phase = 0;
  while (1)
  {
      /* Get TIM2 current count value */
      // delay = htim2.Instance->CNT;
      // delay = (__HAL_TIM_GET_COUNTER(&htim2) >> 1);
      phase = (phase+1) % 360;

#define GAIN_DIVISOR 2
      uint32_t channel_a = sine[phase] / GAIN_DIVISOR;
      uint32_t channel_b = sine[(phase + 120) % 360] / GAIN_DIVISOR;
      uint32_t channel_c = sine[(phase + 240) % 360] / GAIN_DIVISOR;

//          printf("%d, %d, %d, %d\r\n", (int)phase, (int)channel_a, (int)channel_b, (int)channel_c);

       /* these should be back-to-back writes */
       /* TODO: Disable/enable the update event before/after writing timer CCR registers */
      __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, channel_a);
      __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2, channel_b);
      __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3, channel_c);

      HAL_Delay(1);

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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_TIM1;
  PeriphClkInit.Tim1ClockSelection = RCC_TIM1CLK_HCLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* Support printf() to STLINK UART by overwriting method from syscalls.c */
int _write(int file, char *ptr, int len)
{
    HAL_UART_Transmit(&huart2, (uint8_t *)ptr, (uint16_t)len, 1000);
    return len;
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
