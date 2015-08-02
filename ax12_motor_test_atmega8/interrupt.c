#include "interrupt.h"
#include "usart.h"

SIGNAL(SIG_UART_RECV){// usart receive interrupt

	PORTC = ~PORTC; // if usart data receive led is blink
	char buffer = UDR;
	if (buffer ==  'w'){
		SYSTEM_Log("front");
	}
	else if(buffer == 's'){
		SYSTEM_Log("back");
	}
	else if(buffer == 'a'){
		SYSTEM_Log("left");
	}
	else if(buffer == 'd'){
		SYSTEM_Log("right");
	}
	
	//SYSTEM_Log("recv");

}
SIGNAL(SIG_UART_TRANS){// usart transmit interrupt


// add code you want..

}
