//1.1
DDRC &= ~(1 << PORTC6) & ~(1 << PORTC7)

//1.2
int main(void){
uint8_t LIONS = 0;

	while(1){
		DTZ();
		ZTD();
	}
	return 0;
}

void DTZ(){ 																		//Den to wild zone (10 11 01)
	while((PINC & (1 << PORTC7)) > 0){
		while((PINC & (1 << PORTC7)) > 0 && (PINC & (1 << PORTC6)) > 0){
			while((PINC & (1 << PORTC7)) = 0 && (PINC & (1 << PORTC6)) > 0){
				if((PINC & (1 << PORTC7)) = 0 && (PINC & (1 << PORTC6)) = 0){
					LIONS++;
					return;
				}
			}
		}
	}
	return;
}
	
void ZTD(){ 																		//Wild zone to den (01 11 10)
	while((PINC & (1 << PORTC6)) > 0){
		while((PINC & (1 << PORTC7)) > 0 && (PINC & (1 << PORTC6)) > 0){
			while((PINC & (1 << PORTC7)) > 0 && (PINC & (1 << PORTC6)) = 0){
				if((PINC & (1 << PORTC7)) = 0 && (PINC & (1 << PORTC6)) = 0){
					LIONS--;
					return;
				}
			}
		}
	}
	return;
}


//2.1
PIN6 = PCINT22
PIN7 = PCINT23


//2.2
PCMSK2 |= (1 << PCINT22) | (1 << PCINT23);	//22 = bit 6, 23 = bit 7

//2.3
PCICR |= (1 << PCIE2);	//PCIE2 = bit 2

//2.4
UCSR0B |= (1 << RXCIE);	//RXCIE = bit 7