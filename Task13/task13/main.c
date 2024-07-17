/*
 * task13.c
 *
 * Author : FaRaH
 */ 

#include <avr/io.h>
#include <avr/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "LED_interface.h"
#include "ADC_interface.h"

int main(void)
{
    
	LED_Type B0 = {LED_PORTB, LED_PIN0, ACTIVE_HIGH};
	LED_Type B1 = {LED_PORTB, LED_PIN1, ACTIVE_HIGH};
	LED_Type B2 = {LED_PORTB, LED_PIN2, ACTIVE_HIGH};
	LED_Type B3 = {LED_PORTB, LED_PIN3, ACTIVE_HIGH};
	LED_Type B4 = {LED_PORTB, LED_PIN4, ACTIVE_HIGH};
		
	LED_voidInit(B0);
	LED_voidInit(B1);
	LED_voidInit(B2);
	LED_voidInit(B3);
	LED_voidInit(B4);
	
	ADC_voidInit();
	
	u16 ADCValue = 0;
	
    while (1) 
    {
		u8 result = ADC_u8GetResultSync(ADC_CHANNEL0, &ADCValue);
		
		if (result == OK)
		{
			
			if (ADCValue > 800)
			{
				LED_voidOn(B0);
				LED_voidOn(B1);
				LED_voidOn(B2);
				LED_voidOn(B3);
				//_delay_ms(1000);
				LED_voidOff(B0);
				LED_voidOff(B1);
				LED_voidOff(B2);
				LED_voidOff(B3);
			}
			else if (ADCValue < 800 && ADCValue > 500)
			{
				LED_voidOff(B0);
				LED_voidOff(B1);
				LED_voidOff(B2);
				LED_voidOff(B3);
				LED_voidOn(B0);
				LED_voidOn(B1);
				_delay_ms(1000);
				LED_voidOff(B0);
				LED_voidOff(B1);
				LED_voidOn(B2);
				LED_voidOn(B3);
				_delay_ms(1000);
				LED_voidOff(B2);
				LED_voidOff(B3);
			}
			else if (ADCValue < 500 && ADCValue > 300)
			{
				LED_voidOff(B0);
				LED_voidOff(B1);
				LED_voidOff(B2);
				LED_voidOff(B3);
				LED_voidOn(B2);
				LED_voidOn(B3);
				_delay_ms(1000);
				LED_voidOff(B2);
				LED_voidOff(B3);
				LED_voidOn(B0);
				LED_voidOn(B1);
				_delay_ms(1000);
				LED_voidOff(B0);
				LED_voidOff(B1);
			}
			else
			{
				LED_voidOff(B0);
				LED_voidOff(B1);
				LED_voidOff(B2);
				LED_voidOff(B3);
			}
		}
		else
		{
			LED_voidToggle(B4);
		}
    }
}

