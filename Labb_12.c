#define F_CPU 16000000UL
#include yoda.h

void main(){
	led_init();
	button_init();
	
	while(button_read(1) == 1){
		led_toggle(0);
		_delay_ms(100);
	}
}