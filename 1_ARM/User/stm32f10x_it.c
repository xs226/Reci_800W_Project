#include "Globle.h"

u8 ADC1_Convert_Done=0;
u8 DAC_WR_Done=0;
u8 ADC_RD_Done=0;

void EXTI1_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line1) != RESET) //急停
	{						
		EXTI_ClearITPendingBit(EXTI_Line1);     	
		Work_Control(0);
	} 
}

void EXTI9_5_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line6) != RESET) //数据采集完毕中断
	{						
		EXTI_ClearITPendingBit(EXTI_Line6);     	
		ADC_RD_Done=1;	
		//Read_FPGA_ADC_Data();			
	}  

	if(EXTI_GetITStatus(EXTI_Line7) != RESET) //写DAC完成中断
	{						
		DAC_WR_Done=1;
		FSMC_READ(ADDR_CCS_ADCRV);
		EXTI_ClearITPendingBit(EXTI_Line7);    
	}  

	if(EXTI_GetITStatus(EXTI_Line8) != RESET) //状态改变中断
	{			
		Reg_Status=FSMC_READ(ADDR_STATUS);	
		FSMC_WRITE(ADDR_STATUS,0x00ff); 		
		if(Reg_Status&0x0018)	
		{
			Error_Cmd=1;
			if(Reg_Status&0x0010)	Work_Control(0);
		}
	
		EXTI_ClearITPendingBit(EXTI_Line8);     	
	}  
}



void USART2_IRQHandler(void)
{
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
	{ 		   	
		RECEIVE_buffer2 = USART_ReceiveData(USART2);
		if(Run_Mode==1)//调试模式
		{
			if(point2==0)
			{
				if(RECEIVE_buffer2==0x7e) USART_Buffer2[point2++]=RECEIVE_buffer2;      
				else point2=0;	
			}
			else
			{
					USART_Buffer2[point2++]=RECEIVE_buffer2;
					if( RECEIVE_buffer2==0xe7)
					{
						receivedone2=1;
						point2=0;
					}	  
			}
		}
		else if(Run_Mode==0)//工作模式，MODBUS
		{
			if(point2==0)
			{
				if(RECEIVE_buffer2==0x02) USART_Buffer2[point2++]=RECEIVE_buffer2;      
				else point2=0;	
			}
			else
			{
					USART_Buffer2[point2++]=RECEIVE_buffer2;
					if( point2==8)
					{
						receivedone2=1;
						point2=0;
					}	  
			}
		}
	}
} 

void UART4_IRQHandler(void)
{
	if(USART_GetITStatus(UART4, USART_IT_RXNE) != RESET)
	{ 		   	
		RECEIVE_buffer4 = USART_ReceiveData(UART4);
		if(point4==0)
		{
			if(RECEIVE_buffer4==0x7e) USART_Buffer4[point4++]=RECEIVE_buffer4;      
			else point4=0;	
		}
		else
		{
				USART_Buffer4[point4++]=RECEIVE_buffer4;
				if( RECEIVE_buffer4==0xe7)
				{
				 	receivedone4=1;
					USART4_Data_Length=point4;
				 	point4=0;
				}	  
		} 
	}
} 
void DMA1_Channel1_IRQHandler(void)
{
	static u8 ITsum=0;

	if(DMA_GetITStatus(DMA1_IT_TC1))
	{	
    	DMA_ClearITPendingBit(DMA1_IT_GL1);				  
   		ADC_Tab[0][ITsum]=ADC_ConvertedValue[0];
			ADC_Tab[1][ITsum]=ADC_ConvertedValue[1];
			ITsum++;
   		if(ITsum==10)
			{
				ADC1_Convert_Done=1;
				ITsum=0;
				ADC_DMACmd(ADC1, DISABLE);  
			}
 	}
}


//void ADC1_2_IRQHandler(void)
//{

//	ADC1ConvertedValue = ADC_GetConversionValue(ADC1);

//	//if(kk==0) {LED_PIN_SET(0);kk=1;}
////	else {LED_PIN_SET(1);kk=0;}
//}



//void TIM4_IRQHandler(void)
//{
//	static	u16 TIM4_IC_Value1,TIM4_IC_Value2,CaptureNumber=0,Capture;
//    if(TIM_GetITStatus(TIM4, TIM_IT_CC1) == SET) 
//    {
//      TIM_ClearITPendingBit(TIM4, TIM_IT_CC1);
//      if(CaptureNumber == 0)
//      {
//        TIM4_IC_Value1 = TIM_GetCapture1(TIM4);
//        CaptureNumber = 1;
//      }
//      else if(CaptureNumber == 1)
//      {
//        TIM4_IC_Value2 = TIM_GetCapture1(TIM4); 
//        if (TIM4_IC_Value2 > TIM4_IC_Value1)
//        {
//          Capture = (TIM4_IC_Value2 - TIM4_IC_Value1); 
//        }
//        else
//        {
//          Capture = ((0xFFFF - TIM4_IC_Value1) + TIM4_IC_Value2); 
//        }
//        SL_Frequence = 20000 /Capture;
//        CaptureNumber = 0;
//     }
//   }
//	 	
//}

void TIM6_IRQHandler(void)
{
	if ( TIM_GetITStatus(TIM6 , TIM_IT_Update) != RESET ) 
	{	
		TIM_ClearITPendingBit(TIM6 , TIM_FLAG_Update); 
		TIM6_Count++;
		if(TIM6_Count_LD<2)	TIM6_Count_LD++;
	
		if(Run_Mode==1)//调试模式
		{
			if(TIM6_Count==5) 
			{
				Upload_to_pc(0);
			}	
			else	if(TIM6_Count==10) 
			{
				TIM6_Count=0;
				Upload_to_pc(1);
			}	 
		}
		else TIM6_Count=0;
	}		 	
}
