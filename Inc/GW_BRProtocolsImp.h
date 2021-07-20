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

#include "external_flash.h"
#ifndef __GW_BR_PROTOCOLS_IMP__
#define __GW_BR_PROTOCOLS_IMP__

/*All of the command from GW to Bridge as in the ICD doc. Used by the switch in RF_SendCommand func */
#define ACK_COMMAND 								0x02u
#define NACK_COMMAND 								0x03u
#define RES1_2_MB_QUE								0x04u
#define RES2_2_MB_QUE								0x05u
#define RES_2_GET_PARAM							0x06u
#define QUERY_GW2BR_SEND_COMMAND		0x07u
#define SET_PARAMETERS							0x08u
#define REBOOT_COMMAND							0x09u
#define REBOOT_AND_DEF_COMMAND			0x0Au

#define NODE_ID									0x55			//At this point this value is a define but latter on this value will be unique to each bridge and shall be picked by the user


/*All of the codes messages as in the ICD doc*/
#define QUERY_GW2BR_MESSAGE_CODE 				0x31u
#define QUERY_BR2GW1_MESSAGE_CODE 			0x32u
#define QUERY_BR2GW2_MESSAGE_CODE 			0x33u
#define KEEP_ALIVE_MESSAGE_CODE 				0x11u
#define COMMUNICATION_OK 								0x01u
#define COMMUNICATION_NOT_OK 						0x00u
#define ACK_CODE_MESSAGE								0x21u
#define NACK_CODE_MESSAGE								0x22u
#define ACK															0xAAu
#define NACK														0xBBu
#define SET_PARAMS_MESSAGE_CODE					0x41u
#define REBOOT_COMMAND_MESSAGE_CODE			0x50u


/*ACK related defines*/
#define ACK_MESSAGE_SIZE 						0x05u				//The size of the array contain the ACK message
#define ACK_ARR_LOC_0								0u
#define ACK_ARR_LOC_1								1u
#define ACK_ARR_LOC_2								2u
#define ACK_ARR_LOC_3								3u
#define ACK_ARR_LOC_4								4u


/*NACK related defines*/
#define NACK_MESSAGE_SIZE 						0x05u				//The size of the array contain the ACK message
#define NACK_ARR_LOC_0								0u
#define NACK_ARR_LOC_1								1u
#define NACK_ARR_LOC_2								2u
#define NACK_ARR_LOC_3								3u
#define NACK_ARR_LOC_4								4u


/*Query GW2BR related defines*/
#define QUERY_GW2BR_MAX_SIZE								0x84		//132 in decimal
#define QUERY_GW2BR_ARR_LOC_0									0u
#define QUERY_GW2BR_ARR_LOC_1									1u
#define QUERY_GW2BR_ARR_LOC_2									2u
#define QUERY_GW2BR_ARR_LOC_3									3u
#define QUERY_GW2BR_EXTRA_DATA								5u



/*Query response 1 related defines*/
#define QUERY_RES1_ADDRESS_WITHIN_250					187//188//257u			//This the location of the size of the response
#define QUERY_BR2GW1_MAX_SIZE									0x7E


/*Set Parameters related defines*/
#define SET_PARAMS_MESSAGE_SIZE								20u
#define SET_PARAMS_ARR_LOC_0									0u
#define SET_PARAMS_ARR_LOC_1									1u
#define SET_PARAMS_ARR_LOC_2									2u
#define SET_PARAMS_ARR_LOC_3									3u
#define SET_PARAMS_ARR_LOC_18									18u
#define SET_PARAMS_ARR_LOC_19									19u
#define SIZE_OF_BR_COM_INTERVAL 							4u
#define SIZE_OF_RESPONSE_TIMOUT								2u
#define SIZE_OF_SENSOR_TIMEOUT								2u
#define SIZE_OFSAMPLE_INTERVAL								4u


