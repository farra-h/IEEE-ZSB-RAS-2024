/*
 * code.c
 *
 * Author : FaRaH
 */ 

#include <avr/io.h>
#include "avr/delay.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "LED_interface.h"
#include "TIMER_interface.h"

LED_Type A0 = {LED_PORTA, LED_PIN0, ACTIVE_HIGH};
// LED_Type A1 = {LED_PORTA, LED_PIN1, ACTIVE_HIGH};


int main(void)
{
    LED_voidInit(A0);
//     LED_voidInit(A1);
			
    while (1) 
    {
		TIMER_voidWDTSleep();
		TIMER_voidWDTEnable();
		// In this case the delay time is smaller than WDT_PRESCALER (1 sec), WDT will not reset
		LED_voidToggle(A0);
		_delay_ms(700);
		
// 		TIMER_voidWDTSleep();
// 		TIMER_voidWDTEnable();
// 		// In this case the delay time is bigger than WDT_PRESCALER (1 sec), WDT will reset
// 		LED_voidToggle(A0);
// 		_delay_ms(1050);
    }
}

