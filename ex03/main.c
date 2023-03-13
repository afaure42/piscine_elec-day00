#include <avr/io.h>
#include <util/delay.h>

int main()
{
	//setting PB0 as output pin
	DDRB = 1 << PB0;

	//setting PD2 as input pin ( could totally have done DDRD = 0)
	DDRD = 0 << PD2;

	while (1)
	{
		if (PIND & 1 << PD2)
			PORTB = 0;
		else
			PORTB = 1 << PB0;
		
		_delay_ms(2);
	}
}
