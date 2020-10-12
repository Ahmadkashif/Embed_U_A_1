#include <stdint.h>
#include <stdio.h>
#include "tm4c123gh6pm.h"

#define RED_LED (*((volatile uint32_t *) 0x400253FC ))

void quarterSecDelay(void)
{
    //CLEAR ENABLE
	NVIC_ST_CTRL_R &= ~(0x01); 
    //SPECIFY RELOAD VALUE
	NVIC_ST_RELOAD_R = 4000000; 
    //CLEAR
	NVIC_ST_CTRL_R = 0x05; 

	while((NVIC_ST_CTRL_R & 0x10000) == 0x00) {};
    //STOP TIMER
	NVIC_ST_CTRL_R = 0; 
}

void initPortF1(void)
{
    //SET CLOCK FOR PORT F
	SYSCTL_RCGCGPIO_R |= 0x00000020; // activate clock for Port F
    //STABLIZATION
  while((SYSCTL_PRGPIO_R&0x00000020) == 0){};
  //ENABLE GPIO PORT F
  GPIO_PORTF_LOCK_R = 0x4C4F434B;
  //ALLOW CHANGES
  GPIO_PORTF_CR_R = 0x02;
  //DIRECTION OF PINS
  GPIO_PORTF_DIR_R = 0x02;
  //
  GPIO_PORTF_PUR_R = 0x10; 
  //DIGITAL ENABLE
  GPIO_PORTF_DEN_R = 0x02; 
}


int main()
{
	initPortF();
	while(1)
	{
		RED_LED = 0x02; 
		quarterSecDelay();
		RED_LED = 0x00;
	}
}