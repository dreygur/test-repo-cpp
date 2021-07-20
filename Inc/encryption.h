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
#ifndef __ENCRYPTION_H__
#define __ENCRYPTION_H__

/* Includes ------------------------------------------------------------------*/

#include "common.h"

/* Exported typedef -----------------------------------------------------------*/

/* Exported define ------------------------------------------------------------*/

#define ENCRYPTION_TIMEOUT_VALUE  100        // [msec] timeout period for the encryption operation when it is polling based

/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

//extern CRYP_HandleTypeDef hcryp;

/* Exported functions ---------------------------------------------------------*/

void Encrypt_Data(uint8_t *InputArray, uint16_t Byte_Num, uint8_t *EncryptedArray);
void Decrypt_Data(uint8_t *EncryptedArray, uint16_t Byte_Num, uint8_t *DecryptedArray);

#endif /* __ENCRYPTION_H__ */

/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/
