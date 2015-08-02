#include <avr/io.h>
#include "usart.h"
#include "ax-12.h"
#include <util/delay.h>
#include "test.h"

void setup()
{
	
	GPIO_init();
	USART_Init();
	
	SYSTEM_Log("START");
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
