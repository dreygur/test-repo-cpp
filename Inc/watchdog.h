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
#ifndef __WATCHDOG_H__
#define __WATCHDOG_H__

/* Includes ------------------------------------------------------------------*/

#include "common.h"

/* Exported typedef -----------------------------------------------------------*/

/* Exported define ------------------------------------------------------------*/

#define WATCHDOG_RESET_PERIOD 10        // time in seconds for the period for which if the watchdog is not reset it causes a SW reset

/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

//extern IWDG_HandleTypeDef hiwdg;

/* Exported functions ---------------------------------------------------------*/

void WD_Period_Set(uint8_t seconds);
void WD_Reload(void);
void Check_WD_Reset(void);

#endif /* __WATCHDOG_H__ */

/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/
