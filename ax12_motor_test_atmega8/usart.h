#ifndef USART_H_
#define USART_H_

#include <avr/io.h>
#include <stdio.h>

void USART_Transmit(volatile unsigned char data_);
char USART_Receive(void);
void USART_Init(double BPS);
int USART_Print(char * pFormat, ...);
void SYSTEM_Log(char * pFormat, ...);

#endif /* USART_H_ */


