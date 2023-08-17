/*
 * TIMER0_program.c
 *
 *  Created on: Jun 19, 2023
 *      Author: khater
 */

#ifndef TIMER0_PROGRAM_C_
#define TIMER0_PROGRAM_C_

#include <avr/io.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "TIMER0_config.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include <avr/interrupt.h>

static u32 no_ovfs = 0;
static u8 isSingleInterval = 0;
static u8 TCNT0_PERIODIC = 0;

static void (*callBack_ptr)(void) = NULL;

void TIMER0_voidInit(u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
	case TIMER0_NORMAL_MODE:
		TCCR0 = 0;
		break;

	case TIMER0_CTC_MODE:
		TCCR0 = (1 << WGM01);

		break;
	case TIMER0_PHASE_CORRECT_PWM:
		TCCR0 = (1 << WGM00) | (1 << COM01);

		break;
	case TIMER0_FAST_PWM:
		TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01);

		break;
	}
}
void TIMER0_voidSetBusyWait(u32 Copy_u32Ticks)
{
	TCCR0 = (TCCR0 & 0xF8) | TIMER0_PRESCALER;
	u32 Local_ovfCounter = 0;
	no_ovfs = Copy_u32Ticks / TIMER0_MAX_NO_TICKS;
	u8 Local_remainingCounts = Copy_u32Ticks - (Local_ovfCounter * TIMER0_MAX_NO_TICKS);

	while(Local_ovfCounter != no_ovfs)
	{
		while(BIT_IS_CLEAR(TIFR, TOV0));
		Local_ovfCounter++;
		SET_BIT(TIFR, TOV0);
	}

	TCNT0 = (TIMER0_MAX_NO_TICKS) - Local_remainingCounts;
	while(BIT_IS_CLEAR(TIFR, TOV0));
	SET_BIT(TIFR, TOV0);
}

void TIMER0_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_funcPtr) (void))
{
	TCCR0 = (TCCR0 & 0xF8) | TIMER0_PRESCALER;

	SET_BIT(TIMSK, TOIE0);
	callBack_ptr = Copy_funcPtr;
	isSingleInterval = 1;

}
void TIMER0_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_funcPtr) (void))
{
	TCCR0 = (TCCR0 & 0xF8) | TIMER0_PRESCALER;
	TCNT0_PERIODIC = 256 - Copy_u32Ticks;
	TCNT0 = TCNT0_PERIODIC;
	SET_BIT(TIMSK, TOIE0);
	callBack_ptr = Copy_funcPtr;
}

void TIMER0_voidStop(void)
{
	TCCR0 = TCCR0 & 0xF8;
}

ISR(TIMER0_OVF_vect)
{
	if(callBack_ptr)
	{
		callBack_ptr();
		if(isSingleInterval)
		{
			TIMER0_voidStop();
			isSingleInterval = 0;
		}else
		{
			TCNT0 = TCNT0_PERIODIC;
		}
	}
}

#endif /* TIMER0_PROGRAM_C_ */
