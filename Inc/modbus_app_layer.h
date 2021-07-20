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
#ifndef __MODBUS_APP_LAYER_H__
#define __MODBUS_APP_LAYER_H__

/* Includes ------------------------------------------------------------------*/

#include "common.h"

/* Exported typedef -----------------------------------------------------------*/

typedef enum
{
	// supported function codes
	MB_ReadCoils = 1,
	MB_ReadInputs = 2,
	MB_ReadHoldingRegisters = 3,
	MB_ReadInputRegisters = 4,
	MB_WriteSingleCoil = 5,
	MB_WriteSingleRegister = 6,
	MB_Diagnostics = 8,
	MB_DiagnosticsReturnQueryData = 0,
	MB_WriteMultipleCoils = 15,
	MB_WriteMultipleRegisters = 16,


	MB_MaximumDiscreteRequestResponseSize = 2040,
	MB_MaximumRegisterRequestResponseSize = 127,

	// modbus slave exception offset that is added to the function code, to flag an exception
	MB_ExceptionOffset = 128,

	// modbus slave exception codes
	MB_Acknowledge = 5,
	MB_SlaveDeviceBusy = 6,

	// default setting for number of retries for IO operations
	MB_DefaultRetries = 3,

	// default number of milliseconds to wait after encountering an ACKNOWLEGE or SLAVE DEVIC BUSY slave exception response.
	MB_DefaultWaitToRetryMilliseconds = 250,

	// default setting for IO timeouts in milliseconds
	MB_DefaultTimeout = 1000,

	// smallest supported message frame size (sans checksum)
	MB_MinimumFrameSize = 2,

	MB_CoilOn = 0xFF00,
	MB_CoilOff = 0x0000,

	// IP slaves should be addressed by IP
	MB_DefaultIpSlaveUnitId = 0,

	// An existing connection was forcibly closed by the remote host
	MB_ConnectionResetByPeer = 10054,

	// Existing socket connection is being closed
	MB_WSACancelBlockingCall = 10004


} MODBUS_DEFS;


typedef enum
{
	MB_INTERNAL_BUFFER_OVERFLOW,
	MB_OK,
	MB_FRAME_TIMEOUT,
	MB_NOT_ENOUGH_DATA,
	MIN_MB_REQUEST_LESS_3,
	MB_FAILED_TO_TRAMSMIT_UART_DATA

} MB_ERRORS;

typedef struct 
{
	uint8_t QueryFlag; 
	uint8_t SetParamsFlag; 
}NodeFlag;

typedef enum
{
	UNDEFINED_AREA,
	GATEWAY_AREA,
	NODE_QUERY_AREA,
	NODE_CONFIG_PARAMS_AREA,
	FIRMWARE_UPDATE_AREA
}Modbus_Mem_Space;

typedef enum
{
	QUERY,
	SET_PARAMS
}node_data_type;

typedef enum
{
	FIRMWARE_UPDATE_STOPPED,
	//FIRMWARE_UPDATE_STARTED,
	RECEIVING_DATA,
	RECEIVED_IMAGE_CRC,
	FIRMWARE_UPDATE_PROCESS_ERROR
}firmware_update_state;

//#############################################################
typedef enum	//Modbus memory space related defines.	//CODE_REVIEW_done: These should be in a separate file representing the application layer of the modbus. This shouldn't be in modbus driver related files. Consult with Yehuda.
{
	CLEAR_TO_RECEIVE,								//0 	the MCU is ready to receive a new data packet chunk
	NOT_CLEAR_TO_RECEIVE,						//1	the MCU is not ready to receive a new data packet chunk yet (probably because it is saving the previous chunk data in the external flash so you must wait for the MCU to finish)
	WRONG_DATA_CHUNK_INDEX,					//2	error status indicating that the index of the data chunk received is the wrong one.
	NOT_CLEAR_TO_RECEIVE_ERROR,			//3	error status indicating that there was an attempt to do some kind of action with the firmware update process although the status at the time of receiving the command was NOT_CLEAR_TO_RECEIVE
	IMAGE_CRC_ERROR,								//4	calculated CRC of entire received data doesn’t match image CRC received in Image CRC register.
	IMAGE_CRC_VALIDATED,						//5	calculated CRC of entire received data doesn’t match image CRC received in Image CRC register.
	IMAGE_CRC_ANALYSIS_IN_PROGRESS,	//6	The CRC analysis is in progress (MCU is busy)
	GENERAL_ERROR										//7 some kind of error occurred in the process 
}Firmware_Upgrade_Transfer_Status;
//#############################################################

