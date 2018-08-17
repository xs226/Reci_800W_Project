#include "Globle.h"

void EXTI_Configuration(void)
{		  
		GPIO_InitTypeDef GPIO_InitStructure; 
		EXTI_InitTypeDef EXTI_InitStructure;

  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC |RCC_APB2Periph_GPIOE |  RCC_APB2Periph_AFIO,ENABLE);													
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8;       
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;	 // 下拉输入
  	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	  GPIO_Init(GPIOE, &GPIO_InitStructure);
	
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource6); 
  	EXTI_InitStructure.EXTI_Line = EXTI_Line6;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising; //上升沿中断
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);  

  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource7); 
  	EXTI_InitStructure.EXTI_Line = EXTI_Line7;  
  	EXTI_Init(&EXTI_InitStructure); 

		GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource8); 
  	EXTI_InitStructure.EXTI_Line = EXTI_Line8;  
  	EXTI_Init(&EXTI_InitStructure);
		
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource1); 
  	EXTI_InitStructure.EXTI_Line = EXTI_Line1; 
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿中断		
  	EXTI_Init(&EXTI_InitStructure);

}
void EXTI_EN(u8 EXTI_NUM, u8 cmd)
{			//中断线的开关
  EXTI_InitTypeDef EXTI_InitStructure;	
  switch (EXTI_NUM){
  	case 0:	EXTI_InitStructure.EXTI_Line = EXTI_Line0;break;
	case 1:	EXTI_InitStructure.EXTI_Line = EXTI_Line1;break;
	case 2:	EXTI_InitStructure.EXTI_Line = EXTI_Line2;break;
	default: break;
  }
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	   
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;    //上升沿中断
  if (cmd==0)	EXTI_InitStructure.EXTI_LineCmd = DISABLE;
  else  if (cmd==1)  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);		
}