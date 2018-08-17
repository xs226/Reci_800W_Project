/*
 * STM32F10X register header file
 * Write by soso.  2016.05.19
 */

#include "system.h"
#ifndef __STM32F10x_REG_H
#define __STM32F10x_REG_H

/*****************************************************************************/
/*                        Peripheral registers structures                    */
/*****************************************************************************/

/*------------------- CRC calculation unit MANUAL.P36------------------------*/
typedef struct {
	union {
		_IO_UINT32 W;
	} DR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:8;
			_IO_UINT32								:24;
		} B;
	} IDR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 RESET					:1;
			_IO_UINT32 RESERVED				:1;
			_IO_UINT32								:30;
		} B;
	} CR;
} CRC_Type;



/////////////////////////////FLASH////////////////////////////////////

  
typedef struct
{
  __IO uint32_t ACR;
  __IO uint32_t KEYR;
  __IO uint32_t OPTKEYR;
  __IO uint32_t SR;
  __IO uint32_t CR;
  __IO uint32_t AR;
  __IO uint32_t RESERVED;
  __IO uint32_t OBR;
  __IO uint32_t WRPR;
#ifdef STM32F10X_XL
  uint32_t RESERVED1[8]; 
  __IO uint32_t KEYR2;
  uint32_t RESERVED2;   
  __IO uint32_t SR2;
  __IO uint32_t CR2;
  __IO uint32_t AR2; 
#endif /* STM32F10X_XL */  
} FLASH_TypeDef;



#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))
#define assert_param(expr) ((void)0)
//////////////////////////////////////////////////////////////
/*------------------- Power Control MANUAL.P46-------------------------------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 LPDS						:1;
			_IO_UINT32 PDDS						:1;
			_IO_UINT32 CWUF						:1;
			_IO_UINT32 CSBF						:1;
			_IO_UINT32 PVDE						:1;
			_IO_UINT32 PLS						:3;
			_IO_UINT32 DBP						:1;
			_IO_UINT32								:23;
		} B;
	} CR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 WUF						:1;
			_IO_UINT32 SBF						:1;
			_IO_UINT32 PVDO						:1;
			_IO_UINT32								:5;
			_IO_UINT32 EWUP						:1;
			_IO_UINT32								:23;
		} B;
	} CSR;
} PWR_Type;

/*------------------- Backup Registers MANUAL.P51----------------------------*/
typedef struct {
	_UINT32 RESERVED0;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR3;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR4;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR5;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR6;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR7;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR8;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR9;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR10;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CAL						:7;
			_IO_UINT32 CCO						:1;
			_IO_UINT32 ASOE						:1;
			_IO_UINT32 ASOS						:1;
			_IO_UINT32								:22;
		} B;
	} RTCCR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 TPE						:1;
			_IO_UINT32 TPAL						:1;
			_IO_UINT32								:30;
		} B;
	} CR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CTE						:1;
			_IO_UINT32 CTI						:1;
			_IO_UINT32 TPIE						:1;
			_IO_UINT32								:5;
			_IO_UINT32 TEF						:1;
			_IO_UINT32 TIF						:1;
			_IO_UINT32								:22;
		} B;
	} CSR;
	_UINT32 RESERVED2;
	_UINT32 RESERVED3;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR11;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR12;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR13;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR14;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR15;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR16;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR17;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR18;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR19;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR20;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR21;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR22;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR23;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR24;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR25;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR26;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR27;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR28;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR29;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR30;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR31;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR32;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR33;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR34;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR35;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR36;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR37;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR38;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR39;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR40;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR41;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HWL						:16;
			_IO_UINT32								:16;
		} B;
	} DR42;
} BKP_Type;

/*------------------ Reset and Clock Control MANUAL.P77----------------------*/
typedef struct
{
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HSION					:1;
			_IO_UINT32 HSIRDY					:1;
			_IO_UINT32								:1;
			_IO_UINT32 HSITRIM				:5;
			_IO_UINT32 HSICAL					:8;
			_IO_UINT32 HSEON					:1;
			_IO_UINT32 HSERDY					:1;
			_IO_UINT32 HSEBYP					:1;
			_IO_UINT32 CSSON					:1;
			_IO_UINT32								:4;
			_IO_UINT32 PLLON					:1;
			_IO_UINT32 PLLRDY					:1;
			_IO_UINT32								:6;
		} B;
	} CR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 SW							:2;
			_IO_UINT32 SWS						:2;
			_IO_UINT32 HPRE						:4;
			_IO_UINT32 PPRE1					:3;
			_IO_UINT32 PPRE2					:3;
			_IO_UINT32 ADCPRE					:2;
			_IO_UINT32 PLLSRC					:1;
			_IO_UINT32 PLLXTPRE				:1;
			_IO_UINT32 PLLMUL					:4;
			_IO_UINT32 USBPRE					:1;
			_IO_UINT32								:1;
			_IO_UINT32 MCO						:3;
			_IO_UINT32								:5;
		} B;
	} CFGR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 LSIRDYF				:1;
			_IO_UINT32 LSERDYF				:1;
			_IO_UINT32 HSIRDYF				:1;
			_IO_UINT32 HSERDYF				:1;
			_IO_UINT32 PLLRDYF				:1;
			_IO_UINT32 PLL2RDYF				:1;
			_IO_UINT32 PLL3RDYF				:1;
			_IO_UINT32 CSSF						:1;
			_IO_UINT32 LSIRDYIE				:1;
			_IO_UINT32 LSERDYIE				:1;
			_IO_UINT32 HSIRDYIE				:1;
			_IO_UINT32 HSERDYIE				:1;
			_IO_UINT32 PLLRDYIE				:1;
			_IO_UINT32 PLL2RDYIE			:1;
			_IO_UINT32 PLL3RDYIE			:1;
			_IO_UINT32 								:1;
			_IO_UINT32 LSIRDYC				:1;
			_IO_UINT32 LSERDYC				:1;
			_IO_UINT32 HSIRDYC				:1;
			_IO_UINT32 HSERDYC				:1;
			_IO_UINT32 PLLRDYC				:1;
			_IO_UINT32 PLL2RDYC				:1;
			_IO_UINT32 PLL3RDYC				:1;
			_IO_UINT32 CSSC						:1;
			_IO_UINT32 								:8;
		} B;
	} CIR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 AFIORST				:1;
			_IO_UINT32								:1;
			_IO_UINT32 IOPARST				:1;
			_IO_UINT32 IOPBRST				:1;
			_IO_UINT32 IOPCRST				:1;
			_IO_UINT32 IOPDRST				:1;
			_IO_UINT32 IOPERST				:1;
			_IO_UINT32 IOPFRST				:1;
			_IO_UINT32 IOPGRST				:1;
			_IO_UINT32 ADC1RST				:1;
			_IO_UINT32 ADC2RST				:1;
			_IO_UINT32 TIM1RST				:1;
			_IO_UINT32 SPI1RST				:1;
			_IO_UINT32 TIM8RST				:1;
			_IO_UINT32 USART1RST			:1;
			_IO_UINT32 ADC3RST				:1;
			_IO_UINT32								:16;
			} B;
		} APB2RSTR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 TIM2RST				:1;
			_IO_UINT32 TIM3RST				:1;
			_IO_UINT32 TIM4RST				:1;
			_IO_UINT32 TIM5RST				:1;
			_IO_UINT32 TIM6RST				:1;
			_IO_UINT32 TIM7RST				:1;
			_IO_UINT32								:5;
			_IO_UINT32 WWGDRST				:1;
			_IO_UINT32 								:2;
			_IO_UINT32 SPI2RST				:1;
			_IO_UINT32 SPI3RST				:1;
			_IO_UINT32 								:1;
			_IO_UINT32 USART2RST			:1;
			_IO_UINT32 USART3RST			:1;
			_IO_UINT32 UART4RST				:1;
			_IO_UINT32 UART5RST				:1;
			_IO_UINT32 I2C1RST				:1;
			_IO_UINT32 I2C2RST				:1;
			_IO_UINT32 USBRST					:1;
			_IO_UINT32								:1;
			_IO_UINT32 CAN1RST				:1;
			_IO_UINT32 CAN2RST				:1;
			_IO_UINT32 BKPRST					:1;
			_IO_UINT32 PWRRST					:1;
			_IO_UINT32 DACRST					:1;
			_IO_UINT32								:2;
		} B;
	} APB1RSTR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DMA1EN					:1;
			_IO_UINT32 DMA2EN					:1;
			_IO_UINT32 SRAMEN					:1;
			_IO_UINT32 								:1;
			_IO_UINT32 FLITFEN				:1;
			_IO_UINT32 								:1;
			_IO_UINT32 CRCEN					:1;
			_IO_UINT32 								:1;
			_IO_UINT32 FSMCEN					:1;
			_IO_UINT32								:1;
			_IO_UINT32 SDIOEN					:1;
			_IO_UINT32								:21;
		} B;
	} AHBENR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 AFIOEN					:1;
			_IO_UINT32								:1;
			_IO_UINT32 IOPAEN					:1;
			_IO_UINT32 IOPBEN					:1;
			_IO_UINT32 IOPCEN					:1;
			_IO_UINT32 IOPDEN					:1;
			_IO_UINT32 IOPEEN					:1;
			_IO_UINT32 IOPFEN					:1;
			_IO_UINT32 IOPGEN					:1;
			_IO_UINT32 ADC1EN					:1;
			_IO_UINT32 ADC2EN					:1;
			_IO_UINT32 TIM1EN					:1;
			_IO_UINT32 SPI1EN					:1;
			_IO_UINT32 TIM8EN					:1;
			_IO_UINT32 USART1EN				:1;
			_IO_UINT32 ADC3EN					:1;
			_IO_UINT32								:16;
		} B;
	} APB2ENR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 TIM2EN					:1;
			_IO_UINT32 TIM3EN					:1;
			_IO_UINT32 TIM4EN					:1;
			_IO_UINT32 TIM5EN					:1;
			_IO_UINT32 TIM6EN					:1;
			_IO_UINT32 TIM7EN					:1;
			_IO_UINT32								:5;
			_IO_UINT32 WWGDEN					:1;
			_IO_UINT32								:2;
			_IO_UINT32 SPI2EN					:1;
			_IO_UINT32 SPI3EN					:1;
			_IO_UINT32								:1;
			_IO_UINT32 USART2EN 			:1;
			_IO_UINT32 USART3EN 			:1;
			_IO_UINT32 UART4EN				:1;
			_IO_UINT32 UART5EN				:1;
			_IO_UINT32 I2C1EN					:1;
			_IO_UINT32 I2C2EN					:1;
			_IO_UINT32 USBEN					:1;
			_IO_UINT32								:1;
			_IO_UINT32 CAN1EN					:1;
			_IO_UINT32 CAN2EN					:1;
			_IO_UINT32 BKPEN					:1;
			_IO_UINT32 PWREN					:1;
			_IO_UINT32 DACEN					:1;
			_IO_UINT32 								:2;
		} B;
	} APB1ENR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 LSEON					:1;
			_IO_UINT32 LSERDY					:1;
			_IO_UINT32 LSEBYP					:1;
			_IO_UINT32								:5;
			_IO_UINT32 RTCSEL					:2;
			_IO_UINT32								:5;
			_IO_UINT32 RTCEN					:1;
			_IO_UINT32 BDRST					:1;
			_IO_UINT32								:15;
		} B;
	} BDCR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 LSION					:1;
			_IO_UINT32 LSIRDY					:1;
			_IO_UINT32								:22;
			_IO_UINT32 RMVF						:1;
			_IO_UINT32								:1;
			_IO_UINT32 PINRSTF				:1;
			_IO_UINT32 PORRSTF				:1;
			_IO_UINT32 SFTRSTF				:1;
			_IO_UINT32 IWDGRSTF				:1;
			_IO_UINT32 WWDGRSTF				:1;
			_IO_UINT32 LPWRRSTF				:1;
		} B;
	} CSR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32								:12;
			_IO_UINT32 OTGFSRST				:1;
			_IO_UINT32								:1;
			_IO_UINT32 ETHMACRST			:1;
			_IO_UINT32								:17;
		} B;
	} AHBRSTR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 PRDIV1					:4;
			_IO_UINT32 PRDIV2					:4;
			_IO_UINT32 PLL2MUL				:4;
			_IO_UINT32 PLL3MU					:4;
			_IO_UINT32 PREDIV1SRC			:1;
			_IO_UINT32 I2S2SRC				:1;
			_IO_UINT32 I2S3SRC				:1;
			_IO_UINT32								:13;
		} B;
	} CFGR2;
} RCC_Type;

