/*
 ============================================================================
 Name        : cdrivers.c
 Author      : kareem mohamed
 Description : define the used data types  in embedded programming
 Date        : 14/4/2019
 ============================================================================
 */

#include<avr/io.h>
#include"util/delay.h"
#include"hdrivers.h"
#include<avr/interrupt.h>
#include "datatypes.h"
#include "dioavrRegisters.h"
 bool g_interrupt_flag;

// first function to initialize the fast PWM mode in atmega16 to control the speed of DC motor
void Init_pwm_timer0(void)
{
	TCCR0 =(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS01);
	/*
	 * WGM00 AND WGM01 ARE SET TO CHOOSE FAST PWM MODE
	 * COM01 IS SET AND COM00 IS CLEARED TO CHOOSE NON-INVERTING MODE
	 * CS01 IS SET AND CS00 AND CS02 ARE CLEARED TO CHOOSE PRESCALER =8
	 * THE PWM FREQUENCY IS 488 HZ = (1MHZ/(256*8))
	 */
	TCNT0 =0;
	// Initial value for TCNT0 register =0 to start count from 0;
	OCR0=0;
	// Initial value for OCR0 register =0,THIS REGISTER WILL BE SET BY THE USER TO CONTROL SPEED OF DC MOTOR
	DDRB_REG.BITS.BIT3 = HIGH;
	// PIN (PB3) OR (OC0) IS SET TO BE OUTPUT PIN TO CONTROL THE SPEED OF DC MOTOR

}

/* second function to initialize the external interrupt0 to allow the user to change the speed of dc motor
 * value of (OCR0) to change the pwm output from oc0 to change speed of dc motor
 * the user can change the value of the register in ten lvls from 0 to 9  by pushing the button that connected
 * to external interrupt0  every push increment the lvl of the dc motor speed ,
 * the lvl of dc motor speed will be displayed on a 7 segment
 */
void Init_external_interrupt0(void)
{
	SREG |=(1<<7);
	// TO ENABLE GLOBAL INTERRUPT FLAG (I-BIT)
	MCUCR |=(1<<ISC00)|(1<<ISC01);
	// THE ISC00 AND ISC01  BITS AER SET TO 1 TO GENERATE THE INTERRUPT AT RISING EDGE.
	GICR |=(1<<INT0);
	// IS SET TO ENABLE INTERRUPT FLAG OF EXTERNAL INTERRUPT0.
	DDRD_REG.BITS.BIT2=LOW;
	// CLearing pin PB0 To make it input form external interrupt 0 to control the speed of DC MOTOR

}

// the ISR implementation when external interrupt  requested if the user push the botton
ISR(INT0_vect)
{
	g_interrupt_flag=HIGH;
}



