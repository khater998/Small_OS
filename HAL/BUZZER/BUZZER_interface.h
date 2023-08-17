/*
 * BUZZER_interface.h
 *
 *  Created on: Jun 11, 2023
 *      Author: khater
 */

#ifndef HAL_BUZZER_BUZZER_INTERFACE_H_
#define HAL_BUZZER_BUZZER_INTERFACE_H_

#include "../../STD_TYPES.h"


/**
 * @abstract: initializes the Buzzer pin as output pin
 */
void BUZZER_init(void);

/**
 * @abstract: Turns the buzzer on
 */
void BUZZER_turnOn(void);

/**
 * @abstract: Turns the power off
 */
void BUZZER_turnOff(void);

#endif /* HAL_BUZZER_BUZZER_INTERFACE_H_ */
