#ifndef MCAL_TIMER0_TIM0_H_
#define MCAL_TIMER0_TIM0_H_


/******************** Select Mode **************************/
#define TIM0_MODE					NORMAL
/* NORMAL		CTC		PWM_PHASE		FAST_PWM */

/****************** Prescaler ******************************/
#define TIM0_STOPPED				0
#define TIM0_NO_PRESCALER			1
#define TIM0_PRESCALER_8			2
#define TIM0_PRESCALER_64			3
#define TIM0_PRESCALER_256			4
#define TIM0_PRESCALER_1024			5
#define TIM0_EXT_FALLING			6
#define TIM0_EXT_RISINGING			7

/****************** Interrupt control ***********************/
#define TIM0_TIN_EABLE				1
#define TIM0_TIN_DISABLE			0

/***************** CO0 Pin Action (NORMAL, CTC)**************/
#define TIM0_OC0_IN_OUT_PIN			0
#define TIM0_OC0_TOGGLE_PIN			1
#define TIM0_OC0_CLEAR_PIN			2
#define TIM0_OC0_SET_PIN			3


/************************************************************** APIs ****************************************************************/

void TIM0_voidInit			(void);
void TIM0_voidSetPreValue	(u8 Copy_u8CounterStartVal);
void TIM0_voidTimerStart	(u8 Copy_u8Prescaler      );
void TIM0_voidOvrINTControl (u8 Copy_u8InterruptConl  );
void TIM0_voidSetCompareMat (u8 Copy_u8CmpMatVal, u8 Copy_u8OC0PinAction);
void TIM0_voidSetCmpValue	(u8 Copy_u8CmpMatVal      );
void TIM0_voidCmpINTControl (u8 Copy_u8InterruptConl  );
void TIM0_voidTimerStop		(void);
void TIM0_voidOvfCallback   ( void (*Copy_pfTIM0Ovf)(void) );
void TIM0_voidCmpCallback   ( void (*Copy_pfTIM0Cmp)(void) );

// returned type (* pf) (input parameters)









#endif /* MCAL_TIMER0_TIM0_H_ */
