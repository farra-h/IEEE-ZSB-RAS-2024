/*
 * CFile1.c
 *
 *  Author: FaRaH
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"

DIO_ErrorStatus DIO_enumSetPinDirection    (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Direction )
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		if ( Copy_u8Direction == DIO_PIN_OUTPUT )
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8PORT)
			{
				case DIO_PORTA: SET_BIT(DDRA_Register,Copy_u8PIN); break;
				case DIO_PORTB: SET_BIT(DDRB_Register,Copy_u8PIN); break;
				case DIO_PORTC: SET_BIT(DDRC_Register,Copy_u8PIN); break;
				case DIO_PORTD: SET_BIT(DDRD_Register,Copy_u8PIN); break;
			}
		}

		else if ( Copy_u8Direction == DIO_PIN_INPUT )
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8PORT)
			{
				case DIO_PORTA: CLR_BIT(DDRA_Register,Copy_u8PIN); break;
				case DIO_PORTB: CLR_BIT(DDRB_Register,Copy_u8PIN); break;
				case DIO_PORTC: CLR_BIT(DDRC_Register,Copy_u8PIN); break;
				case DIO_PORTD: CLR_BIT(DDRD_Register,Copy_u8PIN); break;
			}
		}

		else
		{
			LOC_enumState = DIO_NOK ;
		}
	}

	else
	{
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState ;

}

DIO_ErrorStatus DIO_enumSetPinValue      (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Value )
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		if (Copy_u8Value == DIO_PIN_HIGH)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8PORT)
			{
				case DIO_PORTA: SET_BIT(PORTA_Register,Copy_u8PIN); break;
				case DIO_PORTB: SET_BIT(PORTB_Register,Copy_u8PIN); break;
				case DIO_PORTC: SET_BIT(PORTC_Register,Copy_u8PIN); break;
				case DIO_PORTD: SET_BIT(PORTD_Register,Copy_u8PIN); break;
			}

		}

		else if (Copy_u8Value == DIO_PIN_LOW)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8PORT)
			{
				case DIO_PORTA: CLR_BIT(PORTA_Register,Copy_u8PIN); break;
				case DIO_PORTB: CLR_BIT(PORTB_Register,Copy_u8PIN); break;
				case DIO_PORTC: CLR_BIT(PORTC_Register,Copy_u8PIN); break;
				case DIO_PORTD: CLR_BIT(PORTD_Register,Copy_u8PIN); break;
			}
		}

		else
		{
			LOC_enumState = DIO_NOK ;
		}
	}

	else
	{
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState ;

}

DIO_ErrorStatus DIO_enumGetPinValue          (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 * Copy_PtrData   )
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		/* Check on the Required PORT Number */
		switch (Copy_u8PORT)
		{
			case DIO_PORTA: * Copy_PtrData = GET_BIT(PINA_Register,Copy_u8PIN); break;
			case DIO_PORTB: * Copy_PtrData = GET_BIT(PINB_Register,Copy_u8PIN); break;
			case DIO_PORTC: * Copy_PtrData = GET_BIT(PINC_Register,Copy_u8PIN); break;
			case DIO_PORTD: * Copy_PtrData = GET_BIT(PIND_Register,Copy_u8PIN); break;
		}
	}

	else
	{
		/* in case of error in the Pin ID or PORT ID */
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState;
}

DIO_ErrorStatus DIO_enumTogglePinValue  ( u8 Copy_u8PORT, u8 Copy_u8PIN )
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if (Copy_u8PIN <= DIO_PIN7)
	{
		switch (Copy_u8PORT)
		{
			case DIO_PORTA : TOG_BIT(PORTA_Register,Copy_u8PIN);
			break ;
			case DIO_PORTB : TOG_BIT(PORTB_Register,Copy_u8PIN);
			break ;
			case DIO_PORTC : TOG_BIT(PORTC_Register,Copy_u8PIN);
			break ;
			case DIO_PORTD : TOG_BIT(PORTD_Register,Copy_u8PIN);
			break ;
		}

	}
	else
	{
		/* in case of error in the Pin ID or PORT ID */
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState;
}