/* Exported define ------------------------------------------------------------*/

#define GATEWAY_ID 10

#define MAX_MODBUS_SLAVE_COMMAND_SIZE 					260
#define RF_MAX_MESSAGE_SIZE 										255

#define MB_FC3_FC4_FC6_REQ_CONST_SIZE 					8
#define MB_FC16_REQ_CONST_SIZE									9
#define MB_FC3_FC4_RES_CONST_SIZE								5
#define MB_FC6_FC16_RES_CONST_SIZE							8

#define MB_FC_3																	0x03
#define MB_FC_4																	0x04
#define MB_FC_6																	0x06
#define MB_FC_16																0x10

#define NB_OF_BYTES_FC3_FC4_RESPONSE_LOCATION		2
#define NB_OF_BYTES_FC3_FC4_REQUEST_LOCATION		6
#define FC_LOCATION															1

#define INCOMING_UART_ARR_LOC_0									0u
#define INCOMING_UART_ARR_LOC_2									2u
#define INCOMING_UART_ARR_LOC_3									3u
#define INCOMING_UART_ARR_LOC_6									6u


#define REGISTERS_PER_NODE	384			// [register #] the number of registers allocated for each node
#define MEM_SPACE_BYTE_NUM_FOR_EACH_NODE 	(REGISTER_BYTE_NUM * REGISTERS_PER_NODE) // [byte #] The number of bytes allocated for each node. Based on the 06.10.2018 the number is 768 bytes

//#############################################################
//Modbus memory space related defines.	//CODE_REVIEW_done: These should be in a separate file representing the application layer of the modbus. This shouldn't be in modbus driver related files. Consult with Yehuda.
//To get the physical memory location 
#define GATEWAY_FIRMWARE_UPGRADE_START_REG						99			// [register #] Gateway Firmware Upgrade Start - GFUS (1 bit) – Set this bit to 1 in order to begin sending data packet chunks of the binary image of the gateway. Once this bit is set to 1, no communication from RF would be received. RF reception would resume only once this bit is set back to 0.
#define FIRMWARE_DATA_PACKET_CHUNK_REG_BEGIN					19400		// [register #] Firmware Data Packet Chunk – FDPC (257 bytes) – after the Firmware Upgrade Start register has been set then you may begin sending the firmware image in data packet chunks to these registers with chunks of 257 bytes. The first byte indicates the index of the chunk (when the chunks are sent they must be sent in rising consecutive order). The following 256 bytes are the relevant data of the chunk. If the last data chunk is less than 256 bytes it’s OK to send less than 256 bytes (do not add padding of bytes to complete the last chunk to 256). 
#define FIRMWARE_DATA_PACKET_CHUNK_REG_END						19528		// [register #] Last register of the Firmware Data Packet Chunk register – FDPC (257 bytes)
#define IMAGE_CRC_REG																	19529		// [register #] Image CRC (16 bit) – the CRC of the image that has been received.
#define FIRMWARE_UPGRADE_START_REG										19530		// [register #] Firmware Upgrade Start - FUS (1 bit) – Set this register to 1 once all firmware data packets and the Image CRC data have been transferred successfully and the Gateway will upgrade the firmware of all the devices that their FUE bit is set to 1. Once the Gateway finishes, updating a specific Bridge it will immediately set their FUE bit to 0 and once all FUE bits have been set to 0 then the FUS bit will be set to 0 too.
																															// [register #] Note: If the GFUS bit of the gateway is set, then the firmware upgrade will only occur for the gateway regardless if there are node FUE bits set to 1. Once the gateway firmware upgrade has been completed, the FUS bit will be set to 0 and if nodes are to be updated then the node image must be sent again and the FUS bit set again afterwards. 
