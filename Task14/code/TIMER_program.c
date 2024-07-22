/*
 * TIMER_program.c
 *  Author: FaRaH
 */ 


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

/*Global Pointer to array of Function to Hold the Call Back Function Address for Timer*/
static void (*TIMERS_pvCallBackFunc[16])(void) = {NULL} ;
	
void TIMER0_voidInit(void)
{
	#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE

		CLR_BIT(TCCR0 , TCCR0_WGM00) ;
		CLR_BIT(TCCR0 , TCCR0_WGM01) ;

		TCNT0 = TIMER0_PRELOAD_VAL ;

		#if TIMER0_OVERFLOW_INTERRUPT == DISABLE
			CLR_BIT(TIMSK , TIMSK_TOIE0) ;
		#elif TIMER0_OVERFLOW_INTERRUPT == ENABLE
			SET_BIT(TIMSK , TIMSK_TOIE0) ;
		#else
			#error "Wrong TIMER0_OVERFLOW_INTERRUPT Config"
		#endif

	#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_PWM_MODE
	
		SET_BIT(TCCR0 , TCCR0_WGM00) ;
		CLR_BIT(TCCR0 , TCCR0_WGM01) ;

	
		#if TIMER0_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
			CLR_BIT(TCCR0 , TCCR0_COM00) ;
			CLR_BIT(TCCR0 , TCCR0_COM01) ;
		#elif TIMER0_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
			CLR_BIT(TCCR0 , TCCR0_COM00) ;
			SET_BIT(TCCR0 , TCCR0_COM01) ;
		#elif TIMER0_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
			SET_BIT(TCCR0 , TCCR0_COM00) ;
			SET_BIT(TCCR0 , TCCR0_COM01) ;
		#else
			#error "Wrong TIMER0_CTC_PWM_MODE Config"
		#endif

		
		OCR0 = TIMER0_CTC_VAL ;

	#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE

		
		CLR_BIT(TCCR0 , TCCR0_WGM00) ;
		SET_BIT(TCCR0 , TCCR0_WGM01) ;

	
		OCR0 = TIMER0_CTC_VAL ;

	
		#if TIMER0_CTC_INTERRUPT == DISABLE
			CLR_BIT(TIMSK , TIMSK_OCIE0) ;
		#elif TIMER0_CTC_INTERRUPT == ENABLE
			SET_BIT(TIMSK , TIMSK_OCIE0) ;
		#else
			#error "Wrong TIMER0_OVERFLOW_INTERRUPT Config"
		#endif

	#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE
		
		SET_BIT(TCCR0 , TCCR0_WGM00) ;
		SET_BIT(TCCR0 , TCCR0_WGM01) ;

		#if TIMER0_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
			CLR_BIT(TCCR0 , TCCR0_COM00) ;
			CLR_BIT(TCCR0 , TCCR0_COM01) ;
		#elif TIMER0_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
			CLR_BIT(TCCR0 , TCCR0_COM00) ;
			SET_BIT(TCCR0 , TCCR0_COM01) ;
		#elif TIMER0_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
			SET_BIT(TCCR0 , TCCR0_COM00) ;
			SET_BIT(TCCR0 , TCCR0_COM01) ;
		#else
			#error "Wrong TIMER0_CTC_PWM_MODE Config"
		#endif

		OCR0 = TIMER0_CTC_VAL ;

	#else
		#error "Wrong TIMER0_WAVEFORM_GENERATION_MODE Config"

	#endif

	TCCR0 &= TIMER_PRESCALER_MASK ;
	TCCR0 |= TIMER0_PRESCALER ;
}

void TIMER2_voidInit(void)
{

	#if TIMER2_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE


		CLR_BIT(TCCR2 , TCCR2_WGM20) ;
		CLR_BIT(TCCR2 , TCCR2_WGM21) ;

		TCNT2 = TIMER2_PRELOAD_VAL ;


		#if TIMER2_OVERFLOW_INTERRUPT == DISABLE
			CLR_BIT(TIMSK , TIMSK_TOIE2) ;
		#elif TIMER2_OVERFLOW_INTERRUPT == ENABLE
			SET_BIT(TIMSK , TIMSK_TOIE2) ;
		#else
			#error "Wrong TIMER2_OVERFLOW_INTERRUPT Config"
		#endif

	#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_PWM_MODE

		SET_BIT(TCCR2 , TCCR2_WGM20) ;
		CLR_BIT(TCCR2 , TCCR2_WGM21) ;


		#if TIMER2_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
			CLR_BIT(TCCR2 , TCCR2_COM20) ;
			CLR_BIT(TCCR2 , TCCR2_COM21) ;
		#elif TIMER2_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
			CLR_BIT(TCCR2 , TCCR2_COM20) ;
			SET_BIT(TCCR2 , TCCR2_COM21) ;
		#elif TIMER2_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
			SET_BIT(TCCR2 , TCCR2_COM20) ;
			SET_BIT(TCCR2 , TCCR2_COM21) ;
		#else
			#error "Wrong TIMER2_CTC_PWM_MODE Config"
		#endif


		OCR2 = TIMER2_CTC_VAL ;

	#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE


		CLR_BIT(TCCR2 , TCCR2_WGM20) ;
		SET_BIT(TCCR2 , TCCR2_WGM21) ;


		OCR2 = TIMER2_CTC_VAL ;


		#if TIMER2_CTC_INTERRUPT == DISABLE
			CLR_BIT(TIMSK , TIMSK_OCIE2) ;
		#elif TIMER2_CTC_INTERRUPT == ENABLE
			SET_BIT(TIMSK , TIMSK_OCIE2) ;
		#else
			#error "Wrong TIMER2_OVERFLOW_INTERRUPT Config"
		#endif

	#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE


		SET_BIT(TCCR2 , TCCR2_WGM20) ;
		SET_BIT(TCCR2 , TCCR2_WGM21) ;


		#if TIMER2_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
			CLR_BIT(TCCR2 , TCCR2_COM20) ;
			CLR_BIT(TCCR2 , TCCR2_COM21) ;
		#elif TIMER2_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
			CLR_BIT(TCCR2 , TCCR2_COM20) ;
			SET_BIT(TCCR2 , TCCR2_COM21) ;
		#elif TIMER2_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
			SET_BIT(TCCR2 , TCCR2_COM20) ;
			SET_BIT(TCCR2 , TCCR2_COM21) ;
		#else
			#error "Wrong TIMER2_CTC_PWM_MODE Config"
		#endif


		OCR2 = TIMER2_CTC_VAL ;

	#else
		#error "Wrong TIMER2_WAVEFORM_GENERATION_MODE Config"

	#endif


	TCCR2 &= TIMER_PRESCALER_MASK ;
	TCCR2 |= TIMER2_PRESCALER ;
}

