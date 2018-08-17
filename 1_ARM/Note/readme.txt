1、编译器设置：STM32F10X_HD, USE_STDPERIPH_DRIVER
2、misc.C：配置中断优先级，系统滴答计数器时钟配置
3、stm32f10x.h：定义中断向量表；定义外设的结构体数据类型；给常用的数据类型重新定义
4、startup_stm32f10x_hd.s：定义中断函数名称
5、AFIO时钟在使用外部中断和重映射功能时需要开启
6、#ifndef __EXIT_H_	#define _EXIT_H_	#include "stm32f10x.h"	#endif
 


配置TIMx_CCER寄存器中的CCxP和CCxNP位，可以为每一个输出独立地选择极性(主输出OCx或互补输出OCxN)。



//	在功能处直接调用该函数
//	LED_1_PIN_SET(0);		  //LD1工作
//	LED_2_PIN_SET(1);		  //LD2工作
//	LED_3_PIN_SET(1);		  //LD3工作
//	LED_4_PIN_SET(0);		  //LD1故障
//	LED_5_PIN_SET(0);		  //LD2故障
//	LED_6_PIN_SET(0);		  //LD3故障

AD 200HZ采样率 KP=29，KI=1.3，KD=197