/*------------ General Purpose and Alternate Function IO MANUAL.P129---------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 MODE0					:2;
			_IO_UINT32 CNF0						:2;
			_IO_UINT32 MODE1					:2;
			_IO_UINT32 CNF1						:2;
			_IO_UINT32 MODE2					:2;
			_IO_UINT32 CNF2						:2;
			_IO_UINT32 MODE3					:2;
			_IO_UINT32 CNF3						:2;
			_IO_UINT32 MODE4					:2;
			_IO_UINT32 CNF4						:2;
			_IO_UINT32 MODE5					:2;
			_IO_UINT32 CNF5						:2;
			_IO_UINT32 MODE6					:2;
			_IO_UINT32 CNF6						:2;
			_IO_UINT32 MODE7					:2;
			_IO_UINT32 CNF7						:2;
		} B;
	} CRL;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 MODE8					:2;
			_IO_UINT32 CNF8						:2;
			_IO_UINT32 MODE9					:2;
			_IO_UINT32 CNF9						:2;
			_IO_UINT32 MODE10					:2;
			_IO_UINT32 CNF10					:2;
			_IO_UINT32 MODE11					:2;
			_IO_UINT32 CNF11					:2;
			_IO_UINT32 MODE12					:2;
			_IO_UINT32 CNF12					:2;
			_IO_UINT32 MODE13					:2;
			_IO_UINT32 CNF13					:2;
			_IO_UINT32 MODE14					:2;
			_IO_UINT32 CNF14					:2;
			_IO_UINT32 MODE15					:2;
			_IO_UINT32 CNF15					:2;
		} B;
	} CRH;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 IO0						:1;
			_IO_UINT32 IO1						:1;
			_IO_UINT32 IO2						:1;
			_IO_UINT32 IO3						:1;
			_IO_UINT32 IO4						:1;
			_IO_UINT32 IO5						:1;
			_IO_UINT32 IO6						:1;
			_IO_UINT32 IO7						:1;
			_IO_UINT32 IO8						:1;
			_IO_UINT32 IO9						:1;
			_IO_UINT32 IO10						:1;
			_IO_UINT32 IO11						:1;
			_IO_UINT32 IO12						:1;
			_IO_UINT32 IO13						:1;
			_IO_UINT32 IO14						:1;
			_IO_UINT32 IO15						:1;
			_IO_UINT32								:16;
		} B;
	} IDR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 IO0						:1;
			_IO_UINT32 IO1						:1;
			_IO_UINT32 IO2						:1;
			_IO_UINT32 IO3						:1;
			_IO_UINT32 IO4						:1;
			_IO_UINT32 IO5						:1;
			_IO_UINT32 IO6						:1;
			_IO_UINT32 IO7						:1;
			_IO_UINT32 IO8						:1;
			_IO_UINT32 IO9						:1;
			_IO_UINT32 IO10						:1;
			_IO_UINT32 IO11						:1;
			_IO_UINT32 IO12						:1;
			_IO_UINT32 IO13						:1;
			_IO_UINT32 IO14						:1;
			_IO_UINT32 IO15						:1;
			_IO_UINT32								:16;
		} B;
	} ODR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT16 SETIO;
			_IO_UINT16 CLRIO;
		} HW;
		struct {
			_IO_UINT32 SETIO0					:1;
			_IO_UINT32 SETIO1					:1;
			_IO_UINT32 SETIO2					:1;
			_IO_UINT32 SETIO3					:1;
			_IO_UINT32 SETIO4					:1;
			_IO_UINT32 SETIO5					:1;
			_IO_UINT32 SETIO6					:1;
			_IO_UINT32 SETIO7					:1;
			_IO_UINT32 SETIO8					:1;
			_IO_UINT32 SETIO9					:1;
			_IO_UINT32 SETIO10				:1;
			_IO_UINT32 SETIO11				:1;
			_IO_UINT32 SETIO12				:1;
			_IO_UINT32 SETIO13				:1;
			_IO_UINT32 SETIO14				:1;
			_IO_UINT32 SETIO15				:1;
			_IO_UINT32 CLRIO0					:1;
			_IO_UINT32 CLRIO1					:1;
			_IO_UINT32 CLRIO2					:1;
			_IO_UINT32 CLRIO3					:1;
			_IO_UINT32 CLRIO4					:1;
			_IO_UINT32 CLRIO5					:1;
			_IO_UINT32 CLRIO6					:1;
			_IO_UINT32 CLRIO7					:1;
			_IO_UINT32 CLRIO8					:1;
			_IO_UINT32 CLRIO9					:1;
			_IO_UINT32 CLRIO10				:1;
			_IO_UINT32 CLRIO11				:1;
			_IO_UINT32 CLRIO12				:1;
			_IO_UINT32 CLRIO13				:1;
			_IO_UINT32 CLRIO14				:1;
			_IO_UINT32 CLRIO15				:1;
		} B;
	} BSRR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CLRIO0					:1;
			_IO_UINT32 CLRIO1					:1;
			_IO_UINT32 CLRIO2					:1;
			_IO_UINT32 CLRIO3					:1;
			_IO_UINT32 CLRIO4					:1;
			_IO_UINT32 CLRIO5					:1;
			_IO_UINT32 CLRIO6					:1;
			_IO_UINT32 CLRIO7					:1;
			_IO_UINT32 CLRIO8					:1;
			_IO_UINT32 CLRIO9					:1;
			_IO_UINT32 CLRIO10				:1;
			_IO_UINT32 CLRIO11				:1;
			_IO_UINT32 CLRIO12				:1;
			_IO_UINT32 CLRIO13				:1;
			_IO_UINT32 CLRIO14				:1;
			_IO_UINT32 CLRIO15				:1;
			_IO_UINT32								:16;
		} B;
	} BRR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 LCK0						:1;
			_IO_UINT32 LCK1						:1;
			_IO_UINT32 LCK2						:1;
			_IO_UINT32 LCK3						:1;
			_IO_UINT32 LCK4						:1;
			_IO_UINT32 LCK5						:1;
			_IO_UINT32 LCK6						:1;
			_IO_UINT32 LCK7						:1;
			_IO_UINT32 LCK8						:1;
			_IO_UINT32 LCK9						:1;
			_IO_UINT32 LCK10					:1;
			_IO_UINT32 LCK11					:1;
			_IO_UINT32 LCK12					:1;
			_IO_UINT32 LCK13					:1;
			_IO_UINT32 LCK14					:1;
			_IO_UINT32 LCK15					:1;
			_IO_UINT32 LCKK						:1;
			_IO_UINT32								:15;
		} B;
	} LCKR;
} GPIO_Type;

typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 PIN						:4;
			_IO_UINT32 PORT						:3;
			_IO_UINT32 EVOE						:1;
			_IO_UINT32								:24;
		} B;
	} EVCR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 SPI1_REMAP			:1;
			_IO_UINT32 I2C1_REMAP			:1;
			_IO_UINT32 USART1_REMAP		:1;
			_IO_UINT32 USART2_REMAP		:1;
			_IO_UINT32 USART3_REMAP		:2;
			_IO_UINT32 TIM1_REMAP			:2;
			_IO_UINT32 TIM2_REMAP			:2;
			_IO_UINT32 TIM3_REMAP			:2;
			_IO_UINT32 TIM4_REMAP			:1;
			_IO_UINT32 CAN_REMAP			:2;
			_IO_UINT32 PD01_REMAP			:1;
			_IO_UINT32 TIM5CH4_IREMAP	:1;
			_IO_UINT32 ADC1_ETRGINJ_REMAP:1;
			_IO_UINT32 ADC1_ETRGREG_REMAP:1;
			_IO_UINT32 ADC2_ETRGINJ_REMAP:1;
			_IO_UINT32 ADC2_ETRGREG_REMAP:1;
			_IO_UINT32								:3;
			_IO_UINT32 SWJ_CFG				:3;
			_IO_UINT32								:5;
		} B;
	} MAPR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 EXTI00					:4;
			_IO_UINT32 EXTI01					:4;
			_IO_UINT32 EXTI02					:4;
			_IO_UINT32 EXTI03					:4;
			_IO_UINT32 								:16;
		} B;
	} EXTICR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 EXTI04					:4;
			_IO_UINT32 EXTI05					:4;
			_IO_UINT32 EXTI06					:4;
			_IO_UINT32 EXTI07					:4;
			_IO_UINT32								:16;
		} B;
	} EXTICR2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 EXTI08					:4;
			_IO_UINT32 EXTI09					:4;
			_IO_UINT32 EXTI10					:4;
			_IO_UINT32 EXTI11					:4;
			_IO_UINT32								:16;
		} B;
	} EXTICR3;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 EXTI12					:4;
			_IO_UINT32 EXTI13					:4;
			_IO_UINT32 EXTI14					:4;
			_IO_UINT32 EXTI15					:4;
			_IO_UINT32								:16;
		} B;
	} EXTICR4;
} AFIO_Type;

/*-------------- External Interrupt/Event Controller MANUAL.P141-------------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 MR00						:1;
			_IO_UINT32 MR01						:1;
			_IO_UINT32 MR02						:1;
			_IO_UINT32 MR03						:1;
			_IO_UINT32 MR04						:1;
			_IO_UINT32 MR05						:1;
			_IO_UINT32 MR06						:1;
			_IO_UINT32 MR07						:1;
			_IO_UINT32 MR08						:1;
			_IO_UINT32 MR09						:1;
			_IO_UINT32 MR10						:1;
			_IO_UINT32 MR11						:1;
			_IO_UINT32 MR12						:1;
			_IO_UINT32 MR13						:1;
			_IO_UINT32 MR14						:1;
			_IO_UINT32 MR15						:1;
			_IO_UINT32 MR16						:1;
			_IO_UINT32 MR17						:1;
			_IO_UINT32 MR18						:1;
			_IO_UINT32 MR19						:1;
			_IO_UINT32								:12;
		} B;
	} IMR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 MR00						:1;
			_IO_UINT32 MR01						:1;
			_IO_UINT32 MR02						:1;
			_IO_UINT32 MR03						:1;
			_IO_UINT32 MR04						:1;
			_IO_UINT32 MR05						:1;
			_IO_UINT32 MR06						:1;
			_IO_UINT32 MR07						:1;
			_IO_UINT32 MR08						:1;
			_IO_UINT32 MR09						:1;
			_IO_UINT32 MR10						:1;
			_IO_UINT32 MR11						:1;
			_IO_UINT32 MR12						:1;
			_IO_UINT32 MR13						:1;
			_IO_UINT32 MR14						:1;
			_IO_UINT32 MR15						:1;
			_IO_UINT32 MR16						:1;
			_IO_UINT32 MR17						:1;
			_IO_UINT32 MR18						:1;
			_IO_UINT32 MR19						:1;
			_IO_UINT32								:12;
		} B;
	} EMR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 TR00						:1;
			_IO_UINT32 TR01						:1;
			_IO_UINT32 TR02						:1;
			_IO_UINT32 TR03						:1;
			_IO_UINT32 TR04						:1;
			_IO_UINT32 TR05						:1;
			_IO_UINT32 TR06						:1;
			_IO_UINT32 TR07						:1;
			_IO_UINT32 TR08						:1;
			_IO_UINT32 TR09						:1;
			_IO_UINT32 TR10						:1;
			_IO_UINT32 TR11						:1;
			_IO_UINT32 TR12						:1;
			_IO_UINT32 TR13						:1;
			_IO_UINT32 TR14						:1;
			_IO_UINT32 TR15						:1;
			_IO_UINT32 TR16						:1;
			_IO_UINT32 TR17						:1;
			_IO_UINT32 TR18						:1;
			_IO_UINT32 TR19						:1;
			_IO_UINT32								:12;
		} B;
	} RTSR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 TR00						:1;
			_IO_UINT32 TR01						:1;
			_IO_UINT32 TR02						:1;
			_IO_UINT32 TR03						:1;
			_IO_UINT32 TR04						:1;
			_IO_UINT32 TR05						:1;
			_IO_UINT32 TR06						:1;
			_IO_UINT32 TR07						:1;
			_IO_UINT32 TR08						:1;
			_IO_UINT32 TR09						:1;
			_IO_UINT32 TR10						:1;
			_IO_UINT32 TR11						:1;
			_IO_UINT32 TR12						:1;
			_IO_UINT32 TR13						:1;
			_IO_UINT32 TR14						:1;
			_IO_UINT32 TR15						:1;
			_IO_UINT32 TR16						:1;
			_IO_UINT32 TR17						:1;
			_IO_UINT32 TR18						:1;
			_IO_UINT32 TR19						:1;
			_IO_UINT32								:12;
		} B;
	} FTSR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 SWIER00				:1;
			_IO_UINT32 SWIER01				:1;
			_IO_UINT32 SWIER02				:1;
			_IO_UINT32 SWIER03				:1;
			_IO_UINT32 SWIER04				:1;
			_IO_UINT32 SWIER05				:1;
			_IO_UINT32 SWIER06				:1;
			_IO_UINT32 SWIER07				:1;
			_IO_UINT32 SWIER08				:1;
			_IO_UINT32 SWIER09				:1;
			_IO_UINT32 SWIER10				:1;
			_IO_UINT32 SWIER11				:1;
			_IO_UINT32 SWIER12				:1;
			_IO_UINT32 SWIER13				:1;
			_IO_UINT32 SWIER14				:1;
			_IO_UINT32 SWIER15				:1;
			_IO_UINT32 SWIER16				:1;
			_IO_UINT32 SWIER17				:1;
			_IO_UINT32 SWIER18				:1;
			_IO_UINT32 SWIER19				:1;
			_IO_UINT32								:12;
		} B;
	} SWIER;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 PR00						:1;
			_IO_UINT32 PR01						:1;
			_IO_UINT32 PR02						:1;
			_IO_UINT32 PR03						:1;
			_IO_UINT32 PR04						:1;
			_IO_UINT32 PR05						:1;
			_IO_UINT32 PR06						:1;
			_IO_UINT32 PR07						:1;
			_IO_UINT32 PR08						:1;
			_IO_UINT32 PR09						:1;
			_IO_UINT32 PR10						:1;
			_IO_UINT32 PR11						:1;
			_IO_UINT32 PR12						:1;
			_IO_UINT32 PR13						:1;
			_IO_UINT32 PR14						:1;
			_IO_UINT32 PR15						:1;
			_IO_UINT32 PR16						:1;
			_IO_UINT32 PR17						:1;
			_IO_UINT32 PR18						:1;
			_IO_UINT32 PR19						:1;
			_IO_UINT32								:12;
		} B;
	} PR;
} EXTI_Type;

/*------------------- DMA Controller MANUAL.P153-----------------------------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 GIF1						:1;
			_IO_UINT32 TCIF1					:1;
			_IO_UINT32 HTIF1					:1;
			_IO_UINT32 TEIF1					:1;
			_IO_UINT32 GIF2						:1;
			_IO_UINT32 TCIF2					:1;
			_IO_UINT32 HTIF2					:1;
			_IO_UINT32 TEIF2					:1;
			_IO_UINT32 GIF3						:1;
			_IO_UINT32 TCIF3					:1;
			_IO_UINT32 HTIF3					:1;
			_IO_UINT32 TEIF3					:1;
			_IO_UINT32 GIF4						:1;
			_IO_UINT32 TCIF4					:1;
			_IO_UINT32 HTIF4					:1;
			_IO_UINT32 TEIF4					:1;
			_IO_UINT32 GIF5						:1;
			_IO_UINT32 TCIF5					:1;
			_IO_UINT32 HTIF5					:1;
			_IO_UINT32 TEIF5					:1;
			_IO_UINT32 GIF6						:1;
			_IO_UINT32 TCIF6					:1;
			_IO_UINT32 HTIF6					:1;
			_IO_UINT32 TEIF6					:1;
			_IO_UINT32 GIF7						:1;
			_IO_UINT32 TCIF7					:1;
			_IO_UINT32 HTIF7					:1;
			_IO_UINT32 TEIF7					:1;
			_IO_UINT32								:4;
		} B;
	} ISR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CGIF1					:1;
			_IO_UINT32 CTCIF1					:1;
			_IO_UINT32 CHTIF1					:1;
			_IO_UINT32 CTEIF1					:1;
			_IO_UINT32 CGIF2					:1;
			_IO_UINT32 CTCIF2					:1;
			_IO_UINT32 CHTIF2					:1;
			_IO_UINT32 CTEIF2					:1;
			_IO_UINT32 CGIF3					:1;
			_IO_UINT32 CTCIF3					:1;
			_IO_UINT32 CHTIF3					:1;
			_IO_UINT32 CTEIF3					:1;
			_IO_UINT32 CGIF4					:1;
			_IO_UINT32 CTCIF4					:1;
			_IO_UINT32 CHTIF4					:1;
			_IO_UINT32 CTEIF4					:1;
			_IO_UINT32 CGIF5					:1;
			_IO_UINT32 CTCIF5					:1;
			_IO_UINT32 CHTIF5					:1;
			_IO_UINT32 CTEIF5					:1;
			_IO_UINT32 CGIF6					:1;
			_IO_UINT32 CTCIF6					:1;
			_IO_UINT32 CHTIF6					:1;
			_IO_UINT32 CTEIF6					:1;
			_IO_UINT32 CGIF7					:1;
			_IO_UINT32 CTCIF7					:1;
			_IO_UINT32 CHTIF7					:1;
			_IO_UINT32 CTEIF7					:1;
			_IO_UINT32								:4;
		} B;
	} IFCR;
} DMA_Type;

typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 EN							:1;
			_IO_UINT32 TCIE						:1;
			_IO_UINT32 HTIE						:1;
			_IO_UINT32 TEIE						:1;
			_IO_UINT32 DIR						:1;
			_IO_UINT32 CIRC						:1;
			_IO_UINT32 PINC						:1;
			_IO_UINT32 MINC						:1;
			_IO_UINT32 PSIZE					:2;
			_IO_UINT32 MSIZE					:2;
			_IO_UINT32 PL							:2;
			_IO_UINT32 MEM2MEM				:1;
			_IO_UINT32								:17;
		} B;
	} CCR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 NDT						:16;
			_IO_UINT32								:16;
		} B;
	} CNDTR;
	union {
		_IO_UINT32 W;
	} CPAR;
	union {
		_IO_UINT32 W;
	} CMAR;
} DMA_CHANNEL_Type;

/*----------------- Analog to Digital Converter MANUAL.P180------------------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 AWD						:1;
			_IO_UINT32 EOC						:1;
			_IO_UINT32 JOC						:1;
			_IO_UINT32 JSTRT					:1;
			_IO_UINT32 STRT						:1;
			_IO_UINT32								:27;
		} B;
	} SR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 AWDCH					:5;
			_IO_UINT32 EOCIE					:1;
			_IO_UINT32 AWDIE					:1;
			_IO_UINT32 JEOCIE					:1;
			_IO_UINT32 SCAN						:1;
			_IO_UINT32 AWDSGL					:1;
			_IO_UINT32 JAUTO					:1;
			_IO_UINT32 DISCEN					:1;
			_IO_UINT32 JDISCEN				:1;
			_IO_UINT32 DISCNUM				:3;
			_IO_UINT32 DUALMOD				:4;
			_IO_UINT32								:2;
			_IO_UINT32 JAWDEN					:1;
			_IO_UINT32 AWDEN					:1;
			_IO_UINT32								:8;
		} B;
	} CR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 ADON						:1;
			_IO_UINT32 CONT						:1;
			_IO_UINT32 CAL						:1;
			_IO_UINT32 RSTCAL					:1;
			_IO_UINT32								:4;
			_IO_UINT32 DMA						:1;
			_IO_UINT32								:2;
			_IO_UINT32 ALIGN					:1;
			_IO_UINT32 JEXTSEL				:3;
			_IO_UINT32 JEXTTRIG				:1;
			_IO_UINT32								:1;
			_IO_UINT32 EXTSEL					:3;
			_IO_UINT32 EXTTRIG  			:1;
			_IO_UINT32 JSWSTART 			:1;
			_IO_UINT32 SWSTART				:1;
			_IO_UINT32 TSVREFE  			:1;
			_IO_UINT32								:8;
		} B;
	} CR2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 SMP10					:3;
			_IO_UINT32 SMP11					:3;
			_IO_UINT32 SMP12					:3;
			_IO_UINT32 SMP13					:3;
			_IO_UINT32 SMP14					:3;
			_IO_UINT32 SMP15					:3;
			_IO_UINT32 SMP16					:3;
			_IO_UINT32 SMP17					:3;
			_IO_UINT32								:8;
		} B;
	} SMPR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 SMP0						:3;
			_IO_UINT32 SMP1						:3;
			_IO_UINT32 SMP2						:3;
			_IO_UINT32 SMP3						:3;
			_IO_UINT32 SMP4						:3;
			_IO_UINT32 SMP5						:3;
			_IO_UINT32 SMP6						:3;
			_IO_UINT32 SMP7						:3;
			_IO_UINT32 SMP8						:3;
			_IO_UINT32 SMP9						:3;
			_IO_UINT32								:2;
		} B;
	} SMPR2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 JOFFSET1				:12;
			_IO_UINT32 								:20;
		} B;
	} JOFR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 JOFFSET2				:12;
			_IO_UINT32								:20;
		} B;
	} JOFR2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 JOFFSET3				:12;
			_IO_UINT32								:20;
		} B;
	} JOFR3;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 JOFFSET4				:12;
			_IO_UINT32								:20;
		} B;
	} JOFR4;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HT							:12;
			_IO_UINT32								:20;
		} B;
	} HTR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 LT							:12;
			_IO_UINT32								:20;
		} B;
	} LTR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 SQ13						:5;
			_IO_UINT32 SQ14						:5;
			_IO_UINT32 SQ15						:5;
			_IO_UINT32 SQ16						:5;
			_IO_UINT32 L							:4;
			_IO_UINT32								:8;
		} B;
	} SQR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 SQ7						:5;
			_IO_UINT32 SQ8						:5;
			_IO_UINT32 SQ9						:5;
			_IO_UINT32 SQ10						:5;
			_IO_UINT32 SQ11						:5;
			_IO_UINT32 SQ12						:5;
			_IO_UINT32								:2;
		} B;
	} SQR2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 SQ1						:5;
			_IO_UINT32 SQ2						:5;
			_IO_UINT32 SQ3						:5;
			_IO_UINT32 SQ4						:5;
			_IO_UINT32 SQ5						:5;
			_IO_UINT32 SQ6						:5;
			_IO_UINT32								:2;
		} B;
	} SQR3;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 JSQ1						:5;
			_IO_UINT32 JSQ2						:5;
			_IO_UINT32 JSQ3						:5;
			_IO_UINT32 JSQ4						:5;
			_IO_UINT32 JL							:2;
			_IO_UINT32								:10;
		} B;
	} JSQR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 JDATA					:16;
			_IO_UINT32								:16;
		} B;
	} JDR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 JDATA					:16;
			_IO_UINT32								:16;
		} B;
	} JDR2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 JDATA					:16;
			_IO_UINT32								:16;
		} B;
	} JDR3;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 JDATA					:16;
			_IO_UINT32								:16;
		} B;
	} JDR4;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DATA						:16;
			_IO_UINT32 ADC2DATA				:16;
		} B;
	} DR;
} ADC_Type;

/*----------------- Digital to Analog Converter MANUAL.P198------------------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 EN1						:1;
			_IO_UINT32 BOFF1					:1;
			_IO_UINT32 TEN1						:1;
			_IO_UINT32 TSEL1					:3;
			_IO_UINT32 WAVE1					:2;
			_IO_UINT32 MAMP1					:4;
			_IO_UINT32 DMAEN1					:1;
			_IO_UINT32								:3;
			_IO_UINT32 EN2						:1;
			_IO_UINT32 BOFF2					:1;
			_IO_UINT32 TEN2						:1;
			_IO_UINT32 TSEL2					:3;
			_IO_UINT32 WAVE2					:2;
			_IO_UINT32 MAMP2					:4;
			_IO_UINT32 DMAEN2					:1;
			_IO_UINT32 								:3;
		} B;
	} CR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 SWTRIG1				:1;
			_IO_UINT32 SWTRIG2				:1;
			_IO_UINT32								:30;
		} B;
	} SWTRIGR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DACC1DHR				:12;
			_IO_UINT32								:20;
		} B;
	} DHR12R1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32								:4;
			_IO_UINT32 DACC1DHR				:12;
			_IO_UINT32								:16;
		} B;
	} DHR12L1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DACC1DHR				:8;
			_IO_UINT32								:24;
		} B;
	} DHR8R1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DACC2DHR				:12;
			_IO_UINT32								:20;
		} B;
	} DHR12R2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32								:4;
			_IO_UINT32 DACC2DHR				:12;
			_IO_UINT32								:16;
		} B;
	} DHR12L2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DACC2DHR				:8;
			_IO_UINT32								:24;
		} B;
	} DHR8R2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DACC1DHR				:12;
			_IO_UINT32								:4;
			_IO_UINT32 DACC2DHR				:12;
			_IO_UINT32								:4;
		} B;
	} DHR12RD;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32								:4;
			_IO_UINT32 DACC1DHR				:12;
			_IO_UINT32 								:4;
			_IO_UINT32 DACC2DHR				:12;
		} B;
	} DHR12LD;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DACC1DHR				:8;
			_IO_UINT32 DACC2DHR				:8;
			_IO_UINT32								:16;
		} B;
	} DHR8RD;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DACC1DOR				:12;
			_IO_UINT32								:20;
		} B;
	} DOR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DACC2DOR				:12;
			_IO_UINT32								:20;
		} B;
	} DOR2;
} DAC_Type;

/*------------- Advanced-control timers (TIM1&TIM8) MANUAL.P251--------------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CEN						:1;
			_IO_UINT32 UDIS						:1;
			_IO_UINT32 URS						:1;
			_IO_UINT32 OPM						:1;
			_IO_UINT32 DIR						:1;
			_IO_UINT32 CMS						:2;
			_IO_UINT32 ARPE						:1;
			_IO_UINT32 CKD						:2;
			_IO_UINT32								:22;
		} B;
	} CR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CCPC						:1;
			_IO_UINT32								:1;
			_IO_UINT32 CCUS						:1;
			_IO_UINT32 CCDS						:1;
			_IO_UINT32 MMS						:3;
			_IO_UINT32 TI1S						:1;
			_IO_UINT32 OIS1						:1;
			_IO_UINT32 OIS1N					:1;
			_IO_UINT32 OIS2						:1;
			_IO_UINT32 OIS2N					:1;
			_IO_UINT32 OIS3						:1;
			_IO_UINT32 OIS3N					:1;
			_IO_UINT32 OIS4						:1;
			_IO_UINT32								:17;
		} B;
	} CR2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 SMS						:3;
			_IO_UINT32								:1;
			_IO_UINT32 TS							:3;
			_IO_UINT32 MSM						:1;
			_IO_UINT32 ETF						:4;
			_IO_UINT32 ETPS						:2;
			_IO_UINT32 ECE						:1;
			_IO_UINT32 ETP						:1;
			_IO_UINT32								:16;
		} B;
	} SMCR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 UIE						:1;
			_IO_UINT32 CC1IE					:1;
			_IO_UINT32 CC2IE					:1;
			_IO_UINT32 CC3IE					:1;
			_IO_UINT32 CC4IE					:1;
			_IO_UINT32 COMIE					:1;
			_IO_UINT32 TIE						:1;
			_IO_UINT32 BIE						:1;
			_IO_UINT32 UDE						:1;
			_IO_UINT32 CC1DE					:1;
			_IO_UINT32 CC2DE					:1;
			_IO_UINT32 CC3DE					:1;
			_IO_UINT32 CC4DE					:1;
			_IO_UINT32 COMDE					:1;
			_IO_UINT32 TDE						:1;
			_IO_UINT32								:17;
		} B;
	} DIER;
	union {
		struct {
		_IO_UINT32 W;
			_IO_UINT32 UIF						:1;
			_IO_UINT32 CC1IF					:1;
			_IO_UINT32 CC2IF					:1;
			_IO_UINT32 CC3IF					:1;
			_IO_UINT32 CC4IF					:1;
			_IO_UINT32 COMIF					:1;
			_IO_UINT32 TIF						:1;
			_IO_UINT32 BIF						:1;
			_IO_UINT32								:1;
			_IO_UINT32 CC1OF					:1;
			_IO_UINT32 CC2OF					:1;
			_IO_UINT32 CC3OF					:1;
			_IO_UINT32 CC4OF					:1;
			_IO_UINT32								:19;
		} B;
	} SR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 UG							:1;
			_IO_UINT32 CC1G						:1;
			_IO_UINT32 CC2G						:1;
			_IO_UINT32 CC3G						:1;
			_IO_UINT32 CC4G						:1;
			_IO_UINT32 COMG						:1;
			_IO_UINT32 TG							:1;
			_IO_UINT32 BG							:1;
			_IO_UINT32								:24;
		} B;
	} EGR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CC1S						:2;
			_IO_UINT32 OC1FE					:1;
			_IO_UINT32 OC1PE					:1;
			_IO_UINT32 OC1M						:3;
			_IO_UINT32 OC1CE					:1;
			_IO_UINT32 CC2S						:2;
			_IO_UINT32 OC2FE					:1;
			_IO_UINT32 OC2PE					:1;
			_IO_UINT32 OC2M						:3;
			_IO_UINT32 OC2CE					:1;
			_IO_UINT32								:16;
		} B_COMP;
		struct {
			_IO_UINT32 CC1S						:2;
			_IO_UINT32 IC1PSC					:2;
			_IO_UINT32 IC1F						:4;
			_IO_UINT32 CC2S						:2;
			_IO_UINT32 IC2PSC					:2;
			_IO_UINT32 IC2F						:4;
			_IO_UINT32								:16;
		} B_CAP;
	} CCMR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CC3S						:2;
			_IO_UINT32 OC3FE					:1;
			_IO_UINT32 OC3PE					:1;
			_IO_UINT32 OC3M						:3;
			_IO_UINT32 OC3CE					:1;
			_IO_UINT32 CC4S						:2;
			_IO_UINT32 OC4FE					:1;
			_IO_UINT32 OC4PE					:1;
			_IO_UINT32 OC4M						:3;
			_IO_UINT32 OC4CE					:1;
			_IO_UINT32								:16;
		} B_COMP;
		struct {
			_IO_UINT32 CC3S						:2;
			_IO_UINT32 IC3PSC					:2;
			_IO_UINT32 IC3F						:4;
			_IO_UINT32 CC4S						:2;
			_IO_UINT32 IC4PSC					:2;
			_IO_UINT32 IC4F						:4;
			_IO_UINT32								:16;
		} B_CAP;
	} CCMR2;
	union {
	_IO_UINT32 W;
		struct {
			_IO_UINT32 CC1E						:1;
			_IO_UINT32 CC1P						:1;
			_IO_UINT32 CC1NE					:1;
			_IO_UINT32 CC1NP					:1;
			_IO_UINT32 CC2E						:1;
			_IO_UINT32 CC2P						:1;
			_IO_UINT32 CC2NE					:1;
			_IO_UINT32 CC2NP					:1;
			_IO_UINT32 CC3E						:1;
			_IO_UINT32 CC3P						:1;
			_IO_UINT32 CC3NE					:1;
			_IO_UINT32 CC3NP					:1;
			_IO_UINT32 CC4E						:1;
			_IO_UINT32 CC4P						:1;
			_IO_UINT32								:18;
		} B;
	} CCER;
	union {
	_IO_UINT32 W;
		struct {
			_IO_UINT32 CNT						:16;
			_IO_UINT32								:16;
		} B;
	} CNT;
	union {
	_IO_UINT32 W;
		struct {
			_IO_UINT32 PSC						:16;
			_IO_UINT32								:16;
		} B;
	} PSC;
	union {
	_IO_UINT32 W;
		struct {
			_IO_UINT32 ARR						:16;
			_IO_UINT32								:16;
		} B;
	} ARR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 REP						: 8;
			_IO_UINT32								:24;
		} B;
	} RCR;
	union {
	_IO_UINT32 W;
		struct {
			_IO_UINT32 CCR						:16;
			_IO_UINT32								:16;
		} B;
	} CCR[4];
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DT							:8;
			_IO_UINT32 LOCK						:2;
			_IO_UINT32 OSSI						:1;
			_IO_UINT32 OSSR						:1;
			_IO_UINT32 BKE						:1;
			_IO_UINT32 BKP						:1;
			_IO_UINT32 AOE						:1;
			_IO_UINT32 MOE						:1;
			_IO_UINT32								:16;
		} B;
	} BDTR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DBA						:5;
			_IO_UINT32								:3;
			_IO_UINT32 DBL						:5;
			_IO_UINT32								:3;
			_IO_UINT32								:16;
		} B;
	} DCR;
	union {
	_IO_UINT32 W;
		struct {
			_IO_UINT32 DMAR						:16;
			_IO_UINT32								:16;
		} B;
	} DMAR;
} TIM_AC_Type;

/*------------ General-purpose timers (TIM2 to TIM5) MANUAL.P296-------------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CEN						:1;
			_IO_UINT32 UDIS						:1;
			_IO_UINT32 URS						:1;
			_IO_UINT32 OPM						:1;
			_IO_UINT32 DIR						:1;
			_IO_UINT32 CMS						:2;
			_IO_UINT32 ARPE						:1;
			_IO_UINT32 CKD						:2;
			_IO_UINT32								:22;
		} B;
	} CR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32								:3;
			_IO_UINT32 CCDS						:1;
			_IO_UINT32 MMS						:3;
			_IO_UINT32 TI1S						:1;
			_IO_UINT32								:22;
		} B;
	} CR2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 SMS						:3;
			_IO_UINT32								:1;
			_IO_UINT32 TS							:3;
			_IO_UINT32 MSM						:1;
			_IO_UINT32 ETF						:4;
			_IO_UINT32 ETPS						:2;
			_IO_UINT32 ECE						:1;
			_IO_UINT32 ETP						:1;
			_IO_UINT32								:16;
		} B;
	} SMCR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 UIE						:1;
			_IO_UINT32 CC1IE					:1;
			_IO_UINT32 CC2IE					:1;
			_IO_UINT32 CC3IE					:1;
			_IO_UINT32 CC4IE					:1;
			_IO_UINT32								:1;
			_IO_UINT32 TIE						:1;
			_IO_UINT32 								:1;
			_IO_UINT32 UDE						:1;
			_IO_UINT32 CC1DE					:1;
			_IO_UINT32 CC2DE					:1;
			_IO_UINT32 CC3DE					:1;
			_IO_UINT32 CC4DE					:1;
			_IO_UINT32								:1;
			_IO_UINT32 TDE						:1;
			_IO_UINT32 								:17;
		} B;
	} DIER;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 UIF						:1;
			_IO_UINT32 CC1IF					:1;
			_IO_UINT32 CC2IF					:1;
			_IO_UINT32 CC3IF					:1;
			_IO_UINT32 CC4IF					:1;
			_IO_UINT32								:1;
			_IO_UINT32 TIF						:1;
			_IO_UINT32								:2;
			_IO_UINT32 CC1OF					:1;
			_IO_UINT32 CC2OF					:1;
			_IO_UINT32 CC3OF					:1;
			_IO_UINT32 CC4OF					:1;
			_IO_UINT32								:19;
		} B;
	} SR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 UG							:1;
			_IO_UINT32 CC1G						:1;
			_IO_UINT32 CC2G						:1;
			_IO_UINT32 CC3G						:1;
			_IO_UINT32 CC4G						:1;
			_IO_UINT32								:1;
			_IO_UINT32 TG							:1;
			_IO_UINT32								:25;
		} B;
	} EGR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CC1S						:2;
			_IO_UINT32 OC1FE					:1;
			_IO_UINT32 OC1PE					:1;
			_IO_UINT32 OC1M						:3;
			_IO_UINT32 OC1CE					:1;
			_IO_UINT32 CC2S						:2;
			_IO_UINT32 OC2FE					:1;
			_IO_UINT32 OC2PE					:1;
			_IO_UINT32 OC2M						:3;
			_IO_UINT32 OC2CE					:1;
			_IO_UINT32								:16;
		} B_COMP;
		struct {
			_IO_UINT32 CC1S						:2;
			_IO_UINT32 IC1PSC					:2;
			_IO_UINT32 IC1F						:4;
			_IO_UINT32 CC2S						:2;
			_IO_UINT32 IC2PSC					:2;
			_IO_UINT32 IC2F						:4;
			_IO_UINT32								:16;
		} B_CAP;
	} CCMR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CC3S						:2;
			_IO_UINT32 OC3FE					:1;
			_IO_UINT32 OC3PE					:1;
			_IO_UINT32 OC3M						:3;
			_IO_UINT32 OC3CE					:1;
			_IO_UINT32 CC4S						:2;
			_IO_UINT32 OC4FE					:1;
			_IO_UINT32 OC4PE					:1;
			_IO_UINT32 OC4M						:3;
			_IO_UINT32 OC4CE					:1;
			_IO_UINT32								:16;
		} B_COMP;
		struct {
			_IO_UINT32 CC3S						:2;
			_IO_UINT32 IC3PSC					:2;
			_IO_UINT32 IC3F						:4;
			_IO_UINT32 CC4S						:2;
			_IO_UINT32 IC4PSC					:2;
			_IO_UINT32 IC4F						:4;
			_IO_UINT32								:16;
		} B_CAP;
	} CCMR2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CC1E						:1;
			_IO_UINT32 CC1P						:1;
			_IO_UINT32								:2;
			_IO_UINT32 CC2E						:1;
			_IO_UINT32 CC2P						:1;
			_IO_UINT32								:2;
			_IO_UINT32 CC3E						:1;
			_IO_UINT32 CC3P						:1;
			_IO_UINT32								:2;
			_IO_UINT32 CC4E						:1;
			_IO_UINT32 CC4P						:1;
			_IO_UINT32								:18;
		} B;
	} CCER;
	union {
	_IO_UINT32 W;
		struct {
			_IO_UINT32 CNT						:16;
			_IO_UINT32								:16;
		} B;
	} CNT;
	union {
	_IO_UINT32 W;
		struct {
			_IO_UINT32 PSC						:16;
			_IO_UINT32								:16;
		} B;
	} PSC;
	union {
	_IO_UINT32 W;
		struct {
			_IO_UINT32 ARR						:16;
			_IO_UINT32								:16;
		} B;
	} ARR;
	_UINT32 RESERVED0;
	union {
	_IO_UINT32 W;
		struct {
			_IO_UINT32 CCR						:16;
			_IO_UINT32								:16;
		} B;
	} CCR[4];
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DBA						:5;
			_IO_UINT32								:3;
			_IO_UINT32 DBL						:5;
			_IO_UINT32								:3;
			_IO_UINT32								:16;
		} B;
	} DCR;
	union {
	_IO_UINT32 W;
		struct {
			_IO_UINT32 DMAR						:16;
			_IO_UINT32								:16;
		} B;
	} DMAR;
} TIM_GP_Type;

/*------------------ Basic timers (TIM6&TIM7) MANUAL.P307--------------------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CEN						:1;
			_IO_UINT32 UDIS						:1;
			_IO_UINT32 URS						:1;
			_IO_UINT32 OPM						:1;
			_IO_UINT32								:3;
			_IO_UINT32 ARPE						:1;
			_IO_UINT32								:24;
		} B;
	} CR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32								:4;
			_IO_UINT32 MMS						:3;
			_IO_UINT32								:25;
		} B;
	} CR2;
	_UINT32 RESERVED0;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 UIE						:1;
			_IO_UINT32								:7;
			_IO_UINT32 UDE						:1;
			_IO_UINT32								:23;
		} B;
	} DIER;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 UIF						:1;
			_IO_UINT32								:31;
		} B;
	} SR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 UG						:1;
			_IO_UINT32							:31;
		} B;
	} EGR;
	_UINT32 RESERVED1[3];
	union {
	_IO_UINT32 W;
		struct {
			_IO_UINT32 CNT						:16;
			_IO_UINT32								:16;
		} B;
	} CNT;
	union {
	_IO_UINT32 W;
		struct {
			_IO_UINT32 PSC						:16;
			_IO_UINT32								:16;
		} B;
	} PSC;
	union {
	_IO_UINT32 W;
		struct {
			_IO_UINT32 ARR						:16;
			_IO_UINT32								:16;
		} B;
	} ARR;
} TIM_BS_Type;

/*--------------------- Real-Time Clock MANUAL.P315--------------------------*/
	typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 SECIE					:1;
			_IO_UINT32 ALRIE					:1;
			_IO_UINT32 OWIE						:1;
			_IO_UINT32								:29;
		} B;
	} CRH;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 SECF						:1;
			_IO_UINT32 ALRF						:1;
			_IO_UINT32 OWF						:1;
			_IO_UINT32 RSF						:1;
			_IO_UINT32 CNF						:1;
			_IO_UINT32 RTOFF					:1;
			_IO_UINT32								:26;
		} B;
	} CRL;
	union {
	_IO_UINT32 W;
		struct {
			_IO_UINT32 PRL						:4;
			_IO_UINT32								:28;
		} B;
	} PRLH;
	union {
	_IO_UINT32 W;
		struct {
			_IO_UINT32 PRL						:16;
			_IO_UINT32								:16;
		} B;
	} PRLL;
	union {
	_IO_UINT32 W;
		struct {
			_IO_UINT32 DIV						:16;
			_IO_UINT32								:16;
		} B;
	} DIVH;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DIV						:16;
			_IO_UINT32								:16;
		} B;
	} DIVL;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CNT						:16;
			_IO_UINT32								:16;
		} B;
	} CNTH;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CNT						:16;
			_IO_UINT32								:16;
		} B;
	} CNTL;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 ALR						:16;
			_IO_UINT32								:16;
		} B;
	} ALRH;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 ALR						:16;
			_IO_UINT32								:16;
		} B;
	} ALRL;
} RTC_Type;

