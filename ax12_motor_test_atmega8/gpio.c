#include "gpio.h"
#include <avr/io.h>

void GPIO_init(){
	DDRC = (1<<DDC1); // set blue led output mode.
	PORTC = (0<<PC1); // blue led on 
	DDRD = (1<<DDD2) | (1<<DDD3) | (1<<DDD4);
	PORTD = (1<<PD2) | (1<<PD3) | (1<<PD4);
}
