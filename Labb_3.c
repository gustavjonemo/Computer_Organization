//1.1
clock cycles = f * delay
16 000 000 * 0.1 = 1 600 000 st

//1.2
2^20 = 1 048 576
2^21 = 2 097 152
prescaler can be used to make it fit 16 bits

//1.3
3 st

//1.4
start;
	ldi r18, 400 000

	delay;
		dec r18
		cpi r18, 0
		brne delay
end;
	rjmp end


//1.5
#define DDRB 	0x04
#define PORTB 	0x05
#define LED2 	2

start;
	ldi r18, (1 << LED2)
	in r17, DDRB
	or r18, r17
	out DDRB, r18
	in r17, PORTB
	or r18, r17
	out PORTB , r18

end;
	rjmp end


//2.1
#define STACK_H 0x3E
#define STACK_L 0x3D
#define N_ALLOC 20

Start;
in r28, STACK_L ; Load low byte of stack pointer to r28
in r29, STACK_H ; Load high byte of stack pointer to r29
sbiw Y, N_ALLOC ; Subtract N from the loaded stack pointer
out STACK_L , r28 ;
out STACK_H , r29 ; Update stack pointer

end;
	rjmp end

//2.2
0x40DC

//3.1
subroutine;
.
.
. ret

man använder CALL subroutine

//3.2
Genom att lagra i register 8 - 25

//3.3
Sending 0: 19 (18.4)
Sending 1: 21 (20.8)
Sending reset: 800

