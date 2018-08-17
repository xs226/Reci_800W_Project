//****************************************************************//
//DHT12 IIC���ݶ�ȡ����
// ��˾��    ���ɵ���
//****************************************************************//

#include "Globle.h"


u16 Ambient_Tem,Ambient_Humi;//������ʪ�ȱ��� ���˱���Ϊȫ�ֱ���
u8 EEPROM_Tab_WR[10];
u8 EEPROM_Tab_RD[256];
/********************************************\
|* ���ܣ�DHT12��ȡ��ʪ�Ⱥ���       *|
\********************************************/
//������Humi_H��ʪ�ȸ�λ��Humi_L��ʪ�ȵ�λ��Temp_H���¶ȸ�λ��Temp_L���¶ȵ�λ��Temp_CAL��У��λ
//���ݸ�ʽΪ��ʪ�ȸ�λ��ʪ��������+ʪ�ȵ�λ��ʪ��С����+�¶ȸ�λ���¶�������+�¶ȵ�λ���¶�С����+ У��λ
//У�飺У��λ=ʪ�ȸ�λ+ʪ�ȵ�λ+�¶ȸ�λ+�¶ȵ�λ
void SHT12_Read(void) 
{	
	u16 i;
	u8 Humi_H,Humi_L,Temp_H,Temp_L,Temp_CAL,temp;

	IIC_Start(1);    //����������ʼ�ź�
	IIC_Send_Byte(1,0Xb8);    //����IIC��ַ
	if(!IIC_Wait_Ack(1))  //�ȴ��ӻ�Ӧ���źţ�����Ӧ�𣺿���IICͨѶƵ���Ƿ�̫�죬���ߴ��������ߴ���
	{
		i=0;
		IIC_Send_Byte(1,0);
		while(IIC_Wait_Ack(1))//�ȴ��ӻ�Ӧ���ź�
		{
		 	if(++i>=500)
			{
			 	break;
			}		 
		} 
		i=0;
		IIC_Start(1);       //����������ʼ�ź�
		IIC_Send_Byte(1,0Xb9);     //���Ͷ�ָ��
		while(IIC_Wait_Ack(1))    //�ȴ��ӻ�Ӧ���ź�
		{
		 	if(++i>=500)
			{
			 	break;
			}			 
		}
	
		Humi_H=IIC_Read_Byte(1,1);   //��ȡʪ�ȸ�λ
		Humi_L=IIC_Read_Byte(1,1);   //��ȡʪ�ȵ�λ
		Temp_H=IIC_Read_Byte(1,1);   //��ȡ�¶ȸ�λ
		Temp_L=IIC_Read_Byte(1,1);   //��ȡ�¶ȵ�λ
		Temp_CAL=IIC_Read_Byte(1,0); //��ȡУ��λ
		IIC_Stop(1);	   //����ֹͣ�ź�	
		temp = (u8)(Humi_H+Humi_L+Temp_H+Temp_L);//ֻȡ��8λ
		if(Temp_CAL==temp)//���У��ɹ�����������
		{
			Ambient_Humi=Humi_H*10+Humi_L; //ʪ��
	
			if(Temp_L&0X80)	//Ϊ���¶�
			{
				//Ambient_Tem =0-(Temp_H*10+((Temp_L&0x7F)));
			}
			else   //Ϊ���¶�
			{
				Ambient_Tem=Temp_H*10+Temp_L;//Ϊ���¶�
				if(Ambient_Tem>600)	Ambient_Tem=600;
			} 	
			//�ж���ʪ���Ƿ񳬹�������Χ���¶ȣ�-20��~60���϶ȣ�ʪ�ȣ�20%RH~95%RH��		
			if(Ambient_Humi>950)  Ambient_Humi=950;
			else if(Ambient_Humi<200)	Ambient_Humi =200;
		}

	}

}

void IIC_Delay_1ms(__IO u16 i){ 
	u16 j;
	while(i--){
		for(j=0;j<8000;j++);
	}		  
}


