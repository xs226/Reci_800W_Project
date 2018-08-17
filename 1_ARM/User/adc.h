#ifndef __ADC_H
#define	__ADC_H


#include "stm32f10x.h"
extern __IO uint16_t ADC_ConvertedValue[5];
extern u8 ADC1_Convert_Done;
extern void ADC1_Configuration(void);
extern void ADelay_1us(__IO u16 i);

extern u16 ADC_Tab[2][10];

#endif /* __ADC_H */

