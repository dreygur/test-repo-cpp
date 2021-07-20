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
#ifndef __RADIO_H__
#define __RADIO_H__

#define RF_TIMEOUT	550	//Defines the timeout of the RF receiving. In ms.

/* Includes ------------------------------------------------------------------*/

#include "common.h"

/* Exported typedef -----------------------------------------------------------*/

/* Exported define ------------------------------------------------------------*/

/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

/* Exported functions ---------------------------------------------------------*/

RADIO_ERR Radio_Init(void);
uint8_t RF_Routine(void);
void EndOfReceiveRF(void);

#endif  /* __RADIO_H__ */

/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/
