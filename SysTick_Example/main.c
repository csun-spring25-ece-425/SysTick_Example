/*
 * @file main.c
 *
 * @brief Main source code for the SysTick_Example program.
 *
 * @author Aaron Nanas
 */

#include "TM4C123GH6PM.h"
#include "GPIO.h"
#include "SysTick_Interrupt.h"

static uint32_t ms_elapsed = 0;

void SysTick_Handler(void)
{
	ms_elapsed = ms_elapsed + 1;
	if (ms_elapsed == 1000)
	{
		ms_elapsed = 0;
		GPIOF->DATA = GPIOF->DATA ^ 0x08;
	}
}

int main(void)
{
	// Initialize the RGB LED (Port F)
	RGB_LED_Init();
	
	// Initialize the SysTick timer used to provide blocking delay functions
	SysTick_Interrupt_Init();

	while(1)
	{

	}
}
