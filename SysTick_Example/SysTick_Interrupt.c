
#include "SysTick_Interrupt.h"

void SysTick_Interrupt_Init(void)
{	
	// Set the SysTick timer reload value for 1 millisecond intervals
	// Each clock cycle is (1 / 4 MHz) = 0.25 us
	SysTick->LOAD = (4000 - 1);
	
	// Clear the VAL register by writing any value to it
	SysTick->VAL = 0;
	
	// Set the Peripheral Internal Oscillator (PIOSC) as the clock source
	// by clearing Bit 2 (CLK_SRC) in the CTRL register
	SysTick->CTRL &= ~(0x04);
	
	// Enable the interrupt by setting Bit 1 (INTEN) in the CTRL register
	SysTick->CTRL |= 0x02;
	
	// Enable the SysTick timer by setting Bit 0 (ENABLE) in the CTRL register
	SysTick->CTRL |= 0x01;
}
