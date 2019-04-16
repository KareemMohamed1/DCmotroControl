/*
 ============================================================================
 Name        : dioavrRegisters.h
 Author      : kareem mohamed
 Description : define the used registers addresses in AVR Micro-controller
 Date        : 14/4/2019
 ============================================================================
 */
#ifndef DIOAVRREGISTERS_H_
#define DIOAVRREGISTERS_H_
/*
 * define new type REG_8BIT TO ACCESS  the registers of avr simply
 */
typedef union {
	uint8 data;
	struct {
		uint8 BIT0 :1;
		uint8 BIT1 :1;
		uint8 BIT2 :1;
		uint8 BIT3 :1;
		uint8 BIT4 :1;
		uint8 BIT5 :1;
		uint8 BIT6 :1;
		uint8 BIT7 :1;
	}BITS;
}REG_8BIT;

/*
 *  define the registers of AVR
 */
#define PORTA_REG (*(volatile REG_8BIT *const)(0X003B))
#define DDRA_REG (*(volatile REG_8BIT *const)(0X003A))
#define PINA_REG (*(volatile const REG_8BIT *const)(0X0039))

#define PORTB_REG (*(volatile REG_8BIT *const)(0X0038))
#define DDRB_REG (*(volatile REG_8BIT *const)(0X0037))
#define PINB_REG (*(volatile const REG_8BIT *const)(0X0036))

#define PORTC_REG (*(volatile REG_8BIT *const)(0X0035))
#define DDRC_REG (*(volatile REG_8BIT *const)(0X0034))
#define PINC_REG (*(volatile const REG_8BIT *const)(0X0033))

#define PORTD_REG (*(volatile REG_8BIT *const)(0X0032))
#define DDRD_REG (*(volatile REG_8BIT *const)(0X0031))
#define PIND_REG (*(volatile const REG_8BIT *const)(0X0030))


#endif /* DIOAVRREGISTERS_H_ */
