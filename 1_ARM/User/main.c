#include "Globle.h"

u16 value=0,value2=0;
u8 Cmd_Flag=0;

u8 IIC_TAB[8]={0,2,3,6,2,8,2,6};
u8  IIC_TAB2[8]={0};


int main(void)
{
	Delay_1ms(1000);
	
	PORT_Init();
	FSMC_Configuration();
	USART_Config();
	NVIC_Configuration();
	ADC1_Configuration();
	//TIM3_Configuration();
	TIM6_Configuration();
	EXTI_Configuration();
	Globle_Init();
	while(1)
	{		


		
		Fault_Check();
		if(receivedone2==1)	{USART2_Commdeal(); receivedone2=0;	}	
		if(receivedone4==1)	{USART4_Commdeal(); receivedone4=0;	}	
		if(TIM6_Count_LD==2)  {LD_Parameter_Check();TIM6_Count_LD=0;}
		if(ADC1_Convert_Done==1) { Tem_AC220_Check();ADC1_Convert_Done=0;ADC_DMACmd(ADC1, ENABLE);}
		Status_Check();
		Key_Scan();
		if( Work_Cmd==1 && Cmd_Flag==0 )
		{
			Work_Control(1);
			Work_LED_SET(0);
			Cmd_Flag=1;
			
		}
		else if( Work_Cmd==0 && Cmd_Flag==1 )
				{	
					Work_Control(0);
					Work_LED_SET(1);
					Cmd_Flag=0;
				}
	}
}

/*********************************************END OF FILE**********************/
