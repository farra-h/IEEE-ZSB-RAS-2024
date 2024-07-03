/*
 * GccApplication1.c
 * Author : FaRaH
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "LED_interface.h"
#include "SW_interface.h"

#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
	LED_Type A0 = {LED_PORTA, LED_PIN0, ACTIVE_HIGH};
	LED_Type A1 = {LED_PORTA, LED_PIN1, ACTIVE_HIGH};
	LED_Type A2 = {LED_PORTA, LED_PIN2, ACTIVE_HIGH};
	LED_Type A3 = {LED_PORTA, LED_PIN3, ACTIVE_HIGH};
	LED_Type A4 = {LED_PORTA, LED_PIN4, ACTIVE_HIGH};
	LED_Type A5 = {LED_PORTA, LED_PIN5, ACTIVE_HIGH};
	LED_Type A6 = {LED_PORTA, LED_PIN6, ACTIVE_HIGH};
	LED_Type A7 = {LED_PORTA, LED_PIN7, ACTIVE_HIGH};
		
	LED_Type B0 = {LED_PORTB, LED_PIN0, ACTIVE_HIGH};
	LED_Type B1 = {LED_PORTB, LED_PIN1, ACTIVE_HIGH};
	LED_Type B2 = {LED_PORTB, LED_PIN2, ACTIVE_HIGH};
	LED_Type B3 = {LED_PORTB, LED_PIN3, ACTIVE_HIGH};
	LED_Type B4 = {LED_PORTB, LED_PIN4, ACTIVE_HIGH};
	LED_Type B5 = {LED_PORTB, LED_PIN5, ACTIVE_HIGH};
	LED_Type B6 = {LED_PORTB, LED_PIN6, ACTIVE_HIGH};
	LED_Type B7 = {LED_PORTB, LED_PIN7, ACTIVE_HIGH};
		
	LED_Type C0 = {LED_PORTC, LED_PIN0, ACTIVE_HIGH};
	LED_Type C1 = {LED_PORTC, LED_PIN1, ACTIVE_HIGH};
	LED_Type C2 = {LED_PORTC, LED_PIN2, ACTIVE_HIGH};
	LED_Type C3 = {LED_PORTC, LED_PIN3, ACTIVE_HIGH};
	LED_Type C4 = {LED_PORTC, LED_PIN4, ACTIVE_HIGH};
	LED_Type C5 = {LED_PORTC, LED_PIN5, ACTIVE_HIGH};
	LED_Type C6 = {LED_PORTC, LED_PIN6, ACTIVE_HIGH};
	LED_Type C7 = {LED_PORTC, LED_PIN7, ACTIVE_HIGH};
		
	SW_Type  D4 = {SW_PORTD, SW_PIN4, SW_Int_PULL_UP};
	SW_Type  D5 = {SW_PORTD, SW_PIN5, SW_Int_PULL_UP};
	SW_Type  D6 = {SW_PORTD, SW_PIN6, SW_Int_PULL_UP};
	SW_Type  D7 = {SW_PORTD, SW_PIN7, SW_Int_PULL_UP};
		
	LED_voidInit(A0);
	LED_voidInit(A1);
	LED_voidInit(A2);
	LED_voidInit(A3);
	LED_voidInit(A4);
	LED_voidInit(A5);
	LED_voidInit(A6);
	LED_voidInit(A7);
	
	LED_voidInit(B0);
	LED_voidInit(B1);
	LED_voidInit(B2);
	LED_voidInit(B3);
	LED_voidInit(B4);
	LED_voidInit(B5);
	LED_voidInit(B6);
	LED_voidInit(B7);
	
	LED_voidInit(C0);
	LED_voidInit(C1);
	LED_voidInit(C2);
	LED_voidInit(C3);
	LED_voidInit(C4);
	LED_voidInit(C5);
	LED_voidInit(C6);
	LED_voidInit(C7);
	
	SW_voidInit(D4);
	SW_voidInit(D5);
	SW_voidInit(D6);
	SW_voidInit(D7);
    
    while (1) 
    {
		if(SW_u8GetPressed(D6) == 1){
			LED_voidOn(B0);
			_delay_ms(200);
			LED_voidOn(B1);
			LED_voidOn(A4);
			LED_voidOn(B4);
			_delay_ms(200);
			LED_voidOff(A4);
			LED_voidOff(B4);
			LED_voidOn(B2);
			LED_voidOn(A5);
			LED_voidOn(B5);
			_delay_ms(200);
			LED_voidOff(A5);
			LED_voidOff(B5);
			LED_voidOn(A6);
			LED_voidOn(B6);
			LED_voidOn(B3);
			_delay_ms(200);
			LED_voidOff(A6);
			LED_voidOff(B6);
			LED_voidOff(B0);
			LED_voidOn(A7);
			LED_voidOn(B7);
			LED_voidOn(C6);
			_delay_ms(200);
			LED_voidOff(A7);
			LED_voidOff(B7);
			LED_voidOff(B1);
			LED_voidOn(C5);
			LED_voidOn(C7);
			_delay_ms(200);
			LED_voidOff(C5);
			LED_voidOff(C7);
			LED_voidOff(B2);
			_delay_ms(200);
			LED_voidOff(B3);
			_delay_ms(200);
			LED_voidOff(C6);
		}
		if (SW_u8GetPressed(D5) == 1) {
			LED_voidOn(C6);
			_delay_ms(200);
			LED_voidOn(C5);
			LED_voidOn(C7);
			LED_voidOn(B3);
			_delay_ms(200);
			LED_voidOff(C5);
			LED_voidOff(C7);
			LED_voidOn(A7);
			LED_voidOn(B7);
			LED_voidOn(B2);
			_delay_ms(200);
			LED_voidOff(A7);
			LED_voidOff(B7);
			LED_voidOn(A6);
			LED_voidOn(B6);
			LED_voidOn(B1);
			_delay_ms(200);
			LED_voidOff(A6);
			LED_voidOff(B6);
			LED_voidOff(C6);
			LED_voidOn(A5);
			LED_voidOn(B5);
			LED_voidOn(B0);
			_delay_ms(200);
			LED_voidOff(A5);
			LED_voidOff(B5);
			LED_voidOff(B3);
			LED_voidOn(A4);
			LED_voidOn(B4);
			_delay_ms(200);
			LED_voidOff(A4);
			LED_voidOff(B4);
			LED_voidOff(B2);
			_delay_ms(200);
			LED_voidOff(B1);
			_delay_ms(200);
			LED_voidOff(B0);
		}
	}
}


