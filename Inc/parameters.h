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
#ifndef __PARAMETERS_H__
#define __PARAMETERS_H__

/* Includes ------------------------------------------------------------------*/

#include "common.h"

/*Default parameters*/

#define BR_COM_INTERVAL_DEF											0x12345678//0x0000003C		//In ms
#define RESPONSE_TIMEOUT_DEF										0x4321//0x0032		//In ms	
#define REPEAT_MESSAGES_DEF											0x9876//0x0005
#define MIN_RAND_DEF														0x9999//0x0005 		//In seconds
#define MAX_RAND_DEF														0x8888//0x001E		//In seconds
#define SENSOR_TIMEOUT_DEF											0x6666//0x0000
#define SENSOR_REPEAT_MESSAGE_DEF								0x4444//0x0000
#define ALARM_WAKEUP_INTERVAL_DEF								0x22223333//0x00000078		//In seconds



/* Exported typedef -----------------------------------------------------------*/

typedef struct
{
  uint32_t ee_adrs;     // EEPROM Address
  uint32_t val;         // The value of the parameter (currently all values are saved as words in the memory even if they are just boolean values).
                        // The reason they are all 32 bits (words) is to maintain consistancy and simplify the driver. It is less optimized memory-wise but there are no lack of EEPROM space.
}Parameter;

typedef enum 
{
  ENABLE_FIRMWARE_UPGRADE,						// Whether the bootloader should load a new image from the external flash
	FIRST_TIME_RUN_FLAG,  					// Whether this is the first time we are running after loading software or not. 
	BR_COM_INTERVAL,
	RESPONSE_TIMEOUT,
	REPEAT_MESSAGES,
	MIN_RAND,
	MAX_RAND,
	ALARM_WAKEUP_INTERVAL
}parameters;

/* Exported define ------------------------------------------------------------*/

#define PARAM_NUM       10u       // number of parameters stored in the memory
#define PARAM_SIZE      4u       // number of bytes allocated for each and every parameter in the eeprom (4 indicates one word - 32 bits)
#define PARAMETERS_RELATIVE_ADDRESS_START       0u       // the position in the eeprom memory bank where the parameters section begins. (0 - the beginning of the bank)

#define ERASED_CELL     0x00u    // the value of an erased EEPROM cell in STM32 MCUs

//default values
#define ENABLE_FIRMWARE_UPGRADE_DEFAULT         (uint32_t)FALSE   // [TRUE/FALSE] Whether the bootloader should load a new image from the external flash
#define FIRST_TIME_RUN_FLAG_DEFAULT             (uint32_t)FALSE   // [TRUE/FALSE] Whether this is the first time we are running after loading software or not. 

/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

/* Exported functions ---------------------------------------------------------*/

void Init_SystemParameters(void);
uint32_t Param_GetVal(parameters param_index);
void Param_SetVal(parameters param_index, uint32_t value);
void UploadDefaultSystemParameters(void);
void Download_SystemParameters(void);
void SetParams2Default(uint8_t NodeID);

#endif /* __PARAMETERS_H__ */

/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/
