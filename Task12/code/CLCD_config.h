/*
 * CLCD_config.h
 *
 *  Author: FaRaH
 */ 


#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

#define CLCD_MODE  4

#define CLCD_DATA_PORT      DIO_PORTA
#define CLCD_CONTROL_PORT   DIO_PORTB	/* RS,RW,EN */

#define CLCD_RS             DIO_PIN1
#define CLCD_RW             DIO_PIN2
#define CLCD_EN             DIO_PIN3



#endif /* CLCD_CONFIG_H_ */