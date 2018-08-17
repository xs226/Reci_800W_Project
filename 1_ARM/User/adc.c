#include "Globle.h"

#define ADC1_DR_Address    ((u32)0x40012400+0x4c)
__IO uint16_t              ADC_ConvertedValue[5]={0};
u16 ADC_Tab[2][10]={0};

void ADC1_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;	
	DMA_InitTypeDef DMA_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1|RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); 
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);	

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOC, &GPIO_InitStructure);	

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , ENABLE); //TIM2��CC2��TIM5��CC2ʹ��ͬһ�����ţ��໥Ӱ�죬��Ҫ��TIM2��ӳ�䵽�������
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM2 ,ENABLE ); 

	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
	TIM_TimeBaseStructure.TIM_Period = 99;
	TIM_TimeBaseStructure.TIM_Prescaler = 359;//100HZ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 20;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);

	TIM_ARRPreloadConfig(TIM2, ENABLE);	
	TIM_Cmd(TIM2, ENABLE);	

	DMA_DeInit(DMA1_Channel1);	 	
	DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;	 			//ADC��ַ
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)ADC_ConvertedValue;     	//�ڴ��ַ
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;						 //����
	DMA_InitStructure.DMA_BufferSize = 2;									   //9�����ݣ�ÿ�������ǰ��֣���16λ
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;	    //�����ַ�̶�
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  			//�ڴ��ַ����	
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;	  //��������ݵ�Ԫ��С--����
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;			//�ڴ�����ݵ�Ԫ��С--����
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;				//ѭ������ģʽ
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;	     //�����ȼ�
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;	   //��ֹ�ڴ浽�ڴ�Ĵ���
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);	   //DMA1��7��ͨ����DMA2��5��ͨ��
	
	DMA_ITConfig(DMA1_Channel1, DMA_IT_TC, ENABLE);		//�ж�����
	DMA_Cmd(DMA1_Channel1, ENABLE);						//ʹ��
	
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;			//����ADCģʽ
	ADC_InitStructure.ADC_ScanConvMode = ENABLE; 	 	//��ͨ�������ɼ�ʹ��		
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE ;		//����ת��ģʽ	
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T2_CC2 ;	//��ʹ���ⲿ����ת��
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;      	//�ɼ������Ҷ���
	ADC_InitStructure.ADC_NbrOfChannel = 2;	 								//Ҫת����ͨ����Ŀ10
	ADC_Init(ADC1, &ADC_InitStructure);
			
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);     
	ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 1, ADC_SampleTime_55Cycles5);//NTC_AD
	ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 2, ADC_SampleTime_55Cycles5);//AC_VALUE

	ADC_ExternalTrigConvCmd(ADC1, ENABLE);
	ADC_Cmd(ADC1, ENABLE);

	ADC_ResetCalibration(ADC1);	/*��λУ׼�Ĵ��� */   	
	while(ADC_GetResetCalibrationStatus(ADC1));/*�ȴ�У׼�Ĵ�����λ��� */		
	ADC_StartCalibration(ADC1);/* ADCУ׼ */
	while(ADC_GetCalibrationStatus(ADC1));	/* �ȴ�У׼���*/

	ADC_DMACmd(ADC1, ENABLE);    	  /* Enable ADC1ʹ��DMA�����ʽ */	
	ADC_ITConfig(ADC1, ADC_IT_EOC, ENABLE);	   // stm32f10x_adc.c������
}


void ADelay_1us(__IO u16 i)
{ 
	u16 j;
	while(i--){
		for(j=0;j<7;j++);
	}		  
}

/*********************************************END OF FILE**********************/

