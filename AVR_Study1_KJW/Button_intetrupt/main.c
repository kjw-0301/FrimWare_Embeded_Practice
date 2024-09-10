#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(INT0_vect)
{
	for(uint8_t i = 0; i < 8; i++)
	{
		PORTC |= (1 <<i);
		_delay_ms(300);
	}
	//PORTC = 0xff;
}

int main(void)
{
	DDRC = 0xff; //PORTC를 출력으로 설정하기 위해 0xff 할당.
	sei();		 //전역 인터럽트 활성화? 
	EICRA |= (1<<ISC01) | (1<<ISC01);//INT0번 falling edge 사용
	EIMSK |= (1<<0);//INT0번 interrupt enable
	
	DDRD &= ~(1<<0); //입력받기위해 0x00으로 설정?? 이는 DDRD & = ~(1<<0)과 같다.
    while (1) 
    {
		PORTC = 0x00;
    }
}

