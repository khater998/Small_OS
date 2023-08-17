/*
 * TIMER0_interface.h
 *
 *  Created on: Jun 19, 2023
 *      Author: khater
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"

typedef enum
{
	TIMER0_STOPPED,
	TIMER0_NO_PRESCALER,
	TIMER0_PRESCALER_8,
	TIMER0_PRESCALER_64,
	TIMER0_PRESCALER_256,
	TIMER0_PRESCALER_1024,
}EN_TIMER0_Prescaler_t;

typedef enum
{
	TIMER0_NORMAL_MODE,
	TIMER0_PHASE_CORRECT_PWM,
	TIMER0_CTC_MODE,
	TIMER0_FAST_PWM,
}EN_TIMER0_Mode_t;


void TIMER0_voidInit(u8 Copy_u8Mode);
void TIMER0_voidSetBusyWait(u32 Copy_u32Ticks);
void TIMER0_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_funcPtr) (void));
void TIMER0_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_funcPtr) (void));
void TIMER0_voidStop(void);


#endif /* TIMER0_INTERFACE_H_ */
