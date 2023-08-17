/*
 * LCD_interface.h
 *
 *  Created on: Jun 11, 2023
 *      Author: khater
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#include "../../STD_TYPES.h"

/**
 * @abstract: initiates lcd in 4 or 8 bit mode depending on configuration
 */
void LCD_init(void);

/**
 * @abstract: Sends a command to the LCD
 * @param command : the command to be sent
 */
void LCD_sendCommand(u8 command);

/**
 * @abstract: displays a character on the LCD
 * @param data: The character to be displayed on the screen
 */
void LCD_displayChar(u8 data);

/**
 * @abstract: clears the LCD screen
 */
void LCD_clearScreen(void);

/**
 * @abstract: Moves the cursor to the required location
 * @param row_number: The LCD Row to move to
 * @param col_number: The LCD column tot move to
 */
void LCD_moveCursor(u8 row_number, u8 col_number);

/**
 * @abstract: Display a string on the LCD
 * @param str: The string to be displayed on the LCD
 */
void LCD_displayString(u8 * str);

/**
 * @abstract: converts a number to string and prints it on LCD
 * @param num: The number to be printed
 */
void LCD_displayNumber(s32 num);


#endif /* HAL_LCD_LCD_INTERFACE_H_ */
