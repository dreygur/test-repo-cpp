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
#ifndef __RTC_H__
#define __RTC_H__

/* Includes ------------------------------------------------------------------*/

#include "common.h"

/* Exported typedef -----------------------------------------------------------*/

/* Exported define ------------------------------------------------------------*/

/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

extern volatile uint8_t RTC_WakeUpInterrupt_Flag;

/* Exported functions ---------------------------------------------------------*/

void Set_RTC_Wakeup(uint32_t period);
void Disable_RTC_Wakeup(void);
void Set_RTC_Alarm(uint32_t period, uint32_t alarm);
void Disable_RTC_Alarm(uint32_t alarm);
void Set_RTCAlarmTypeDef(RTC_AlarmTypeDef exported_alarm, uint32_t alarm);
void HAL_RTCEx_WakeUpTimerEventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc);
void HAL_RTCEx_AlarmBEventCallback(RTC_HandleTypeDef *hrtc);

#endif /* __RTC_H__ */

/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/
