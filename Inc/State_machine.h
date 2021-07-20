#include "common.h"
#include "app_main.h"
#include "radio.h"
#include "GW_BRProtocolsImp.h"
#include "common.h"


#define BACK_FROM_UART_RECEIVE_STATE											0x01u
#define BACK_FROM_UART_TRANSMIT_STATE											0x02u
#define BACK_FROM_UART_INCOMMING_DATA_ANALZE_STATE				0x03u
#define BACK_FROM_RF_INCOMMING_DATA_ANALZE_STATE					0x04u
#define BACK_FROM_RF_RECEIVE_STATE												0x05u
#define BACK_FROM_RF_TRANSMIT_STATE												0x06u
#define BACK_FROM_NODES_MEMORY_MANAGE_WRITE_STATE					0x07u
#define BACK_FROM_NODES_MEMORY_MANAGE_READ_STATE					0x08u
#define BACK_FROM_GW_MEMORY_MANAGE_READ_STATE							0x09u
#define BACK_FROM_GW_MEMORY_MANAGE_WRITE_STATE						0x0Au


#define UART_RECEIVE_STATE																0x0Bu
#define UART_TRANSMIT_STATE																0x0Cu
#define UART_INCOMMING_DATA_ANALYZE_STATE									0x0Du
#define RF_INCOMING_DATA_ANALYZE_STATE										0x0Eu
#define RF_RECEIVE_STATE																	0x0Fu
#define RF_TRANSMIT_STATE																	0x10u
#define NODES_MEMORY_MANAGE_WRITE_STATE										0x11u
#define NODES_MEMORY_MANAGE_READ_STATE										0x12u
#define GW_MEMORY_MANAGE_READ_STATE												0x13u
#define GW_MEMORY_MANAGE_WRITE_STATE											0x14u

#define TIMEOUT4Q_AND_GET_PARAMS_RESPONSES								50				//In ms. This is the time the GW will wait for the responses of query or get params



/*Global variables and flags of this state machine*/
extern uint8_t state;
extern uint8_t RFData2AnalyzeFlag;
extern uint8_t Wait4QueryResponse1;
extern uint8_t Wait4QueryResponse2;
extern uint8_t ACK_RF_Flag;
extern uint8_t NACK_RF_Flag;
extern uint8_t QueryRF_Flag;
extern uint8_t SetParamsRF_Flag;
extern uint8_t RESET_RF_Flag;
extern uint8_t RESET_AndDef_RF_Flag;


/*Functions declerations*/
uint8_t MainStateMachineLoop(uint8_t CurrentState);
uint8_t RF_receiveState(void);
uint8_t RF_transmitState(void);
uint8_t UART_receiveState(void);
uint8_t UART_transmitState(void);
uint8_t UART_InsomingDataAnalyzeState(void);
uint8_t RF_IncomingDataAnalayzeState(void);
uint8_t NodesMemoryManageWriteState(void);
uint8_t NodesMemoryManageReadState(void);
uint8_t GWMemoryManageWriteState(void);
uint8_t GWMemoryManageReadState(void);


