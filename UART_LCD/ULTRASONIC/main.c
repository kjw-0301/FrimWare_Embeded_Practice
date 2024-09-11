#include "uts.h"
#include "us_lcd.h"

FILE OUTPUT = FDEV_SETUP_STREAM(UART0_Transmit, NULL,_FDEV_SETUP_WRITE);
void timerInit()	
{
	TCCR1B |= (1<<CS12) | (1<<CS10); //16비트 타이머 1번, 분주비 1024설정.
}
void triggerPin()
{
	PORTD &= ~(1<<PORTD1);
	_delay_us(1);
	PORTD |= (1<<PORTD1);
	_delay_us(10);
	PORTD &= ~(1<<PORTD1);
}
uint8_t meanDistance()
{
	TCNT1 = 0;
	while(!(PIND & 0x01))	//echo핀이 high가 될 때 까지 대기
	{
		if(TCNT1 > 65000)
		{
			return;
		}
	}
	TCNT1 = 0;
	while(PIND & 0x01)		//echo핀이 low가 될 때 까지 대기
	{
		if(TCNT1 > 65000)
		{
			TCNT1 = 0;
			break;
		}
	}
	double pulseWidth = 1000000.0 * TCNT1 * 1024 / 16000000;	//TCNT1의 값이 us단위,  거리 = 시간 * 속도(속도 : 340m/sec) 
																//1024 / 16000000는 분주.
	return pulseWidth / 58;
}
int main(void)
{
	
	uint8_t buff[30];
	uint8_t distance;
	stdout = &OUTPUT;
	LCD_Init();
	UART0_Init();
	sei();
	
	DDRD |= 0x02;
	DDRD &= 0xfe;
	timerInit();
	
    while (1) 
    {
		triggerPin();
		distance = meanDistance();
		sprintf(buff, "%-3dCm", distance);
		LCD_WriteStringXY(0,0,"Distance");
		LCD_WriteStringXY(1,0,buff);
		_delay_ms(1000);
    }
}

