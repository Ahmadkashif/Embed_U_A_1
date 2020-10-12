#include <stdio.h>
#include <stdint.h>
#include "tm4c123gh6pm.h"


void port_A(void)
{
	SYSCTL_RCGCGPIO_R |= 0x01;
	while((SYSCTL_PRGPIO_R & 0x01) == 0){}
	GPIO_PORTA_DEN_R |= 0x0E; //digital yes
	GPIO_PORTA_AMSEL_R = 0x0E; // analog no
	GPIO_PORTA_AFSEL_R = 0x00; 
	GPIO_PORTA_PCTL_R = 0x00000000;
	GPIO_PORTA_DIR_R |= 0x0E; //00001110
	GPIO_PORTA_CR_R = 0x0E;
}


int main ()
{
	uint8_t x = 0x02;
	x = x<<1;
	port_A();
	GPIO_PORTA_DATA_R |= x;
}
