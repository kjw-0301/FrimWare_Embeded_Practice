#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB |= (1<<DDRB4);
	//TCCR0 = 0x1c 0001 1100;
	TCCR0 |= (1<<WGM01) | (1<<COM00) | (1<<CS02)|(1<<CS00);
	OCR0 = 249;
	
	//위코드는 TCCRx의 타이머/카운터 레지스터 제어의 관한 설정을 해준 것.
    while (1) 
    {
		//OCF0값이 0인지 아닌지 구분
		while((TIFR & 0x02) == 0);
		TIFR = 0x02;
		OCR0 = 249;
    }
}

