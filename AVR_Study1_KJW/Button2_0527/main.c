// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>
#include "Button2.h"

int main(void)
{
	LED_DDR = 0XFF;
	Button btnon;
	Button btnoff;
	Button btnTog;
	Button_Init(&btnon,&Button_DDR,&Button_PIN,Button_ON);
	Button_Init(&btnoff,&Button_DDR,&Button_PIN,Button_OFF);
	Button_Init(&btnTog,&Button_DDR,&Button_PIN,Button_Toggle);
    while (1) 
    {
		if(Button_getState(&btnon) == ACT_RELEASE)
		{
			LED_PORT = 0xff;
		}
		else if(Button_getState(&btnoff) == ACT_RELEASE)
		{
			LED_PORT = 0x00;
		}
		else if(Button_getState(&btnTog) == ACT_RELEASE)
		{
			LED_PORT ^= 0xff;//현재상태 반전
		}
    }
}

