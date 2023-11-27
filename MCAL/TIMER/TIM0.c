
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/******************************************************/
#define NORMAL			0
#define CTC				1
#define PWM_PHASE		2
#define FAST_PWM		3
/******************************************************/
#include "TIM0.h"

/* Global pointer to function */
void (*TIM0_pfTIM0Ovf)(void);
void (*TIM0_pfTIM0Cmp)(void);


void TIM0_voidInit	(void){
	/* select ur mode */
#if TIM0_MODE == NORMAL
	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);
#elif TIM0_MODE == CTC
	CLR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
#elif TIM0_MODE == PWM_PHASE
	CLR_BIT(TCCR0, WGM01);
	SET_BIT(TCCR0, WGM00);
#else
	SET_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
#endif

}


void TIM0_voidSetPreValue	(u8 Copy_u8CounterStartVal){
	/* set timer start value */
	TCNT0 = Copy_u8CounterStartVal;

}


void TIM0_voidTimerStart	(u8 Copy_u8Prescaler){
	/* Set prescaler */
	TCCR0 &= 0b11111000;
	TCCR0 |= Copy_u8Prescaler;

}


void TIM0_voidOvrINTControl (u8 Copy_u8InterruptConl){

	if(Copy_u8InterruptConl == TIM0_TIN_EABLE)
		{SET_BIT(TIMSK, TOIE0);}
	else
		{CLR_BIT(TIMSK, TOIE0);}

}


void TIM0_voidSetCompareMat (u8 Copy_u8CmpMatVal, u8 Copy_u8OC0PinAction){

	switch(Copy_u8OC0PinAction)
	{
		case TIM0_OC0_TOGGLE_PIN :
			SET_BIT(TCCR0, COM00);
			CLR_BIT(TCCR0, COM01);
			break;

		case TIM0_OC0_CLEAR_PIN  :
			SET_BIT(TCCR0, COM01);
			CLR_BIT(TCCR0, COM00);
			break;

		case TIM0_OC0_SET_PIN    :
			SET_BIT(TCCR0, COM00);
			SET_BIT(TCCR0, COM01);
			break;

		default				     :
			CLR_BIT(TCCR0, COM00);
			CLR_BIT(TCCR0, COM01);
			break;
	}

	/* Set Compare value */
	OCR0 = Copy_u8CmpMatVal;

}


void TIM0_voidSetCmpValue	(u8 Copy_u8CmpMatVal){

	/* Set Compare value */
	OCR0 = Copy_u8CmpMatVal;

}


void TIM0_voidCmpINTControl (u8 Copy_u8InterruptConl){

	if(Copy_u8InterruptConl == TIM0_TIN_EABLE)
		{SET_BIT(TIMSK, OCIE0);}
	else
		{CLR_BIT(TIMSK, OCIE0);}

}


void TIM0_voidTimerStop		(void){

	TCCR0 &= 0b11111000;

}


void TIM0_voidOvfCallback   ( void (*Copy_pfTIM0Ovf)(void) ){

	TIM0_pfTIM0Ovf = Copy_pfTIM0Ovf;
}


void TIM0_voidCmpCallback   ( void (*Copy_pfTIM0Cmp)(void) ){

	TIM0_pfTIM0Cmp = Copy_pfTIM0Cmp;

}


ISR(TIMER0_OVF_vect){

	TIM0_pfTIM0Ovf();
}


ISR(TIMER0_COMP_vect){

	TIM0_pfTIM0Cmp();
}
