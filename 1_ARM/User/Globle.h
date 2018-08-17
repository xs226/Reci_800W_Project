#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include <stdio.h>
#include "FSMC_FPGA.h"
#include "LD_Drive.h"
#include "USART.h"
#include "adc.h"
#include "Timer.h"
#include "Exit.h"
#include "math.h"
#include "Flash.h"
#include "DHT12_EEPROM.h"
#include "ds1302.h"
#include "modbus.h"

extern u16 LDtemperature;
extern const u16 NTCTAB[];
extern u16 AC_Power;
extern u16 RedLaser_PWM_Value;
extern u8 Run_Mode;//0:工作模式，1：运行模式
extern u8 PWM_Mode;//2:AD模式，3：RS232模式

extern void PORT_Init(void);
extern void Delay_1ms(__IO u16 i);
extern void Delay_1us(__IO u16 i);

extern uint8_t Read_IO_State(GPIO_TypeDef* GPIOx,u16 GPIO_Pin_x);
extern void Globle_Init(void);
extern void NVIC_Configuration(void);
void Tem_AC220_Check();
extern u16 LinearInsert(u16 tempresult,const u16 *TABLE);
extern void Lookup_TAB(u16 resultADC, const u16 *TABLE,u16 *aptr);
extern void exch(u16 *b1,u16 *b2);
extern void Key_Scan();
extern void WMT_Set(u8 cmd);

extern u16 Reg_Value;
#define RedLaser_PIN_SET(a)	if (a)  GPIO_SetBits(GPIOA,GPIO_Pin_7);  else GPIO_ResetBits(GPIOA,GPIO_Pin_7)
#define Fault_LED_SET(a)	if (a)  GPIO_SetBits(GPIOD,GPIO_Pin_6);  else GPIO_ResetBits(GPIOD,GPIO_Pin_6)
#define Work_LED_SET(a)		if (a)  GPIO_SetBits(GPIOD,GPIO_Pin_2);  else GPIO_ResetBits(GPIOD,GPIO_Pin_2)
#define Mode_LED_SET(a)		if (a)  GPIO_SetBits(GPIOD,GPIO_Pin_3);  else GPIO_ResetBits(GPIOD,GPIO_Pin_3)
#define FPGA_RST_SET(a)		if (a)  GPIO_SetBits(GPIOC,GPIO_Pin_9);	 else GPIO_ResetBits(GPIOC,GPIO_Pin_9)
#define Panel_LED1_SET(a)		if (a)  GPIO_SetBits(GPIOB,GPIO_Pin_7);  else GPIO_ResetBits(GPIOB,GPIO_Pin_7)
#define Panel_LED2_SET(a)		if (a)  GPIO_SetBits(GPIOE,GPIO_Pin_0);  else GPIO_ResetBits(GPIOE,GPIO_Pin_0)

#define Delay_ms(x) Delay_us(100*x)	 //单位ms
#define Q_Data 64

#endif /* __SYSTICK_H */
