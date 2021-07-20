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
#ifndef __MODBUS_DRIVER_H__
#define __MODBUS_DRIVER_H__


#define ENABLE_CHECKSUM_FOR_NODE_PARAM

/* Includes ------------------------------------------------------------------*/

#include "common.h"
#include "BIT.h"

/* Exported typedef -----------------------------------------------------------*/

/* Exported define ------------------------------------------------------------*/

#define REGISTER_BYTE_NUM		2				// [byte #] the number of bytes within each register in the modbus memory space

#define REGISTER_ADDRESS_MSB		2				// the index number within a modbus command array where the MSB bits of the register address are positioned
#define REGISTER_ADDRESS_LSB		3				// the index number within a modbus command array where the LSB bits of the register address are positioned
#define DATA_ADDRESS_MSB		4				// the index number within a modbus command array where the MSB bits of the data are positioned (relevant for single register write command only)
#define DATA_ADDRESS_LSB		5				// the index number within a modbus command array where the LSB bits of the data are positioned (relevant for single register write command only)

//#############################################################

/*Array location defines*/
#define ARR_LOC_0				0u
#define ARR_LOC_1				1u
#define ARR_LOC_2				2u
#define ARR_LOC_3				3u
#define ARR_LOC_4				4u
#define ARR_LOC_5				5u
#define ARR_LOC_6				6u
#define ARR_LOC_7				7u
#define ARR_LOC_8				8u
#define ARR_LOC_9				9u
#define ARR_LOC_10			10u

#define MB_FC_3_RESPONSE_EXTRA_DATA	5			//This defines the number of bytes returned in function code 3 of MB protocol beside the data required.
#define MB_FC_3_SIZE		8u

#define MB_FC_10_EXTRA_DATA	9				//The number of bytes in every MB command 16, not include payload.

#define RESPOSNE_LENGTH_SINGLE_REGISTER_WRITE				8	// [bytes #] the number of bytes in the response to the modbus command write single register
#define RESPOSNE_LENGTH_MULTIPLE_REGISTER_WRITE			8	// [bytes #] the number of bytes in the response to the modbus command write multiple registers

#define MAX_BYTE_NUMBER_TO_WRITE		257			// the maximum number of bytes that can be written in a multiple register write command

/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

//extern uint8_t SizeOfLastQuery;

/* Exported functions ---------------------------------------------------------*/

uint16_t CalcCRC(uint8_t * buf, uint16_t size);
uint8_t MB_Apply_ReadHoldingRegisters(uint8_t *IncomingArr);
uint8_t MB_Apply_WriteSingleRegister(uint8_t * IncomingArr);
uint8_t MB_Apply_WriteMultipleRegisters(uint8_t * IncomingArr);


#endif /* __MODBUS_DRIVER_H__ */

/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/
