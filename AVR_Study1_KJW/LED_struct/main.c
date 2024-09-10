//#define F_CPU 16000000UL
//#include <avr/io.h>
#include <util/delay.h>
#include "led.h"


int main()
{
	//구조체 변수선언
	LED_S m_led;
	m_led.port = &PORTC;
	m_led.pinNumber = 0;
	
	//구조체 주소 초기화
	ledInit(&m_led);
	
    while (1) 
    {
		ledON(&m_led);
		_delay_ms(300);
		ledOFF(&m_led);
		_delay_ms(300);
		//m_led.pinNumber++;
		//if(m_led.pinNumber == 8)
		//{
			//m_led.pinNumber = 0;
		//}
    }
}

