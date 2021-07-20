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
#ifndef __MODBUS_IMPLEM_H__
#define __MODBUS_IMPLEM_H__

/* Includes ------------------------------------------------------------------*/

#include <stdint.h>

/* Exported typedef -----------------------------------------------------------*/

/* Exported define ------------------------------------------------------------*/

/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

/* Exported functions ---------------------------------------------------------*/

void Modbus_WriteSingleRegister(uint32_t startAddress, uint16_t *value,uint16_t size);
void Modbus_WriteSingleCoil(uint32_t startAddress, uint16_t value); 
//extern int writeTOFlashTable(uint32_t Address, uint16_t Value, uint16_t size)
int writeTOFlashTableMultiData(uint32_t Address, uint32_t *Value, uint32_t size);

#endif  /* __MODBUS_IMPLEM_H__ */

/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/
