#ifndef __DJ_Control_H__
#define __DJ_Control_H__

#include "stm32f10x.h"


extern u16 Exit0_Count,Exit1_Count;
extern u16 DJ1_Step_Length,DJ2_Step_Length;
extern u16 DJ1_Run_Length,DJ2_Run_Length;
extern u8 DJ1_DI_Flag,DJ2_DI_Flag;
extern u16 DJ1_Current_Position,DJ2_Current_Position;
extern u8 DJ1_Mode,DJ2_Mode;
extern u8 DJ_Cmd;


extern void DJ_Calibration(u8 *tab);


#endif








