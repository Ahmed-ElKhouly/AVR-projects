/*
 * Memmap.h
 *
 *  Created on: Aug 31, 2019
 *      Author: Ahmed ElSayed ElKhouly
 */

#define PORTA (*(volatile uint8*)(0x3B))
#define DDRA (*(volatile uint8*)(0x3A))
#define PINA (*(volatile uint8*)(0x39))

#define PORTB (*(volatile uint8*)(0x38))
#define DDRB (*(volatile uint8*)(0x37))
#define PINB (*(volatile uint8*)(0x36))

#define PORTC (*(volatile uint8*)(0x35))
#define DDRC (*(volatile uint8*)(0x34))
#define PINC (*(volatile uint8*)(0x33))

#define PORTD (*(volatile uint8*)(0x32))
#define DDRD (*(volatile uint8*)(0x31))
#define PIND (*(volatile uint8*)(0x30))

#define ADMUX (*(volatile uint8*)(0x27))
#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define MUX4 4
#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define ADCSRA (*(volatile uint8*)(0x26))
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE 3
#define ADIF 4
#define ADATE 5
#define ADSC 6
#define ADEN 7

#define ADCH (*(volatile uint8*)(0x25))

#define ADCL (*(volatile uint8*)(0x24))

#define SFIOR (*(volatile uint8*)(0x50))
#define PSR10 0
#define PSR2 1
#define PUD 2
#define ACME 3
#define ADTS0 5
#define ADTS1 6
#define ADTS2 7

#define TCCR0 (*(volatile uint8*)(0x53))
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0 7

#define TCNT0 (*(volatile uint8*)(0x52))

#define OCR0 (*(volatile uint8*)(0x5C))

#define TIMSK (*(volatile uint8*)(0x59))
#define TOIE0 0
#define OCIE0 1
#define TOIE1 2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5
#define TOIE2 6
#define OCIE2 7

#define TIFR (*(volatile uint8*)(0x58))
#define TOV0 0
#define OCF0 1
#define TOV1 2
#define OCF1B 3
#define OCF1A 4
#define ICF1 5
#define TOV2 6
#define OCF2 7

#define UDR (*(volatile uint8*)(0x2C))

#define UCSRA (*(volatile uint8*)(0x2B))
#define MPCM 0
#define U2X 1
#define PE 2
#define DOR 3
#define FE 4
#define UDRE 5
#define TXC 6
#define RXC 7

#define UCSRB (*(volatile uint8*)(0x2A))
#define TXB8 0
#define RXB8 1
#define UCSZ2 2
#define TXEN 3
#define RXEN 4
#define UDRIE 5
#define TXCIE 6
#define RXCIE 7

#define UCSRC (*(volatile uint8*)(0x40))
#define UCPOL 0
#define UCSZ0 1
#define UCSZ1 2
#define USBS 3
#define UPM0 4
#define UPM1 5
#define UMSEL 6
#define URSEL 7

#define UBRRL (*(volatile uint8*)(0x29))
