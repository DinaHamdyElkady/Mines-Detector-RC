#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#define ADC_REF_VOLT		ADC_AVCC
/* ADC_AVCC		ADC_AREF	ADC_2_56_V */

/************************ Prescaler ****************/
#define ADC_DIV_2			1
#define ADC_DIV_4			2
#define ADC_DIV_8			3
#define ADC_DIV_16			4
#define ADC_DIV_32			5
#define ADC_DIV_64			6
#define ADC_DIV_128			7
/***************************************************/

#define ADC_Channel_0		0
#define ADC_Channel_1		1
#define ADC_Channel_2		2
#define ADC_Channel_3		3
#define ADC_Channel_4		4
#define ADC_Channel_5		5
#define ADC_Channel_6		6
#define ADC_Channel_7		7

/******************************************************* APIs ********************************************************************/

void ADC_voidInit(u8 Copy_u8Prescaler);
u16  ADC_u16GetDigitalValue(u8 Copy_u8Channel);
void ADC_voidDisable(void);



#endif /* MCAL_ADC_ADC_H_ */
