#ifndef   DIO_INTERFACE_H_
#define   DIO_INTERFACE_H_

typedef enum               
 {
	DIO_NOK,
	DIO_OK
	
 }DIO_ErrorStatus;


#define  DIO_PORTA  0
#define  DIO_PORTB  1
#define  DIO_PORTC  2
#define  DIO_PORTD  3

#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7


#define DIO_PIN_OUTPUT	    1
#define DIO_PIN_INPUT	    0

#define DIO_PIN_HIGH		1
#define DIO_PIN_LOW			0

#define DIO_PORT_OUTPUT		0xFF
#define DIO_PORT_INPUT		0

#define DIO_PORT_HIGH 		0xFF
#define DIO_PORT_LOW  		0

#define PUD  2

#define DIO_HIGH 1

#define DIO_INPUT  0
#define DIO_OUTPUT 1


DIO_ErrorStatus DIO_enumSetPinDirection      (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Direction     );
DIO_ErrorStatus DIO_enumSetPinValue          (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value         );
DIO_ErrorStatus DIO_enumGetPinValue          (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 * Copy_PtrData       );
DIO_ErrorStatus DIO_enumTogglePinValue       (u8 Copy_u8PORT, u8 Copy_u8PIN                          );

//DIO_ErrorStatus DIO_enumConnectPullup        (u8 Copy_u8PORT ,u8 Copy_u8PIN, u8 Copy_u8ConnectPullup );

DIO_ErrorStatus DIO_enumSetPortDirection     (u8 Copy_u8PORT, u8 Copy_u8Direction  );
DIO_ErrorStatus DIO_enumSetPortValue         (u8 Copy_u8PORT, u8 Copy_u8Value      );
DIO_ErrorStatus DIO_enumGetPortValue         (u8 Copy_u8PORT, u8 * Copy_PtrData    );
DIO_ErrorStatus DIO_enumTogglePortValue      (u8 Copy_u8PORT                       );

DIO_ErrorStatus DIO_voidWriteHighNibbles (u8 Copy_u8PORT,u8 value);
DIO_ErrorStatus DIO_voidWriteLowNibbles  (u8 Copy_u8PORT,u8 value);


#endif