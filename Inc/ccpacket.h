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
#ifndef __CCPACKET_H__
#define __CCPACKET_H__

/* Includes ------------------------------------------------------------------*/

#include "common.h"

/* Exported define ------------------------------------------------------------*/

/**
* Buffer and data lengths
*/
#define CCPACKET_BUFFER_LEN        64
#define CCPACKET_DATA_LEN          10

/* Exported typedef -----------------------------------------------------------*/

/**
* Class: CCPACKET
*
* Description:
* CC1101 data packet class
*/
typedef struct _CCPACKET
{

	/**
	* Data length
	*/
	unsigned char   length;

	/**
	* Data buffer
	*/
	unsigned char data[CCPACKET_DATA_LEN];

	/**
	* CRC OK flag
	*/
	bool crc_ok;

	/**
	* Received Strength Signal Indication
	*/
	unsigned char rssi;

	/**
	* Link Quality Index
	*/
	unsigned char lqi;

} CCPACKET;

/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

/* Exported functions ---------------------------------------------------------*/


#endif /* __CCPACKET_H__ */

/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/