#define NODE_FIRMWARE_UPGRADE_TRANSFER_REG						19531		// [register #] Node Firmwsare Upgrade Transfer Begin – NFUTB (1 bit) – You must set this bit in order to begin transfer of data packets of the binary image to the gateway. This register is the equivalent of the GFUS register for the gateway.
#define FIRMWARE_UPGRADE_TRANSFER_STATUS_REG					19532		// [register #] Firmware Upgrade Transfer Status – FUTS (16 bits) this register is read only. Its purpose is to notify the master when to send a new data packet chunk

#define GATEWAY_FIRMWARE_UPGRADE_ENABLE						(1u)	// the value within the register GATEWAY_FIRMWARE_UPGRADE_START_REG (GFUS) that sets the firmware upgrade
#define FIRMWARE_UPGRADE_START_ENABLE							(1u)	// the value within the register FIRMWARE_UPGRADE_START_REG (FUS) that starts the bootloading process
//#############################################################
//Firmware upgrade related defines:
#define CHUNK_INDEX_POSITION													7				// [byte index] the position within the modbus command for the chunk index when writing to the FDPC register in multiple byte write command
#define CHUNK_DATA_POSITION_BEGIN											8				// [byte index] the position within the modbus command for where the chunk data begins when writing to the FDPC register in multiple byte write command
#define CHUNK_BYTE_NUM_POSITION												6				// [byte index] the position within the modbus command for the number of bytes received in the chunk when writing to the FDPC register in multiple byte write command
#define MAX_NUMBER_OF_BYTES_FOR_DATA_CHUNK						256			// [# bytes] the maximum number of bytes in a data chunk

#define QUERY_2_SEND			1
#define NOT_QUERY_2_SEND	0

//From here downward is from W3_Flash.h --> requires organization
#define FLASH_USER_START_ADDR   0x0800E1FF			  /* Start @ of user Flash area */			//This size is right for 10 nodes only!!
#define FLASH_USER_END_ADDR     0x0800FFFF			   /* End @ of user Flash area */
#define SIZE_OF_GW_REG_AREA			0xC6			//0-98 register in the GW's memory map.
#define SIZE_OF_FUE							0x2				//Register 99 of the GW's memory map.
#define SIZE_OF_SLOTS_SET 			0xC8				//100-199 registers in the GW's memory map. 640 (hex) = 8bit*2*100 (dec)
#define REMOTE_UNIT_REG_ADRRESS (FLASH_USER_START_ADDR + SIZE_OF_GW_REG_AREA + SIZE_OF_FUE + SIZE_OF_SLOTS_SET) 

#define START_OF_CONFIG_REGISTERS_GW_MEM_AREA							0
#define FW_UPGRADE_BIT_GW_MEM_AREA												99
#define START_OF_SLOTS_REGISTERING_REGISTERS_GW_MEM_AREA	100

/*Defines of the location of the start of each segment or block in memory within the area for each node.
This value shall be multiplay by the node number and offset by the size of 200 registers at the the top
of this memory map*/

/*Remote unit configuration registers*/
#define BR_COM_INTERVAL_LOCATION_WITHIN_NODE_MEM_SPACE						0u			//The size of this parameter is four bytes
#define RESPONSE_TIMEOUT_LOCATION_WITHIN_NODE_MEM_SPACE						4u			//The size of this parameter is two bytes
#define REPEAT_MESSAGES_LOCATION_WITHIN_NODE_MEM_SPACE						6u			//The size of this parameter is one byte
#define MIN_RAND_LOCATION_WITHIN_NODE_MEM_SPACE										8u			//The size of this parameter is one byte
#define MAX_RAND_LOCATION_WITHIN_NODE_MEM_SPACE										10u			//The size of this parameter is one byte
#define SENSOR_TIMEOUT_LOCATION_WITHIN_NODE_MEM_SPACE							12u			//The size of this parameter is two bytes
#define SENSOR_REPEAT_MESSAGES_LOCATION_WITHIN_NODE_MEM_SPACE 		14u			//The size of this parameter is one byte
#define ALARM_WAKEUP_INTERVAL_LOCATION_WITHIN_NODE_MEM_SPACE			16u			//The size of this parameter is four bytes
#define CHECKSUM_OF_NODE_PARAM_LOCATION_WITHIN_NODE_MEM_SPACE			49u

