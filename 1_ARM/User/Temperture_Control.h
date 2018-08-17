#ifndef __TEMPERTURE_H
#define	__TEMPERTURE_H

#include "stm32f10x.h"
#include <stdio.h>
/*
extern void tem_control(void);
extern void exch(unsigned char *b1,unsigned char *b2);
extern void Lookup_TAB(uint resultADC, const uint *TABLE,uint *aptr);
extern u16 LinearInsert(uint tempresult,const uint *TABLE);
 */
extern u16 LDtemperature,Tem_Set_Value1,Tem_Set_Value2;//实际温度值的10倍,温度初始化为38℃；
extern u16 Hold_Time1,Hold_Time2;
extern u8 Temperture_Fault;//LD温度故障
extern u16 Tem_Tab[12];
extern u16 PT100_Tab[12];
extern u16 RTD_TAB_PT100[211];

extern void exch(u16 *b1,u16 *b2);
extern u16 Data_Filter(u16 *tab);
extern u16 CalculateTemperature(u16 fR);
extern u16 Tem_PID_Control(u16 Tem_Set,u16 Tem_Value);
extern void Tem_Process(void);
extern void Tem_State_Control(void);

extern u32 R_Value;

extern int32_t EK,EK1;
extern int32_t Kp,Ki,Kd;
extern int32_t Pterm,Iterm,Dterm;
extern int32_t UK;

extern u16 PV,IV,DV,PWM_Value;

extern u16 PWM_Edge;

extern u16 PWM_Edge1,PWM_Edge2,PWM_Edge3;

extern u8 Current_State;
extern u8 Tem_Cmd;

#endif

