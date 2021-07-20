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
#ifndef __BOOTLOADER_SUPPORT_H__
#define __BOOTLOADER_SUPPORT_H__

/* Includes ------------------------------------------------------------------*/

#include "common.h"

/* Exported typedef -----------------------------------------------------------*/

/* Exported define ------------------------------------------------------------*/

/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

extern uint8_t BOOTLOADER_PROCESS_START_FLAG;

/* Exported functions ---------------------------------------------------------*/

void Prepare_For_Bootloading(void);
void Begin_Bootloading(void);
void Save_Image_Size_To_ExternalFlash(uint16_t binary_image_bytes_received);
uint16_t Calc_And_Save_Binary_Image_CRC(void);

#endif /* __BOOTLOADER_SUPPORT_H__ */

/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/
