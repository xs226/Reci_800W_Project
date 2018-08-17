#include "Globle.h"

u8 RECEIVE_buffer2=0,RECEIVE_buffer4=0;
u8 point2=0,point4=0,receivedone2,receivedone4;
u8 USART_Buffer2[50]={0},USART_Buffer4[50]={0x7e,0xd1,0x31,0x32,0x38,0x37,0x34,0xe7};
u8 Upload_Tab2[30],Upload_Tab4[12]={0};
u8 USART4_Data_Length=0;

void USART_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	
	USART_DeInit(USART2);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2| RCC_APB1Periph_UART4, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;	
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;	
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART2, &USART_InitStructure);
	
	USART_InitStructure.USART_BaudRate = 9600;
	USART_Init(UART4, &USART_InitStructure);
	
  USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);	
	USART_ITConfig(UART4,  USART_IT_RXNE, ENABLE);
	USART_Cmd(USART2, ENABLE);
	USART_Cmd(UART4, ENABLE);
}





void USART2_Commdeal(void)//用于接收上位机的相关指令，并执行相应的操作 
{
 u8 command,temp,tab[15];
 //u8 accumulation=0; 
	
 static u8 Temp_Duty=50;
 static u16 Temp_Frequence=100,temp2,Temp_Key_Value=0;
 u8 RTC_Type,RTC_Value;
 u16 RS_CRC_Data=0,RX_CMD_Address=0;
 u8 Modbus_Fault_Code=0;
 command=USART_Buffer2[1];

 if(Run_Mode==1)//调试模式
 {
	 switch (command)
	 {
			case 0XA1:	//强电控制
		{
			temp=USART_Buffer2[2];
			TDK_Power_Set(temp);
			break;
		}
		case 0XA2:	//红光控制
		{
			if(USART_Buffer2[2]==1) TIM_Cmd(TIM3, ENABLE);
			else if(USART_Buffer2[2]==0) TIM_Cmd(TIM3, DISABLE); 
			break;
		}
		case 0XA3:	//FPGA复位
		{
			Globle_Init();
			break;
		}
		case 0XA4:	//故障设置
		{
			Fault_Type=USART_Buffer2[2];
			Fault_Cmd=USART_Buffer2[3];
			Fault_Check_Set(Fault_Type,Fault_Cmd);		
			break;
		}
		
		 case 0XA5:	//出光
		{
			Work_Cmd=USART_Buffer2[2];	
			break;
		}	
		 case 0XA6:	//参数保存
		{
			Write_Parameter_ToFLASH();
			break;
		}
		 case 0XA7:	//电流设置
		{
			LD_Current_Set1=USART_Buffer2[2];
			LD_Current_Set2=USART_Buffer2[3];
			LD_Current_Set(1,LD_Current_Set1);
			LD_Current_Set(2,LD_Current_Set2);
			break;
		}
		case 0XA8:	//内时统设置
		{
			LD_Duty=USART_Buffer2[2];
			LD_Frequence=USART_Buffer2[3]*256+USART_Buffer2[4];
			LD_PWM_Set(LD_Frequence,LD_Duty);
			Write_Parameter_ToFLASH();
			break;
		}	
		case 0XA9:	//ANG_KAD设置
		{
			temp2=USART_Buffer2[2]*256+USART_Buffer2[3];
			if(temp2>920&&temp2<1127)
			{
				ANG_KAD_VALUE=temp2;
				FSMC_WRITE(ADDR_ANG_KAD,ANG_KAD_VALUE);
			}
			break;
		}
		case 0XAA:	//时间设定
		{
			RTC_Type=USART_Buffer2[2];
			RTC_Value=USART_Buffer2[3];
			RTC_Parameter_Set(RTC_Type,RTC_Value);
			break;
		}
		case 0XAB:	//阈值设定
		{
			CCS1_MAXADC_VALUE=USART_Buffer2[2]*256+USART_Buffer2[3];
			CCS2_MAXADC_VALUE=USART_Buffer2[4]*256+USART_Buffer2[5];
			OPP_MAXADC_VALUE=USART_Buffer2[6]*256+USART_Buffer2[7];
			LD_Threshold_Set();
			break;
		}	
		case 0XAF:	//工作模式
		{
			PWM_Mode=USART_Buffer2[2];
			PWM_Mode_Set(PWM_Mode);
			break;
		}
		default:break;
	 }
 }
 else if(Run_Mode==0)//工作模式，MODBUS 
 {
	 	if(USART_Buffer2[1] == 0x01)							  //01功能码，读功能 bit
		{
			RX_CMD_Address=USART_Buffer2[2]<<8|USART_Buffer2[3];
			RS_CRC_Data=crc16(USART_Buffer2,6);					  //校验
			if(RS_CRC_Data==(USART_Buffer2[7]<<8 | USART_Buffer2[6]) )	  //校验正确时
			{					
				if(Work_Cmd==1) Temp_Key_Value|=0x1100;
				else if(Work_Cmd==0) Temp_Key_Value&=~0x1100;
				if(Error_Code&0x0020) Temp_Key_Value|=0x0200;//IDLE过流
				else Temp_Key_Value&=~0x0200;
				if(Error_Code&0x0008) Temp_Key_Value|=0x0400;//过流
				else Temp_Key_Value&=~0x0400;
				if(Error_Code&0x0010) Temp_Key_Value|=0x0800;//水冷
				else Temp_Key_Value&=~0x0800;
				
				tab[0]=USART_Buffer2[0];					  //站号
				tab[1]=USART_Buffer2[1];					  //功能码
				tab[2]=0x02;							  //字节数
				tab[3]=Temp_Key_Value>>8;						  //低位状态,即LED开关情况
				tab[4]=Temp_Key_Value;
				RS_CRC_Data=crc16(tab,5);					  //校验
				tab[5]=RS_CRC_Data%256;					  //校验低位
				tab[6]=RS_CRC_Data/256;					  //校验高位
			  USART_Send_String(USART2,tab,7);	
			 
			}
		}	
		if(USART_Buffer2[1] == 0x05)							  //05功能码，写功能 bit
		{
			RX_CMD_Address=USART_Buffer2[2]<<8|USART_Buffer2[3];
			RS_CRC_Data=crc16(USART_Buffer2,6);					  //校验
			if(RS_CRC_Data==(USART_Buffer2[7]<<8 | USART_Buffer2[6]) )	  //校验正确时
			{				
				switch (RX_CMD_Address)
				{
					case 0x00: //使能
					{
						if(USART_Buffer2[4]==0xff) Work_Cmd=1;
						else Work_Cmd=0;		
						break;
					}
					default:break;
			 }	

			 USART_Send_String(USART2,USART_Buffer2,8);	
			 temp2=0;
			}
		}		
		if(USART_Buffer2[1] == 0x03)							  //03功能码，读功能 寄存器，做链路用
		{
			RX_CMD_Address=USART_Buffer2[2]<<8|USART_Buffer2[3];
			RS_CRC_Data=crc16(USART_Buffer2,6);					  //校验
			if(RS_CRC_Data==(USART_Buffer2[7]<<8 | USART_Buffer2[6]) )	  //校验正确时
			{			
				
				tab[0]=USART_Buffer2[0];					  //站号
				tab[1]=USART_Buffer2[1];					  //功能码
				tab[2]=0x04;							  //字节数
				tab[3]=LD_Frequence>>8;
				tab[4]=LD_Frequence;
				tab[5]=0;
				tab[6]=LD_Duty;				
				RS_CRC_Data=crc16(tab,7);					  //校验
				tab[7]=RS_CRC_Data%256;					  //校验低位
				tab[8]=RS_CRC_Data/256;					  //校验高位
			  USART_Send_String(USART2,tab,9);	
			 
			}
		}	
		if(USART_Buffer2[1] == 0x06)							  //06功能码，写寄存器功能
		{
			RX_CMD_Address=USART_Buffer2[2]<<8|USART_Buffer2[3];
			RS_CRC_Data=crc16(USART_Buffer2,6);					  //校验
			if(RS_CRC_Data==(USART_Buffer2[7]<<8 | USART_Buffer2[6]) )	  //校验正确时
			{			
				switch (RX_CMD_Address)
				{
					case 0x01: //频率
					{
						LD_Frequence=USART_Buffer2[4]<<8|USART_Buffer2[5];
						if(LD_Frequence>10000) LD_Frequence=10000;
						LD_PWM_Set(LD_Frequence,LD_Duty);
						break;
					}
					case 0x02: //占空比
					{
						LD_Duty=USART_Buffer2[5];
						if(LD_Duty>100) LD_Duty=100;
						LD_PWM_Set(LD_Frequence,LD_Duty);
						break;
					}
					default:break;
			  }	
				Write_Parameter_ToFLASH();
				USART_Send_String(USART2,USART_Buffer2,8);	
			  temp2=0;
			}
		}
 }
 
}


