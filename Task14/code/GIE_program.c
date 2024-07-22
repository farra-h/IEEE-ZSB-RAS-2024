/*
 * GIE_program.c
 *
 *  Author: FaRaH
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GIE_interface.h"
#include "GIE_private.h"

/*
 * Brief : This Function used to enable General Interrupt Enable (GIE)
 * Parameters : void
 * return : void
*/
void GIE_VoidEnable (void)
{
	SET_BIT (SREG , SREG_I);
}

/*
* Brief : This Function used to disable General Interrupt Enable (GIE)
* Parameters : void
* return : void
*/
void GIE_VoidDisable(void)
{
	CLR_BIT(SREG , SREG_I);
}