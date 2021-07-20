/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

#include "stm32l0xx_hal.h"
#include "stm32l0xx_hal_dma.h"
#include "stm32l0xx_hal_cryp.h"
#include "stm32l0xx_hal_rng.h"
#include "stm32l0xx_hal_adc.h"
#include "stm32l0xx_hal_iwdg.h"
#include "stm32l0xx_hal_rtc.h"
#include "stm32l0xx_hal_spi.h"
#include "stm32l0xx_hal_i2c.h"
#include "stm32l0xx_hal_uart.h"

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define GDO0_Pin GPIO_PIN_13
#define GDO0_GPIO_Port GPIOC
#define GDO0_EXTI_IRQn EXTI4_15_IRQn
#define IO4_Pin GPIO_PIN_0
#define IO4_GPIO_Port GPIOC
#define IO3_Pin GPIO_PIN_1
#define IO3_GPIO_Port GPIOC
#define MCU_DB_3V_Pin GPIO_PIN_2
#define MCU_DB_3V_GPIO_Port GPIOC
#define AN_IN_Pin GPIO_PIN_0
#define AN_IN_GPIO_Port GPIOA
#define RS485_DE2_Pin GPIO_PIN_1
#define RS485_DE2_GPIO_Port GPIOA
#define Red_LED_Pin GPIO_PIN_4
#define Red_LED_GPIO_Port GPIOA
#define Yellow_LED_Pin GPIO_PIN_5
#define Yellow_LED_GPIO_Port GPIOA
#define Green_LED_Pin GPIO_PIN_6
#define Green_LED_GPIO_Port GPIOA
#define Blue_LED_Pin GPIO_PIN_7
#define Blue_LED_GPIO_Port GPIOA
#define Jumper3_Pin GPIO_PIN_0
#define Jumper3_GPIO_Port GPIOB
#define V_BAT_Pin GPIO_PIN_1
#define V_BAT_GPIO_Port GPIOB
#define Jumper2_Pin GPIO_PIN_2
#define Jumper2_GPIO_Port GPIOB
#define IO2_Pin GPIO_PIN_10
#define IO2_GPIO_Port GPIOB
#define IO1_Pin GPIO_PIN_11
#define IO1_GPIO_Port GPIOB
#define SPI2_CS_Pin GPIO_PIN_12
#define SPI2_CS_GPIO_Port GPIOB
#define U_BTN_Pin GPIO_PIN_6
#define U_BTN_GPIO_Port GPIOC
#define U_BTN_EXTI_IRQn EXTI4_15_IRQn
#define VDD_PER_EN_Pin GPIO_PIN_8
#define VDD_PER_EN_GPIO_Port GPIOC
#define EN_Vsys_Pin GPIO_PIN_9
#define EN_Vsys_GPIO_Port GPIOC
#define Jumper5_Pin GPIO_PIN_8
#define Jumper5_GPIO_Port GPIOA
#define EN_12V_Pin GPIO_PIN_11
#define EN_12V_GPIO_Port GPIOA
#define RS485_DE1_Pin GPIO_PIN_12
#define RS485_DE1_GPIO_Port GPIOA
#define SPI1_NNS_Pin GPIO_PIN_15
#define SPI1_NNS_GPIO_Port GPIOA
#define RS485_RE1_Pin GPIO_PIN_10
#define RS485_RE1_GPIO_Port GPIOC
#define RS485_RE2_Pin GPIO_PIN_11
#define RS485_RE2_GPIO_Port GPIOC
#define DB_3V_MCU_EN_Pin GPIO_PIN_12
#define DB_3V_MCU_EN_GPIO_Port GPIOC
#define EN_MCPU_Pin GPIO_PIN_2
#define EN_MCPU_GPIO_Port GPIOD
#define PG_PS_Pin GPIO_PIN_6
#define PG_PS_GPIO_Port GPIOB
#define Jumper1_Pin GPIO_PIN_8
#define Jumper1_GPIO_Port GPIOB
#define Jumper4_Pin GPIO_PIN_9
#define Jumper4_GPIO_Port GPIOB

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
 #define USE_FULL_ASSERT    1U 

/* USER CODE BEGIN Private defines */

extern ADC_HandleTypeDef hadc;

extern CRYP_HandleTypeDef hcryp;

extern I2C_HandleTypeDef hi2c2;

extern IWDG_HandleTypeDef hiwdg;

extern UART_HandleTypeDef hlpuart1;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

extern RNG_HandleTypeDef hrng;

extern RTC_HandleTypeDef hrtc;

extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;
void SystemClock_Config(void);
void MX_AES_Init(void);

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
