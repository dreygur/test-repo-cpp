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
#ifndef __EXTERNAL_FLASH_H__
#define __EXTERNAL_FLASH_H__

/* Includes ------------------------------------------------------------------*/

#include "common.h"

/* Exported typedef -----------------------------------------------------------*/

/* Exported define ------------------------------------------------------------*/

#define MX25R0835F

/* MX25R1635F SPI Registers Definition */
#define WRSR_REG		            (0x01u)            // Write Status Register
#define PP_REG		                (0x02u)            // Page Program Register
#define READ_REGISTER	        	(0x03u)            // Normal Read Register
#define WRDI_REG		            (0x04u)            // Write Disable Register
#define RDSR_REG		            (0x05u)            // Read Status Register
#define WREN_REG		            (0x06u)            // Write Enable Register 
#define FAST_READ_REG		        (0x0Bu)            // Fast Read Register  
#define RDCR_REG		            (0x15u)            // Read Configuration Register
#define SE_REG                      (0x20u)            // Sector Erase (4K) Register
#define CE_REG		                (0x60u)            // Chip Erase Register
#define REMS_REG                    (0x90u)            // Read Electronic Manufacturer & device ID
#define RDID_REG                    (0x9Fu)            // Read Identification Register
#define CE_REG_SPI                  (0xC7u)            // Chip Erase takes 4 -12 sec.
#define BE32K                       (0x52u)            // Block Erase (32K) Register
#define MAX_SPI_BUFFER_LENGTH       (256u)

#ifdef MX25R1635F
	#define SPI_FLASH_MANUFACTURER_ID   (0xC2u)
	#define SPI_FLASH_MEMORY_TYPE       (0x28u)
	#define SPI_FLASH_MEMORY_DENSITY    (0x15u)
	/* Flash size */
	#define EXTERNAL_FLASH_SIZE         (0x1FF000u)
#else 
	#ifdef MX25R0835F
		#define SPI_FLASH_MANUFACTURER_ID   (0xC2u)
		#define SPI_FLASH_MEMORY_TYPE       (0x28u)
		#define SPI_FLASH_MEMORY_DENSITY    (0x14u)
		/* Flash size */
		#define EXTERNAL_FLASH_SIZE         (0x0FF000u)
	#endif
#endif
//
// Flash control register mask define
// status register
#define FLASH_WIP_MASK                          (0x01u)
#define SECTOR_SIZE                             (0x1000u)

/* MX25R8035F Blocks locations */
#define BASE_BLOCK_SIZE                         (0x008000u)

#define FLASH_BLOCK_00_ADDR BASE_BLOCK_SIZE*(00u)
#define FLASH_BLOCK_01_ADDR BASE_BLOCK_SIZE*(01u)
#define FLASH_BLOCK_02_ADDR BASE_BLOCK_SIZE*(02u)
#define FLASH_BLOCK_03_ADDR BASE_BLOCK_SIZE*(03u)
#define FLASH_BLOCK_04_ADDR BASE_BLOCK_SIZE*(04u)
#define FLASH_BLOCK_05_ADDR BASE_BLOCK_SIZE*(05u)
#define FLASH_BLOCK_06_ADDR BASE_BLOCK_SIZE*(06u)
#define FLASH_BLOCK_07_ADDR BASE_BLOCK_SIZE*(07u)
#define FLASH_BLOCK_08_ADDR BASE_BLOCK_SIZE*(08u)
#define FLASH_BLOCK_09_ADDR BASE_BLOCK_SIZE*(09u)
#define FLASH_BLOCK_10_ADDR BASE_BLOCK_SIZE*(10u)
#define FLASH_BLOCK_11_ADDR BASE_BLOCK_SIZE*(11u)
#define FLASH_BLOCK_12_ADDR BASE_BLOCK_SIZE*(12u)
#define FLASH_BLOCK_13_ADDR BASE_BLOCK_SIZE*(13u)
#define FLASH_BLOCK_14_ADDR BASE_BLOCK_SIZE*(14u)
#define FLASH_BLOCK_15_ADDR BASE_BLOCK_SIZE*(15u)
#define FLASH_BLOCK_16_ADDR BASE_BLOCK_SIZE*(16u)
#define FLASH_BLOCK_17_ADDR BASE_BLOCK_SIZE*(17u)
#define FLASH_BLOCK_18_ADDR BASE_BLOCK_SIZE*(18u)
#define FLASH_BLOCK_19_ADDR BASE_BLOCK_SIZE*(19u)
#define FLASH_BLOCK_20_ADDR BASE_BLOCK_SIZE*(20u)
#define FLASH_BLOCK_21_ADDR BASE_BLOCK_SIZE*(21u)
#define FLASH_BLOCK_22_ADDR BASE_BLOCK_SIZE*(22u)
#define FLASH_BLOCK_23_ADDR BASE_BLOCK_SIZE*(23u)
#define FLASH_BLOCK_24_ADDR BASE_BLOCK_SIZE*(24u)
#define FLASH_BLOCK_25_ADDR BASE_BLOCK_SIZE*(25u)
#define FLASH_BLOCK_26_ADDR BASE_BLOCK_SIZE*(26u)
#define FLASH_BLOCK_27_ADDR BASE_BLOCK_SIZE*(27u)
#define FLASH_BLOCK_28_ADDR BASE_BLOCK_SIZE*(28u)
#define FLASH_BLOCK_29_ADDR BASE_BLOCK_SIZE*(29u)
#define FLASH_BLOCK_30_ADDR BASE_BLOCK_SIZE*(30u)
#define FLASH_BLOCK_31_ADDR BASE_BLOCK_SIZE*(31u)

