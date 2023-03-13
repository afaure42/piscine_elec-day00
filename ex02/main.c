#include <avr/io.h>


void wait(unsigned long ms)
{

	//i am dividing by 2 because it looks like the loop takes 2 cycles
	for(unsigned long i = ((F_CPU / 1000) * ms) / 2;i; i--) {
		__asm__("nop");
	};
}

int main() {
	//setting PB0 as output ( true ) in the Direction register of port B
	DDRB |= 1 << PB0;

	//setting output to high in port B bit 0
	PORTB |= 1 << PB0;

	while (1)
	{
		// for (unsigned long i = 1000000; i > 0; i--)
		// {
		// 	//
		// }
		wait(500);

		//switching output bit of port PB0
		PORTB ^= (1 << PB0);
	}
}