/*------------------ Independent WATCHDOG MANUAL.P319------------------------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 KEY						:16;
			_IO_UINT32								:16;
		} B;
	} KR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 PR							:3;
			_IO_UINT32								:29;
		} B;
	} PR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 RL							:12;
			_IO_UINT32								:20;
		} B;
	} RLR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 PVU						:1;
			_IO_UINT32 RVU						:1;
			_IO_UINT32								:30;
		} B;
	} SR;
} IWDG_Type;

/*---------------------- Window WATCHDOG MANUAL.P323-------------------------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 T							:7;
			_IO_UINT32 WDGA						:2;
			_IO_UINT32								:23;

		} B;
	} CR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 W							:7;
			_IO_UINT32 WDGTB0					:1;
			_IO_UINT32 WDGTB1					:1;
			_IO_UINT32 EWI						:1;
			_IO_UINT32								:22;
		} B;
	} CFR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 EWIF						:1;
			_IO_UINT32								:31;
		} B;
	} SR;
} WWDG_Type;

/*-------------- Flexible Static Memory Controller MANUAL.P362---------------*/
typedef struct {
	_IO_UINT32 BCR1;
	_IO_UINT32 BTR1;
	_IO_UINT32 BCR2;
	_IO_UINT32 BTR2;
	_IO_UINT32 BCR3;
	_IO_UINT32 BTR3;
	_IO_UINT32 BCR4;
	_IO_UINT32 BTR4;
} FSMC_Bank1_Type;

