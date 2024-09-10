#include "LED.h"

int main(void)
{
	ledInit();
	uint8_t ledData = 0x01;
	
    while (1) 
    {
		for (uint8_t i = 0; i < 7; i++)
		{
			ledLeftShift(&ledData);
			_delay_ms(300);
		}
		for (uint8_t i = 0; i < 7; i++)
		{
			ledRightShift(&ledData);
			_delay_ms(300);
		}
			
    }
}

