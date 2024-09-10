#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0xff;
	
	DDRD &= ~(1<<0); //PORT의 0번핀, DDR을 0 으로 설정
	//PORTF |= (1<<0);
	//SFIOR |= (1<<2);
	
    while (1) 
    {
		if (PIND & (1 << 0)) 
		{
			//PORTC = 0x01;
			PORTC &= ~(1 << 3);
		}
		else
		{
			//PORTC = 0x80;
			PORTC |= (1 << 3);
		}
			
    }
}

