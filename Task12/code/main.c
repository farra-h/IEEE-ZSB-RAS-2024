/*
 * code.c
 *
 * Author : FaRaH
 */ 

#include <avr/io.h>
#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "CLCD_interface.h"
#include "KPD_interface.h"





int main(void)
{
    CLCD_voidInit();
	KPD_Init();
	
	u8 choices, choice ;
	
    while (1) 
    {
		CLCD_voidSendString("Welcome!");
		_delay_ms(1000);
		CLCD_voidClearScreen();
 		CLCD_voidSendString("Press any Number");

		choices = KPD_u8GetPressed();
		
		if (choices == '1')
		{
			CLCD_voidClearScreen();
			CLCD_voidSendString("1");
			CLCD_voidClearScreen();
			CLCD_voidSendString("Guess the Number i'm thinking ^_^");
			choice = KPD_u8GetPressed();
			if (choice == '3')
			{
				CLCD_voidSendString("That's Right ^_^");
				_delay_ms(1000);
				CLCD_voidClearScreen();
				CLCD_voidSendString("Good job!!");
				_delay_ms(1000);
				CLCD_voidClearScreen();
			}else{
				CLCD_voidSendString("Not Right :(");
				_delay_ms(1000);
				CLCD_voidClearScreen();
			}
		}
	    else if (choices == '2')
		{
			CLCD_voidClearScreen();
			CLCD_voidSendString("2");
			CLCD_voidClearScreen();
			CLCD_voidSendString("What's my favorite Number ^_^");
			choice = KPD_u8GetPressed();
			if (choice == '9')
			{
				CLCD_voidSendString("That's Right ^_^");
				_delay_ms(1000);
				CLCD_voidClearScreen();
				CLCD_voidSendString("Good job!!");
				_delay_ms(1000);
				CLCD_voidClearScreen();
				}else{
				CLCD_voidSendString("Not Right :(");
				_delay_ms(1000);
				CLCD_voidClearScreen();
			}
		}
		 else if (choices == '3')
		 {
			 CLCD_voidClearScreen();
			 CLCD_voidSendString("3");
			 CLCD_voidClearScreen();
			 CLCD_voidSendString("Nothing for you~");
			 _delay_ms(1000);
			 CLCD_voidClearScreen();

		 }
		  else if (choices == '4')
		  {
			  CLCD_voidClearScreen();
			  CLCD_voidSendString("4");
			  CLCD_voidClearScreen();
			  CLCD_voidSendString("1 + 1 =?");
			  choice = KPD_u8GetPressed();
			  if (choice == '0')
			  {
				  CLCD_voidSendString("That's Right ^_^");
				  _delay_ms(1000);
				  CLCD_voidClearScreen();
				  }else{
				  CLCD_voidSendString("Not Right :(");
				  _delay_ms(1000);
				  CLCD_voidClearScreen();
			  }
		  }
		   else if (choices == '5')
		   {
			   CLCD_voidClearScreen();
			   CLCD_voidSendString("5");
			   CLCD_voidClearScreen();
			   CLCD_voidSendString("Square has ? sides");
			   choice = KPD_u8GetPressed();
			   if (choice == '4')
			   {
				   CLCD_voidSendString("That's Right");
				   _delay_ms(1000);
				   CLCD_voidClearScreen();
				   }else{
				   CLCD_voidSendString("Not Right :(");
				   _delay_ms(1000);
				   CLCD_voidClearScreen();
			   }
		   }
		    else if (choices == '6')
		    {
			    CLCD_voidClearScreen();
			    CLCD_voidSendString("6");
			    CLCD_voidClearScreen();
			    CLCD_voidSendString("? continents on earth");
			    choice = KPD_u8GetPressed();
			    if (choice == '7')
			    {
				    CLCD_voidSendString("That's Right ^_^");
				    _delay_ms(1000);
				    CLCD_voidClearScreen();
				    }else{
				    CLCD_voidSendString("Not Right :(");
				    _delay_ms(1000);
				    CLCD_voidClearScreen();
			    }
		    }
			 else if (choices == '7')
			 {
				 CLCD_voidClearScreen();
				 CLCD_voidSendString("7");
				 CLCD_voidClearScreen();
				 CLCD_voidSendString("Spider has ? legs");
				 choice = KPD_u8GetPressed();
				 if (choice == '8')
				 {
					 CLCD_voidSendString("That's Right ^_^");
					 _delay_ms(1000);
					 CLCD_voidClearScreen();
					 }else{
					 CLCD_voidSendString("Not Right :(");
					 _delay_ms(1000);
					 CLCD_voidClearScreen();
				 }
			 }
			  else if (choices == '8')
			  {
				  CLCD_voidClearScreen();
				  CLCD_voidSendString("8");
				  CLCD_voidClearScreen();
				  CLCD_voidSendString("Nothing ^_^");
				  _delay_ms(1000);
				  CLCD_voidClearScreen();
			  }
			   else if (choices == '9')
			   {
				   CLCD_voidClearScreen();
				   CLCD_voidSendString("9");
				   CLCD_voidClearScreen();
				   CLCD_voidSendString("Rainbow has ? colors");
				   choice = KPD_u8GetPressed();
				   if (choice == '7')
				   {
					   CLCD_voidSendString("That's Right ^_^");
					   _delay_ms(1000);
					   CLCD_voidClearScreen();
					   CLCD_voidSendString("Good job!!");
					   _delay_ms(1000);
					   CLCD_voidClearScreen();
					   }else{
					   CLCD_voidSendString("Not Right :(");
					   _delay_ms(1000);
					   CLCD_voidClearScreen();
				   }
			   }
			    else if (choices == '0')
			    {
				    CLCD_voidClearScreen();
				    CLCD_voidSendString("0");
				    CLCD_voidClearScreen();
				    CLCD_voidSendString("N o t h i n g");
					_delay_ms(1000);
					CLCD_voidClearScreen();
			    }
				 else if (choices == '?')
				 {
					 CLCD_voidClearScreen();
					 
				 }
		
		
    }
}

