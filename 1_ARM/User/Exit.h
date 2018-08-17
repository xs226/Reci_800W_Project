#ifndef __EXIT_H_
#define _EXIT_H_
#include "stm32f10x.h"


extern void EXTI_Configuration(void);
extern void EXTI_EN(u8 EXTI_NUM, u8 cmd);

#endif
