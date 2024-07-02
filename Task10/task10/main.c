/*
 * task10.c
 *
 * Author : FaRaH
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "LED_interface.h"

#include <util/delay.h>
#include <avr/io.h>


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
	
	LED_Type D0 = {LED_PORTD, LED_PIN0, ACTIVE_HIGH};
	LED_Type D1 = {LED_PORTD, LED_PIN1, ACTIVE_HIGH};
	LED_Type D2 = {LED_PORTD, LED_PIN2, ACTIVE_HIGH};
	LED_Type D3 = {LED_PORTD, LED_PIN3, ACTIVE_HIGH};
	LED_Type D4 = {LED_PORTD, LED_PIN4, ACTIVE_HIGH};
	LED_Type D5 = {LED_PORTD, LED_PIN5, ACTIVE_HIGH};
	LED_Type D6 = {LED_PORTD, LED_PIN6, ACTIVE_HIGH};
	LED_Type D7 = {LED_PORTD, LED_PIN7, ACTIVE_HIGH};
	
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
	
	LED_voidInit(D0);
	LED_voidInit(D1);
	LED_voidInit(D2);
	LED_voidInit(D3);
	LED_voidInit(D4);
	LED_voidInit(D5);
	LED_voidInit(D6);
	LED_voidInit(D7);
	
    while (1) 
    {
		LED_voidOn(A4);
		LED_voidOn(A5);
		LED_voidOn(A6);
		LED_voidOn(A7);
		
		LED_voidToggle(A0);
		LED_voidToggle(A1);
		LED_voidToggle(A2);
		LED_voidToggle(A3);
		_delay_ms(100);
		LED_voidToggle(B0);
		LED_voidToggle(B1);
		LED_voidToggle(B2);
		LED_voidToggle(B3);
		_delay_ms(100);
		LED_voidToggle(B4);
		LED_voidToggle(B5);
		LED_voidToggle(B6);
		LED_voidToggle(B7);
		_delay_ms(100);
		
		LED_voidOn(D3);
		LED_voidOn(D4);
		LED_voidOn(C3);
		LED_voidOn(C4);
		_delay_ms(100);

		LED_voidOn(D1);
		LED_voidOn(D2);
		LED_voidOn(C1);
		LED_voidOn(C2);
		LED_voidOn(D5);
		LED_voidOn(D6);
		LED_voidOn(C5);
		LED_voidOn(C6);
		_delay_ms(100);

		LED_voidOn(D0);
		LED_voidOn(D7);
		LED_voidOn(C0);
		LED_voidOn(C7);

		_delay_ms(500);
		LED_voidOff(D0);
		LED_voidOff(D1);
		LED_voidOff(D2);
		LED_voidOff(D3);
		LED_voidOff(D4);
		LED_voidOff(D5);
		LED_voidOff(D6);
		LED_voidOff(D7);
		LED_voidOff(C0);
		LED_voidOff(C1);
		LED_voidOff(C2);
		LED_voidOff(C3);
		LED_voidOff(C4);
		LED_voidOff(C5);
		LED_voidOff(C6);
		LED_voidOff(C7);
			
    }
}