void TIMER0_voidSetPreload (u8 Copy_u8Preload)
{
	TCNT0 = Copy_u8Preload ;
}

void TIMER1_voidSetPreload (u16 Copy_u16Preload)
{
	TCNT1 = Copy_u16Preload ;
}


void TIMER2_voidSetPreload (u8 Copy_u8Preload)
{
	TCNT2 = Copy_u8Preload ;
}

void TIMER0_voidSetCTC (u8 Copy_u8CTC)
{
	OCR0 = Copy_u8CTC ;
}

void TIMER1_voidSetCTCA (u16 Copy_u16CTCA)
{
	OCR1A = Copy_u16CTCA ;
}

void TIMER1_voidSetCTCB (u16 Copy_u16CTCB)
{
	OCR1B = Copy_u16CTCB ;
}

void TIMER2_voidSetCTC (u8 Copy_u8CTC)
{
	OCR2 = Copy_u8CTC ;
}

void TIMER1_voidSetICR1 (u16 Copy_u16ICR1)
{
	ICR1 = Copy_u16ICR1 ;
}

u8 TIMER0_u8GetTimerCounterValue (void)
{
	return TCNT0 ;
}

u16 TIMER1_u16GetTimerCounterValue (void)
{
	return TCNT1 ;
}

u8 TIMER2_u8GetTimerCounterValue (void)
{
	return TCNT2 ;
}

u8 TIMER_u8SetCallBack(void (*Copy_pvCallBackFunc)(void) , u8 Copy_u8VectorID)
{
	u8 Local_u8ErrorState = OK ;

	if (Copy_pvCallBackFunc != NULL)
	{
		TIMERS_pvCallBackFunc[Copy_u8VectorID] = Copy_pvCallBackFunc ;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}

	return Local_u8ErrorState ;
}

/*TIMER0 Normal Mode ISR*/
void __vector_11 (void)		__attribute__((signal)) ;
void __vector_11 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER0_OVF_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER0_OVF_VECTOR_ID]() ;
	}
}

/*TIMER0 CTC Mode ISR*/
void __vector_10 (void)		__attribute__((signal)) ;
void __vector_10 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER0_CTC_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER0_CTC_VECTOR_ID]() ;
	}
}

/*TIMER1 Normal Mode ISR*/
void __vector_9 (void)		__attribute__((signal)) ;
void __vector_9 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER1_OVF_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER1_OVF_VECTOR_ID]() ;
	}
}

/*TIMER1 CTCB Mode ISR*/
void __vector_8 (void)		__attribute__((signal)) ;
void __vector_8 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER1_CTCB_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER1_CTCB_VECTOR_ID]() ;
	}
}

/*TIMER1 CTCA Mode ISR*/
void __vector_7 (void)		__attribute__((signal)) ;
void __vector_7 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER1_CTCA_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER1_CTCA_VECTOR_ID]() ;
	}
}

/*TIMER1 ICU ISR*/
void __vector_6 (void)		__attribute__((signal)) ;
void __vector_6 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER1_ICU_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER1_ICU_VECTOR_ID]() ;
	}
}

/*TIMER2 Normal Mode ISR*/
void __vector_5 (void)		__attribute__((signal)) ;
void __vector_5 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER2_OVF_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER2_OVF_VECTOR_ID]() ;
	}
}

/*TIMER2 CTC Mode ISR*/
void __vector_4 (void)		__attribute__((signal)) ;
void __vector_4 (void)
{
	if (TIMERS_pvCallBackFunc[TIMER2_CTC_VECTOR_ID] != NULL)
	{
		TIMERS_pvCallBackFunc[TIMER2_CTC_VECTOR_ID]() ;
	}
}
