 #define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB |= (1<<DDRB4);
	TCCR0 |= (1<<WGM01) | (1<<WGM00) | (1<<COM01) |(1<<CS02);
	//OCR0 = 64;
    while (1) 
    {
		for(uint8_t i = 0;i<255; i++)
		{
			OCR0 = i;
			_delay_ms(10);
		}
    }
}

