#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include "../../LIB/STD_Types.h"
/*********************************************************************/

#define DIO_HIGH		1
#define DIO_LOW			0
/*************************************************************************/

#define	DIO_OUTPUT		1
#define	DIO_INPUT		0
/********************************************************************/

#define	DIO_PORTA		0
#define	DIO_PORTB		1
#define	DIO_PORTC		2
#define	DIO_PORTD		3
/*********************************************************************/

#define	DIO_PIN0		0
#define	DIO_PIN1		1
#define	DIO_PIN2		2
#define	DIO_PIN3		3
#define	DIO_PIN4		4
#define	DIO_PIN5		5
#define	DIO_PIN6		6
#define	DIO_PIN7		7

/********************************************* APIs****************************************/
void DIO_voidSetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);	//DDR
void DIO_voidSetPinValue	 (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);		//PORT
u8   DIO_u8GetPinValue		 (u8 Copy_u8Port, u8 Copy_u8Pin);						//PIN
void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
void DIO_voidSetPortValue	 (u8 Copy_u8Port, u8 Copy_u8Value);
void DIO_voidTogglePin		 (u8 Copy_u8Port, u8 Copy_u8Pin);


#endif /* MCAL_DIO_DIO_H_ */
