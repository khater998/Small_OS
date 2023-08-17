/*
 * main.c
 *
 *  Created on: Aug 3, 2023
 *      Author: khater
 */

#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/ADC/adc.h"
#include "HAL/BUZZER/BUZZER_interface.h"
#include "HAL/LM35_SENSOR/lm35_sensor.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/DC_MOTOR/DC_MOTOR_interface.h"
#include "OS_interface.h"
#include "avr/io.h"


void BUZZER_task(void);
void LCD_task(void);
void LED_task(void);
void DC_MOTOR_task(void);
void LM35_task(void);

int main(void)
{
	LCD_init();
	LCD_displayString("MOHAMED IBRAHIM");
	GPIO_voidSetPinDirection(GPIO_PORTA, PIN7, PIN_OUTPUT);

	ADC_ConfigType adc_ch2 = {.ref_volt = ADC_Internal, .prescaler = ADC_PRESCALER_8};
	ADC_init(&adc_ch2);
	GPIO_voidSetPinDirection(GPIO_PORTD, PIN4, PIN_OUTPUT);

	DcMotor_Init();
	DcMotor_Rotate(CW);

	GPIO_voidSetPinDirection(GPIO_PORTC, PIN0, PIN_OUTPUT);

	GPIO_voidSetPinDirection(GPIO_PORTC, PIN4, PIN_OUTPUT);
	GPIO_voidSetPinDirection(GPIO_PORTC, PIN5, PIN_OUTPUT);
	GPIO_voidSetPinDirection(GPIO_PORTC, PIN6, PIN_OUTPUT);
	GPIO_voidSetPinDirection(GPIO_PORTC, PIN7, PIN_OUTPUT);

	OS_voidInit();

	OS_u8CreatTask(0, 50, 0, BUZZER_task);
	OS_u8CreatTask(1, 13, 0, LCD_task);
	OS_u8CreatTask(2, 30, 0, LED_task);
	OS_u8CreatTask(3, 40, 0, DC_MOTOR_task);
	OS_u8CreatTask(4, 100, 25, LM35_task);



	SET_BIT(SREG, 7);
	OS_voidStartScheduler();

	while(1)
	{

	}

}

void BUZZER_task(void)
{
	GPIO_voidTogglePin(GPIO_PORTC, PIN0);
}

void LCD_task(void)
{
	LCD_sendCommand(0X1C);
}


void LED_task(void)
{
	GPIO_voidTogglePin(GPIO_PORTC, PIN4);
	GPIO_voidTogglePin(GPIO_PORTC, PIN5);
	GPIO_voidTogglePin(GPIO_PORTC, PIN6);
	GPIO_voidTogglePin(GPIO_PORTC, PIN7);

}

void DC_MOTOR_task(void)
{
	DcMotor_voidChangeDir();
}

void LM35_task(void)
{
	GPIO_voidTogglePin(GPIO_PORTA, PIN7);
	//GPIO_voidSetPinValue(GPIO_PORTA, PIN7, LOGIC_HIGH);
	 u8 temp;
	/* get lm35 reading */
	temp = LM35_getTemperature();
	GPIO_voidTogglePin(GPIO_PORTD, PIN4);
	//GPIO_voidSetPinValue(GPIO_PORTA, PIN7, LOGIC_LOW);


}

