/*
 * LCD_private.h
 *
 *  Created on: Jun 11, 2023
 *      Author: khater
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_


static void LCD_generateEnablePulse();

#define LCD_FOUR_BIT_MODE 	0
#define LCD_EIGHT_BIT_MODE	1


#if	LCD_OPERATION_MODE == LCD_FOUR_BIT_MODE
#define LCD_DATA_PINS_USED							4
#define LCD_TWO_LINES_4BITS_MODE     				0x28
#define LCD_FOUR_BIT_INIT_ONE						0x33
#define LCD_FOUR_BIT_INIT_TWO						0x32

#define	LCD_HIGHER_NIBBLES_PINS				LCD_DB4_PIN_ID, LCD_DB5_PIN_ID, LCD_DB6_PIN_ID, LCD_DB7_PIN_ID


#elif LCD_OPERATION_MODE == LCD_EIGHT_BIT_MODE

#define	LCD_LOWER_NIBBLES_PINS				LCD_DB0_PIN_ID, LCD_DB1_PIN_ID, LCD_DB2_PIN_ID, LCD_DB3_PIN_ID

#define LCD_DATA_PINS_USED						8
#define LCD_ONE_LINE_EIGHT_BITS_MODE			0x30
#define LCD_TWO_LINES_8BITS_MODE				0x38


#else
#error "UNDEFINED LCD CONFIGURATION"
#endif

#define DECIMAL 	10

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
