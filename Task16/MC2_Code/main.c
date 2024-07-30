/*
 * MC2_Code.c
 *
 * Author : FaRaH
 */ 

#include <avr/io.h>
#include <string.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "LED_interface.h"
#include "USART_interface.h"

#define BUFFER_SIZE 10

void executeCommand(const char *command);

LED_Type led0 = {LED_PORTA, LED_PIN0, ACTIVE_HIGH};
LED_Type led1 = {LED_PORTA, LED_PIN1, ACTIVE_HIGH};
LED_Type led2 = {LED_PORTA, LED_PIN2, ACTIVE_HIGH};


int main(void)
{
	LED_voidInit(led0);
	LED_voidInit(led1);
	LED_voidInit(led2);
		
	USART_voidInit();
	
	char buffer[BUFFER_SIZE];
	u8 index=0;
    u8 receivedData;
	
    while (1) 
    {
		if (USART_u8RecevieData(&receivedData) == OK)
		{
			if (receivedData == '\r')
			{
				buffer[index] = '\0';
				executeCommand(buffer);
				index = 0;
			}
			else
			{
				buffer[index++] = receivedData;
				if (index >= BUFFER_SIZE)
				{
					index = 0;
				}
			}
		}
    }
}

void executeCommand(const char *command)
{
	if (strcmp(command, "allon") == 0) 
	{
		LED_voidOn(led0);
		LED_voidOn(led1);
		LED_voidOn(led2);		} 
	else if (strcmp(command, "alloff") == 0) 
		{
		LED_voidOff(led0);
		LED_voidOff(led1);
		LED_voidOff(led2);		} 
	else if (strcmp(command, "oneon") == 0) 
	{
		LED_voidOn(led0);		
	} 
	else if (strcmp(command, "oneoff") == 0) 
	{
		LED_voidOff(led0);
	} 
	else if (strcmp(command, "twoon") == 0) 
	{
		LED_voidOn(led1);
	} 
	else if (strcmp(command, "twooff") == 0) 
	{
		LED_voidOff(led1);
	} 
	else if (strcmp(command, "threeon") == 0) 
	{
		LED_voidOn(led2);
	}
		else if (strcmp(command, "threeoff") == 0) 
	{
		LED_voidOff(led2);
	}	
}