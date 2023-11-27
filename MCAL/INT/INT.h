#ifndef MCAL_INT_INT_H_
#define MCAL_INT_INT_H_

/*************************************************** Cfg ***********************************************************/
#define INT_INT0			0
#define INT_INT1			1
#define INT_INT2			2

/********************* Sense *************************/
#define INT_FALLING_EDGE		0
#define INT_RISING_EDGE			1
#define INT_ANY_CHANGE			2
#define INT_LOW_LEVEL			3

/********************************************************** APIs **************************************************************/

void INT_voidEnable(u8 Copy_u8INTINdex, u8 Copy_u8INTSense);
void INT_voidDisable(u8 Copy_u8INTINdex);

#endif /* MCAL_INT_INT_H_ */
