#include <avr/io.h>


int main() {
	//setting PB0 as output ( true ) in the Direction register of port B
	DDRB |= 1 << PB0;

	//setting output to high in port B bit 0
	PORTB |= 1 << PB0;
}
