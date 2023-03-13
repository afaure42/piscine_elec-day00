#include <avr/io.h>
#include <util/delay.h>

int main()
{
	//setting the port PB0 as ouput
	DDRB = 1 << PB0;

	//setting the pin PD2 as input
	DDRD = 0 << PD2;

	int last_pin_state = 0;

	while (1)
	{
		//if button was detected as not pushed and is now pushed
		if (last_pin_state == 0 && !(PIND & 1 << PD2))	
		{	
			//switching current led state
			PORTB ^= 1 << PB0;
			last_pin_state = 1;
			//delay to avoid rebound
			_delay_ms(10);
		}

		//if button was dected as pushed and now isnt pushed
		else if (last_pin_state == 1 && (PIND & 1 << PD2))
		{
			last_pin_state = 0;
			//delay to avoid rebound
			_delay_ms(10);
		}
	}
}
