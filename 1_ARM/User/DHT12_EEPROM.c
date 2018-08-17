//****************************************************************//
//DHT12 IIC数据读取程序
// 公司：    奥松电子
//****************************************************************//

#include "Globle.h"


u16 Ambient_Tem,Ambient_Humi;//定义温湿度变量 ，此变量为全局变量
u8 EEPROM_Tab_WR[10];
u8 EEPROM_Tab_RD[256];
/********************************************\
|* 功能：DHT12读取温湿度函数       *|
\********************************************/
//变量：Humi_H：湿度高位；Humi_L：湿度低位；Temp_H：温度高位；Temp_L：温度低位；Temp_CAL：校验位
//数据格式为：湿度高位（湿度整数）+湿度低位（湿度小数）+温度高位（温度整数）+温度低位（温度小数）+ 校验位
//校验：校验位=湿度高位+湿度低位+温度高位+温度低位
void SHT12_Read(void) 
{	
	u16 i;
	u8 Humi_H,Humi_L,Temp_H,Temp_L,Temp_CAL,temp;

	IIC_Start(1);    //主机发送起始信号
	IIC_Send_Byte(1,0Xb8);    //发送IIC地址
	if(!IIC_Wait_Ack(1))  //等待从机应答信号（如无应答：考虑IIC通讯频率是否太快，或者传感器接线错误）
	{
		i=0;
		IIC_Send_Byte(1,0);
		while(IIC_Wait_Ack(1))//等待从机应答信号
		{
		 	if(++i>=500)
			{
			 	break;
			}		 
		} 
		i=0;
		IIC_Start(1);       //主机发送起始信号
		IIC_Send_Byte(1,0Xb9);     //发送读指令
		while(IIC_Wait_Ack(1))    //等待从机应答信号
		{
		 	if(++i>=500)
			{
			 	break;
			}			 
		}
	
		Humi_H=IIC_Read_Byte(1,1);   //读取湿度高位
		Humi_L=IIC_Read_Byte(1,1);   //读取湿度低位
		Temp_H=IIC_Read_Byte(1,1);   //读取温度高位
		Temp_L=IIC_Read_Byte(1,1);   //读取温度低位
		Temp_CAL=IIC_Read_Byte(1,0); //读取校验位
		IIC_Stop(1);	   //发送停止信号	
		temp = (u8)(Humi_H+Humi_L+Temp_H+Temp_L);//只取低8位
		if(Temp_CAL==temp)//如果校验成功，往下运行
		{
			Ambient_Humi=Humi_H*10+Humi_L; //湿度
	
			if(Temp_L&0X80)	//为负温度
			{
				//Ambient_Tem =0-(Temp_H*10+((Temp_L&0x7F)));
			}
			else   //为正温度
			{
				Ambient_Tem=Temp_H*10+Temp_L;//为正温度
				if(Ambient_Tem>600)	Ambient_Tem=600;
			} 	
			//判断温湿度是否超过测量范围（温度：-20℃~60摄氏度；湿度：20%RH~95%RH）		
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
	 IIC_Send_Byte(0,0xa0);//从机地址 	
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
   IIC_Send_Byte(0,0xa0);//从机地址 	
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
	SDA_OUT(device);     //sda线输出
	IIC_SDA(device,1);	  	  
	IIC_SCL(device,1);
	I2C_Delay_1us(14);
	IIC_SDA(device,0);//开始：当SCL为高时，数据从高到低变化
	I2C_Delay_1us(14);
	IIC_SCL(device,0);//钳住I2C总线，准备发送或接收数据 
}	  

void IIC_Stop(u8 device)
{
	SDA_OUT(device);//sda线输出
	IIC_SCL(device,0);
	IIC_SDA(device,0);//停止:当SCL为高时，数据从低到高变化
 	I2C_Delay_1us(14);
	IIC_SCL(device,1);
	I2C_Delay_1us(14);	 
	IIC_SDA(device,1);//发送I2C总线结束信号
							   	
}
//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
u8 IIC_Wait_Ack(u8 device)
{
	u8 ucErrTime=0;
	IIC_SCL(device,0);
	IIC_SDA(device,1);
	SDA_IN(device);      //SDA设置为输入  
	I2C_Delay_1us(14);	   
	IIC_SCL(device,1);
	I2C_Delay_1us(14);	
	if(device)
	{
		while(Read_IO_State(GPIOB,GPIO_Pin_11))//等到SDA变低
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
		while(Read_IO_State(GPIOB,GPIO_Pin_9))//等到SDA变低
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
	IIC_SCL(device,0);//时钟输出0
	I2C_Delay_1us(10); 
	return 0;  
} 
//产生ACK应答
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
//产生非ACK应答		    
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
//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答			  
void IIC_Send_Byte(u8 device,u8 txd)
{                        
  u8 t;   
	SDA_OUT(device); 	    
  IIC_SCL(device,0);//拉低时钟开始数据传输
  for(t=0;t<8;t++)
  {              
		IIC_SCL(device,0);
		if((txd&0x80)>>7)
			IIC_SDA(device,1);
		else
			IIC_SDA(device,0);
		txd<<=1; 	  
		I2C_Delay_1us(15);   //延时
		IIC_SCL(device,1);
		I2C_Delay_1us(15); 	
  }
		IIC_SCL(device,0);	 
} 	    
//读1个字节，ack=1时，发送ACK，ack=0，发送nACK   
u8 IIC_Read_Byte(u8 device,unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN(device);//SDA设置为输入
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
  if (!ack)  IIC_NAck(device);//发送nACK
  else       IIC_Ack(device); //发送ACK   
  return receive;
}




































