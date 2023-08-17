/*
 * LCD_program.c
 *
 *  Created on: Jun 11, 2023
 *      Author: khater
 */


#include "LCD_interface.h"
#include "LCD_cfg.h"
#include "LCD_private.h"
#include "LCD_types.h"

#include "../../STD_TYPES.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../BIT_MATH.h"
#include <stdlib.h>
#include <util/delay.h>




/* Create an array of the data pins of the LCD, SIZE will depend on the configuration */
u8 LCD_dataPins_Ids[LCD_DATA_PINS_USED] =
{
#if	(LCD_OPERATION_MODE == LCD_EIGHT_BIT_MODE)
		LCD_LOWER_NIBBLES_PINS,
#endif
		LCD_HIGHER_NIBBLES_PINS
};


void LCD_init(void)
{
	/* create a variable to loop through the data pins */
	u8 pin_counter;

	/* Adjust Enable, RS, and Data pins as output*/
	GPIO_voidSetPinDirection(LCD_RS_PORT, LCD_RS_PIN, PIN_OUTPUT);
	GPIO_voidSetPinDirection(LCD_EN_PORT, LCD_EN_PIN, PIN_OUTPUT);

	/* Adjust the data pins as output */
	for(pin_counter = 0; pin_counter < LCD_DATA_PINS_USED; pin_counter++)
	{
		GPIO_voidSetPinDirection(LCD_DATA_PORT_ID, LCD_dataPins_Ids[pin_counter], PIN_OUTPUT);
	}

	_delay_ms(20);

#if	(LCD_OPERATION_MODE == LCD_4BIT_MODE)
	{
		LCD_sendCommand(LCD_TWO_LINES_4BITS_MODE);
		LCD_sendCommand(LCD_FOUR_BIT_INIT_ONE);
		LCD_sendCommand(LCD_FOUR_BIT_INIT_TWO);
	}
#elif (LCD_OPERATION_MODE == LCD_EIGHT_BIT_MODE)
	{
		LCD_sendCommand(LCD_TWO_LINES_8BITS_MODE);
	}
#else
	{
#error "undefined operation mode"
	}
#endif

	LCD_sendCommand(LCD_DISPLAY_ON_CURSOR_OFF);
	LCD_sendCommand(LCD_CLEAR_DISPLAY);

}

void LCD_sendCommand(u8 command)
{
	/* create a variable to loop through the data pins */
	u8 pin_counter = 0;

	/* CHOOSE COMMAND REGISTER AND PUT DATA ON THE DATA PINS */
	GPIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN, LOGIC_LOW);

#if	(LCD_OPERATION_MODE == LCD_FOUR_BIT_MODE)

	/* Set the higher nibble of the command, on the data pins */
	for(pin_counter = 0; pin_counter < LCD_DATA_PINS_USED; pin_counter++)
	{
		GPIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_dataPins_Ids[pin_counter], GET_BIT(command, 4+pin_counter));
	}

	/* generate the high to low pulse on enable */
	LCD_generateEnablePulse();

	/* Set the lower nibble of the command, on the data pins */
	for(pin_counter = 0; pin_counter < LCD_DATA_PINS_USED; pin_counter++)
	{
		GPIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_dataPins_Ids[pin_counter], GET_BIT(command, pin_counter));
	}
	LCD_generateEnablePulse();


#elif (LCD_OPERATION_MODE == LCD_EIGHT_BIT_MODE)
	for(pin_counter = 0; pin_counter < LCD_DATA_PINS_USED; pin_counter++)
	{
		GPIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_dataPins_Ids[pin_counter], GET_BIT(command, pin_counter));
	}
#else
	/* error */
#endif

}

void LCD_displayChar(u8 data)
{
	/* create a variable to loop through the data pins */
	u8 pin_counter;

	/* Write 1 on the RS pin to send data */
	GPIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN, LOGIC_HIGH);

#if	(LCD_OPERATION_MODE == LCD_FOUR_BIT_MODE)

	/* Set the higher nibble of the data on the data pins */
	for(pin_counter = 0; pin_counter < LCD_DATA_PINS_USED; pin_counter++)
	{
		GPIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_dataPins_Ids[pin_counter], GET_BIT(data, 4+pin_counter));
	}

	LCD_generateEnablePulse();

	/* Set the lower nibble of the command, on the data pins */
	for(pin_counter = 0; pin_counter < LCD_DATA_PINS_USED; pin_counter++)
	{
		GPIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_dataPins_Ids[pin_counter], GET_BIT(data, pin_counter));
	}

	LCD_generateEnablePulse();

#elif (LCD_OPERATION_MODE == LCD_EIGHT_BIT_MODE)
	for(pin_counter = 0; pin_counter < LCD_DATA_PINS_USED; pin_counter++)
	{
		GPIO_voidSetPinValue(LCD_DATA_PORT_ID, LCD_dataPins_Ids[pin_counter], GET_BIT(data, pin_counter));
	}
#else
	/* error */
#endif

}

void LCD_displayString(u8 * str)
{
	u8 counter = 0;
	while(str[counter])
	{
		LCD_displayChar(str[counter++]);
	}
}

static void LCD_generateEnablePulse()
{
	GPIO_voidSetPinValue(LCD_EN_PORT, LCD_EN_PIN, LOGIC_HIGH);
	_delay_ms(2);
	GPIO_voidSetPinValue(LCD_EN_PORT, LCD_EN_PIN, LOGIC_LOW);
}


void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_DISPLAY);
}

void LCD_moveCursor(u8 row_number, u8 col_number)
{
	u8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row_number)
	{
	case 0:
		lcd_memory_address=col_number;
		break;
	case 1:
		lcd_memory_address=col_number+0x40;
		break;
	case 2:
		lcd_memory_address=col_number+0x10;
		break;
	case 3:
		lcd_memory_address=col_number+0x50;
		break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);

}

void LCD_displayNumber(s32 num)
{
	u8 buffer[15] = {'\0'};
	itoa(num, buffer, DECIMAL);
	LCD_displayString(buffer);
}
