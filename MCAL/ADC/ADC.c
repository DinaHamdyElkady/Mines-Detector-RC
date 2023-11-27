/*
 * ADC.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Salem Elfaidy
 */
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"
#include <avr/io.h>

#define ADC_AVCC		0
#define ADC_AREF		1
#define ADC_2_56_V		2

#include "ADC.h"

void ADC_voidInit(u8 Copy_u8Prescaler){

	/* Enable ADC */
	SET_BIT(ADCSRA, ADEN);

	/* Select Vref */
#if ADC_REF_VOLT == ADC_AVCC
	SET_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);
#elif ADC_REF_VOLT == ADC_AREF
	CLR_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);
#else
	SET_BIT(ADMUX, REFS0);
	SET_BIT(ADMUX, REFS1);
#endif

	/* select right adjust */
	CLR_BIT(ADMUX, ADLAR);

	/* prescaler */
	ADCSRA &= 0b11111000;
	ADCSRA |= Copy_u8Prescaler; // 0b00000110

}


u16  ADC_u16GetDigitalValue(u8 Copy_u8Channel){

	/* select Channel */
	ADMUX &= 0b11100000;
	ADMUX |= Copy_u8Channel;

	/*  Start Conversion */
	SET_BIT(ADCSRA, ADSC);

	/* wait flag = 1 */
	while(GET_BIT(ADCSRA, ADIF) == 0);

	/* clear flag */
	CLR_BIT(ADCSRA, ADIF);

	/* read ADC value */
	return ADC;

}


void ADC_voidDisable(void){

	/* Disable ADC */
	CLR_BIT(ADCSRA, ADEN);

}
