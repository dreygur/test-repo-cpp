/* ========================================
 *
 * Copyright Magneto, 2018
 * Written by Novodes for Magneto
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Magneto.
 *
 * ========================================
*/

/* [] BEGINNING OF FILE */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __POWER_MANAGEMENT_H__
#define __POWER_MANAGEMENT_H__

/* Includes ------------------------------------------------------------------*/

#include "common.h"

/* Exported typedef -----------------------------------------------------------*/

/* Exported define ------------------------------------------------------------*/

/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

typedef enum
{
  LOW_POWER_RUN,
  SLEEP,
  LOW_POWER_SLEEP,
  STOP_MODE,
  STANDBY_MODE
}LowPowerModeTypeDef;

/* Exported functions ---------------------------------------------------------*/

void SystemPower_Config(void);
void Enter_Low_Power_Mode(LowPowerModeTypeDef low_power_mode, uint32_t total_sleep_time);

#endif /* __POWER_MANAGEMENT_H__ */

/************************ (C) COPYRIGHT Magneto *****END OF FILE****/
