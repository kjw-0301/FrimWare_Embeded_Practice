#include "uart0.h"

int main(void)
{
	LED_DDR = 0xff;
	UART0_Init();
	uint8_t led_data = 0;
	
    while (1) 
    {
		led_data = UART0_Receive();
		UART0_Transmit(led_data);
		if(led_data == '1')
		{
			LED_PORT = 0x80;
		}
		else if(led_data == '2')
		{
			LED_PORT = 0x00;	
		}
		
		
    }
}