void USART4_Commdeal(void)//用于接收上位机的相关指令，并执行相应的操作 
{
	u8 command,i,j=0;
	u16 temp1,temp2,Data_Value=0;
	static u16 LCD_Duty=0,LCD_Frequence=0;
	
	command=USART_Buffer4[1];
	for(i=USART4_Data_Length-3;i>0;i--)
	{
		temp1=pow(10, USART4_Data_Length-3-i);
		temp2=USART_Buffer4[USART4_Data_Length-2-j++]-0x30;
		Data_Value+=temp2*temp1;
	}
 switch (command)
 {
 	 	case 0Xd1:	//频率
	{
		LCD_Frequence=Data_Value;
		LD_PWM_Set(LCD_Frequence,LCD_Duty);
    break;
	}
 	case 0Xd2:	//占空比
	{
		LCD_Duty=Data_Value;
		LD_PWM_Set(LCD_Frequence,LCD_Duty);
    break;
	}
	case 0Xd3:	//出光能量
	{
		Data_Value=Data_Value*113/500;
		if(Data_Value>115) Data_Value=115;
		LD_Current_Set(1,Data_Value);
		LD_Current_Set(2,Data_Value);
    break;
	}
	default:break;
 }
}


void Upload_to_pc(u8 cmd)
{
	static u8 RST_Cmd=0;
	
	Upload_Tab2[0]=0x7E;
	if(cmd==0)
	{                 
		Upload_Tab2[1]=0xb1;
		Upload_Tab2[2]=LD_Current1;
		Upload_Tab2[3]=LD_MOS_V1;
		Upload_Tab2[4]=LD_Current2;
		Upload_Tab2[5]=LD_MOS_V2;
		Upload_Tab2[6]=LDtemperature>>8;
		Upload_Tab2[7]=LDtemperature;
		Upload_Tab2[8]=ANG_KAD_VALUE>>8;
		Upload_Tab2[9]=ANG_KAD_VALUE;
		Upload_Tab2[10]=AC_Power>>8;
		Upload_Tab2[11]=AC_Power;	
		
		Upload_Tab2[12]=FPGA_ADC_TAB[0]>>8;	
		Upload_Tab2[13]=FPGA_ADC_TAB[0];
		Upload_Tab2[14]=FPGA_ADC_TAB[1]>>8;	
		Upload_Tab2[15]=FPGA_ADC_TAB[1];
		Upload_Tab2[16]=FPGA_ADC_TAB[2]>>8;	
		Upload_Tab2[17]=FPGA_ADC_TAB[2];			
		
		Upload_Tab2[18]=Ambient_Tem>>8;		
		Upload_Tab2[19]=Ambient_Tem;
		Upload_Tab2[20]=Ambient_Humi>>8;		
		Upload_Tab2[21]=Ambient_Humi;		
    
		Upload_Tab2[22]=EX_AD_ISet;	
		
		Upload_Tab2[28]=RST_Cmd;
		Upload_Tab2[29]=0xe7;
	}
	else if(cmd==1)
	{                  
		Upload_Tab2[1]=0xb2;
		Upload_Tab2[2]=Fault_Tab[0];
		Upload_Tab2[3]=Fault_Tab[1];
		Upload_Tab2[4]=Fault_Tab[2];
		Upload_Tab2[5]=Fault_Tab[3];
		Upload_Tab2[6]=Fault_Tab[4];
		Upload_Tab2[7]=Fault_Tab[5];
		Upload_Tab2[8]=Fault_Tab[6];
		Upload_Tab2[9]=Fault_Tab[7];		
		Upload_Tab2[10]=Fault_Tab[8];
		Upload_Tab2[11]=Fault_Tab[9];

		Upload_Tab2[12]=Status_Tab[0];
		Upload_Tab2[13]=Status_Tab[1];		
		Upload_Tab2[14]=Status_Tab[2];
		Upload_Tab2[15]=Status_Tab[3];
		Upload_Tab2[16]=Status_Tab[4];
		Upload_Tab2[17]=Status_Tab[5];
		Upload_Tab2[18]=Status_Tab[6];
		
		Upload_Tab2[29]=0xe7;
	}
	USART_Send_String(USART2,Upload_Tab2,30);	
  if(RST_Cmd==0) RST_Cmd=1;	
}

void USART_Send_String(USART_TypeDef* USARTx,u8 *str,u8 sum)
{
	u8 i;
	for(i=0;i<sum;i++)
	{
		USART_SendData(USARTx, str[i]);
		while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET){}  
	} 
}


void TFT_Send_String(u8 *str)
{
	u8 i;
	while(*str!=0)
	{
		USART_SendData(UART4, *str);
		str++;
		while(USART_GetFlagStatus(UART4, USART_FLAG_TC) == RESET){}  
	} 
	for(i=0;i<3;i++)
	{
		USART_SendData(UART4, 0xff);
		while(USART_GetFlagStatus(UART4, USART_FLAG_TC) == RESET){}
	}
}



/*********************************************END OF FILE**********************/











































