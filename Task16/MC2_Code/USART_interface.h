/*
 * USART_interface.h
 *
 *  Author: FaRaH
 */ 


#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit (void);

u8   USART_u8SendData (u8 Copy_u8Data);

u8   USART_u8RecevieData (u8 * Copy_u8ReceviedData) ;


#endif /* USART_INTERFACE_H_ */