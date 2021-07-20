/* ========================================
 *
 * Copyright AIO SYSTEMS, 2018
 * Written by Novodes for AIO SYSTEMS
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF AIO SYSTEMS.
 *
 * ========================================
*/

/* [] BEGINNING OF FILE */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RECEIVE_INTERRUPT_H__
#define __RECEIVE_INTERRUPT_H__

/* Includes ------------------------------------------------------------------*/

#include "common.h"
#include "modbus_app_layer.h"


/* Exported typedef -----------------------------------------------------------*/

/* Exported define ------------------------------------------------------------*/

// UART related definitions:
#define LOGGER_COMMAND_HANDLER_UART 	LPUART1  // define which usart is for printing logs
#define LOGGER_COMMAND_BUFFER_SIZE     30     // the size of the buffer for receiving commands
#define LOGGER_COMMAND_DATA_SIZE       2       // the size of the command data array. This array should only receive one byte and transfer it to the command buffer. So technically we only need one byte but it is set as two just in case. 
#define LOGGER_TRANSMIT_POLLING_TIMEOUT 50

// Main Controller (MC) channel
#define MAIN_CONTROLLER_CHANNEL 	USART1	// define which USART or LPUART is for managing the communication with the main controller. 
#define MC_COMMAND_BUFFER_SIZE     100     // the size of the buffer for receiving commands
#define MC_COMMAND_DATA_SIZE       2       // the size of the command data array. This array should only receive one byte and transfer it to the command buffer. So technically we only need one byte but it is set as two just in case. 
#define MC_TRANSMIT_POLLING_TIMEOUT 50
/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

/* Exported functions ---------------------------------------------------------*/

void Init_Receive_Interrupt(void);
void EndOfReceiveUART(void);
void CommandHandler(void);


#endif /* __RECEIVE_INTERRUPT_H__ */

/************************ (C) COPYRIGHT AIO SYSTEMS *****END OF FILE****/
