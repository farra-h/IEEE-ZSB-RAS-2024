/*
 * Code.c
 *
 * Author : FaRaH
 */ 

#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "CLCD_interface.h"
#include <util/delay.h>



int main(void) {
	
	LCD_init();
	LCD_clearScreen();
	
	uint8 counter=0;
	while(counter <= 3)
	{
		LCD_clearScreen();
		LCD_intgerToString(counter++);
		_delay_ms(500);
	}
	
	LCD_moveCursor(0, 0);
	LCD_displayString("It's the last");
	LCD_moveCursor(1, 0);
	LCD_displayString("Task *_*");
	_delay_ms(2000);
	
	LCD_clearScreen();
	LCD_displayString("Finallyyy >_<");
	_delay_ms(2000);
	LCD_clearScreen();
	_delay_ms(1000);
	LCD_sendCommand(LCD_CURSOR_OFF);
	return 0;
}

