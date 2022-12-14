/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  -
 *
 *  Description:  Contains all MCU Registers Definitions     
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "platform_types.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/*
#define SRAM_BASE 				0x20000000 // Define base address of bit-band
#define BASE_SRAM_ALIAS   0x22000000 // Define base address of alias band
#define	PERI_BASE				  0x40000000 // Define base address of peripheral bit-band
#define BASE_PRI_ALIAS    0x42000000 // Define base address of peripheral alias band

// Convert SRAM address to alias region

#define GET_BITBAND_SRAM(REG_ADD,BIT_NUM) (( BASE_SRAM_ALIAS + (REG_ADD - SRAM_BASE)*32 + (BIT_NUM*4)))
 
// Convert PERI address to alias region
#define GET_BITBAND_PERI(REG_ADD,BIT_NUM) (( BASE_PRI_ALIAS  + (REG_ADD - PERI_BASE)*32 + (BIT_NUM*4)))

*/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/**************************************
*   NVIC REGISTRE
***************************************/
#define NVIC_ENABLE_BASE_ADDRESS              ((volatile uint32*)0xE000E100)
#define NVIC_PRIORITY_BASE_ADDRESS            ((volatile uint32*)0xE000E400)

#define APINT_KEY 				   						0x05FA
#define APINT_SYSRESREQ									2
#define APINT_KEY_START_BIT  						16
#define NVIC_GROUPING_SYSTEM_START_BIT  8


/**************************************
*   SYSTEM CONTROL REGISTRES
***************************************/

#define APINT                            *((volatile uint32*)0xE000ED0C)
#define SYSCTR_BASE_ADDRESS              0x400FE000
#define RESC                             *((volatile uint32*)0x400FE05C)
#define RCGCGPIO_OFFSET                  0x608
#define RCGCGPIO                         *((volatile uint32*)(SYSCTR_BASE_ADDRESS+RCGCGPIO_OFFSET)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

typedef struct
{
	uint32 MOSCDIS  :1;
	uint32          :3;
	uint32 OSCSRC   :2;
	uint32 XTAL     :5;
	uint32 BYPASS   :1;
	uint32          :1;
	uint32 PWRDN    :1;
	uint32          :3;
	uint32 PWMDIV   :3;
	uint32 USEPWMDIV:1;
	uint32          :1;
	uint32 USESYSDIV:1;
	uint32 SYSDIV   :4;
	uint32 ACG      :1;
	uint32          :4;	
}Mcu_StrBF;	
	
typedef union
{
	uint32 R;
	Mcu_StrBF B;

}RCC_TAG;

#define RCC                     (*((volatile RCC_TAG*)0x400FE060))
#define RCC2                    (*((volatile RCC2_TAG*)0x400FE070))
#define PLLSTAT                 *((volatile uint32*)0x400FE168)
#define SYSCTR_RCG_BASE_ADDR    0x400FE600
/**************************************
*   GPIO REGISTRE
***************************************/
#define GPIO_APB_BASE_ADDRESS_A          0x40004000
#define GPIO_APB_BASE_ADDRESS_B          0x40005000
#define GPIO_APB_BASE_ADDRESS_C          0x40006000
#define GPIO_APB_BASE_ADDRESS_D          0x40007000
#define GPIO_APB_BASE_ADDRESS_E          0x40024000
#define GPIO_APB_BASE_ADDRESS_F          0x40025000

#define GPIODIR_OFFSET			0x400



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define GET_REG(BaseAddr,RegOffset)        *((volatile uint32*)(BaseAddr+RegOffset))
#define GPIODIR(BaseAddr)                  *((volatile uint32*)BaseAddr+GPIODIR_OFFSET) 

#define BASE_ADDRESS_PRE                              0x40000000
#define BASE_ADDRESS_PRE_ALIAS                        0x42000000

#define GET_RegisterOffset(RegisterAddr)              ((RegisterAddr - BASE_ADDRESS_PRE)/4)
#define GET_BitOffset(RegisterAddr,BitPos)            ((GET_RegisterOffset(RegisterAddr)*32) + BitPos)
#define GET_BBAlIAS_PRE_REG(RegisterAddr, BitPos)     (*(volatile uint32*)((GET_BitOffset(RegisterAddr,BitPos)*4) + BASE_ADDRESS_PRE_ALIAS))

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/	