#include "usart.h"

void USART_Transmit(volatile unsigned char data_)
{
	while((UCSRA&0x20)==0); 
	UDR = (data_); 
}

int USART_Print(char * pFormat, ...)
{
    int nRst;
    char aBuff[128] = {0, }, * p;
    va_list ap;
    va_start(ap, pFormat);
    nRst = vsprintf(aBuff, pFormat, ap);
    va_end(ap);
    for(p = aBuff; *p != '\0'; p++)
    USART_Transmit(*p);
    return nRst;
}


char USART_Receive(void)

{
	while(!(UCSRA&0x80));
	return UDR;
}

void USART_Init(double BPS)
{

    UCSRA = 0x00;
    UCSRB = 0xd8;
	if( BPS == 9600){
	    
		UCSRC=0x86;
		UBRRL=103;
	}
	else if( BPS == 57600){
		UCSRC=0x86;
//		UBRRH = 0;
		UBRRL=3;
	}
	else{
		UCSRC = 0x06;
		UBRRH = 0;
	    UBRRL = 8;
	}

	SREG |= 0x80;

}
void SYSTEM_Log(char * pFormat, ...){
	USART_Print(pFormat);
	USART_Print("\r\n");

}

