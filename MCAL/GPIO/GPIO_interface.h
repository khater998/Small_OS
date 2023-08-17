/*
 * GPIO_interface.h
 *
 *  Created on: Jun 10, 2023
 *      Author: khater
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "../../STD_TYPES.h"


typedef enum
{
	GPIO_PORTA,
	GPIO_PORTB,
	GPIO_PORTC,
	GPIO_PORTD
}EN_GPIO_PortId_t;

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}EN_GPIO_PinId_t;


typedef enum
{
	PIN_INPUT,
	PIN_OUTPUT,
	PIN_INPUT_PULLUP
}EN_GPIO_PinState_t;

typedef enum
{
	LOGIC_LOW,
	LOGIC_HIGH
}EN_GPIO_Logic_t;


/**
 * @abstract: sets a pin as either input or output pin
 * @param port: The port where the pin at
 * @param pin: The pin to be configured
 * @param pinDirection: The required direction of the pin
 */
void GPIO_voidSetPinDirection(EN_GPIO_PortId_t Copy_EnuPortId, EN_GPIO_PinId_t Copy_EnuPinId ,EN_GPIO_PinState_t Copy_EnuPinDirection);

/**
 * @abstract: set the pin logic to either high or low
 * @param port: The port where the pin at
 * @param pin: The pin to be configured
 * @param pinLogic: The required logic of the pin
 */
void GPIO_voidSetPinValue(EN_GPIO_PortId_t Copy_EnuPortId, EN_GPIO_PinId_t Copy_EnuPinId ,EN_GPIO_Logic_t pinLogic);

/**
 * @abstract: Toggles the pin logic
 * @param port: The port where the pin at
 * @param pin: The pin to be configured
 */
void GPIO_voidTogglePin(EN_GPIO_PortId_t Copy_EnuPortId, EN_GPIO_PinId_t Copy_EnuPinId);

/**
 * @abstract: Reads the current logic of the pin
 * @param port: The port where the pin at
 * @param pin: The pin to be configured
 */
void GPIO_voidGetPinValue(EN_GPIO_PortId_t Copy_EnuPortId, EN_GPIO_PinId_t Copy_EnuPinId, u8 * Copy_u8PinValue);


/**
 * @abstract: sets a complete port as input or output
 * @param port: The port ID to be initialized
 * @param pinDirection: The required direction of the port
 */
void GPIO_voidSetPortDirection(EN_GPIO_PortId_t Copy_EnuPortId, EN_GPIO_PinState_t Copy_EnuPinDirection);

/**
 * @abstract: write a value on the whole port
 * @param port: The port to be written
 * @param value: The value to be written
 */
void GPIO_voidSetPortValue(EN_GPIO_PortId_t Copy_EnuPortId, u8 Copy_u8PortValue);

/**
 *
 * @param port: The port to be read
 * @return returns the status of the port
 */
void GPIO_voidGetPortValue(EN_GPIO_PortId_t Copy_EnuPortId, u8 * Copy_u8PortValue);





#endif /* GPIO_INTERFACE_H_ */
