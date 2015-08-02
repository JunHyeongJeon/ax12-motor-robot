#include <avr/io.h>
#include "usart.h"
#include <util/delay.h>


void setup()
{
	GPIO_init();
	USART_Init();
}
void loop()
{
	//	_delay_ms(16000); // 1s, this is complier error.
}



int main(){

	setup();

	while(1){
		loop();
	}

	return 0;

}
