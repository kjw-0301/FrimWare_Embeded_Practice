#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define FND_DATA_DDR		DDRC
#define FND_SELECT_DDR		DDRG
#define FND_DATA_PORT		PORTC
#define	FND_SELECT_PORT		PORTG

void FND_Display(uint16_t data)
{
	static uint8_t position = 0;//Digit position 변수 설정 및 초기화
	uint8_t fndData[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x27,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
	
	switch(position)
	{
		
		case 0:
		//portg = [pg0 = 0,pg1 = 1,pg2 = 1,pg3 = 1]
		FND_SELECT_PORT &= ~(1<<0); //digit 1  = LOW
		FND_SELECT_PORT |= (1<<1) | (1<<2) | (1<<3); //digit 2,3,4 High.
		//입력된 데이터의 천의 자리를 구해서 fnd에 출력
		FND_DATA_PORT = fndData[data/1000];
		break;
		
		//portg = [pg0 = 1,pg1 = 0,pg2 = 1,pg3 = 1]
		case 1:
		FND_SELECT_PORT &= ~(1<<1); //digit 2 = Low
		FND_SELECT_PORT |= (1<<0) | (1<<2) | (1<<3); //digit = 1,3,4 High
		FND_DATA_PORT = fndData[data/100%10];
		break;
		
		//portg = [pg0 = 1,pg1 = 1,pg2 = 0,pg3 = 1]
		case 2:
		FND_SELECT_PORT &= ~(1<<2); //digit 3 = LOW
		FND_SELECT_PORT |= (1<<0) | (1<<1) | (1<<3); //digit 1,2,4 High
		FND_DATA_PORT = fndData[data/10%10];
		break;
		
		//portg = [pg0 = 1,pg1 = 1,pg2 = 1,pg3 = 0]
		case 3:
			FND_SELECT_PORT &= ~(1<<3);
			FND_SELECT_PORT |= (1<<0) | (1<<1) | (1<<2);
			FND_DATA_PORT = fndData[data%10];
		break;
	}
	position++;// 포지션 증가
	position = position % 4; //4자리숫자가 최대이니 4자리 수 이상으로 넘어가지 않기위함.
	
}

int main(void)
{
	
// 	DDRG = 0xff;
// 	uint8_t seg[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x27,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
// 	int count = 0; //int type은 ATmega128에서는 2byte 0 ~ 65535.
// 	DDRC = 0xff;
//     while (1) 
//     {
// 		PORTC = seg[count];
// 		count = (count + 1) % 16;
// 		_delay_ms(600);
//     }
	FND_DATA_DDR = 0xff;
	FND_SELECT_DDR = 0xff;
	FND_SELECT_PORT = 0x00; //초기값 설정
	
	uint16_t count = 0;
	uint32_t timeTick = 0;
	uint32_t prevTime = 0;
	
	while(1)
	{
		FND_Display(count);
		if(timeTick - prevTime > 100)
		{
			prevTime = timeTick;
			count++;
		}	
		_delay_ms(1);
		timeTick++;
	}
}

