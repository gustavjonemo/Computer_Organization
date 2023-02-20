#define F_CPU 16000000UL
#include yoda.h

void main(){
	led_init();
	while(true){
		led_on(0);
		_delay_ms(500);
		led_off(0);
		_delay_ms(500);
	}
}