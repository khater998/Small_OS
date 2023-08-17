/*
 * LCD_cfg.h
 *
 *  Created on: Jun 11, 2023
 *      Author: khater
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_

#define LCD_OPERATION_MODE		LCD_FOUR_BIT_MODE


/* Define the pins for the RS */
#define LCD_RS_PORT				GPIO_PORTA
#define LCD_RS_PIN				PIN3

/* Define the pins for the EN */
#define LCD_EN_PORT				GPIO_PORTA
#define LCD_EN_PIN				PIN2

/* Define the port used for data pins */
#define LCD_DATA_PORT_ID		GPIO_PORTB

/* Define the pins for each data pin */
#if LCD_OPERATION_MODE	== LCD_8BIT_MODE
#define LCD_DB0_PIN_ID                 PIN3
#define LCD_DB1_PIN_ID                 PIN5
#define LCD_DB2_PIN_ID                 PIN6
#define LCD_DB3_PIN_ID                 PIN7
#endif

#define LCD_DB4_PIN_ID                 PIN0
#define LCD_DB5_PIN_ID                 PIN1
#define LCD_DB6_PIN_ID                 PIN2
#define LCD_DB7_PIN_ID                 PIN3


#define LCD_CLEAR_DISPLAY					0x01
#define LCD_RETURN_HOME						0x02
#define LCD_ENTRY_MODE						0x06
#define LCD_DISPLAY_OFF_CURSOR_OFF			0x08
#define LCD_DISPLAY_ON_CURSOR_ON			0x0E
#define LCD_DISPLAY_ON_CURSOR_OFF			0x0C
#define LCD_DISPLAY_ON_CURSOR_BLINKING		0x0F
#define LCD_SHIFFT_ENTIRE_DISPLAY_LEFT		0x18
#define LCD_SHIFFT_ENTIRE_DISPLAY_RIGHT		0x1C
#define LCD_SET_CURSOR_LOCATION				0x80





#endif /* HAL_LCD_LCD_CFG_H_ */