/* MX25R8035F Sectors locations */
#define BASE_SECTOR_SIZE                         (0x001000u)

//Sectors for holding memory when performing automatic writing ( see description of function EXTERNAL_FLASH_WriteData_Automatic() )
#define FIRST_SECTOR_INDEX_FOR_MEM_HOLD (0u)
#define LAST_SECTOR_INDEX_FOR_MEM_HOLD (3u)

//############ APPLICATION RELATED MEMORY SPACE DEFINITIONS ##########################
//Organize the defines in incremental order so that it would be easy to see how the memory space is broken down.

/*Addresses in flash*/
#define MODBUS_MEM_SPACE_START_ADDRESS 			( BASE_SECTOR_SIZE * (LAST_SECTOR_INDEX_FOR_MEM_HOLD+1) )				//The beginning of the modbus memory space - located after the sectors for holding data during erase.
#define GW_MODBUS_REGISTERS_START_ADRS			MODBUS_MEM_SPACE_START_ADDRESS																	//The beginning of the memory space where the gateway modbus registers are located 
#define GW_FW_UPGRADE_EN_ADRS	(MODBUS_MEM_SPACE_START_ADDRESS + 0xC6u)										//0xc6 is 198 bytes for registers configuration of the GW	//CODE_REVIEW: Please do not EVER use hex format to assign numbers to variables or definitions unless it is necessary or usefull. In almost ALL cases in this firmware it gives no additional value to write it in hex format - in fact it is annoying since it requires the reader to calculate it in order to verify the decimal number. Simply write it in DECIMNAL.
#define GW_SLOTS_OF_NODES_ADRS	(MODBUS_MEM_SPACE_START_ADDRESS + GW_FW_UPGRADE_EN_ADRS + 0x02u)				//0x02 is the size for FW upgrade enable bit
#define START_OF_NODES_MEM_AREA_ADRS (GW_SLOTS_OF_NODES_ADRS/* + 0xC8u*/)												//0xc8 is 200 bytes for registering the nodes.
#define NUMBER_OF_REGS_FOR_GW 200u	// the number of registers assigned for the gateway configuration and control

//Sectors for storing the application image for bootloading
#define APP_IMAGE_SECTOR_START (240u)
#define APP_IMAGE_SECTOR_FINISH (254u)
#define APP_IMAGE_SECTOR_ACCESSORIES (APP_IMAGE_SECTOR_FINISH+1)	// the sector in which the CRC and the size of the stored binary image (size in number of bytes) are stored

#define APP_IMAGE_CRC_POSITION	(0u)				// [# bytes] the relative position within the sector APP_IMAGE_SECTOR_ACCESSORIES that the CRC of the binary image is positioned
#define APP_IMAGE_CRC_SIZE			(2u)				// [# bytes] the number of bytes allocated to the CRC of the binary image
#define APP_IMAGE_BYTE_NUM_POSITION		(APP_IMAGE_CRC_POSITION + APP_IMAGE_CRC_SIZE)		// [# bytes] the relative position within the sector APP_IMAGE_SECTOR_ACCESSORIES that the CRC of the binary image is positioned
#define APP_IMAGE_BYTE_NUM_SIZE	(2u)				// [# bytes] the number of bytes allocated to the size of the binary image

//############ END OF APPLICATION RELATED MEMORY SPACE DEFINITIONS #################### 

/*Pointers to sections at FLASH memory*/

#define EXTERNAL_FLASH_PAGE_SIZE                   (256u)


#define FLASH_TIMEOUT_ERROR											(0x40000000u)
#define FLASH_MEM_BOUNDRY_ERROR									(0x50000000u)
#define FLASH_MEM_HOLD_SECTOR_BOUNDRY_ERROR			(0x60000000u)
#define FLASH_MEM_MAX_SECTOR_NUM_ERROR					(0x70000000u)

#define SPI_EXT_FLASH_POLLING_TIMEOUT	5	// [msec] the time for the SPI commands to timeout 

/* Exported macro -------------------------------------------------------------*/

/* Exported variables ---------------------------------------------------------*/

/* Exported functions ---------------------------------------------------------*/

void EXTERNAL_FLASH_Init(void);
uint32_t EXTERNAL_FLASH_ReadDeviceID(uint8_t *manufacturerIdPtr, uint8_t *memTypePtr, uint8_t *memDensityPtr);
uint32_t EXTERNAL_FLASH_EnableWriting(void);
void EXTERNAL_FLASH_DisableWriting(void);

uint32_t EXTERNAL_FLASH_WriteData(uint32_t address, uint16_t data_length, uint8_t *data);
uint32_t EXTERNAL_FLASH_WriteData_Automatic(uint32_t address, uint16_t data_length, uint8_t *data);
uint32_t EXTERNAL_FLASH_ReadData(uint32_t address, uint8_t *data, uint16_t data_length);
uint32_t EXTERNAL_FLASH_PageProgram(uint32_t address, uint16_t data_length, uint8_t *data);
uint32_t EXTERNAL_FLASH_EraseBlock(uint32_t address);
uint32_t EXTERNAL_FLASH_EraseSector(uint32_t address);
uint32_t EXTERNAL_FLASH_EraseAll(void);
uint32_t EXTERNAL_FLASH_IsFlashBusy(bool *busyPtr);
//void IsFlashBusy(void);



#endif /* __EXTERNAL_FLASH_H__ */

/************************ (C) COPYRIGHT AIO Systems *****END OF FILE****/
