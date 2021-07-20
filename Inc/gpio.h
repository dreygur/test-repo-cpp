/* ========================================
*
* Copyright AIO Systems, 2018
* Written by Novodes for AIO Systems
* All Rights Reserved
* UNPUBLISHED, LICENSED SOFTWARE.
*
* CONFIDENTIAL AND PROPRIETARY INFORMATION
* WHICH IS THE PROPERTY OF AIO Systems.
*
* ========================================
*/

/* [] BEGINNING OF FILE */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H__
#define __GPIO_H__

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"
#include "main.h"
#include "common.h"
#include "stm32l0xx_hal_gpio.h"

/* Exported typedef -----------------------------------------------------------*/
typedef enum
{
	Red_LED,		//output
	Yellow_LED,		//output
	Green_LED,		//output
	Blue_LED,		//output
	Jumper3,		//input
	V_BAT,			//ADC input
	Jumper2,		//input
	IO2,			//high-z
	IO1,			//high-z
	SPI2_CS,		//output
	SPI1_NNS,		//output
	U_BTN,			//input interrupt
	VDD_PER_EN,		//output
	EN_Vsys,        //output
	Jumper5,		//input
	EN_12V,			//output
	RS485_DE1,		//output
	RS485_RE1,		//output
	RS485_RE2,		//output
	DB_3V_MCU_EN,	//output
	EN_MCPU,		//output
	PG_PS,			//input
	Jumper1,		//input
	Jumper4,		//input	
	GDO0,			//input interrupt
	IO4,			//high-z
	IO3,			//high-z
	MCU_DB_3V,		//output
	AN_IN,			//ADC input
	RS485_DE2		//output
}GPIO_pins;

typedef struct
{
	uint32_t      Pin;    //for pin selection
	GPIO_TypeDef  *GPIO_PORT;  //for port selection
}GPIO_def;

typedef enum
{
	LOW = 0,
	HIGH = 1
}GPIO_State;

/* Exported define ------------------------------------------------------------*/

#define GPIO_PINS_USED_NUM  30      // the number of GPIO pins used in the system as inputs and outputs

#define RF 1u			//YBC: Used by GW_BR_CommRF_OrMB flag.
#define MB 0u			//YBC: Used by GW_BR_CommRF_OrMB flag.

/* Exported macro -------------------------------------------------------------*/


/* Exported variables ---------------------------------------------------------*/

extern bool GW_BR_CommRF_OrMB;		//YBC: This flag is the selector between MB comm or RF comm between the GW and the BR.

extern  GPIO_def GPIO_ARRAY[GPIO_PINS_USED_NUM];

/* Exported functions ---------------------------------------------------------*/

void GPIO_Init(void);
void GPIO_SetVal(GPIO_pins GPIO_Index, GPIO_State State);
void GPIO_ToggleVal(GPIO_pins GPIO_Index);
uint8_t GPIO_ReadVal(GPIO_pins GPIO_Index);
void LedBlinkNTimes(GPIO_pins gpioIndex, uint32_t delay, uint8_t times);
void AllLedsBlink(uint32_t delay, uint8_t times);

void GPIO_Init4LowPower(void);

#endif /* __GPIO_H__ */

/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/

