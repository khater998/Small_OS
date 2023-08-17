/*
 * GPIO_program.c
 *
 *  Created on: Jun 10, 2023
 *      Author: khater
 */

#include "../../BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"


void GPIO_voidSetPinDirection(EN_GPIO_PortId_t Copy_EnuPortId, EN_GPIO_PinId_t Copy_EnuPinId ,EN_GPIO_PinState_t Copy_EnuPinDirection)
{

	if(Copy_EnuPortId < PORT_MAX_NUM && Copy_EnuPinDirection < PIN_MAX_NUM)
	{
		if(Copy_EnuPinDirection == PIN_INPUT)
		{
			switch(Copy_EnuPortId)
			{
			case GPIO_PORTA: 	CLR_BIT(GPIO_DDRA_REG, Copy_EnuPinId);	break;
			case GPIO_PORTB:	CLR_BIT(GPIO_DDRB_REG, Copy_EnuPinId);	break;
			case GPIO_PORTC:	CLR_BIT(GPIO_DDRC_REG, Copy_EnuPinId);	break;
			case GPIO_PORTD:	CLR_BIT(GPIO_DDRD_REG, Copy_EnuPinId);	break;
			default: 			/* error message */				break;
			}
		}
		else if (Copy_EnuPinDirection == PIN_OUTPUT)
		{
			switch(Copy_EnuPortId)
			{
			case GPIO_PORTA: 	SET_BIT(GPIO_DDRA_REG, Copy_EnuPinId);	break;
			case GPIO_PORTB:	SET_BIT(GPIO_DDRB_REG, Copy_EnuPinId);	break;
			case GPIO_PORTC:	SET_BIT(GPIO_DDRC_REG, Copy_EnuPinId);	break;
			case GPIO_PORTD:	SET_BIT(GPIO_DDRD_REG, Copy_EnuPinId);	break;
			default: 			/* error message */				break;
			}
		}
		else if (Copy_EnuPinDirection == PIN_INPUT_PULLUP)
		{
			switch(Copy_EnuPortId)
			{
			case GPIO_PORTA:
				CLR_BIT(GPIO_DDRA_REG, Copy_EnuPinId);
				SET_BIT(GPIO_PORTA_REG, Copy_EnuPinId);
				break;
			case GPIO_PORTB:
				CLR_BIT(GPIO_DDRB_REG, Copy_EnuPinId);
				SET_BIT(GPIO_PORTB_REG, Copy_EnuPinId);
				break;
			case GPIO_PORTC:
				CLR_BIT(GPIO_DDRC_REG, Copy_EnuPinId);
				SET_BIT(GPIO_PORTC_REG, Copy_EnuPinId);
				break;
			case GPIO_PORTD:
				CLR_BIT(GPIO_DDRD_REG, Copy_EnuPinId);
				SET_BIT(GPIO_PORTD_REG, Copy_EnuPinId);
				break;
			default: 			/* error message */				break;
			}
		}
		else
		{
			/* error message */
		}
	}
	else
	{
		/* error message */
	}
}
void GPIO_voidSetPinValue(EN_GPIO_PortId_t Copy_EnuPortId, EN_GPIO_PinId_t Copy_EnuPinId ,EN_GPIO_Logic_t pinLogic)
{
	if(Copy_EnuPortId < PORT_MAX_NUM && Copy_EnuPinId < PIN_MAX_NUM)
	{
		if(pinLogic == LOGIC_LOW)
		{
			switch(Copy_EnuPortId)
			{
			case GPIO_PORTA: 	CLR_BIT(GPIO_PORTA_REG, Copy_EnuPinId);	break;
			case GPIO_PORTB:	CLR_BIT(GPIO_PORTB_REG, Copy_EnuPinId);	break;
			case GPIO_PORTC:	CLR_BIT(GPIO_PORTC_REG, Copy_EnuPinId);	break;
			case GPIO_PORTD:	CLR_BIT(GPIO_PORTD_REG, Copy_EnuPinId);	break;
			default: 			/* error message */				break;
			}
		}
		else if (pinLogic == LOGIC_HIGH)
		{
			switch(Copy_EnuPortId)
			{
			case GPIO_PORTA: 	SET_BIT(GPIO_PORTA_REG, Copy_EnuPinId);	break;
			case GPIO_PORTB:	SET_BIT(GPIO_PORTB_REG, Copy_EnuPinId);	break;
			case GPIO_PORTC:	SET_BIT(GPIO_PORTC_REG, Copy_EnuPinId);	break;
			case GPIO_PORTD:	SET_BIT(GPIO_PORTD_REG, Copy_EnuPinId);	break;
			default: 			/* error message */				break;
			}
		}
		else
		{
			/* error message */
		}
	}
	else
	{
		/* error message */

	}

}