typedef struct {
	_IO_UINT32 PCR2;
	_IO_UINT32 SR2;
	_IO_UINT32 PMEM2;
	_IO_UINT32 PATT2;
	_UINT32 RESERVED0;
	_IO_UINT32 ECCR2;
} FSMC_Bank2_Type;

typedef struct {
	_IO_UINT32 PCR3;
	_IO_UINT32 SR3;
	_IO_UINT32 PMEM3;
	_IO_UINT32 PATT3;
	_UINT32 RESERVED0;
	_IO_UINT32 ECCR3;
} FSMC_Bank3_Type;

typedef struct {
	_IO_UINT32 PCR4;
	_IO_UINT32 SR4;
	_IO_UINT32 PMEM4;
	_IO_UINT32 PATT4;
	_IO_UINT32 PIO4;
} FSMC_Bank4_Type;

typedef struct {
	_IO_UINT32 BWTR1;
	_UINT32 RESERVED0;
	_IO_UINT32 BWTR2;
	_UINT32 RESERVED1;
	_IO_UINT32 BWTR3;
	_UINT32 RESERVED2;
	_IO_UINT32 BWTR4;
	_UINT32 RESERVED3;
} FSMC_Bank1E_Type;

/*----------- Secure digital input/output interface MANUAL.P402--------------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 PWRCTRL				:2;
			_IO_UINT32 								:30;
		} B;
	} POWER;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CLKDIV					:8;
			_IO_UINT32 CLKEN					:1;
			_IO_UINT32 PWRSAV					:1;
			_IO_UINT32 BYPASS					:1;
			_IO_UINT32 WIDBUS					:2;
			_IO_UINT32 NEGEDGE				:1;
			_IO_UINT32 HWFC_EN				:1;
			_IO_UINT32 								:17;
		} B;
	} CLKCR;
	union {
		_IO_UINT32 W;
	}	ARG;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CMDINDEX				:6;
			_IO_UINT32 WAITRESP				:2;
			_IO_UINT32 WAITINT				:1;
			_IO_UINT32 WAITPEND				:1;
			_IO_UINT32 CPSMEN					:1;
			_IO_UINT32 SDIOsuspend		:1;
			_IO_UINT32 ENCMDcompl			:1;
			_IO_UINT32 nIEN						:1;
			_IO_UINT32 CE_ATACMD			:1;
			_IO_UINT32 								:17;
		} B;
	} CMD;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 RESPCMD				:6;
			_IO_UINT32 								:26;
		} B;
	} RESPCMD;
	union {
		_IO_UINT32 W;
	} RESP1;
	union {
		_IO_UINT32 W;
	} RESP2;
	union {
		_IO_UINT32 W;
	} RESP3;
	union {
		_IO_UINT32 W;
	} RESP4;
	union {
		_IO_UINT32 W;
	} DTIMER;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DATALENGTH			:25;
			_IO_UINT32 								:7;
		} B;
	} DLEN;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DTEN						:1;
			_IO_UINT32 DTDIR					:1;
			_IO_UINT32 DTMODE					:1;
			_IO_UINT32 DMAEN					:1;
			_IO_UINT32 DBLOCKSIZE			:4;
			_IO_UINT32 RWSTART				:1;
			_IO_UINT32 RWSTOP					:1;
			_IO_UINT32 RWMOD					:1;
			_IO_UINT32 SDIOEN					:1;
			_IO_UINT32 								:20;
		} B;
	} DCTRL;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DATACOUNT			:25;
			_IO_UINT32 								:7;
		} B;
	} DCOUNT;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CCRCFAIL				:1;
			_IO_UINT32 DCRCFAIL				:1;
			_IO_UINT32 CTIMEOUT				:1;
			_IO_UINT32 DTMEOUT				:1;
			_IO_UINT32 TXUNDERR				:1;
			_IO_UINT32 RXOVERR				:1;
			_IO_UINT32 CMDREND				:1;
			_IO_UINT32 CMDSENT				:1;
			_IO_UINT32 DATAEND				:1;
			_IO_UINT32 STBITERR				:1;
			_IO_UINT32 DBCKEND				:1;
			_IO_UINT32 CMDACT					:1;
			_IO_UINT32 TXACT					:1;
			_IO_UINT32 RXACT					:1;
			_IO_UINT32 TXFIFOHE				:1;
			_IO_UINT32 RXFIFOHF				:1;
			_IO_UINT32 TXFIFOF				:1;
			_IO_UINT32 RXFIFOF				:1;
			_IO_UINT32 TXFIFOE				:1;
			_IO_UINT32 RXFIFOE				:4;
			_IO_UINT32 TXDAVL					:1;
			_IO_UINT32 RXDAVL					:1;
			_IO_UINT32 SDIOIT					:1;
			_IO_UINT32 CEATAEND				:1;
			_IO_UINT32 								:8;	
		} B;
	} STA;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CCRCFAILC			:1;
			_IO_UINT32 DCRCFAILC			:1;
			_IO_UINT32 CTIMEOUTC			:1;
			_IO_UINT32 DTMEOUTC				:1;
			_IO_UINT32 TXUNDERRC			:1;
			_IO_UINT32 RXOVERRC				:1;
			_IO_UINT32 CMDRENDC				:1;
			_IO_UINT32 CMDSENTC				:1;
			_IO_UINT32 DATAENDC				:1;
			_IO_UINT32 STBITERRC			:1;
			_IO_UINT32 DBCKENDC				:1;
			_IO_UINT32 								:11;
			_IO_UINT32 SDIOITC				:1;
			_IO_UINT32 CEATAENDC			:1;
			_IO_UINT32 								:8;
		} B;
	} ICR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CCRCFAILIE			:1;
			_IO_UINT32 DCRCFAILIE			:1;
			_IO_UINT32 CTIMEOUTIE			:1;
			_IO_UINT32 DTMEOUTIE			:1;
			_IO_UINT32 TXUNDERRIE			:1;
			_IO_UINT32 RXOVERRIE			:1;
			_IO_UINT32 CMDRENDIE			:1;
			_IO_UINT32 CMDSENTIE			:1;
			_IO_UINT32 DATAENDIE			:1;
			_IO_UINT32 STBITERRIE			:1;
			_IO_UINT32 DBCKENDIE			:1;
			_IO_UINT32 CMDACTIE				:1;
			_IO_UINT32 TXACTIE				:1;
			_IO_UINT32 RXACTIE				:1;
			_IO_UINT32 TXFIFOHEIE			:1;
			_IO_UINT32 RXFIFOHFIE			:1;
			_IO_UINT32 TXFIFOFIE			:1;
			_IO_UINT32 RXFIFOFIE			:1;
			_IO_UINT32 TXFIFOEIE			:1;
			_IO_UINT32 RXFIFOEIE			:1;
			_IO_UINT32 TXDAVLIE				:1;
			_IO_UINT32 RXDAVLIE				:1;
			_IO_UINT32 SDIOITIE				:1;
			_IO_UINT32 CEATAENDIE			:1;
			_IO_UINT32 								:8;
		} B;
	} MASK;
	_UINT32 RESERVED0[2];
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 FIFOCOUNT			:24;
			_IO_UINT32 								:8;
		} B;
	} FIFOCNT;
	_UINT32 RESERVED1[13];
	union {
		_IO_UINT32 W;
	} FIFO;
} SDIO_Type;

/*----- Universal serial bus full -speed device interface MANUAL.P421--------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 EA							:4;
			_IO_UINT32 STAT_TX				:2;
			_IO_UINT32 DTOG_TX				:1;
			_IO_UINT32 CTR_TX					:1;
			_IO_UINT32 EP_KIND				:1;
			_IO_UINT32 EPTYPE					:2;
			_IO_UINT32 SETUP					:1;
			_IO_UINT32 STAT_RX				:2;
			_IO_UINT32 DTOG_RX				:1;
			_IO_UINT32 CTR_RX					:1;
			_IO_UINT32								:16;
		} B;
	} EP0R;
} USB_ERxR_Type;

typedef struct {
	USB_ERxR_Type ERxR[8];
	_UINT32 RESERVED0[8];
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 FRES						:1;
			_IO_UINT32 PDWN						:1;
			_IO_UINT32 LPMODE					:1;
			_IO_UINT32 FSUSP					:1;
			_IO_UINT32 RESUME					:1;
			_IO_UINT32								:3;
			_IO_UINT32 ESOFM					:1;
			_IO_UINT32 SOFM						:1;
			_IO_UINT32 RESETM					:1;
			_IO_UINT32 SUSPM					:1;
			_IO_UINT32 WKUPM					:1;
			_IO_UINT32 ERRM						:1;
			_IO_UINT32 PMAOVRM				:1;
			_IO_UINT32 CTRM						:1;
			_IO_UINT32								:16;
		} B;
	} CNTR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 EP_ID					:4;
			_IO_UINT32 DIR						:1;
			_IO_UINT32								:3;
			_IO_UINT32 ESOF						:1;
			_IO_UINT32 SOF						:1;
			_IO_UINT32 RESET					:1;
			_IO_UINT32 SUSP						:1;
			_IO_UINT32 WKUP						:1;
			_IO_UINT32 ERR						:1;
			_IO_UINT32 PMAOVR					:1;
			_IO_UINT32 CTR						:1;
			_IO_UINT32								:16;
		} B;
	} CISTR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 FN							:11;
			_IO_UINT32 LSOF						:2;
			_IO_UINT32 LCK						:1;
			_IO_UINT32 RXDM						:1;
			_IO_UINT32 RXDP						:1;
			_IO_UINT32								:16;
		} B;
	} FNR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 ADD						:7;
			_IO_UINT32 EF							:1;
			_IO_UINT32								:24;
		} B;
	} DADDR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32								:3;
			_IO_UINT32 BTABLE					:13;
			_IO_UINT32								:16;
		} B;
	} BTABLE;
} USB_Type;

/*------------------ Controller Area Network MANUAL.P454---------------------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 INRQ						:1;
			_IO_UINT32 SLEEP					:1;
			_IO_UINT32 TXFP						:1;
			_IO_UINT32 RFLM						:1;
			_IO_UINT32 NART						:1;
			_IO_UINT32 AWUM						:1;
			_IO_UINT32 ABOM						:1;
			_IO_UINT32 TTCM						:1;
			_IO_UINT32								:7;
			_IO_UINT32 RESET					:1;
			_IO_UINT32								:16;
		} B;
	} MCR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 INAK						:1;
			_IO_UINT32 SLAK						:1;
			_IO_UINT32 ERRI						:1;
			_IO_UINT32 WKUI						:1;
			_IO_UINT32 SLAKI					:1;
			_IO_UINT32								:3;
			_IO_UINT32 TXM						:1;
			_IO_UINT32 RXM						:1;
			_IO_UINT32 SAMP						:1;
			_IO_UINT32 RX							:1;
			_IO_UINT32								:20;
		} B;
	} MSR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 RQCP0					:1;
			_IO_UINT32 TXOK0					:1;
			_IO_UINT32 ALST0					:1;
			_IO_UINT32 TERR0					:1;
			_IO_UINT32								:3;
			_IO_UINT32 ABRQ0					:1;
			_IO_UINT32 RQCP1					:1;
			_IO_UINT32 TXOK1					:1;
			_IO_UINT32 ALST1					:1;
			_IO_UINT32 TERR1					:1;
			_IO_UINT32								:3;
			_IO_UINT32 ABRQ1					:1;
			_IO_UINT32 RQCP2					:1;
			_IO_UINT32 TXOK2					:1;
			_IO_UINT32 ALST2					:1;
			_IO_UINT32 TERR2					:1;
			_IO_UINT32								:3;
			_IO_UINT32 ABRQ2					:1;
			_IO_UINT32 CODE						:2;
			_IO_UINT32 TME						:3;
			_IO_UINT32 LOW						:3;
		} B;
	} TSR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 FMP0						:2;
			_IO_UINT32								:1;
			_IO_UINT32 FULL0					:1;
			_IO_UINT32 FOVR0					:1;
			_IO_UINT32 RFOM0					:1;
			_IO_UINT32								:26;
		} B;
	} RF0R;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 FMP1						:2;
			_IO_UINT32								:1;
			_IO_UINT32 FULL1					:1;
			_IO_UINT32 FOVR1					:1;
			_IO_UINT32 RFOM1					:1;
			_IO_UINT32								:26;
		} B;
	} RF1R;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 TMEIE					:1;
			_IO_UINT32 FMPIE0					:1;
			_IO_UINT32 FFIE0					:1;
			_IO_UINT32 FOVIE0					:1;
			_IO_UINT32 FMPIE1					:1;
			_IO_UINT32 FFIE1					:1;
			_IO_UINT32 FOVIE1					:1;
			_IO_UINT32								:1;
			_IO_UINT32 EWGIE					:1;
			_IO_UINT32 EPVIE					:1;
			_IO_UINT32 BOFIE					:1;
			_IO_UINT32 LECIE					:1;
			_IO_UINT32								:3;
			_IO_UINT32 ERRIE					:1;
			_IO_UINT32 WKUIE					:1;
			_IO_UINT32 SLKIE					:1;
			_IO_UINT32								:14;
		} B;
	} IER;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 EWGF						:1;
			_IO_UINT32 EPVF						:1;
			_IO_UINT32 BOFF						:1;
			_IO_UINT32								:1;
			_IO_UINT32 LEC						:3;
			_IO_UINT32								:9;
			_IO_UINT32 TEC						:8;
			_IO_UINT32 REC						:8;
		} B;
	} ESR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 BRP						:10;
			_IO_UINT32								:6;
			_IO_UINT32 TS1						:4;
			_IO_UINT32 TS2						:3;
			_IO_UINT32								:1;
			_IO_UINT32 SJW						:2;
			_IO_UINT32								:4;
			_IO_UINT32 LBKM						:1;
			_IO_UINT32 SILM						:1;
		} B;
	} BTR;
	_UINT32 RESERVED0[58];
	struct {
		union {
			_IO_UINT32 W;
			struct {
				_IO_UINT32 TXRQ						:1;
				_IO_UINT32 RTR						:1;
				_IO_UINT32 IDE						:1;
				_IO_UINT32 EXID						:29;
			} BExt;
			struct {
				_IO_UINT32 TXRQ						:1;
				_IO_UINT32 RTR						:1;
				_IO_UINT32 IDE						:1;
				_IO_UINT32								:18;
				_IO_UINT32 STID						:11;
			} B;
		} TIR;
		union {
			_IO_UINT32 W;
			struct {
				_IO_UINT32 DLC						:4;
				_IO_UINT32								:4;
				_IO_UINT32 TGT						:1;
				_IO_UINT32								:7;
				_IO_UINT32 TIME						:16;
			} B;
		} TDTR;
		union {
			_IO_UINT32 W;
			struct {
				_IO_UINT32 DATA0					:8;
				_IO_UINT32 DATA1					:8;
				_IO_UINT32 DATA2					:8;
				_IO_UINT32 DATA3					:8;
			} B;
		} TDLR;
		union {
			_IO_UINT32 W;
			struct {
				_IO_UINT32 DATA4					:8;
				_IO_UINT32 DATA5					:8;
				_IO_UINT32 DATA6					:8;
				_IO_UINT32 DATA7					:8;
			} B;
		} TDHR;
	} sTxMailBox[3];
	struct {
		union {
			_IO_UINT32 W;
			struct {
				_IO_UINT32								:1;
				_IO_UINT32 RTR						:1;
				_IO_UINT32 IDE						:1;
				_IO_UINT32 EXID						:29;
			} BExt;
			struct {
				_IO_UINT32								:1;
				_IO_UINT32 RTR						:1;
				_IO_UINT32 IDE						:1;
				_IO_UINT32								:18;
				_IO_UINT32 STID						:11;
			} B;
		} RIR;
		union {
			_IO_UINT32 W;
			struct {
				_IO_UINT32 DLC						:4;
				_IO_UINT32								:4;
				_IO_UINT32 FMI						:8;
				_IO_UINT32 TIME						:16;
			} B;
		} RDTR;
		union {
			_IO_UINT32 W;
			struct {
				_IO_UINT32 DATA0					:8;
				_IO_UINT32 DATA1					:8;
				_IO_UINT32 DATA2					:8;
				_IO_UINT32 DATA3					:8;
			} B;
		} RDLR;
		union {
			_IO_UINT32 W;
			struct {
				_IO_UINT32 DATA4					:8;
				_IO_UINT32 DATA5					:8;
				_IO_UINT32 DATA6					:8;
				_IO_UINT32 DATA7					:8;
			} B;
		} RDHR;
	} sFIFOMailBox[2];
	_UINT32 RESERVED1[12];
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 FINIT					:1;
			_IO_UINT32								:7;
			_IO_UINT32 CAN2SB					:6;
			_IO_UINT32								:18;
		} B;
	} FMR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 FBM						:28;
			_IO_UINT32								:4;
		} B;
	} FM1R;
	_UINT32 RESERVED2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 FSC0						:28;
			_IO_UINT32								:4;
		} B;
	} FS1R;
	_UINT32 RESERVED3;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 FFA						:28;
			_IO_UINT32								:4;
		} B;
	} FFA1R;
	_UINT32 RESERVED4;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 FACT						:28;
			_IO_UINT32								:4;
		} B;
	} FA1R;
	_UINT32 RESERVED5[8];
	struct {
		union {
			_IO_UINT32 W;
		} FxR1;
		union {
			_IO_UINT32 W;
		} FxR2;
	} sFilterRegister[28];
} CAN_Type;

/*------------------ Serial Peripheral Interface MANUAL.P492-----------------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CPHA						:1;
			_IO_UINT32 CPOL						:1;
			_IO_UINT32 MSTR						:1;
			_IO_UINT32 BR							:3;
			_IO_UINT32 SPE						:1;
			_IO_UINT32 LSBFIRST				:1;
			_IO_UINT32 SSI						:1;
			_IO_UINT32 SSM						:1;
			_IO_UINT32 RXONLY					:1;
			_IO_UINT32 DFF						:1;
			_IO_UINT32 CRCNEXT				:1;
			_IO_UINT32 CRCEN					:1;
			_IO_UINT32 BIDIOE					:1;
			_IO_UINT32 BIDIMODE				:1;
			_IO_UINT32								:16;
		} B;
	} CR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 RXDMAEN				:1;
			_IO_UINT32 TXDMAEN				:1;
			_IO_UINT32 SSOE						:1;
			_IO_UINT32								:2;
			_IO_UINT32 ERRIE					:1;
			_IO_UINT32 RXNEIE					:1;
			_IO_UINT32 TXEIE					:1;
			_IO_UINT32								:24;
		} B;
	}  CR2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 RXNE						:1;
			_IO_UINT32 TXE						:1;
			_IO_UINT32								:2;
			_IO_UINT32 CRCERR					:1;
			_IO_UINT32 MODF						:1;
			_IO_UINT32 OVR						:1;
			_IO_UINT32 BSY						:1;
			_IO_UINT32								:24;
		} B;
	}  SR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DATA						:16;
			_IO_UINT32								:16;
		} B;
	} DR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CRCPOLY				:16;
			_IO_UINT32								:16;
		} B;
	} CRCPR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 RxCRC					:16;
			_IO_UINT32								:16;
		} B;
	} RXCRCR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 TxCRC					:16;
			_IO_UINT32								:16;
		} B;
	} TXCRCR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CHLEN					:1;
			_IO_UINT32 DATLEN					:2;
			_IO_UINT32 CKPOL					:1;
			_IO_UINT32 I2SSTD					:2;
			_IO_UINT32								:1;
			_IO_UINT32 PCMSYNC				:1;
			_IO_UINT32 I2SCFG					:2;
			_IO_UINT32 I2SE						:1;
			_IO_UINT32 I2SMOD					:1;
			_IO_UINT32								:20;
		} B;
	}  I2SCFGR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 I2SDIV					:8;
			_IO_UINT32 ODD						:1;
			_IO_UINT32 MCKOE					:1;
			_IO_UINT32								:22;
		} B;
	}  I2SPR;
} SPI_Type;

/*-------------- Inter-integrated Circuit Interface MANUAL.P515--------------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 PE							:1;
			_IO_UINT32 SMBUS					:1;
			_IO_UINT32								:1;
			_IO_UINT32 SMBTYPE				:1;
			_IO_UINT32 ENARP					:1;
			_IO_UINT32 ENPEC					:1;
			_IO_UINT32 ENGC						:1;
			_IO_UINT32 NOSTRETCH			:1;
			_IO_UINT32 START					:1;
			_IO_UINT32 STOP						:1;
			_IO_UINT32 ACK						:1;
			_IO_UINT32 POS						:1;
			_IO_UINT32 PEC						:1;
			_IO_UINT32 ALERT					:1;
			_IO_UINT32								:1;
			_IO_UINT32 SWRST					:1;
			_IO_UINT32								:16;
		} B;
	} CR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 FREQ						:6;
			_IO_UINT32								:2;
			_IO_UINT32 ITERREN				:1;
			_IO_UINT32 ITEVTEN				:1;
			_IO_UINT32 ITBUFEN				:1;
			_IO_UINT32 DMAEN					:1;
			_IO_UINT32 LAST						:1;
			_IO_UINT32								:19;
		} B;
	} CR2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 ADD						:10;
			_IO_UINT32								:5;
			_IO_UINT32 ADDMODE				:1;
			_IO_UINT32								:16;
		} B10bit;
		struct {
			_IO_UINT32								:1;
			_IO_UINT32 ADD						:7;
			_IO_UINT32								:7;
			_IO_UINT32 ADDMODE				:1;
			_IO_UINT32								:16;
		} B7bit;
	} OAR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 ENDUAL					:1;
			_IO_UINT32 ADD2						:7;
			_IO_UINT32								:24;
		} B;
	} OAR2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DR							:8;
			_IO_UINT32								:24;
		} B;
	} DR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 SB							:1;
			_IO_UINT32 ADDR						:1;
			_IO_UINT32 BTF						:1;
			_IO_UINT32 ADD10					:1;
			_IO_UINT32 STOPF					:1;
			_IO_UINT32								:1;
			_IO_UINT32 RXNE						:1;
			_IO_UINT32 TXE						:1;
			_IO_UINT32 BERR						:1;
			_IO_UINT32 ARLO						:1;
			_IO_UINT32 AF							:1;
			_IO_UINT32 OVR						:1;
			_IO_UINT32 PECERR					:1;
			_IO_UINT32								:1;
			_IO_UINT32 TIMEOUT				:1;
			_IO_UINT32 SMBALERT				:1;
			_IO_UINT32								:16;
		} B;	
	} SR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 MSL						:1;
			_IO_UINT32 BUSY						:1;
			_IO_UINT32 TRA						:1;
			_IO_UINT32								:1;
			_IO_UINT32 GENCALL				:1;
			_IO_UINT32 SMBDEFAULT			:1;
			_IO_UINT32 SMBHOST				:1;
			_IO_UINT32 DUALF					:1;
			_IO_UINT32 PEC						:8;
			_IO_UINT32								:16;
		} B;
	} SR2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 CCR						:12;
			_IO_UINT32								:2;
			_IO_UINT32 DUTY						:1;
			_IO_UINT32 F_S						:1;
			_IO_UINT32								:16;
		} B;
	} CCR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 TRISE					:6;
			_IO_UINT32								:26;
		} B;
	} TRISE;
} I2C_Type;

/*--- Universal Synchronous Asynchronous Receiver Transmitter MANUAL.P548----*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 PE							:1;
			_IO_UINT32 FE							:1;
			_IO_UINT32 NE							:1;
			_IO_UINT32 ORE						:1;
			_IO_UINT32 IDLE						:1;
			_IO_UINT32 RXNE						:1;
			_IO_UINT32 TC							:1;
			_IO_UINT32 TXE						:1;
			_IO_UINT32 LBD						:1;
			_IO_UINT32 CTS						:1;
			_IO_UINT32								:22;
		} B;
	} SR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DATA						:9;
			_IO_UINT32								:23;
		} B;
	} DR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DIV_Fraction		:4;
			_IO_UINT32 DIV_Mantissa		:12;
			_IO_UINT32 								:16;
		} B;
	} BRR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 SBK						:1;
			_IO_UINT32 RWU						:1;
			_IO_UINT32 RE							:1;
			_IO_UINT32 TE							:1;
			_IO_UINT32 IDLEIE					:1;
			_IO_UINT32 RXNEIE					:1;
			_IO_UINT32 TCIE						:1;
			_IO_UINT32 TXEIE					:1;
			_IO_UINT32 PEIE						:1;
			_IO_UINT32 PS							:1;
			_IO_UINT32 PCE						:1;
			_IO_UINT32 WAKE						:1;
			_IO_UINT32 M							:1;
			_IO_UINT32 UE							:1;
			_IO_UINT32								:18;
		} B;
	} CR1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 ADD						:4;
			_IO_UINT32								:1;
			_IO_UINT32 LBDL						:1;
			_IO_UINT32 LBDIE					:1;
			_IO_UINT32								:1;
			_IO_UINT32 LBCL						:1;
			_IO_UINT32 CPHA						:1;
			_IO_UINT32 CPOL						:1;
			_IO_UINT32 CLKEN					:1;
			_IO_UINT32 STOP						:2;
			_IO_UINT32 LINEN					:1;
			_IO_UINT32								:17;
		} B;
	} CR2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 EIE						:1;
			_IO_UINT32 IREN						:1;
			_IO_UINT32 IRLP						:1;
			_IO_UINT32 HDSEL					:1;
			_IO_UINT32 NACK						:1;
			_IO_UINT32 SCEN						:1;
			_IO_UINT32 DMAR						:1;
			_IO_UINT32 DMAT						:1;
			_IO_UINT32 RTSE						:1;
			_IO_UINT32 CTSE						:1;
			_IO_UINT32 CTSIE					:1;
			_IO_UINT32								:21;
		} B;
	} CR3;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 PSC						:8;
			_IO_UINT32 GT							:8;
			_IO_UINT32								:16;
		} B;
	} GTPR;
} USART_Type;

/*----------------- USB on-the-go full-speed MANUAL.P610---------------------*/

