#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	uint8_t seg[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x27,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
	int count = 0; //int type은 ATmega128에서는 2byte 0 ~ 65535.
	DDRA = 0xff;
    while (1) 
    {
		PORTA = seg[count];
		count = (count + 1) % 16;
		_delay_ms(600);
// 		for(uint8_t i =0;i<16; i++)
// 		{
// 			PORTA = seg[i];
// 			_delay_ms(300);
// 		}
		
    }
}

