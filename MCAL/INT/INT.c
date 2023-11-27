#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include <avr/interrupt.h>
#include "INT.h"

void INT_voidEnable(u8 Copy_u8INTINdex, u8 Copy_u8INTSense){

	switch (Copy_u8INTINdex) {
		case INT_INT0:
			/* Select sense */
			switch (Copy_u8INTSense) {
				case INT_FALLING_EDGE:
					CLR_BIT(MCUCR, ISC00);
					SET_BIT(MCUCR, ISC01);
					break;

				case INT_RISING_EDGE:
					SET_BIT(MCUCR, ISC00);
					SET_BIT(MCUCR, ISC01);
					break;

				case INT_ANY_CHANGE:
					CLR_BIT(MCUCR, ISC01);
					SET_BIT(MCUCR, ISC00);
					break;

				case INT_LOW_LEVEL:
					CLR_BIT(MCUCR, ISC00);
					CLR_BIT(MCUCR, ISC01);
					break;
			}
			/* Enable interrupt 0 */
			SET_BIT(GICR, INT0);
			break;

		case INT_INT1:
			/* Select sense */
			switch (Copy_u8INTSense) {
				case INT_FALLING_EDGE:
					CLR_BIT(MCUCR, ISC10);
					SET_BIT(MCUCR, ISC11);
					break;

				case INT_RISING_EDGE:
					SET_BIT(MCUCR, ISC10);
					SET_BIT(MCUCR, ISC11);
					break;

				case INT_ANY_CHANGE:
					CLR_BIT(MCUCR, ISC11);
					SET_BIT(MCUCR, ISC10);
					break;

				case INT_LOW_LEVEL:
					CLR_BIT(MCUCR, ISC10);
					CLR_BIT(MCUCR, ISC11);
					break;
			}
			/* Enable interrupt 1 */
			SET_BIT(GICR, INT1);
			break;

		case INT_INT2:
			/* Select sense */
			switch (Copy_u8INTSense) {
				case INT_FALLING_EDGE:
					CLR_BIT(MCUCSR, ISC2);
					break;

				case INT_RISING_EDGE:
					SET_BIT(MCUCSR, ISC2);
					break;
			}
			/* Enable interrupt 2 */
			SET_BIT(GICR, INT2);
			break;
	}

}



void INT_voidDisable(u8 Copy_u8INTINdex){

	switch (Copy_u8INTINdex) {
		case INT_INT0:
			CLR_BIT(GICR, INT0);
			break;
		case INT_INT1:
			CLR_BIT(GICR, INT1);
			break;
		case INT_INT2:
			CLR_BIT(GICR, INT2);
			break;
	}

}
