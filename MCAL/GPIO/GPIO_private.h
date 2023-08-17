/*
 * GPIO_private.h
 *
 *  Created on: Jun 10, 2023
 *      Author: khater
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define PORT_MAX_NUM	4
#define PIN_MAX_NUM		8

#include "../../STD_TYPES.h"

#define GPIO_DDRA_REG			(*(volatile u8*)(0x3A))
#define GPIO_DDRB_REG			(*(volatile u8*)(0x37))
#define GPIO_DDRC_REG			(*(volatile u8*)(0x34))
#define GPIO_DDRD_REG			(*(volatile u8*)(0x31))


#define GPIO_PORTA_REG			(*(volatile u8*)(0x3B))
#define GPIO_PORTB_REG			(*(volatile u8*)(0x38))
#define GPIO_PORTC_REG			(*(volatile u8*)(0x35))
#define GPIO_PORTD_REG			(*(volatile u8*)(0x32))


#define GPIO_PINA_REG			(*(volatile u8*)(0x39))
#define GPIO_PINB_REG			(*(volatile u8*)(0x36))
#define GPIO_PINC_REG			(*(volatile u8*)(0x33))
#define GPIO_PIND_REG			(*(volatile u8*)(0x30))


#endif /* 02__MCAL_GPIO_GPIO_PRIVATE_H_ */
