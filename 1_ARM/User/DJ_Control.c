#include "DJ_Control.h"
#include "Globle.h"

u16 Exit0_Count=0,Exit1_Count=0;
u16 DJ1_Step_Length=2,DJ2_Step_Length=2;
u16 DJ1_Run_Length=2,DJ2_Run_Length=2;
u8 DJ1_DI_Flag=0,DJ2_DI_Flag=0;
u16 DJ1_Current_Position=30000,DJ2_Current_Position=30000;
u8 DJ1_Mode=1,DJ2_Mode=1;
u8 DJ_Start_State=0;


void DJ_Calibration(u8 *tab)
{
	u16 temp;
	if(tab[2]==1)
	{
		DJ1_Mode=0;
	 	if(tab[3]==1)	
		 {
		  	DJ1_DI_SET(1);
		  	DJ1_DI_Flag=1;
		 }
		 else if(tab[3]==2)
		 {	
		  	DJ1_DI_SET(0);
		   	DJ1_DI_Flag=0;
		 }
		 temp=tab[4]*256+tab[5];
		 if(temp>0)
		 {
			Exit0_Count=0;
			DJ1_Step_Length=temp;
		 }
		 TIM_CCxCmd(TIM5, TIM_Channel_4, TIM_CCx_Enable);	
	}
	else if(tab[2]==2)//2ºÅµç»ú
	{
		 DJ2_Mode=0;
		 if(tab[3]==1)	
		 {
		  	DJ2_DI_SET(1);
		  	DJ2_DI_Flag=1;
		 }
		 else if(tab[3]==2)
		 {	
		  	DJ2_DI_SET(0);
		   	DJ2_DI_Flag=0;
		 }
		 temp=tab[4]*256+tab[5];
		 if(temp>0)
		 {
			 Exit1_Count=0;
			 DJ2_Step_Length=temp;
		 }
		 TIM_CCxCmd(TIM5, TIM_Channel_3, TIM_CCx_Enable);
	 }
 
}
/*
void DJ_Cmd_Process()
{
	static u8 flag=0;
	if(DJ_Start_State==1&&DJ1_Current_Position==0)
	{
		DJ1_DI_SET(1);
		DJ1_DI_Flag=1;
		TIM_CCxCmd(TIM5, TIM_Channel_4, TIM_CCx_Enable);
	}
	else if(DJ_Start_State==2&&DJ2_Current_Position==0)
	{
		DJ2_DI_SET(1);
		DJ2_DI_Flag=1;
		TIM_CCxCmd(TIM5, TIM_Channel_3, TIM_CCx_Enable);
	}
	else if(DJ_Start_State==3) 
}
*/



