/*---------------------- Ethernet (ETH) MANUAL.P729--------------------------*/

/*------------------------ Debug MCU MANUAL.P754-----------------------------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 DEV_ID					:8;
			_IO_UINT32 								:4;
			_IO_UINT32 REV_ID					:16;
		} B;
	} IDCODE;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 SLEEP					:1;
			_IO_UINT32 STOP						:1;
			_IO_UINT32 STANDBY				:1;
			_IO_UINT32								:2;
			_IO_UINT32 TRACE_IOEN			:1;
			_IO_UINT32 TRACE_MODE			:2;
			_IO_UINT32 IWDG_STOP			:1;
			_IO_UINT32 WWDG_STOP			:1;
			_IO_UINT32 TIM1_STOP			:1;
			_IO_UINT32 TIM2_STOP			:1;
			_IO_UINT32 TIM3_STOP			:1;
			_IO_UINT32 TIM4_STOP			:1;
			_IO_UINT32 CAN1_STOP			:1;
			_IO_UINT32 I2C1_SMBUS_TIMEOU:1;
			_IO_UINT32 I2C2_SMBUS_TIMEOU:1;
			_IO_UINT32 TIM5_STOP			:1;
			_IO_UINT32 TIM6_STOP			:1;
			_IO_UINT32 TIM7_STOP			:1;
			_IO_UINT32 TIM8_STOP			:1;
			_IO_UINT32 CAN2_STOP			:1;	
			_IO_UINT32								:10;
		} B;
	} CR;
}DBGMCU_Type;

/*------------------------------ FLASH_MANUAL.P13----------------------------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 RDP						:8;
			_IO_UINT32 nRDP						:8;
			_IO_UINT32 USER						:8;
			_IO_UINT32 nUSER					:8;
		} B;
	} OB1;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 Data0					:8;
			_IO_UINT32 nData0					:8;
			_IO_UINT32 Data1					:8;
			_IO_UINT32 nData1					:8;
		} B;
	} OB2;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 WRP0						:8;
			_IO_UINT32 nWRP0					:8;
			_IO_UINT32 WRP1						:8;
			_IO_UINT32 nWRP1					:8;
		} B;
	} OB3;
		union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 WRP2						:8;
			_IO_UINT32 nWRP2					:8;
			_IO_UINT32 WRP3						:8;
			_IO_UINT32 nWRP3					:8;
		} B;
	} OB4;
} OB_Type;

typedef struct
{
  __IO uint16_t RDP;
  __IO uint16_t USER;
  __IO uint16_t Data0;
  __IO uint16_t Data1;
  __IO uint16_t WRP0;
  __IO uint16_t WRP1;
  __IO uint16_t WRP2;
  __IO uint16_t WRP3;
} OB_TypeDef;

/*-------------- FLASH and Option Bytes Registers FLASH_MANUAL.P19-----------*/
typedef struct {
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 LATENCY				:3;
			_IO_UINT32 HLFCYA					:1;
			_IO_UINT32 PRFTBE					:1;
			_IO_UINT32 PRFTBS					:1;
			_IO_UINT32								:26;
		} B;
	} ACR;
	union {
		_IO_UINT32 W;
	} KEYR;
	union {
		_IO_UINT32 W;
	} OPTKEYR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 BSY						:1;
			_IO_UINT32 ERLYBSY				:1;
			_IO_UINT32 PGERR					:1;
			_IO_UINT32								:1;
			_IO_UINT32 WRPRTER				:1;
			_IO_UINT32 EOP						:1;
			_IO_UINT32								:30;
		} B;
	} SR;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 PG							:1;
			_IO_UINT32 PER						:1;
			_IO_UINT32 MER						:1;
			_IO_UINT32								:1;
			_IO_UINT32 OPTPG					:1;
			_IO_UINT32 OPTER					:1;
			_IO_UINT32 STRT						:1;
			_IO_UINT32 LOCK						:1;
			_IO_UINT32								:1;
			_IO_UINT32 OPTWRE					:1;
			_IO_UINT32 ERRIE					:1;
			_IO_UINT32								:1;
			_IO_UINT32 EOPIE					:1;
			_IO_UINT32								:19;
		} B;
	} CR;
	union {
		_IO_UINT32 W;
	} AR;
	_IO_UINT32 RESERVED0;
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 OPTERR					:1;
			_IO_UINT32 RDPRT					:1;
			_IO_UINT32 WDG_SW					:1;
			_IO_UINT32 nRST_STOP			:1;
			_IO_UINT32 nRST_STDB			:1;
			_IO_UINT32								:5;
			_IO_UINT32 DATA2					:8;
			_IO_UINT32 DATA1					:8;
			_IO_UINT32								:6;
		} B;
	} OBR;
	union {
		_IO_UINT32 W;
	} WRPR;
} FLASH_Type;

