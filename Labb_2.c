#1.1
char *p = 0x24;
*p |= (1 << 2);
p++;
*p |= (1 << 2);

#1.2
volatile char *bp = 0x21;
*bp &= ~(1 << 3);
bp--;
char read = *bp & (1 << 3);

#1.3
Hög spänning ska trigga en timer som väntar tills "studsandet" upphört.

#1.4

int button_read_reliably(){
	volatile char *p = PORTx;
	if((*p & (1 << Bx)) != 0){
		_delay_ms(2.5);
		return (*p & (1 << Bx));
	}
	return 0;
}



#2.1
UCSR |= (1 << RXEN) | (1 << TXEN);

#2.2
set_control(0b00001100);

#2.3
set_baud(16 000 000/(16*9600) - 1);

#2.4
unsigned char USART_Receive( void )
{
 /* Wait for data to be received */
 while ( !(UCSR0A & (1<<RXC)) )
 ;
 /* Get and return received data from buffer */
 return UDR0;
}


#2.5
void USART_Transmit( unsigned char data )
{
 /* Wait for empty transmit buffer */
 while ( !( UCSR0A & (1<<UDRE)) )
 ;
 /* Put data into buffer, sends the data */
 UDR0 = data;
}
	
	
#2.6
LED_protocol(){
	char HEADER = 0xFF;
	char TRAILER = 0xFE
	char[8] v = {0};
	char receive = USART_Receive();
	DDRB = 0x01;
	
	while(1){
		while(receive != HEADER){
			receive = USART_Receive();
		}	
		while(receive == HEADER){
			receive = USART_Receive();
		}
		uint8_t i = 0;
		while(receive != HEADER && receive != TRAILER && i <= 7){
			v[i] = receive;
			i++;
			receive = USART_Receive();
		}
		if(receive == TRAILER && i == 8){
			for(int a = 0; a <=7; a++){
				if (v[a] > 0){
					PORTB |= (1 << a);
				} else {
					PORTB &= ~(1 << a);
				}	
			}
		}
	}
}


#3.1
TCCR3A |= (1 << COM3A0) | (1 << WGM30); /*COM3A0 = 6. WGM31 = 0*/

#3.2
TCCR3B |= (1 << CS32) | (1 << CS30);

#3.3
DDRB |= (1 << PB6);

#4.1
ADCSRA |= (1 << ADEN);

#4.2
ADCSRA |= 0x07;

#4.3
ADMUX &= 0b11100000  //Single ended. Potentiometer 1

#4.4
ADMUX |= (1 << REFS0);

#4.5
ADCSRA |= (1 << ADSC);

#5.1
2.94 ms

#5.2
No prescaling

#5.3
141.7 mm
