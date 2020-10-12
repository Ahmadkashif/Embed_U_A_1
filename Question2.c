#include <stdint.h>
#include <stdio.h>
#include "tm4c123gh6pm.h"

#define LED (*((volatile uint32_t *)0x400253FC))

void delay(void)
{
    //CLEAR ENABLE
	NVIC_ST_CTRL_R &= ~(0x01); 
    //SPECIFY RELOAD VALUE
	NVIC_ST_RELOAD_R = 4000000; // set ending point
    //CLEAR
	NVIC_ST_CTRL_R = 0x05; // enable counter and start counting
	while((NVIC_ST_CTRL_R & 0x10000) == 0x00) {};
	NVIC_ST_CTRL_R = 0; //stop timer	
}

// void port_F(void)
// {
// 	SYSCTL_RCGCGPIO_R |= 0x00000020; // activate clock for Port F
//   while((SYSCTL_PRGPIO_R&0x00000020) == 0){};// ready?
//   GPIO_PORTF_LOCK_R = 0x4C4F434B; // unlock GPIO Port F
//   GPIO_PORTF_CR_R = 0x02; // allow changes to PF1
//   GPIO_PORTF_DIR_R = 0x02; // PF1 out
//   GPIO_PORTF_PUR_R = 0x10; // enable pull-up on PF4
//   GPIO_PORTF_DEN_R = 0x02; // enable digital I/O on PF1
// }


// int main()
// {
// 	port_F();
	
// 	while(1)
// 	{
// 		LED = 0x02; // set Port F1
// 		delay();
// 		LED = 0x00; // reset Port F1
// 	}
// }