/*Remote unit status and measurements registers*/
#define RSSI_LOCATION_WITHIN_NODE_MEM_SPACE												100u			//The size of this parameter is one byte
#define BATTERY_VOLTAGE_LOCATION_WITHIN_NODE_MEM_SPACE						102u			//The size of this parameter is two bytes
#define BR_FIRMWARE_VERSION_LOCATION_WITHIN_NODE_MEM_SPACE				104u			//The size of this parameter is two bytes
#define TIME_SINCE_LAST_COMM_LOCATION_WITHIN_NODE_MEM_SPACE				106u			//The size of this parameter is four bytes
#define	ALARAM_CODE_LOCATION_WITHIN_NODE_MEM_SPACE								110u			//The size of this parameter is one byte.
#define NO_CONNECTION_TIME_LOCATION_WITHIN_NODE_MEM_SPACE					112u			//The size of this parameter is two bytes.
#define NO_CONNECTION_LOCATION_WITHIN_NODE_MEM_SPACE							114u		//The size of this parameter is one byte.

/*Remote unit actuation*/
#define RESET_REMOTE_UNIT_LOCATION_WITHIN_NODE_MEM_SPACE					116u		//The value of this parameter is one byte.
#define RST_2_DEFAULT_LOCATION_WITHIN_NODE_MEM_SPACE							118u		//Ths size of this parameter is one byte.
#define	FW_UPDATE_ENABLE_LOCATION_WITHIN_NODE_MEM_SPACE						120u		//The value of this parameter is one byte.

/*Remote unit response to AIO sensor*/
#define QUERY_SIZE_LOCATION_WITHIN_NODE_MEM_SPACE									256u		//The size of this value is one byte
#define QUERY_ADDRESS_WITHIN_NODE_MEM_SPACE												258u		//The size of this parameter is up to 126 register so it's up to 252 bytes

/*Remote unit response from AIO sensor*/
#define QUERY_RESPONSE_SIZE_LOCATION_WITHIN_NODE_MEM_SPACE				512u		//The size of this value is one byte
#define QUERY_RESPONSE_ADDRESS_WITHIN_NODE_MEM_SPACE							514u		//The size of this parameter is up to 126 register so it's up to 252 bytes

/*Data of remote unit - Keep alive messagge*/
#define ADDRESS_OF_PARMAS_OF_KA_WITHIN_NODE_MEM_SPACE							100u			//The offset of RSSI within 500 bytes. As in the ICD document.
#define ALARM_CODE_ADDRESS_WITHIN_NODE_MEM_SPACE									110u

/*FW upgrade resisters*/
#define FW_DATA_PCKG_LOCATION_WITHIN_NODE_MEM_SPACE								982u		//The size of this parameter is up to 256bytes.
#define FW_UPGRADE_START_LOCATION_WITHIN_NODE_MEM_SPACE						983u		//The size of this parameters is one byte.	

#define TOTAL_NUMBER_OF_NODES			50u

#define DATA_CHANGED								1u
#define DATA_NOT_CHANGED						0u

//#define QUERY																	13u			//This define is use for setting and reseting the flag of Query.
//#define SET_PARAMS														14u

/*Defines related to new flags set*/
//#define GW_CONFIGURATION_AREA	1
//#define NEW_QUERY 2
//#define NEW_PARAMETERS	3
//#define POST_NODES_AREA	4

/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

extern NodeFlag ArrOfFlags4Nodes[TOTAL_NUMBER_OF_NODES];

/* Exported functions ---------------------------------------------------------*/

void IncomingDataAnalysis(uint8_t *arr2Analyze, uint8_t arrSize);
extern uint8_t receivedDataModbus[MAX_MODBUS_SLAVE_COMMAND_SIZE];

//from W3_Flash - needs to be organized...
uint8_t CheckIfNewData4Node(uint8_t NodeID, node_data_type FlagType);
void SetNewDataFlag4Node(uint8_t NodeID, uint8_t FlagType);
void UnsetNewDataFlag4Node(uint8_t NodeID, uint8_t FlagType);

Modbus_Mem_Space NewDataFlagsSelector(uint32_t received_register);

#endif  /* __MODBUS_APP_LAYER_H__ */

/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/