/*-------------------- NVIC Cortex-M3+¼¼Êõ²Î¿¼ÊÖ²á.P70-----------------------*/
/*-------- Nested Vectored Interrupt Controller Reference_manual.P132--------*/
typedef union {
	_IO_UINT32 W[2];
	struct {
		_IO_UINT32 WWDG						:1;
		_IO_UINT32 PVD						:1;
		_IO_UINT32 TAMPER					:1;
		_IO_UINT32 RTC						:1;
		_IO_UINT32 FLASH					:1;
		_IO_UINT32 RCC						:1;
		_IO_UINT32 EXTI0					:1;
		_IO_UINT32 EXTI1					:1;
		_IO_UINT32 EXTI2					:1;
		_IO_UINT32 EXTI3					:1;
		_IO_UINT32 EXTI4					:1;
		_IO_UINT32 DMA1_CH1			 	:1;
		_IO_UINT32 DMA1_CH2 			:1;
		_IO_UINT32 DMA1_CH3 			:1;
		_IO_UINT32 DMA1_CH4 			:1;
		_IO_UINT32 DMA1_CH5 			:1;
		_IO_UINT32 DMA1_CH6 			:1;
		_IO_UINT32 DMA1_CH7 			:1;
		_IO_UINT32 ADC1_2					:1;
		_IO_UINT32 USB_HP_CAN_TX	:1;
		_IO_UINT32 USB_LP_CAN_RX0	:1;
		_IO_UINT32 CAN_RX1  			:1;
		_IO_UINT32 CAN_SCE  			:1;
		_IO_UINT32 EXTI9_5  			:1;
		_IO_UINT32 TIM1_BRK 			:1;
		_IO_UINT32 TIM1_UP  			:1;
		_IO_UINT32 TIM1_TRG_COM		:1;
		_IO_UINT32 TIM1_CC  			:1;
		_IO_UINT32 TIM2						:1;
		_IO_UINT32 TIM3						:1;
		_IO_UINT32 TIM4						:1;
		_IO_UINT32 I2C1_EV  			:1;
		_IO_UINT32 I2C1_ER				:1;
		_IO_UINT32 I2C2_EV				:1;
		_IO_UINT32 I2C2_ER				:1;
		_IO_UINT32 SPI1						:1;
		_IO_UINT32 SPI2						:1;
		_IO_UINT32 USART1_				:1;
		_IO_UINT32 USART2_				:1;
		_IO_UINT32 USART3_				:1;
		_IO_UINT32 EXTI15_10			:1;
		_IO_UINT32 RTCAlarm				:1;
		_IO_UINT32 USBWakeUp			:1;
		_IO_UINT32 TIM8_BRK				:1;
		_IO_UINT32 TIM8_UP				:1;
		_IO_UINT32 TIM8_TRG_COM		:1;
		_IO_UINT32 TIM8_CC				:1;
		_IO_UINT32 ADC3						:1;
		_IO_UINT32 FSMC						:1;
		_IO_UINT32 SDIO						:1;
		_IO_UINT32 TIM5						:1;
		_IO_UINT32 SPI3						:1;
		_IO_UINT32 UART4					:1;
		_IO_UINT32 UART5					:1;
		_IO_UINT32 TIM6						:1;
		_IO_UINT32 TIM7						:1;
		_IO_UINT32 DMA2_CH1				:1;
		_IO_UINT32 DMA2_CH2				:1;
		_IO_UINT32 DMA2_CH3				:1;
		_IO_UINT32 DMA2_CH4_5			:1;
		_IO_UINT32								:4;
	} B;
} IRQn_Type;