void Write_Fault_ToEEPROM()
{
	u8 Temp_Tab[1],Len,Address;
	u8 tab1[1],tab2[2];

	EEPROM_Read(0,tab1,1);
	Len=tab1[0];
	if(Len>25) Len=0;
	IIC_Delay_1ms(5);
	Address=1+Len*9;
	EEPROM_Tab_WR[0]=Readtime.year;	
	EEPROM_Tab_WR[1]=Readtime.month;
	EEPROM_Tab_WR[2]=Readtime.day;
	EEPROM_Tab_WR[3]=Readtime.week;	
	EEPROM_Tab_WR[4]=Readtime.hour;	
	EEPROM_Tab_WR[5]=Readtime.min;	
	EEPROM_Tab_WR[6]=Readtime.sec;	
	EEPROM_Tab_WR[7]=Error_Code>>8;	
	EEPROM_Tab_WR[8]=Error_Code;		
	EEPROM_Write(Address,EEPROM_Tab_WR,9);
	IIC_Delay_1ms(5);	
	Len++;
	tab2[0]=Len;
	EEPROM_Write(0,tab2,1);
  IIC_Delay_1ms(5);
}

void Read_EEPROM_ToRAM()
{
	u8 Temp_Tab[1],Len;	
	EEPROM_Read(0,Temp_Tab,1);
	Len=Temp_Tab[0]*9;	
	if(Temp_Tab[0]>0) EEPROM_Read(1,EEPROM_Tab_RD,Len);
}



u8 EEPROM_Write(unsigned char  Address,unsigned char  *s,unsigned char  SUM)
{
   unsigned char i,ack;

   IIC_Start(0); 
	 IIC_Send_Byte(0,0xa0);//�ӻ���ַ 	
	 ack=IIC_Wait_Ack(0);	
   if(ack==1)return(0);
	 IIC_Send_Byte(0,Address);
   ack=IIC_Wait_Ack(0);	
   if(ack==1)return(0);

   for(i=0;i<SUM;i++)
   {   
		 IIC_Send_Byte(0,*s);		 
     ack=IIC_Wait_Ack(0);	
		 if(ack==1)return(0);
     s++;
   } 
   IIC_Stop(0);             

   return(1);
}

u8 EEPROM_Read(unsigned char  Address,unsigned char  *s,unsigned char  SUM)
{
   unsigned char i,ack;

   IIC_Start(0);                
   IIC_Send_Byte(0,0xa0);//�ӻ���ַ 	
	 ack=IIC_Wait_Ack(0);	
   if(ack==1)return(0);
	
   IIC_Send_Byte(0,Address);
   ack=IIC_Wait_Ack(0);	
   if(ack==1)return(0);

   IIC_Start(0);              
	 IIC_Send_Byte(0,0xa1);
   ack=IIC_Wait_Ack(0);	
   if(ack==1)return(0);
	
   for(i=0;i<SUM-1;i++)
   {   
     *s=IIC_Read_Byte(0,1);                        
     s++;
   } 
   *s=IIC_Read_Byte(0,1);                   
   IIC_Stop(0);              
   return(1);
}








void SDA_IN(u8 device)//device:0 AT24C02 	1 DHT12
{
	if(device)
	{
		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ;   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	}
	else 
	{
		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ;   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	}
}

void SDA_OUT(u8 device)
{
	if(device)
	{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );	   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	}
	else 
	{
		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );	   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	}
	
}



void IIC_SCL(u8 device,u8 a)
{
	if(device)
	{
		if (a)  GPIO_SetBits(GPIOB,GPIO_Pin_10);  
		else GPIO_ResetBits(GPIOB,GPIO_Pin_10);
	}
	else
	{
		if (a)  GPIO_SetBits(GPIOB,GPIO_Pin_8);  
		else GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	}
}

void IIC_SDA(u8 device,u8 a)
{
	if(device)
	{	
		if (a)  GPIO_SetBits(GPIOB,GPIO_Pin_11);  
		else GPIO_ResetBits(GPIOB,GPIO_Pin_11);
	}
	else
	{
		if (a)  GPIO_SetBits(GPIOB,GPIO_Pin_9);  
		else GPIO_ResetBits(GPIOB,GPIO_Pin_9);
	}
}

void I2C_Delay_1us(__IO u16 i)
{ 
	u16 j;
	while(i--)
	{
		for(j=0;j<7;j++);
	}		  
}

