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
#ifndef __PC_GW_PROTOCOL_FUNCTIONS_H__
#define __PC_GW_PROTOCOL_FUNCTIONS_H__

/* Includes ------------------------------------------------------------------*/

#include "common.h"

/* Exported typedef -----------------------------------------------------------*/

/* Exported define ------------------------------------------------------------*/

#define SIZE_OF_UNIQUE_ID_OF_SLOT		4			//Size is bytes
#define LOCATION_OF_NB_OF_BYTES			6			//The location of number of bytes to follow in FC=16 MB command.
#define PAYLOAD_BYTE_NB_0						7
#define PAYLOAD_BYTE_NB_1						8
#define PAYLOAD_BYTE_NB_2						9
#define PAYLOAD_BYTE_NB_3						10

#define NB_OF_NODES_REGISTERING_REGISTERS		100


/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

//extern CRYP_HandleTypeDef hcryp;

/* Exported functions ---------------------------------------------------------*/
uint8_t AddingRemovingNodeAnalyze(uint8_t *IncomingArr);
void RemoveOldNode(uint8_t NodeID);
void SignNewNode(uint32_t UniqueNodeID);

#endif /* __PC_GW_PROTOCOL_FUNCTIONS__ */

/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/