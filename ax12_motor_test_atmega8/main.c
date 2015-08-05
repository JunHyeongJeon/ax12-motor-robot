#include <avr/io.h>
#include "usart.h"
#include "ax-12.h"
#include <util/delay.h>
#include "test.h"

void setup()
{
	
	GPIO_init();
	USART_Init(115200);
	
	SYSTEM_Log("START");
}

void loop()
{
//	MOTOR_Move_With_RxTx_Control(1, 300, 200 );
//	_delay_ms(16000); // 1s, this is complier error.
//	MOTOR_Move_With_RxTx_Control(1, 500, 200 );
//	_delay_ms(16000);
}



int main(){

	setup();

	while(1){
		loop();
	}

	return 0;

}