typedef struct {
	//Interrupt Set Enable Register
	//ÖÐ¶ÏÊ¹ÄÜÉèÖÃ¼Ä´æÆ÷0xE000E100
	IRQn_Type ISER;
	_UINT32 RESERVED0[30];
	//Interrupt Clear Enable Register
	//ÖÐ¶ÏÊ¹ÄÜÇå³ý¼Ä´æÆ÷0xE000E180
	IRQn_Type ICER;
	_UINT32 RSERVED1[30];
	//Interrupt Set Pending Register
	//ÖÐ¶Ï¹ÒÆðÉèÖÃ¼Ä´æÆ÷0xE000E200
	IRQn_Type ISPR;
	_UINT32 RESERVED2[30];
	//Interrupt Clear Pending Register
	//ÖÐ¶Ï¹ÒÆðÇå³ý¼Ä´æÆ÷0xE000E280
	IRQn_Type ICPR;
	_UINT32 RESERVED3[30];
	//Interrupt Active bit Register
	//ÖÐ¶Ï¼¤»îÎ»¼Ä´æÆ÷0xE000E300
	IRQn_Type IABR;
	_UINT32 RESERVED4[62];
	//Interrupt Priority Register
	//ÖÐ¶ÏÓÅÏÈ¼¶¼Ä´æÆ÷0xE000E400
	union {
		_IO_UINT32 W[15];
		struct {
			_IO_BYTE WWDG							:8;
			_IO_BYTE PVD							:8;
			_IO_BYTE TAMPER						:8;
			_IO_BYTE RTC							:8;
			_IO_BYTE FLASH						:8;
			_IO_BYTE RCC							:8;
			_IO_BYTE EXTI0						:8;
			_IO_BYTE EXTI1						:8;
			_IO_BYTE EXTI2						:8;
			_IO_BYTE EXTI3						:8;
			_IO_BYTE EXTI4						:8;
			_IO_BYTE DMA1_CH1					:8;
			_IO_BYTE DMA1_CH2					:8;
			_IO_BYTE DMA1_CH3					:8;
			_IO_BYTE DMA1_CH4					:8;
			_IO_BYTE DMA1_CH5					:8;
			_IO_BYTE DMA1_CH6					:8;
			_IO_BYTE DMA1_CH7					:8;
			_IO_BYTE ADC1_2						:8;
			_IO_BYTE USB_HP_CAN_TX		:8;
			_IO_BYTE USB_LP_CAN_RX0		:8;
			_IO_BYTE CAN_RX1					:8;
			_IO_BYTE CAN_SCE					:8;
			_IO_BYTE EXTI9_5					:8;
			_IO_BYTE TIM1_BRK					:8;
			_IO_BYTE TIM1_UP					:8;
			_IO_BYTE TIM1_TRG_COM			:8;
			_IO_BYTE TIM1_CC					:8;
			_IO_BYTE TIM2							:8;
			_IO_BYTE TIM3							:8;
			_IO_BYTE TIM4							:8;
			_IO_BYTE I2C1_EV					:8;
			_IO_BYTE I2C1_ER					:8;
			_IO_BYTE I2C2_EV					:8;
			_IO_BYTE I2C2_ER					:8;
			_IO_BYTE SPI1							:8;
			_IO_BYTE SPI2							:8;
			_IO_BYTE USART1						:8;
			_IO_BYTE USART2						:8;
			_IO_BYTE USART3						:8;
			_IO_BYTE EXTI15_10				:8;
			_IO_BYTE RTCAlarm					:8;
			_IO_BYTE USBWakeUp				:8;
			_IO_BYTE TIM8_BRK					:8;
			_IO_BYTE TIM8_UP					:8;
			_IO_BYTE TIM8_TRG_COM			:8;
			_IO_BYTE TIM8_CC					:8;
			_IO_BYTE ADC3							:8;
			_IO_BYTE FSMC							:8;
			_IO_BYTE SDIO							:8;
			_IO_BYTE TIM5							:8;
			_IO_BYTE SPI3							:8;
			_IO_BYTE UART4						:8;
			_IO_BYTE UART5						:8;
			_IO_BYTE TIM6							:8;
			_IO_BYTE TIM7							:8;
			_IO_BYTE DMA2_CH1					:8;
			_IO_BYTE DMA2_CH2					:8;
			_IO_BYTE DMA2_CH3					:8;
			_IO_BYTE DMA2_CH4_5				:8;
		} BYTE;
	} IPR;
} NVIC_Type;

/*---------------------------System Timer (SysTick)---------------------------*/
/*----------------- SystemTick Cortex-M3+¼¼Êõ²Î¿¼ÊÖ²á.P74---------------------*/
typedef struct {
	//¿ØÖÆ¼°×´Ì¬¼Ä´æÆ÷0xE000E010
	_IO_UINT32 CTRL;
	//ÖØ×°ÔØÊýÖµ¼Ä´æÆ÷0xE000E014
	_IO_UINT32 RELOAD;
	//µ±Ç°ÊýÖµ¼Ä´æÆ÷0xE000E018
	_IO_UINT32 VAL;
	//Ð£×¼ÊýÖµ¼Ä´æÆ÷0xE000E01C
	_IO_UINT32 CALIB;
} SYSTICK_Type;

/*-----------------------System Control Block (SCB)----------------------------*/
/*----------------- ÏµÍ³¿ØÖÆµ¥Ôª Cortex-M3+¼¼Êõ²Î¿¼ÊÖ²á.P80--------------------*/
typedef struct {
	union {
		//CPUID Base Register
		//CPU ID»ùÖ·¼Ä´æÆ÷0xE000ED00 
		_IO_UINT32 W;
		struct {
			_IO_UINT32 REVISION 			:4;
			_IO_UINT32 PARTNO					:12;
			_IO_UINT32 CONST					:4;
			_IO_UINT32 VARIANT  			:4;
			_IO_UINT32 IMPLEMENTER		:8;
		} B;
	} CPUID;
	union {
		//Interrupt Control and State Register
		//ÖÐ¶Ï¿ØÖÆ×´Ì¬¼Ä´æÆ÷0xE000ED04 
		_IO_UINT32 W;
		struct {
			_IO_UINT32 VECTACTIVE			:9;
			_IO_UINT32								:2;
			_IO_UINT32 RETTOBASE			:1;
			_IO_UINT32 VECTPENDING		:10;
			_IO_UINT32 ISRPENDING			:1;
			_IO_UINT32 ISRPREEMPT			:1;
			_IO_UINT32								:1;
			_IO_UINT32 PENDSTCLR			:1;
			_IO_UINT32 PENDSTSET			:1;
			_IO_UINT32 PENDSVCLR			:1;
			_IO_UINT32 PENDSVSET			:1;
			_IO_UINT32								:2;
			_IO_UINT32 NMIPENDSET			:1;
		} B;
	} ICSR;
	union {
		//Vector Table Offset Register
		//ÏòÁ¿±íÆ«ÒÆ¼Ä´æÆ÷0xE000ED08
		_IO_UINT32 W;
		struct {
			_IO_UINT32								:7;
			_IO_UINT32 TBLOFF					:22;
			_IO_UINT32 TBLBASE				:1;
			_IO_UINT32								:2;
		} B;
	} VTOR;
	union {
		//Application Interrupt and Reset Control Register
		//Ó¦ÓÃÖÐ¶ÏÓë¸´Î»¿ØÖÆ¼Ä´æÆ÷0xE000ED0C
		_IO_UINT32 W;
		struct {
			_IO_UINT32 VECTRESET			:1;
			_IO_UINT32 VECTCLRACTIVE	:1;
			_IO_UINT32 SYSRESETREQ		:1;
			_IO_UINT32								:5;
			_IO_UINT32 PRIGROUP				:3;
			_IO_UINT32								:4;
			_IO_UINT32 ENDIANESS			:1;
			_IO_UINT32 VECTKEY				:16;
		} B;
	} AIRCR;
	union {
		//System Control Register
		//ÏµÍ³¿ØÖÆ¼Ä´æÆ÷0xE000ED10
		_IO_UINT32 W;
		struct {
			_IO_UINT32								:1;
			_IO_UINT32 SLEEPONEXIT		:1;
			_IO_UINT32 SLEEPDEEP			:1;
			_IO_UINT32								:1;
			_IO_UINT32 SEVONPEND			:1;
			_IO_UINT32								:27;
		} B;
	} SCR;
	union {
		//Configuration Control Register
		//ÅäÖÃ¿ØÖÆ¼Ä´æÆ÷0xE000ED14
		_IO_UINT32 W;
		struct {
			_IO_UINT32 NONEBASETHRDENA:1;
			_IO_UINT32 USERSETMPEND		:1;
			_IO_UINT32								:1;
			_IO_UINT32 UNALIGN_TRP		:1;
			_IO_UINT32 DIV_0_TRP			:1;
			_IO_UINT32								:3;
			_IO_UINT32 BFHFNMIGN			:1;
			_IO_UINT32 STKALIGN				:1;
			_IO_UINT32								:22;
		} B;
	} CCR;
	//System Handlers Priority Registers
	//ÏµÍ³´¦ÀíÆ÷ÓÅÏÈ¼¶¼Ä´æÆ÷0xE000ED18£¬0xE000ED1C £¬0xE000ED20
	union {
		_IO_UINT32 W;
		struct {
			_IO_UINT32 MemManage			:8;
			_IO_UINT32 BusFault				:8;
			_IO_UINT32 UsageFault			:8;
			_IO_UINT32 RS							:8;
		} B;
	} SHPR1;
	union	{
		_IO_UINT32 W;
		struct {
			_IO_UINT32 RS							:8;
			_IO_UINT32 RS1						:8;
			_IO_UINT32 RS2						:8;
			_IO_UINT32 SVCall					:8;
		} B;
	} SHPR2;
	union	{
		_IO_UINT32 W;
		struct {
			_IO_UINT32 Debug					:8;
			_IO_UINT32 RS							:8;
			_IO_UINT32 PendSV					:8;
			_IO_UINT32 SYSTICK				:8;
		} B;
	} SHPR3;
	union {
		//System Handler Control and State Register
		//ÏµÍ³´¦ÀíÆ÷¿ØÖÆÓë×´Ì¬¼Ä´æÆ÷0xE000ED24
		_IO_UINT32 W;
		struct {
			_IO_UINT32 MEMFAULTACT 		:1;
			_IO_UINT32 BUSFAULTACT		:1;
			_IO_UINT32								:1;
			_IO_UINT32 USGFAULTACT		:1;
			_IO_UINT32								:3;
			_IO_UINT32 SVCALLACT 			:1;
			_IO_UINT32 MONITORACT			:1;
			_IO_UINT32								:1;
			_IO_UINT32 PENDSVACT			:1;
			_IO_UINT32 SYSTICKACT			:1;
			_IO_UINT32								:1;
			_IO_UINT32 MEMFAULTPENDED	:1;
			_IO_UINT32 BUSFAULTPENDED	:1;
			_IO_UINT32 SVCALLPENDED		:1;
			_IO_UINT32 MEMFAULTENA		:1;
			_IO_UINT32 BUSFAULTENA		:1;
			_IO_UINT32 USGFAULTENA		:1;
			_IO_UINT32								:13;
		} B;
	} SHCSR;
	union {
		//Configurable Fault Status Register
		//´æ´¢Æ÷¹ÜÀí¹ÊÕÏ×´Ì¬¼Ä´æÆ÷0xE000ED28
		_IO_UINT32 W;
		struct {
			_IO_UINT32 IACCVIOL				:1;
			_IO_UINT32 DACCVIOL				:1;
			_IO_UINT32								:1;
			_IO_UINT32 MUNSTKERR			:1;
			_IO_UINT32 MSTKERR 				:1;
			_IO_UINT32								:2;
			_IO_UINT32 MMARVALID			:1;
			//×ÜÏß¹ÊÕÏ×´Ì¬¼Ä´æÆ÷
			_IO_UINT32 IBUSERR				:1;
			_IO_UINT32 PRECISERR			:1;
			_IO_UINT32 IMPRECISERR		:1;
			_IO_UINT32 UNSTKERR				:1;
			_IO_UINT32 STKERR					:1;
			_IO_UINT32								:2;
			_IO_UINT32 BFARVALID			:1;
			//Ê¹ÓÃ¹ÊÕÏ×´Ì¬¼Ä´æÆ÷
			_IO_UINT32 UNDEFINSTR			:1;
			_IO_UINT32 INVSTATE				:1;
			_IO_UINT32 INVPC					:1;
			_IO_UINT32 NOCP						:1;
			_IO_UINT32								:4;
			_IO_UINT32 UNALIGNED			:1;
			_IO_UINT32 DIVBYZERO			:1;
			_IO_UINT32								:6;
		} B;
	} CFSR;
	union {
		//HardFault Status Register
		//Ó²¹ÊÕÏ×´Ì¬¼Ä´æÆ÷0xE000ED2C
		_IO_UINT32 W;
		struct {
			_IO_UINT32								:1;
			_IO_UINT32 VECTTBL				:1;
			_IO_UINT32								:28;
			_IO_UINT32 FORCED					:1;
			_IO_UINT32 DEBUGEVT				:1;
		} B;
	} HFSR;
	union {
		//Debug Fault Status Register
		//µ÷ÊÔ¹ÊÕÏ×´Ì¬¼Ä´æÆ÷0xE000ED30
		_IO_UINT32 W;
		struct {
			_IO_UINT32 HALTED					:1;
			_IO_UINT32 BKPT						:1;
			_IO_UINT32 DWTTRAP				:1;
			_IO_UINT32 VCATCH					:1;
			_IO_UINT32 EXTERNAL				:1;
			_IO_UINT32								:27;
		} B;
	} DFSR;
	union {
		//MemManage Fault Address Register
		//´æ´¢Æ÷¹ÜÀí¹ÊÕÏµØÖ·¼Ä´æÆ÷0xE000ED34
		_IO_UINT32 W;
	} MMFAR;
	union {
		//BusFault Address Register
		//×ÜÏß¹ÊÕÏµØÖ·¼Ä´æÆ÷0xE000ED38
		_IO_UINT32 W;
	} BFAR;
	union {
		//Auxiliary Fault Status Register
		//¸¨Öú¹ÊÕÏ×´Ì¬¼Ä´æÆ÷0xE000ED3C
		_IO_UINT32 W;
	} AFSR;
} SCB_Type;


