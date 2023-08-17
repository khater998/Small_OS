/*
 * BUZZER_program.c
 *
 *  Created on: Jun 11, 2023
 *      Author: khater
 */

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "BUZZER_cfg.h"
#include "BUZZER_interface.h"
#include "BUZZER_private.h"

void BUZZER_init(void)
{
	GPIO_voidSetPinDirection(BUZZER_PORT_ID, BUZZER_PIN_ID, PIN_OUTPUT);
}
void BUZZER_turnOn(void)
{
	GPIO_voidSetPinValue(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_HIGH);
}
void BUZZER_turnOff(void)
{
	GPIO_voidSetPinValue(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);

}

