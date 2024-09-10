#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD |= (1<<DDRD5);
	PORTD &= ~(1<<PORTD5); //portd5를 low(0)으로 시작.
	TCCR0 |= (1<<CS02) | (1<<CS00); //분주비 128설정
	TCNT0 = 255 - 249;
	
    while (1) 
    {
		while((TIFR & 0x01)==0);

		//단순히 0~255까지 clock을 카운트하는 동작은 같지만 Timing도 처럼 보이려고 portd를 계속 반전시켜 
		//low일때 255까지 세고, 다시 high일때 255까지 카운트한다. 
		PORTD = ~PORTD; // = PORTD ^= (1<<PORTD5);
		TCNT0 = 6;
		TIFR = 0x01;
    }
}

