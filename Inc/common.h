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
/**
******************************************************************************
* @file           : common.h
* @brief          : This file should include relevant header files of the
					application and contain general global variables and
					definitions that are used by many files.
******************************************************************************
**/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __COMMON_H__
#define __COMMON_H__

/* Includes ------------------------------------------------------------------*/

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "logger.h"
#include "usart.h"
#include "receive_interrupt.h"
#include "parameters.h"

/* Exported typedef -----------------------------------------------------------*/

typedef uint8_t byte;
typedef uint8_t BOOL;
typedef uint8_t bool;

typedef enum RADIO_ERR
{

	RADIO_OK = 1,
	RADIO_NOT_CONNECTED,
	RADIO_NOT_IDLE,
	RADIO_NOT_RX_STATE,
	RADIO_NOT_TX_STATE,
	RADIO_NOT_SENT

} RADIO_ERR;

typedef uint32_t Tick_Counter;	// this is for defining a global definition for the Tick_Counter (any variable that uses the Get_Tick() function). The rational for this is because there may be systems that the definition may change (either uint32_t or uint64_t) so here it would be easier to change and adapt when porting code between systems.

/* Exported define ------------------------------------------------------------*/

#define ENABLE_WATCH_DOG       // enable this if you would like to enable the watchdog in the system
#define ENABLE_DEBUG_MODE		// enable this if you would like to enable parts of code used only for debugging

#define RF_ALL_PAYLOADS_MAX_SIZE 0xFF

#define DEVICE_ID_RF_1	10
#define DEVICE_ID_RF_2 	8

#define FAIL	1
#define PASS	0	// it is set to zero here because in the HAL of ST the HAL_OK is equal to 0 so we want to be consistent. 

#define	FALSE	0
#define TRUE	1

#define OK		0x01
#define NOT_OK	0x00

#define BRIDGE 0
#define GATEWAY 1

#define BYTE_SHIFT			8u

#define bit(b) (1UL << (b))
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

#define ONE_MICROSEC_CYCLE  32 //1000 / (1 \ 32 * 1000000) * 1000000

#define LSI_FREQUENCY	37000	// internal oscillator - it is equal ~39Khz according to the datasheet (but there can be a serious drift ob +4% and -10% and the nominal value can range between 25Khz and 50Khz.
#define LSE_FREQUENCY	32768	// external oscillator

/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

extern uint8_t RF_RXBuffer[RF_ALL_PAYLOADS_MAX_SIZE];
extern uint8_t RF_RXBufferSize;
extern uint8_t BR_Mode_GW_Or_BR;

/* Exported functions ---------------------------------------------------------*/

void Disable_Interrupts(void);
void Enable_Interrupts(void);
void SystemReset(void);

#endif  /* __COMMON_H__ */

/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/
