#include "DAC.h"
#include "Globle.h"


void DAC_Config(void)	  //DA不是由MCU直接输出，通过控制MAX536实现
{		 
  	GPIO_InitTypeDef GPIO_InitStructure;
	DAC_InitTypeDef  DAC_InitStructure;

  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		
 	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;	 
  	GPIO_Init(GPIOA, &GPIO_InitStructure);	 
	
  	DAC_InitStructure.DAC_Trigger = DAC_Trigger_Software;						
  	DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;	
  	DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
  	DAC_Init(DAC_Channel_1, &DAC_InitStructure);
  	DAC_Init(DAC_Channel_2, &DAC_InitStructure);
  	DAC_Cmd(DAC_Channel_1, ENABLE);
 	DAC_Cmd(DAC_Channel_2, ENABLE);

	DAC_SetChannel1Data(DAC_Align_12b_R, 0);
	DAC_SetChannel2Data(DAC_Align_12b_R, 0x0000);
    DAC_SoftwareTriggerCmd(DAC_Channel_1, ENABLE);
	DAC_SoftwareTriggerCmd(DAC_Channel_2, ENABLE);
}