void IIC_Start(u8 device)
{
	SDA_OUT(device);     //sda�����
	IIC_SDA(device,1);	  	  
	IIC_SCL(device,1);
	I2C_Delay_1us(14);
	IIC_SDA(device,0);//��ʼ����SCLΪ��ʱ�����ݴӸߵ��ͱ仯
	I2C_Delay_1us(14);
	IIC_SCL(device,0);//ǯסI2C���ߣ�׼�����ͻ�������� 
}	  

void IIC_Stop(u8 device)
{
	SDA_OUT(device);//sda�����
	IIC_SCL(device,0);
	IIC_SDA(device,0);//ֹͣ:��SCLΪ��ʱ�����ݴӵ͵��߱仯
 	I2C_Delay_1us(14);
	IIC_SCL(device,1);
	I2C_Delay_1us(14);	 
	IIC_SDA(device,1);//����I2C���߽����ź�
							   	
}
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
u8 IIC_Wait_Ack(u8 device)
{
	u8 ucErrTime=0;
	IIC_SCL(device,0);
	IIC_SDA(device,1);
	SDA_IN(device);      //SDA����Ϊ����  
	I2C_Delay_1us(14);	   
	IIC_SCL(device,1);
	I2C_Delay_1us(14);	
	if(device)
	{
		while(Read_IO_State(GPIOB,GPIO_Pin_11))//�ȵ�SDA���
		{
			ucErrTime++;
			if(ucErrTime>250)
			{
				IIC_Stop(device);
				return 1;
			}
			I2C_Delay_1us(1);
		}
	}
	else 
	{
		while(Read_IO_State(GPIOB,GPIO_Pin_9))//�ȵ�SDA���
		{
			ucErrTime++;
			if(ucErrTime>250)
			{
				IIC_Stop(device);
				return 1;
			}
			I2C_Delay_1us(1);
		}
	}
	IIC_SCL(device,0);//ʱ�����0
	I2C_Delay_1us(10); 
	return 0;  
} 
//����ACKӦ��
void IIC_Ack(u8 device)
{
	IIC_SCL(device,0);
	SDA_OUT(device);
	IIC_SDA(device,0);
	I2C_Delay_1us(15);
	IIC_SCL(device,1);
	I2C_Delay_1us(15);
	IIC_SCL(device,0);
}
//������ACKӦ��		    
void IIC_NAck(u8 device)
{
	IIC_SCL(device,0);
	SDA_OUT(device);
	IIC_SDA(device,1);
	I2C_Delay_1us(15);
	IIC_SCL(device,1);
	I2C_Delay_1us(15);
	IIC_SCL(device,0);
}					 				     
//IIC����һ���ֽ�
//���شӻ�����Ӧ��
//1����Ӧ��
//0����Ӧ��			  
void IIC_Send_Byte(u8 device,u8 txd)
{                        
  u8 t;   
	SDA_OUT(device); 	    
  IIC_SCL(device,0);//����ʱ�ӿ�ʼ���ݴ���
  for(t=0;t<8;t++)
  {              
		IIC_SCL(device,0);
		if((txd&0x80)>>7)
			IIC_SDA(device,1);
		else
			IIC_SDA(device,0);
		txd<<=1; 	  
		I2C_Delay_1us(15);   //��ʱ
		IIC_SCL(device,1);
		I2C_Delay_1us(15); 	
  }
		IIC_SCL(device,0);	 
} 	    
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
u8 IIC_Read_Byte(u8 device,unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN(device);//SDA����Ϊ����
  for(i=0;i<8;i++ )
	{
    IIC_SCL(device,0); 
    I2C_Delay_1us(50);
		IIC_SCL(device,1);
		I2C_Delay_1us(50);
    receive<<=1;
		if(device){    if(Read_IO_State(GPIOB,GPIO_Pin_11))receive++; }
		else {    if(Read_IO_State(GPIOB,GPIO_Pin_9))receive++; }
  }
  IIC_SCL(device,0);						 
  if (!ack)  IIC_NAck(device);//����nACK
  else       IIC_Ack(device); //����ACK   
  return receive;
}




































