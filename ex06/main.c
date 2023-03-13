#include <avr/io.h>
#include <util/delay.h>

#define LEDS_SIZE 4
#define DELAY_MS 100

int main()
{
	uint8_t leds[] = {PB0, PB1, PB2, PB4};

	for (int i = 0; i < LEDS_SIZE; i++)
		DDRB |= 1 << leds[i];

	uint8_t i = 0;	
	while (1)
	{
		while (i < LEDS_SIZE)
		{
			PORTB = 1 << leds[i];
			_delay_ms(DELAY_MS);
			i++;
		}

		while (i)
		{
			i--;
			PORTB = 1 << leds[i];
			_delay_ms(DELAY_MS);
		}		
	}
	return (0);
}
