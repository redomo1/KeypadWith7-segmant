/*
 * main.c
 *
 *  Created on: Dec 1, 2021
 *      Author: Eng-Rehab Soliman
 */

#include"LIB\LSTD_TYPES.h"
#include"MCAL\MDIO\MDIO_Interface.h"
#include"HAL\HKPD\HKPD_Interface.h"
#include"HAL\HCLCD\HCLCD_Interface.h"
int main(void)
{
	u8 LOC_u8KeyPressed;
	/* store numbers from 0 to 9 in array */
	u8 ARR_7_Seg_Display[10] = {0b00111111,0b00000110,
			0b01011011,0b01001111,
			0b01100110,0b01101101,
			0b01111101,0b00000111,
			0b01111111,0b01101111};
	/*set portc as output----->for seven segment*/
	MDIO_Error_State_SetPortDirection(MDIO_PORTC,PORT_OUTPUT);
	/*Keypad Initialization*/
	HKPD_VidInit();
	/*CLCD initialization*/
	HCLCD_Vid4Bits_Init();
	while(1)
	{
		LOC_u8KeyPressed=HKPD_U8GetKeyPressed();
		if(LOC_u8KeyPressed !=NOT_PRESSED)
		{
			switch(LOC_u8KeyPressed)
			{
			case'0':
				MDIO_Error_State_SetPortValue(MDIO_PORTC,ARR_7_Seg_Display[0]);
				HCLCD_VidSendChar_4Bits(LOC_u8KeyPressed);
				break;
			case'1':
				MDIO_Error_State_SetPortValue(MDIO_PORTC,ARR_7_Seg_Display[1]);
				HCLCD_VidSendChar_4Bits(LOC_u8KeyPressed);
				break;
			case'2':
				MDIO_Error_State_SetPortValue(MDIO_PORTC,ARR_7_Seg_Display[2]);
				HCLCD_VidSendChar_4Bits(LOC_u8KeyPressed);
				break;
			case'3':
				MDIO_Error_State_SetPortValue(MDIO_PORTC,ARR_7_Seg_Display[3]);
				HCLCD_VidSendChar_4Bits(LOC_u8KeyPressed);
				break;
			case'4':
				MDIO_Error_State_SetPortValue(MDIO_PORTC,ARR_7_Seg_Display[4]);
				HCLCD_VidSendChar_4Bits(LOC_u8KeyPressed);
				break;
			case'5':
				MDIO_Error_State_SetPortValue(MDIO_PORTC,ARR_7_Seg_Display[5]);
				HCLCD_VidSendChar_4Bits(LOC_u8KeyPressed);
				break;
			case'6':
				MDIO_Error_State_SetPortValue(MDIO_PORTC,ARR_7_Seg_Display[6]);
				HCLCD_VidSendChar_4Bits(LOC_u8KeyPressed);
				break;
			case'7':
				MDIO_Error_State_SetPortValue(MDIO_PORTC,ARR_7_Seg_Display[7]);
				HCLCD_VidSendChar_4Bits(LOC_u8KeyPressed);
				break;
			case'8':
				MDIO_Error_State_SetPortValue(MDIO_PORTC,ARR_7_Seg_Display[8]);
				HCLCD_VidSendChar_4Bits(LOC_u8KeyPressed);
				break;
			case'9':
				MDIO_Error_State_SetPortValue(MDIO_PORTC,ARR_7_Seg_Display[9]);
				HCLCD_VidSendChar_4Bits(LOC_u8KeyPressed);
				break;
			}
		}
		else
		{
			/*Do Nothing*/
		}


	}




	return 0;
}
