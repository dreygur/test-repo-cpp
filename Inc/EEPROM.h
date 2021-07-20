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
#ifndef __EEPROM_H__
#define __EEPROM_H__

/* Includes ------------------------------------------------------------------*/

#include "common.h"

/* Exported typedef -----------------------------------------------------------*/

/* Exported define ------------------------------------------------------------*/

//EEPROM and FLASH Address Definitions:
//The size is 2kbytes
#ifdef STM32L063xx
  #define FLASH_EEPROM_START_ADDR       0x08080000   /* Start @ of EEPROM bank*/
  #define FLASH_EEPROM_END_ADDR         0x080807FF   /* End @ of EEPROM bank*/
#else
  #ifdef STM32L152xE
    #define FLASH_EEPROM_START_ADDR       0x08080000   /* Start @ of EEPROM bank 1*/
    #define FLASH_EEPROM_END_ADDR         0x08081FFF   /* End @ of EEPROM bank 1*/
    //there is also bank 2 but it is not supported yet in this driver
  #endif
#endif

/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

/* Exported functions ---------------------------------------------------------*/

void EEPROM_WRITE_WORD(uint32_t relative_address, uint32_t data);
void EEPROM_WRITE_BYTE(uint32_t relative_address, uint32_t data);
uint32_t EEPROM_READ_WORD(uint32_t relative_address);
uint8_t  EEPROM_READ_BYTE(uint32_t relative_address);
void EEPROM_READ_BYTE_SECTOR(uint8_t *arrayPtr,uint16_t arraySize,uint16_t initialAddress);

#endif /* __EEPROM_H__ */

/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/
