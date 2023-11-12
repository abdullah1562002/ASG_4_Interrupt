/*
 * ASG_4_Interrput.c
 *
 * Created: 11/11/2023 4:43:35 PM
 * Author : aabdu
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "EXTI_interface.h"
#include "DIO_interface.h"
#include "GI_interface.h"

u8 LED0_value , LED1_value, LED2_value;

int main(void)
{
	// LEDS
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT); //LED0 >> O/P
	DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT); //LED1 >> O/P
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT); //LED2 >> O/P
	
	
	// Buttons
	DIO_setPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);  //Button 2 INT0 >> I/P
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_INPUT);  //Button 1 INT2 >> I/P
	
	GI_enable();
	
	EXTI_enable(EXTI_INT0,EXTI_RISING_EDGE);
	EXTI_enable(EXTI_INT2,EXTI_RISING_EDGE);
	while (1)
	{
			DIO_getPinValue(DIO_PORTC,DIO_PIN2, &LED0_value);
			DIO_getPinValue(DIO_PORTC,DIO_PIN7, &LED1_value);
			DIO_getPinValue(DIO_PORTD,DIO_PIN3, &LED2_value);
	}
}

// for INT0
void __vector_1(void) __attribute__ ((signal));
void __vector_1(void)
{

	if (LED0_value==0 && LED1_value==0 && LED2_value==0)
	{
		DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH); // LED0 on
	}
	else if(LED0_value==1 && LED1_value==0 && LED2_value==0)
	{
		DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH); // LED1 on
	}
	else if(LED0_value==1 && LED1_value==1 && LED2_value==0)
	{
		DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH); // LED2 on
	}
	
}

// for INT2
void __vector_3(void) __attribute__ ((signal));
void __vector_3(void)
{
		if (LED0_value==1 && LED1_value==1 && LED2_value==1)
		{
			DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW); // LED2 off
		}
		else if(LED0_value==1 && LED1_value==1 && LED2_value==0)
		{
			DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW); // LED1 off
		}
		else if(LED0_value==1 && LED1_value==0 && LED2_value==0)
		{
			DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW); // LED0 off
		}
}