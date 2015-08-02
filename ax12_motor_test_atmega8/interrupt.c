#include "interrupt.h"
#include "usart.h"
#include "ax-12.h"

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
	else if(buffer == 'z'){
		int i;
		for (i =0; i < 200; i ++){
			MOTOR_Move(i, 500, 500 );
		}
	}
	else if(buffer == 'x'){
		int i;
		for (i =0; i < 200; i ++){
			MOTOR_Move(i, 300, 500 );
		}
	}


}
SIGNAL(SIG_UART_TRANS){// usart transmit interrupt


// add code you want..

}
