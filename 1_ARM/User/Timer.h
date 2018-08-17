#ifndef TIME_TEST_H
#define TIME_TEST_H

#include "stm32f10x.h"

extern u16 TIM4_Count;
extern u16 TIM6_Count;
extern u16 Tem_State_Count;
extern u16 TIM6_Count_LD;

extern void TIM5_Configuration(void);
extern void TIM3_Configuration(void);
extern void TIM6_Configuration(void);
extern void RedLaser_PWM_Set(u16 value);

#endif	/* TIME_TEST_H */
