#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

uint8_t ledArr[]=
{
	0x81,
	0x42,
	0x24,
	0x18,
	0x24,
	0x42,
	//0x81
};
int main(void)
{
	DDRC = 0XFF; //DDRC 방향을 출력으로 설정
    while (1) 
    {
		for(uint8_t i = 0; i < 6;i++)
		{
			PORTC = ledArr[i];
			_delay_ms(300);
		}
    }
}

