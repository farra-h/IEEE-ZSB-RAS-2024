/*
 * code.c
 * Author : FaRaH
 */ 

#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "LED_interface.h"
#include "GIE_interface.h"
#include "TIMER_interface.h"

LED_Type A0 = {LED_PORTA, LED_PIN0, ACTIVE_HIGH};
LED_Type A1 = {LED_PORTA, LED_PIN1, ACTIVE_HIGH};

u8 Copy_u8PL = 192;
u8 Copy_u8CM = 125;

volatile u32 counter1 = 0;
volatile u32 counter2 = 0;

void LED_A0(){  /*TIMER_NORMAL_MODE*/
	counter1++;
	
	if (counter1 == 1000)
	{
		TIMER0_voidSetPreload(Copy_u8PL);
		LED_voidToggle(A0);
		counter1 = 0;
	}
}

void LED_A1(){  /*TIMER_CTC_MODE*/
	counter2++;
	
	if (counter2 == 2000)
	{
		TIMER2_voidSetCTC(Copy_u8CM);
		LED_voidToggle(A1);
		counter2 = 0;
	}
}

int main(void)
{
	LED_voidInit(A0);
	LED_voidInit(A1);
	TIMER0_voidInit();
	TIMER2_voidInit();
	
	TIMER_u8SetCallBack(LED_A0, TIMER0_OVF_VECTOR_ID);
	TIMER_u8SetCallBack(LED_A1, TIMER2_CTC_VECTOR_ID);
	GIE_VoidEnable();
    
    while (1) 
    {
    }
}

