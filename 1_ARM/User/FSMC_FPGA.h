#ifndef __FSMC_H
#define __FSMC_H

#include "stm32f10x.h"


#define Bank1_SRAM1_ADDR    ((uint32_t)0x60000000) 

#define	ADDR_TYP_VER			(0x00)  //8'b0000_0000   //type and version
#define	ADDR_CTRL				(0x01)  //8'b0000_0001
#define	ADDR_STATUS				(0x02)  //8'b0000_0010
#define	ADDR_PERIODL			(0x03)  //8'b0000_0011
#define	ADDR_PERIODH_DUTY		(0x04)  //8'b0000_0100
#define	ADDR_NSAMP				(0x05)  //8'b0000_0101
#define ADDR_RISING_TIM			(0x06)  //8'b0000_0110
#define	ADDR_ERROR				(0x07)  //8'b0000_0111
#define	ADDR_ERR_CHECK			(0x08)  //8'b0000_1000
#define ADDR_ERR_CNTLIM			(0x09)  //8'b0000_1001
  //CCS
#define	ADDR_CCS_SPISET			(0x0a)  //8'b0000_1010
#define ADDR_CCS1_SPISTA		(0x0b)  //8'b0000_1011
#define	ADDR_CCS2_SPISTA		(0x0c)  //8'b0000_1100
#define ADDR_CCS3_SPISTA		(0x0d)  //8'b0000_1101
#define ADDR_CCS4_SPISTA		(0x0e)  //8'b0000_1110
#define ADDR_CCS5_SPISTA		(0x0f)  //8'b0000_1111
#define ADDR_CCS6_SPISTA		(0x10)  //8'b0001_0000
#define	ADDR_CCS_DACSET			(0x11)  //8'b0001_0001
#define ADDR_CCS_DACOFFSET		(0x12)  //8'b0001_0010
#define	ADDR_CCS_ADCRV			(0x13)  //8'b0001_0011	
#define ADDR_CCS_ADCMV			(0x14)  //8'b0001_0100
#define ADDR_CCS_MINADC			(0x15)  //8'b0001_0101
#define	ADDR_CCS_MAXADC			(0x16)  //8'b0001_0110
#define	ADDR_CCS_PREERRCD		(0x17)  //8'b0001_0111
#define ADDR_CCS_SAMPERRCD		(0x18)  //8'b0001_1000
//OPP
#define ADDR_OPP_SPISTA  	 	(0x19)  //	8'b0001_1001 
#define ADDR_OPP_ADC0			(0x1a)  //8'b0001_1010
#define	ADDR_OPP_ADC1			(0x1b)  //8'b0001_1011
#define ADDR_OPP_MINADC 		(0x1c)  //8'b0001_1100
#define ADDR_OPP_MAXADC			(0x1d)  //8'b0001_1101
#define ADDR_OPP_PWLMT			(0x1e)  //8'b0001_1110
#define ADDR_OPP_ERRCD			(0x1f)  //8'b0001_1111
 //ANG
#define ADDR_ANG_SPISET			(0x20)  //8'b0010_0000
#define ADDR_ANG_SPISTA			(0x21)  //8'b0010_0001
#define ADDR_ANG_SPIDATA		(0x22)  //8'b0010_0010
#define ADDR_ANG_DACSET			(0x23)  //8'b0010_0011
#define ADDR_ANG_FRAMDACSET		(0x24)  //8'b0010_0100
#define ADDR_ANG_MINADC			(0x25)  //8'b0010_0101
#define ADDR_ANG_MAXADC		 	(0x26)  //8'b0010_0110
#define ADDR_ANG_THCHG_NSAMP	(0x27)  //8'b0010_0111
#define ADDR_ANG_KAD			(0x28)   //8'b0010_1000

#define ADDR_WMT_DATA			(0x29)  //8'b0010_1001
#define ADDR_WMT_PDCTMAX		(0x2a)  //8'b0010_1010		
#define ADDR_WMT_PDCTMIN		(0x2b)  //8'b0010_1011

#define ADDR_IDLE_ADC			(0x2c)                // 8'b0010_1100  
//#define ADDR_OFFSET_ADC		(0x2d)              //8'b0010_1101  //45

//total power protection /* modify 2018.1.9
#define  ADDR_TLPW_THD		     	(0x2d)   //45
#define  ADDR_TLPWERR_CNTLIM	 	(0x2e)   //46
//total current to minimum and medium bk opp
#define  ADDR_IOPP_CNTLIM				(0x2f) 
#define  ADDR_TLCUR_MINJUDGE		(0x30)   //48
#define  ADDR_TLCUR_MEDJUDGE		(0x31)	 
#define  ADDR_BKOPP_MINTHD			(0x32)	
#define  ADDR_BKOPP_MEDTHD			(0x33)	  
//total current to integrate opp protection
#define  ADDR_INTEGOPP_K				(0x34)	 //52   //K*256
#define  ADDR_INTEGOPP_B				(0x35)	  //53	//B*256
//test 								
#define  ADDR_OVERLMT_COUNT			(0x36)	  //54
#define  ADDR_IO_STA						(0x37)	  //55
//  modify 2018.1.9*/

#define ADDR_IDATA_START		(0x38)  //56


#define SamPassive 0
#define SamActStable 1
#define SamActAllTime 2





extern void FSMC_Configuration(void);
extern uint16_t FSMC_READ(uint32_t ReadAddr);
extern void FSMC_WRITE(uint32_t WriteAddr, uint16_t data);
extern void Sample_Mode_Set(u8 mode);
extern void LD_Ready_Set(u8 cmd);
extern void PWM_Mode_Set(u8 mode);
extern void TDK_Power_Set(u8 cmd);
extern void Run_Mode_Set(u8 cmd);
extern u16 Reg_Ctrl_Value;

extern u16 FPGA_ADC_Data[8][26];

#endif 



