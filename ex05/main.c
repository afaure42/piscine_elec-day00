#include <avr/io.h>
#include <util/delay.h>

void switch_and_wait(uint8_t *state)
{
	*state ^= 1;
	_delay_ms(10);
}

int main()
{
	//setting ports PB0,1,2,4 as outputs
	DDRB = 1 << PB0 | 1 << PB1 | 1 << PB2 | 1 << PB4;


	//setting pin PD2 and PD4 as inputs
	DDRD = 0;

	uint8_t counter = 0;
	uint8_t switch1_state = 0;
	uint8_t switch2_state = 0;
	while (1)
	{

		if (switch1_state == 1 && PIND & 1 << PD2)
			switch_and_wait(&switch1_state);

		if (switch2_state == 1 && PIND & 1 << PD4)
			switch_and_wait(&switch2_state);

		if (switch1_state == 0 && !(PIND & 1 << PD2))
		{	
			counter++;
			switch_and_wait(&switch1_state);
		}

		if (switch2_state == 0 && !(PIND & 1 << PD4))
		{
			counter--;
			switch_and_wait(&switch2_state);
		}

		//assigning bit 1-2-3 to ports 0-1-2
		PORTB = (counter & 0b00000111) << PB0;

		//assigning bit 4 to port 4 becuase 3 isnt available
		PORTB |= ((counter & 1 << 3) >> 3 )<< PB4;
	}
}