void GPIO_voidGetPinValue(EN_GPIO_PortId_t Copy_EnuPortId, EN_GPIO_PinId_t Copy_EnuPinId, u8 * Copy_u8PinValue)
{
	EN_GPIO_Logic_t state;

	if(Copy_EnuPortId < PORT_MAX_NUM && Copy_EnuPinId < PIN_MAX_NUM)
	{
		switch(Copy_EnuPortId)
		{
		case GPIO_PORTA: 	state = GET_BIT(GPIO_PINA_REG, Copy_EnuPinId);	break;
		case GPIO_PORTB:	state = GET_BIT(GPIO_PINB_REG, Copy_EnuPinId);	break;
		case GPIO_PORTC:	state = GET_BIT(GPIO_PINC_REG, Copy_EnuPinId);	break;
		case GPIO_PORTD:	state = GET_BIT(GPIO_PIND_REG, Copy_EnuPinId);	break;
		default: 			/* error message */				break;
		}

	}
	else
	{
		/* error message */

	}
	*Copy_u8PinValue =  state;
}

void GPIO_voidTogglePin(EN_GPIO_PortId_t Copy_EnuPortId, EN_GPIO_PinId_t Copy_EnuPinId)
{
	if(Copy_EnuPortId < PORT_MAX_NUM && Copy_EnuPinId < PIN_MAX_NUM)
	{
		switch(Copy_EnuPortId)
		{
		case GPIO_PORTA: 	TOG_BIT(GPIO_PORTA_REG, Copy_EnuPinId);	break;
		case GPIO_PORTB:	TOG_BIT(GPIO_PORTB_REG, Copy_EnuPinId);	break;
		case GPIO_PORTC:	TOG_BIT(GPIO_PORTC_REG, Copy_EnuPinId);	break;
		case GPIO_PORTD:	TOG_BIT(GPIO_PORTD_REG, Copy_EnuPinId);	break;
		default: 			/* error message */				break;
		}
	}
	else
	{
		/* error message */

	}

}


void GPIO_voidSetPortDirection(EN_GPIO_PortId_t Copy_EnuPortId, EN_GPIO_PinState_t Copy_EnuPinDirection)
{
	if(Copy_EnuPinDirection == PIN_INPUT)
	{
		switch(Copy_EnuPortId)
		{
		case GPIO_PORTA: 	GPIO_DDRA_REG = 0;		break;
		case GPIO_PORTB: 	GPIO_DDRA_REG = 0;		break;
		case GPIO_PORTC: 	GPIO_DDRA_REG = 0;		break;
		case GPIO_PORTD: 	GPIO_DDRA_REG = 0;		break;
		default: /* error message */				break;
		}
	}
	else if(Copy_EnuPinDirection == PIN_OUTPUT)
	{
		switch(Copy_EnuPortId)
		{
		case GPIO_PORTA: 	GPIO_DDRA_REG = 0xFF;	break;
		case GPIO_PORTB: 	GPIO_DDRA_REG = 0xFF;	break;
		case GPIO_PORTC: 	GPIO_DDRA_REG = 0xFF;	break;
		case GPIO_PORTD: 	GPIO_DDRA_REG = 0xFF;	break;
		default: /* error message */				break;
		}
	}
	else
	{
		/* error message */
	}
}

void GPIO_voidSetPortValue(EN_GPIO_PortId_t Copy_EnuPortId, u8 Copy_u8PortValue)
{
	if(Copy_u8PortValue < 256)
	{
		switch(Copy_EnuPortId)
		{
		case GPIO_PORTA: 	GPIO_PORTA_REG = Copy_u8PortValue;		break;
		case GPIO_PORTB: 	GPIO_PORTB_REG = Copy_u8PortValue;		break;
		case GPIO_PORTC: 	GPIO_PORTC_REG = Copy_u8PortValue;		break;
		case GPIO_PORTD: 	GPIO_PORTD_REG = Copy_u8PortValue;		break;
		default: /* error message */					break;
		}
	}
	else
	{
		/* error message */
	}
}

void GPIO_voidGetPortValue(EN_GPIO_PortId_t Copy_EnuPortId, u8 * Copy_u8PortValue)
{
	u8 Local_portValue = 0;
	switch(Copy_EnuPortId)
	{
	case GPIO_PORTA: 	Local_portValue = GPIO_PINA_REG;		break;
	case GPIO_PORTB: 	Local_portValue = GPIO_PINB_REG;		break;
	case GPIO_PORTC: 	Local_portValue = GPIO_PINC_REG;		break;
	case GPIO_PORTD: 	Local_portValue = GPIO_PIND_REG;		break;
	default: /* error message */						break;
	}
	*Copy_u8PortValue =  Local_portValue;
}

