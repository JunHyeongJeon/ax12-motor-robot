#include "gpio.h"
#include <avr/io.h>

void GPIO_init(){
	DDRC = (1<<DDC1); // set blue led output mode.
	PORTC = (0<<PC1); // blue led on 
}
