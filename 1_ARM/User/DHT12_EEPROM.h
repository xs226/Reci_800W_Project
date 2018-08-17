#ifndef _DHT12_H_
#define _DHT12_H_
#include "stm32f10x.h"
#include "stdio.h"

extern u8 EEPROM_Tab_WR[10];
extern u8 EEPROM_Tab_RD[256];
extern u16 Ambient_Tem,Ambient_Humi;//定义温湿度变量 ，此变量为全局变量
u8 IIC_Read_Byte(u8 device,unsigned char ack);
void  IIC_Send_Byte(u8 device,u8 txd);
void IIC_NAck(u8 device);
u8 IIC_Wait_Ack(u8 device);
void IIC_Stop(u8 device);
void IIC_Start(u8 device);
void IIC_SCL(u8 device,u8 a);
void IIC_SDA(u8 device,u8 a);

extern void SHT12_Read(void);//读取数据		 
extern u8 EEPROM_Write(unsigned char  Address,unsigned char  *s,unsigned char  SUM);
extern u8 EEPROM_Read(unsigned char  Address,unsigned char  *s,unsigned char  SUM);
extern void Write_Fault_ToEEPROM();
extern void Read_EEPROM_ToRAM();
extern void I2C_Delay_1us(__IO u16 i);



#endif	//_DHT12_H_
