#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR DDRC // LED bar 제어를 위한 방향설정
#define LED_PORT PORTC // LED bar 를 켜고 끄기 위한 포트 정의.
//코드의 최적화 및 간결화를 위해서 정의를 해주면 유지보수 및 관리하기 편함.

int main(void)
{
	LED_DDR = 0xff; //0b11111111 = 0xff; (방향설정 출력 or 입력)
    while (1) 
    {
		for(uint8_t i = 0; i < 3; i++)
		{
			LED_PORT = (0x01 << i) | (0x80 >> i);
			_delay_ms(200);
		}
		for(uint8_t j = 1; j < 4; j++)
		{
			LED_PORT = (0x08 << j) | (0x10 >>j);
			_delay_ms(200);
		}
			
		
			
			
		//for(uint8_t i = 0; i < 8; i++)
		//{
			//LED_PORT = 0x01 << i;
			//_delay_ms(200);
			//if(LED_PORT == 0x80)
			//{
				//for(uint8_t j = 0; j<8;j++)
				//{
					//LED_PORT = 0x80 >> j;
					//_delay_ms(200);
				//}
			//}
			//
		//}


		//for (uint8_t j = 7; j > 0; j--)
		//{
		//LED_PORT = 0x01 << j;
		//_delay_ms(200);
		//}

		
    }
}

