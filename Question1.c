#include <stdio.h>
#include <stdint.h>
#include "tm4c123gh6pm.h"

void initPortA()
{
    SYSCTL_RCGCGPIO_R |= 0x01;
    //ENABLE DIGITAL
    GPIO_PORTA_DEN_R |= 0x0E;           
    //DISABLE ANALOG
    GPIO_PORTA_AMSEL_R = 0x0E;
    //DISABLE ALTERNATE FUNCTION          
	GPIO_PORTA_AFSEL_R = 0x00;          
    //ONLY FOR I/O
	GPIO_PORTA_PCTL_R = 0x00000000;    
    //SET DIRECTION OF PINS 
	GPIO_PORTA_DIR_R |= 0x0E;           
    //ALLOW CHANGES
	GPIO_PORTA_CR_R = 0x0E;             
}