/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/* Peripheral and SRAM base address in the alias region */
#define PERIPH_BB_BASE			(0x42000000UL)
#define SRAM_BB_BASE				(0x22000000UL)

/* Peripheral and SRAM base address in the bit-band region */
#define SRAM_BASE						(0x20000000UL)
#define PERIPH_BASE					(0x40000000UL)
#define FLASH_BASE          (0x08000000UL)

/* FSMC registers base address */
#define FSMC_R_BASE					(0xA0000000UL)

/* Peripheral memory map */
#define APB1PERIPH_BASE			(PERIPH_BASE)
#define APB2PERIPH_BASE			(PERIPH_BASE+0x00010000UL)
#define AHBPERIPH_BASE			(PERIPH_BASE+0x00020000UL)

#define TIM2_BASE						(APB1PERIPH_BASE+0x0000UL)
#define TIM3_BASE						(APB1PERIPH_BASE+0x0400UL)
#define TIM4_BASE						(APB1PERIPH_BASE+0x0800UL)
#define TIM5_BASE						(APB1PERIPH_BASE+0x0C00UL)
#define TIM6_BASE						(APB1PERIPH_BASE+0x1000UL)
#define TIM7_BASE						(APB1PERIPH_BASE+0x1400UL)
//RESERVED
#define RTC_BASE						(APB1PERIPH_BASE+0x2800UL)
#define WWDG_BASE						(APB1PERIPH_BASE+0x2C00UL)
#define IWDG_BASE						(APB1PERIPH_BASE+0x3000UL)
//RESERVED
#define SPI2_BASE						(APB1PERIPH_BASE+0x3800UL)
#define SPI3_BASE						(APB1PERIPH_BASE+0x3C00UL)
//RESERVED
#define USART2_BASE					(APB1PERIPH_BASE+0x4400UL)
#define USART3_BASE					(APB1PERIPH_BASE+0x4800UL)
#define UART4_BASE					(APB1PERIPH_BASE+0x4C00UL)
#define UART5_BASE					(APB1PERIPH_BASE+0x5000UL)
#define I2C1_BASE						(APB1PERIPH_BASE+0x5400UL)
#define I2C2_BASE						(APB1PERIPH_BASE+0x5800UL)
//USBÈ«ËÙÉè±¸¼Ä´æÆ÷ 
//USB/CAN¹²ÏíµÄ512 ×Ö½ÚSRAM
#define CAN1_BASE						(APB1PERIPH_BASE+0x6400UL)
#define CAN2_BASE						(APB1PERIPH_BASE+0x6800UL)
#define BKP_BASE						(APB1PERIPH_BASE+0x6C00UL)
#define PWR_BASE						(APB1PERIPH_BASE+0x7000UL)
#define DAC_BASE						(APB1PERIPH_BASE+0x7400UL)
//RESERVED
#define AFIO_BASE						(APB2PERIPH_BASE+0x0000UL)
#define EXTI_BASE						(APB2PERIPH_BASE+0x0400UL)
#define GPIOA_BASE					(APB2PERIPH_BASE+0x0800UL)
#define GPIOB_BASE					(APB2PERIPH_BASE+0x0C00UL)
#define GPIOC_BASE					(APB2PERIPH_BASE+0x1000UL)
#define GPIOD_BASE					(APB2PERIPH_BASE+0x1400UL)
#define GPIOE_BASE					(APB2PERIPH_BASE+0x1800UL)
#define GPIOF_BASE					(APB2PERIPH_BASE+0x1C00UL)
#define GPIOG_BASE					(APB2PERIPH_BASE+0x2000UL)
#define ADC1_BASE						(APB2PERIPH_BASE+0x2400UL)
#define ADC2_BASE						(APB2PERIPH_BASE+0x2800UL)
#define TIM1_BASE						(APB2PERIPH_BASE+0x2C00UL)
#define SPI1_BASE						(APB2PERIPH_BASE+0x3000UL)
#define TIM8_BASE						(APB2PERIPH_BASE+0x3400UL)
#define USART1_BASE					(APB2PERIPH_BASE+0x3800UL)
#define ADC3_BASE						(APB2PERIPH_BASE+0x3C00UL)
//RESERVED
#define SDIO_BASE						(PERIPH_BASE+0x00018000UL)
//RESERVED
#define DMA1_BASE						(AHBPERIPH_BASE+0x0000UL)
#define DMA1_CHANNEL1_BASE	(AHBPERIPH_BASE+0x0008UL)
#define DMA1_CHANNEL2_BASE	(AHBPERIPH_BASE+0x001CUL)
#define DMA1_CHANNEL3_BASE	(AHBPERIPH_BASE+0x0030UL)
#define DMA1_CHANNEL4_BASE	(AHBPERIPH_BASE+0x0044UL)
#define DMA1_CHANNEL5_BASE	(AHBPERIPH_BASE+0x0058UL)
#define DMA1_CHANNEL6_BASE	(AHBPERIPH_BASE+0x006CUL)
#define DMA1_CHANNEL7_BASE	(AHBPERIPH_BASE+0x0080UL)
#define DMA2_BASE						(AHBPERIPH_BASE+0x0400UL)
#define DMA2_CHANNEL1_BASE	(AHBPERIPH_BASE+0x0408UL)
#define DMA2_CHANNEL2_BASE	(AHBPERIPH_BASE+0x041CUL)
#define DMA2_CHANNEL3_BASE	(AHBPERIPH_BASE+0x0430UL)
#define DMA2_CHANNEL4_BASE	(AHBPERIPH_BASE+0x0444UL)
#define DMA2_CHANNEL5_BASE	(AHBPERIPH_BASE+0x0458UL)
//RESERVED
#define FLASH_R_BASE				(AHBPERIPH_BASE+0x2000UL)
#define FSMC_Bank1_R_BASE		(FSMC_R_BASE+0x0000UL)
#define FSMC_Bank1E_R_BASE	(FSMC_R_BASE+0x0104UL)
#define FSMC_Bank2_R_BASE		(FSMC_R_BASE+0x0060UL)
#define FSMC_Bank3_R_BASE		(FSMC_R_BASE+0x0080UL)
#define FSMC_Bank4_R_BASE		(FSMC_R_BASE+0x00A0UL)
#define RCC_BASE						(AHBPERIPH_BASE+0x1000UL)
#define CRC_BASE						(AHBPERIPH_BASE+0x3000UL)


//RESERVED
//ÒÔÌ«Íø
//RESERVED
//USB OTG  È«ËÙ

/* Flash Option Bytes base address */
#define OB_BASE							(0x1FFFF800UL)

/* Debug MCU registers base address */
#define DBGMCU_BASE					(0xE0042000UL)

/* System Control Space memory map */
#define SCS_BASE						(0xE000E000UL)
#define SYSTICK_BASE				(SCS_BASE+0x0010UL)
#define NVIC_BASE						(SCS_BASE+0x0100UL)
#define SCB_BASE						(SCS_BASE+0x0D00UL)


/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/

#ifdef _TIM_GP
	#define TIM2							((TIM_GP_Type*)TIM2_BASE)
	#define TIM3							((TIM_GP_Type*)TIM3_BASE)
	#define TIM4							((TIM_GP_Type*)TIM4_BASE)
	#define TIM5							((TIM_GP_Type*)TIM5_BASE)
#endif /*_TIM_GP */

#ifdef _TIM_BS
	#define TIM6							((TIM_BS_Type*)TIM6_BASE)
	#define TIM7							((TIM_BS_Type*)TIM7_BASE)
#endif /*_TIM_BS */

#ifdef _TIM_AC
	#define TIM1							((TIM_AC_Type*)TIM1_BASE)
	#define TIM8							((TIM_AC_Type*)TIM8_BASE)
#endif /*_TypeIM_AC */

#ifdef _RTC
	#define RTC								((RTC_Type*)RTC_BASE)
#endif /*_RTC */

#ifdef _WWDG
	#define WWDG							((WWDG_Type*)WWDG_BASE)
#endif /*_WWDG */

#ifdef _IWDG
	#define IWDG							((IWDG_Type*)IWDG_BASE)
#endif /*_IWDG */

#ifdef _SPI
	#define SPI2							((SPI_Type*)SPI2_BASE)
	#define SPI3							((SPI_Type*)SPI3_BASE)
	#define SPI1							((SPI_Type*)SPI1_BASE)
#endif /*_SPI */

#ifdef _USART
	#define USART2						((USART_Type*)USART2_BASE)
	#define USART3						((USART_Type*)USART3_BASE)
	#define USART1						((USART_Type*)USART1_BASE)
#endif /*_USART */
	
#ifdef _UART
	#define UART4							((USART_Type*)UART4_BASE)
	#define UART5							((USART_Type*)UART5_BASE)
#endif /*_UART */

#ifdef _I2C
	#define I2C1							((I2C_Type*)I2C1_BASE)
	#define I2C2							((I2C_Type*)I2C2_BASE)
#endif /*_I2C */

#ifdef _CAN
	#define CAN1							((CAN_Type*)CAN1_BASE)
	#define CAN2							((CAN_Type*)CAN2_BASE)
#endif /*_CAN */

#ifdef _BKP
	#define BKP								((BKP_Type*)BKP_BASE)
#endif /*_BKP */

#ifdef _PWR
	#define PWR								((PWR_Type*)PWR_BASE)
#endif /*_PWR */

#ifdef _DAC
	#define DAC								((DAC_Type*)DAC_BASE)
#endif /*_DAC */

#ifdef _AFIO
	#define AFIO							((AFIO_Type*)AFIO_BASE)
#endif /*_AFIO */

#ifdef _EXTI
	#define EXTI							((EXTI_Type*)EXTI_BASE)
#endif /*_EXTI */

#ifdef _GPIO
	#define GPIOA							((GPIO_Type*)GPIOA_BASE)
	#define GPIOB							((GPIO_Type*)GPIOB_BASE)
	#define GPIOC							((GPIO_Type*)GPIOC_BASE)
	#define GPIOD							((GPIO_Type*)GPIOD_BASE)
	#define GPIOE							((GPIO_Type*)GPIOE_BASE)
	#define GPIOF							((GPIO_Type*)GPIOF_BASE)
	#define GPIOG							((GPIO_Type*)GPIOG_BASE)
#endif /*_GPIO */

#ifdef _ADC
	#define ADC1							((ADC_Type*)ADC1_BASE)
	#define ADC2							((ADC_Type*)ADC2_BASE)
	#define ADC3							((ADC_Type*)ADC3_BASE)
#endif /*_ADC */

#ifdef _SDIO
	#define SDIO							((SDIO_Type*)SDIO_BASE)
#endif /*_SDIO */

#ifdef _DMA1
	#define DMA1                ((DMA_Type*)DMA1_BASE)
	#define DMA1_CHANNEL1				((DMA_CHANNEL_Type*)DMA1_CHANNEL1_BASE)
	#define DMA1_CHANNEL2				((DMA_CHANNEL_Type*)DMA1_CHANNEL2_BASE)
	#define DMA1_CHANNEL3				((DMA_CHANNEL_Type*)DMA1_CHANNEL3_BASE)
	#define DMA1_CHANNEL4				((DMA_CHANNEL_Type*)DMA1_CHANNEL4_BASE)
	#define DMA1_CHANNEL5				((DMA_CHANNEL_Type*)DMA1_CHANNEL5_BASE)
	#define DMA1_CHANNEL6				((DMA_CHANNEL_Type*)DMA1_CHANNEL6_BASE)
	#define DMA1_CHANNEL7				((DMA_CHANNEL_Type*)DMA1_CHANNEL7_BASE)
#endif /*_DMA1 */

#ifdef _DMA2
	#define DMA2                ((DMA_Type*)DMA2_BASE)
	#define DMA2_CHANNEL1				((DMA_CHANNEL_Type*)DMA2_CHANNEL1_BASE)
	#define DMA2_CHANNEL2				((DMA_CHANNEL_Type*)DMA2_CHANNEL2_BASE)
	#define DMA2_CHANNEL3				((DMA_CHANNEL_Type*)DMA2_CHANNEL3_BASE)
	#define DMA2_CHANNEL4				((DMA_CHANNEL_Type*)DMA2_CHANNEL4_BASE)
	#define DMA2_CHANNEL5				((DMA_CHANNEL_Type*)DMA2_CHANNEL5_BASE)
#endif /*_DMA2 */

#ifdef _RCC
	#define RCC									((RCC_Type*)RCC_BASE)
#endif /*_RCC */

#ifdef _FLASH
	#define FLASH               ((FLASH_TypeDef*)FLASH_R_BASE)
	#define OB                  ((OB_TypeDef*)OB_BASE)
#endif /*_FLASH */

#ifdef _CRC
	#define CRC									((CRC_Type*)CRC_BASE)
#endif /*_CRC */

#ifdef _FSMC
	#define FSMC_Bank1					((FSMC_Bank1_Type*)FSMC_Bank1_R_BASE)
	#define FSMC_Bank1E					((FSMC_Bank1E_Type*)FSMC_Bank1E_R_BASE)
	#define FSMC_Bank2					((FSMC_Bank2_Type*)FSMC_Bank2_R_BASE)
	#define FSMC_Bank3					((FSMC_Bank3_Type*)FSMC_Bank3_R_BASE)
	#define FSMC_Bank4					((FSMC_Bank4_Type*)FSMC_Bank4_R_BASE)
#endif /*_FSMC */

#ifdef _DBGMCU
	#define DBGMCU							((DBGMCU_Type*)DBGMCU_BASE)
#endif /*_DBGMCU */

#ifdef _SYSTICK
	#define SYSTICK							((SYSTICK_Type*)SYSTICK_BASE)
#endif /*_SYSTICK */											  

#ifdef _NVIC
	#define NVIC								((NVIC_Type*)NVIC_BASE)
	#define SCB									((SCB_Type*)SCB_BASE)  
#endif /*_NVIC */

/* Bit-Band MODE */
#define BITBAND(addr,offset,bitnum)	((_IO_UINT32*)((addr&0xF0000000UL)|0x02000000|((((addr&0x000FFFFFUL)+offset)<<5)+(bitnum<<2))))

/////////////////////////////////////////////////
typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;




/////////////////////////////////////////////////////

#endif /* __STM32F10x_REG_H */

