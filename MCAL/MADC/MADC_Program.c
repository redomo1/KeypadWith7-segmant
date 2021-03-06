/*
 * MADC_Program.c
 *
 *  Created on: Nov 22, 2021
 *      Author: gerges
 */

#include"..\..\LIB\LSTD_TYPES.h"
#include"..\..\LIB\LBIT_MATH.h"
#include"..\MEXTI\MEXTI_Interface.h"
#include"..\MGIE\MGIE_Interface.h"
#include"MADC_Private.h"
#include"MADC_Config.h"

/*ADC Initialization*/
void MADC_VidInit_WithEXTI(void)
{
	/*Select Reference Voltage*/
#if MADC_SET_REFERENCEVOLATGE == MADC_AVCC_REFERENCEVOLATGE
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
#elif MADC_SET_REFERENCEVOLATGE == MADC_2.56V_REFERENCEVOLATGE
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
#else
#error"ADC Reference Voltage Option I s not valid.... "
#endif
	/*Set Prescaler*/
	ADCSRA&=MADC_BIT_MASKING_PRESCALER;
	ADCSRA|=MADC_SET_PRESCALER;

#if MADC_SET_ADJUST == MADC_LEFT_ADJUST
	SET_BIT(ADMUX,5);
#elif MADC_SET_ADJUST == MADC_RIGHT_ADJUST
	CLR_BIT(ADMUX,5);
#else
#error"ADC Left adjust option is not valid...."
#endif

	/*		ADC Auto Trigger Enable		*/
	SET_BIT(ADCSRA,5);
	MEXTI0_VidInit();
	MGIE_VidEnable();
	/*		ADC Auto Trigger Source		*/
	SFIOR&=MADC_BIT_MASKING_TRIGGER_SOURCE;
	SFIOR|=MADC_SET_TRIGGER_SOURCE;

	/*Enable To ADC*/
	SET_BIT(ADCSRA,7);
}

void MADC_VidInit(void)
{
	/*Select Reference Voltage*/
#if MADC_SET_REFERENCEVOLATGE == MADC_AVCC_REFERENCEVOLATGE
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
#elif MADC_SET_REFERENCEVOLATGE == MADC_2.56V_REFERENCEVOLATGE
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
#else
#error"ADC Reference Voltage Option I s not valid.... "
#endif
	/*Set Prescaler*/
	ADCSRA&=MADC_BIT_MASKING_PRESCALER;
	ADCSRA|=MADC_SET_PRESCALER;

#if MADC_SET_ADJUST == MADC_LEFT_ADJUST
	SET_BIT(ADMUX,5);
#elif MADC_SET_ADJUST == MADC_RIGHT_ADJUST
	CLR_BIT(ADMUX,5);
#else
#error"ADC Left adjust option is not valid...."
#endif
	/*Enable To ADC*/
	SET_BIT(ADCSRA,7);
}
/*ADC Start Conversion-->Polling , Return ADC Value*/
u16 MADC_u16ADC_StartConversion(u8 Copy_u8Channel)
{
	/*Select Channel*/
	Copy_u8Channel&=MADC_BIT_MASKING_CHANNEL;
	ADMUX&=MADC_BIT_MASKING_REG_CHANNEL;
	ADMUX|=Copy_u8Channel;
	/*send Start Conversion*/
	SET_BIT(ADCSRA,6);
	/*Wait On ADC Conversion Completed Flag is set to one */
	while(GET_BIT(ADCSRA,4)==0);

	return ADC;
}