/*Keep alive related defines*/
#define QUERY_RESPONSE_FLAF_IN_KA_MES					12
#define SIZE_OF_PARMAS_OF_KA									26u			//The size of the data came over Keep alive message that the GW should store is the Flash						
#define RSSI_FIRST_BYTE_LOC										0u
#define RSSI_SECOND_BYTE_LOC									1u
#define V_BAT_FIRST_BYTE_LOC									2u
#define V_BAT_SECOND_BYTE_LOC									3u
#define BR_FW_VERSION_FIRST_BYTE_LOC					4u
#define BR_FW_VERSION_SECOND_BYTE_LOC					5u
#define TIME_SINCE_LAST_COM_FIRST_BYTE_LOC		6u
#define ALARM_CODE_FIRST_BYTE_LOC							10u				//The gup is due to some other parameters in this location and are not part of KA message.
#define ALARM_CODE_SECOND_BYTE_LOC						11u
#define NO_CONNECTION_TIME_FIRST_BYTE_LOC			12u
#define TIME_DATA_FIRST_BYTE_LOC							22u
#define NUMBER_OF_BYTES_TIME_LAST_COM					4u
#define NUMBER_OF_BYTES_BETWEEN_NO_COMM_AND_TIME_DATA	10


/*Reboot command related defines*/
#define REBOOT_COMMAND_MESSAGE_SIZE						5u
#define REBOOT_COMMAND_ARR_LOC_0							0u
#define REBOOT_COMMAND_ARR_LOC_1							1u
#define REBOOT_COMMAND_ARR_LOC_2							2u
#define REBOOT_COMMAND_ARR_LOC_3							3u
#define REBOOT_COMMAND_ARR_LOC_4							4u


/*Other defines*/
#define MESSAGE_CODE_LOC_IN_RF_MES		0u
#define NODE_ID_LOC_IN_RF_MES					1u		//The location of the byte represent the NODE ID in the RF array
#define GW_AVALIABLE_4_COMM						0xFF
#define NODE_ID_LOC_IN_MB_MES					0u



/* Includes ------------------------------------------------------------------*/

#include "common.h"

/* Exported typedef -----------------------------------------------------------*/

typedef struct 		//This struct is for holding the data coming of the keep alive message.
{
	uint8_t TimeAndDate[4];
	uint8_t VBat[2];
	uint8_t FW_V[2];
	bool QueryResponseFlg;
}KeepAliveData;

/* Exported define ------------------------------------------------------------*/

#define RF_ONE_PAYLOAD_MAX_SIZE 48	//54		//This value is the max number of bytes of data on one burst of RF transmit\receive
#define ONE_BURST 1

/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

/* Exported functions ---------------------------------------------------------*/

uint8_t QueryResponseAnaylas(uint8_t *IncomingDataArr);
uint8_t SendQueryGW2BR(uint8_t NumberOfBytes, uint8_t *QueryData);
uint8_t KeepAliveDataHandler(uint8_t *IncomingDataArr, KeepAliveData *data);
void sendDataOverRF(byte *inComingData, uint8_t size);
void GW2BR_QuerySendRF(void);
void NACK_SendRF(void);
void ACK_SendRF(void);
void RF_SendCommand(uint8_t command);
uint8_t GetDataAndSizeOfQuery(uint8_t *QueryData);
void SetParams_GW2BRSendRF(void);
void RFIncomingData4BRAnalays(uint8_t *arr2analyze);
void GW2BRResponseHandler(void);
void KeepAliveResponseHandler(uint8_t *arr2Analyze, uint8_t NodeID);
uint32_t add2ReadQuery(uint8_t NodeID);
void QueryResp1_ResponseHnadler(uint8_t *arr2Analyze, uint8_t NodeID);
void QueryResp2_ResponseHnadler(uint8_t *arr2Analyze, uint8_t NodeID);
void ACKResponseHandler(void);
uint32_t add2ReadFromFlash(uint8_t NodeID, uint16_t parameter);
void GetDataOfParamsFromFlash(uint8_t *Arr2write);
void RebootCommand_SendRF(void);
uint8_t CheckIfReset(void);
void UnsetResetBit(void);
void UnsetResetAndDefBit(void);


extern uint8_t CurrentNodeID;

#endif /* __GW_BR_PROTOCOLS_IMP__ */

/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/
