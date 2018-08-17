#ifndef __LD_Drive_H__
#define __LD_Drive_H__

#include "stm32f10x.h"

extern u8 LD_Current_Set1,LD_Current1,LD_Current_Set2,LD_Current2;
extern u8 LD_MOS_V1,LD_MOS_V2,EX_AD_ISet;
extern u16 Reg_Error,Reg_Status;
extern u8 Work_Cmd;
extern u16 OPP_Power;//¹â¹¦ÂÊ
extern u8 Field_Cmd;
extern u8 Error_Cmd;
extern u16 Error_Code;
extern u8 Status_Code;
extern u8 Fault_Tab[15];
extern u8 Status_Tab[8];
extern u16 FPGA_ADC_TAB[5];
extern u16 CCS1_MAXADC_VALUE,CCS2_MAXADC_VALUE,OPP_MAXADC_VALUE;
extern u16 ERR_CHECK_VALUE;
extern u8 Fault_Type,Fault_Cmd;
extern u16 ANG_KAD_VALUE;
extern u8 FPGA_RedLaser_Cmd;
extern u16 LD_Frequence;
extern u8 LD_Duty;

extern void LD_Current_Set(u16 Num , u8 Current);
extern void LD_Offset_Set(u16 Num , u8 Current);
extern void LD_PWM_Set(u16 Frequence,u8 Duty);
extern void Work_Control(u8 cmd);
extern void Fault_Check();
extern void LD_Parameter_Check();
extern void Read_FPGA_ADC_Data();
extern void LD_Threshold_Set();
extern void Status_Check();
extern void Fault_Check_Set(u8 Fault,u8 Cmd);




#endif
