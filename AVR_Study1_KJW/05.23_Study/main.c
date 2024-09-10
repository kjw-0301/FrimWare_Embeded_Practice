#define F_CPU 16000000UL // 1600MHz >> ���� Ŭ��.(�߿�)
#include <avr/io.h>
#include <util/delay.h>
// �� 3������ �⺻������ �־�� ���α׷��� �����Ѵ�!

int main(void)
{
	DDRC = 0xff; //D��Ʈ ��ü�� ��¹������� ���� > 0xff = 0b11111111; / 0x01 = 0b00000001
    while (1) 
    {
		PORTC = 0xff; // 8��Ʈ ��ü�� ���(High)
		_delay_ms(500); // 0.5�� ���� ����.
		PORTC = 0x00; //8��Ʈ ��ü�� ��(Low)
		_delay_ms(500); // 0.5�� ���� ����.
	
    }
}

