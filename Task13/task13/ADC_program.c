/*
 * ADC_program.c
 *
 *  Author: FaRaH
 */ 


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"

static u8 ADC_u8State= IDLE ;   // flag for the ADC Busy State



void ADC_voidInit(void)
{
	//voltage reference
	#if ADC_VREF == AREF
	CLR_BIT(ADMUX , ADMUX_REFS0) ;
	CLR_BIT(ADMUX , ADMUX_REFS1) ;

	#elif ADC_VREF == AVCC
	SET_BIT(ADMUX , ADMUX_REFS0) ;
	CLR_BIT(ADMUX , ADMUX_REFS1) ;

	#elif ADC_VREF == INTERNAL_2_56
	SET_BIT(ADMUX , ADMUX_REFS0) ;
	SET_BIT(ADMUX , ADMUX_REFS1) ;

	#else
	#error "Wrong ADC_VREF config"

	#endif


	// Adjust Result
	#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
	CLR_BIT(ADMUX , ADMUX_ADLAR) ;

	#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
	SET_BIT(ADMUX , ADMUX_ADLAR) ;

	#else
	#error "Wrong ADC_ADJUSTMENT config"
	
	#endif

	// Prescaler Value
	ADSAR &= ADC_PRE_MASK ;
	ADSAR |= ADC_PRESCALLER ;

	
	// Enable ADC Peripheral
	#if ADC_STATUS == ADC_DISABLE
	CLR_BIT(ADSAR , ADSAR_ADEN) ;
	#elif ADC_STATUS == ADC_ENABLE
	SET_BIT(ADSAR , ADSAR_ADEN) ;
	#else
	#error "Wrong ADC_STATUS config"
	#endif

	// Enable ADC Interrupt
	#if INT_STATUS == INT_DISABLE
	CLR_BIT(ADSAR , ADSAR_ADIE) ;
	#elif INT_STATUS == INT_ENABLE
	SET_BIT(ADSAR , ADSAR_ADIE) ;
	#else
	#error "Wrong INT_STATUS config"
	#endif

}


void ADC_voidEnable (void)
{
	SET_BIT(ADSAR , ADSAR_ADEN) ;
}



void ADC_voidDisable (void)
{
	CLR_BIT(ADSAR , ADSAR_ADEN) ;
}



void ADC_voidInterruptEnable (void)
{
	SET_BIT(ADSAR , ADSAR_ADIE) ;
}



void ADC_voidInterruptDisable (void)
{
	CLR_BIT(ADSAR , ADSAR_ADIE) ;
}



u8 ADC_u8SetPrescaler (u8 Copy_u8Prescaler)
{
	u8 Local_u8ErrorState = OK ;

	if (Copy_u8Prescaler < 8)
	{
		// Set Prescaler Value
		ADSAR &= ADC_PRE_MASK ;
		ADSAR |= Copy_u8Prescaler ;
	}

	return Local_u8ErrorState ;
}


u8 ADC_u8GetResultSync (u8 Copy_u8Channel , u16 * Copy_pu16Result)
{
	u8 Local_u8ErrorState = OK ;
	u32 Local_u32TimeoutCounter = 0 ;
	if (Copy_pu16Result != NULL)
	{
		if (ADC_u8State == IDLE)
		{
			
			ADC_u8State = BUSY ;

			
			ADMUX &= ADC_CH_MASK ;
			ADMUX |= Copy_u8Channel ;

			
			SET_BIT(ADSAR , ADSAR_ADSC) ;

			
			while (((GET_BIT(ADSAR , ADSAR_ADIF)) == 0) && (Local_u32TimeoutCounter < ADC_TIMEOUT))
			{
				Local_u32TimeoutCounter++ ;
			}
			if (Local_u32TimeoutCounter == ADC_TIMEOUT)
			{
				Local_u8ErrorState = TIMEOUT_STATE ;
			}
			else
			{
				
				SET_BIT(ADSAR , ADSAR_ADIF) ;

				
				#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
				*Copy_pu16Result = (ADCL|(ADCH << 8))  ;

				#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
				*Copy_pu16Result = ADCH ;
				#else
				#error "Wrong ADC_ADJUSTMENT config"

				#endif
			}

			
			ADC_u8State = IDLE ;
		}
		else
		{
			Local_u8ErrorState = BUSY_STATE ;
		}


	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}
	return Local_u8ErrorState ;
}