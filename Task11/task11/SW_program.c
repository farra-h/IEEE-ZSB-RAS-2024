﻿/*
 * SW_program.c
 *
 *  Author: FaRaH
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>

#include "DIO_interface.h"


#include "SW_interface.h"


void SW_voidInit      ( SW_Type SW_Config ){
	
	DIO_enumSetPinDirection( SW_Config.Port , SW_Config.Pin , DIO_PIN_INPUT );
	

	if( SW_Config.Pull_State == SW_Int_PULL_UP ){
		
		DIO_enumSetPinValue    ( SW_Config.Port , SW_Config.Pin , DIO_PIN_HIGH  );
		
	}
	
}

u8   SW_u8GetPressed ( SW_Type SW_Config ){
	
	u8 LOC_u8Result = SW_NOT_PRESSED ;
	u8 LOC_u8PinVal = SW_NOT_PRESSED ;
	
	if ( (SW_Config.Pull_State == SW_Int_PULL_UP) || (SW_Config.Pull_State == SW_Ext_PULL_UP) )
	{
		DIO_enumGetPinValue( SW_Config.Port , SW_Config.Pin , &LOC_u8PinVal );
		
		if (LOC_u8PinVal==0)
		{
			LOC_u8Result = SW_PRESSED ;
		}
		else if (LOC_u8PinVal==1)
		{
			LOC_u8Result = SW_NOT_PRESSED ;
		}

	}
	else if (SW_Config.Pull_State == SW_Ext_PULL_DOWN)
	{
		DIO_enumGetPinValue( SW_Config.Port , SW_Config.Pin , &LOC_u8PinVal );
		
		if (LOC_u8PinVal==0)
		{
			LOC_u8Result = SW_NOT_PRESSED ;
		}
		else if (LOC_u8PinVal==1)
		{
			LOC_u8Result = SW_PRESSED ;
		}
	}
	
	return LOC_u8Result ;
	
}