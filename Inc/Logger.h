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
#ifndef __LOGGER_H__
#define __LOGGER_H__

/* Includes ------------------------------------------------------------------*/

#include "common.h"
#include "receive_interrupt.h"

/* Exported typedef -----------------------------------------------------------*/

/* Exported define ------------------------------------------------------------*/

//###############################################################################
// Logger prints (to UART) related definitions:
#define ENABLE_LOGS     // to enable the log prints in the entire program

#ifdef ENABLE_LOGS
	#define INTERNAL_SYSTEM // to enable all the log prints related to the internal system components (WD, RTC, etc.)
	#define EXTERNAL_PERIPHERALS  // to enable all the log prints related to the external peripherals of the system (buzzer, LEDs, external flash, etc.)
	#define DEBUG_LOGS				// to enable printing logs related to sections of code used only for debug
#endif 

#ifdef ENABLE_LOGS
    #ifdef INTERNAL_SYSTEM
			#define WATCHDOG_LOGS			// to enable the log prints related to the iWatchdog
			#define GENERAL_INDICATIONS     // to enable general indications in the system (system init, etc.)
			#define RTC_LOGS				// to enable logs related to the RTC (Real Time Clock)
			#define POWER_MANAGEMENT_LOGS	// to enable logs related to the power management (low power modes, etc.)
			#define USART1_INDICATIONS		// to enable logs related to the USART1 driver
			#define COMMAND_HANDLER_LOGS	// to enable logs related to the command handler
			#define PARAMETERS_INDICATIONS	// to enable logs related to the parameters stored in the EEPROM
			#define ENABLE_MODBUS_LOGS	// to enable the logs related to modbus driver functions
			#define ENABLE_MODBUS_APP_LOGS	// to enable the logs related to modbus application layer functions
			#define ENABLE_BOOTLOADING_LOGS	// to enable the logs related to the bootloading process
			#define ENCRYPTION_LOGS					// to enable encryption logs
    #endif
    #ifdef EXTERNAL_PERIPHERALS
			#define RF_INDICATIONS			// to enable the log prints related to the RF
			#define FLASH_LOGGER			// to enable the log prints related to the external flash
    #endif
	#ifdef DEBUG_LOGS
			#define ENABLE_FILL_SECTOR_ADVANCED_LOGS // to enable the log prints related to the external flash FILL_SECTOR function
	#endif
#endif
//###############################################################################

// UART related definitions:
#define LOGGER_UART_TRANSMIT_POLLING_TIMEOUT   50      // [milliseconds] the UART transmit (polling mode) timeout that is used for logging

/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

/* Exported functions ---------------------------------------------------------*/
#ifdef ENABLE_DEBUG_MODE
	void Command_Analyzer(uint8_t *dataPtr);
	void EXTERNAL_FLASH_FILL_SECTOR(uint16_t sector_num, uint8_t data, uint32_t write_byte_num, uint16_t delay);
	void system_tests(void);
	void Encryption_Test(void);
	void EXTERNAL_FLASH_GetDeviceID(void);
	void EXTERNAL_FLASH_AUTO_FILL_SECTORS(uint16_t sector_num, uint8_t data, uint32_t write_byte_num, uint16_t delay);
	void PrintFromFlashHandler(uint8_t *dataPtr);
#endif

#endif /* __LOGGER_H__ */

/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/
