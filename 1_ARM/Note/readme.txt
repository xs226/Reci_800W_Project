1�����������ã�STM32F10X_HD, USE_STDPERIPH_DRIVER
2��misc.C�������ж����ȼ���ϵͳ�δ������ʱ������
3��stm32f10x.h�������ж���������������Ľṹ���������ͣ������õ������������¶���
4��startup_stm32f10x_hd.s�������жϺ�������
5��AFIOʱ����ʹ���ⲿ�жϺ���ӳ�书��ʱ��Ҫ����
6��#ifndef __EXIT_H_	#define _EXIT_H_	#include "stm32f10x.h"	#endif
 


����TIMx_CCER�Ĵ����е�CCxP��CCxNPλ������Ϊÿһ�����������ѡ����(�����OCx�򻥲����OCxN)��



//	�ڹ��ܴ�ֱ�ӵ��øú���
//	LED_1_PIN_SET(0);		  //LD1����
//	LED_2_PIN_SET(1);		  //LD2����
//	LED_3_PIN_SET(1);		  //LD3����
//	LED_4_PIN_SET(0);		  //LD1����
//	LED_5_PIN_SET(0);		  //LD2����
//	LED_6_PIN_SET(0);		  //LD3����

AD 200HZ������ KP=29��KI=1.3��KD=197