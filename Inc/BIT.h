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
#ifndef __BIT_H__
#define __BIT_H__

/* Includes ------------------------------------------------------------------*/
#include "common.h"
#include "external_flash.h"
#include "modbus_driver.h"

/* Exported typedef -----------------------------------------------------------*/

/* Exported define ------------------------------------------------------------*/

#define BIT_PASS 1
#define BIT_FAIL 0

#define BAT_VOLTAGE_LIMIT_FOR_BIT			2700

/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/
 
/* Exported function prototypes -----------------------------------------------*/

/* Exported functions ---------------------------------------------------------*/

uint8_t BIT_SPI_FlashTest(void);
uint8_t BIT_VoltageTest(void);
uint8_t BIT_ChecksumOfGW_Data(void);
uint8_t BIT_ChecksumOfNodesData(void);
uint8_t BIT_Tests(void);

#endif
/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/
