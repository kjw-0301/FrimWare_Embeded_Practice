#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRC = 0xff;
	DDRD &= ~(1<<DDRD0) |~(1<<DDRD1)|~(1<<DDRD2) ;
	
	uint8_t ledData = 0x01;
	uint8_t buttonData; //버튼 입력 받은 변수 설정
	int flag = 0;		//atmega128에서는 int가 2byte
	PORTC = 0x00;
    while (1) 
    {
		buttonData = PIND;
		if((buttonData &(1<<0))==0)
		{
			PORTC = ledData;
			ledData = (ledData >> 7) | (ledData << 1);
			_delay_ms(300);
		}
		else if((buttonData &(1<<1))==0)
		{
			PORTC = ledData;
			ledData = (ledData >> 1) | (ledData << 6);
			_delay_ms(300);
		}
		else if(flag == 0)
		{
			if((buttonData & (1<<2)) == 0)
			{
				flag = 1;
			}
			else
			{
				flag = 0;
			}
		}
		else if(flag == 1)
		{
			for(uint8_t i = 0; i < 5; i++)
			{
				PORTC = 0xff;
				_delay_ms(200);
				PORTC = 0x00;
				_delay_ms(200);
			}
			flag = 0;
			
		}
    }
}

