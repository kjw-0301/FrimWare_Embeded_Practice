#define F_CPU 16000000UL // 1600MHz >> 기준 클락.(중요)
#include <avr/io.h>
#include <util/delay.h>
// 위 3가지는 기본적으로 있어야 프로그램이 동작한다!

int main(void)
{
	DDRC = 0xff; //D포트 전체를 출력방향으로 설정 > 0xff = 0b11111111; / 0x01 = 0b00000001
    while (1) 
    {
		PORTC = 0xff; // 8비트 전체를 출력(High)
		_delay_ms(500); // 0.5초 동안 정지.
		PORTC = 0x00; //8비트 전체를 끔(Low)
		_delay_ms(500); // 0.5초 동안 정지.
	
    }
}

