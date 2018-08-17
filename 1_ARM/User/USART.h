#ifndef __USART_H
#define	__USART_H

#include "stm32f10x.h"
#include <stdio.h>

extern u8 RECEIVE_buffer2,RECEIVE_buffer4;
extern u8 point2,point4,receivedone2,receivedone4;
extern u8 USART_Buffer2[50],USART_Buffer4[50];
extern u8 Upload_Tab2[30],Upload_Tab4[12];
extern u8 USART4_Data_Length;

extern void USART_Config(void);
extern void USART2_Commdeal(void);
extern void USART4_Commdeal(void);
extern void USART_Send_String(USART_TypeDef* USARTx,u8 *str,u8 sum);
extern void Upload_to_pc(u8 cmd);
extern void TFT_Send_String(u8 *str);

#endif /* __USART1_H */
