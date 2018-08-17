#include "Globle.h"

u16 TIM6_Count=0;
u16 TIM6_Count_LD=0;
u16 Tem_State_Count=0;
u16 TIM4_Count=0;

//void TIM3_Configuration(void)
//{
//  	GPIO_InitTypeDef GPIO_InitStructure;
//		TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//		TIM_OCInitTypeDef  TIM_OCInitStructure;

//  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); /* 设置TIM3CLK 为 72MHZ */
//  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  

//  	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7;
//  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    
//  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//		GPIO_Init(GPIOA, &GPIO_InitStructure);

//  	TIM_TimeBaseStructure.TIM_Period = 999;//定时20HZ       
//  	TIM_TimeBaseStructure.TIM_Prescaler =71;	    
//  	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;	
//  	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
//  	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

//		TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    
//		TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	
//		TIM_OCInitStructure.TIM_Pulse = 400;	   
//		TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;  
//		TIM_OC2Init(TIM3, &TIM_OCInitStructure);	
//		TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);

//  	TIM_ARRPreloadConfig(TIM3, ENABLE);			
//  	TIM_Cmd(TIM3, ENABLE);                   	
//}

//void RedLaser_PWM_Set(u16 value)
//{
//	TIM_OCInitTypeDef  TIM_OCInitStructure;
//  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	
//	TIM_OCInitStructure.TIM_Pulse = value;	   
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;  
//	TIM_OC2Init(TIM3, &TIM_OCInitStructure);
//}

void TIM6_Configuration(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;		
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6 , ENABLE);	
    TIM_TimeBaseStructure.TIM_Period=999;		   //1000*50us=100ms
    TIM_TimeBaseStructure.TIM_Prescaler= 7199;		 //5K	
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;	
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
		TIM_TimeBaseStructure.TIM_RepetitionCounter=0; 
    TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);
	
    TIM_ClearFlag(TIM6, TIM_FLAG_Update);	
    TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);		
    TIM_Cmd(TIM6, ENABLE);																		  
}



