/*
 ============================================================================
 Name        : app.c
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
static uint8 g_motorSpeedlvl=0;
extern bool g_interrupt_flag;

int main(void)
{
	//Initialize the external interrupt 0 and the pwm mode in timer 0
	Init_pwm_timer0();
	Init_external_interrupt0();
	// We cleared pins , PA1 AND PA2 in DDRA_REG register TO BE INPUT BINS PA1 AND PA2 TO CONTROL THE DC MOTOR DIRECTION
	DDRA_REG.BITS.BIT1 =LOW ;
	DDRA_REG.BITS.BIT2 =LOW;
	// WE SET PC0 , PC1 , PC2 AND PC3 TO BE OUTPUT PINS TO DISPLAY THE DC MOTOR SPEED LVL ON 7 SEGMENT
	DDRC_REG.data |=0X0f;
	PORTC_REG.data &=0Xf0;
	// SET PD0 AND PD1 TO BE OUTPUT PINS TO CONTROL THE DIRECTION OF DC MOTOR
	DDRD_REG.BITS.BIT0=HIGH;
	DDRD_REG.BITS.BIT1=HIGH;

	while(1)
	{
		if(PINA_REG.BITS.BIT0==HIGH)
		{
			PORTD_REG.BITS.BIT0 =HIGH;
			PORTD_REG.BITS.BIT1 =LOW;
		}
		else if(PINA_REG.BITS.BIT1==HIGH)
		{
			PORTD_REG.BITS.BIT1 =HIGH;
			PORTD_REG.BITS.BIT0 =LOW;
		}
		// this code will be implemented when the interrupt request happen.
		if(g_interrupt_flag==HIGH)
		{
			if(g_motorSpeedlvl==9)
			{
				g_motorSpeedlvl=0;
				PORTC_REG.data &=0XF0;
			}
			g_motorSpeedlvl++;
			OCR0=(255*g_motorSpeedlvl)/9;
			PORTC_REG.data = (PORTC_REG.data& 0XF0)|(g_motorSpeedlvl & 0X0F);
			g_interrupt_flag=LOW;
		}
	}
}

