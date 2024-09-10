#include "LED.h"

//LED 초기화
void ledInit()
{
	LED_DDR = 0xFF; //출력방향 설정
}

void GPIO_Output(uint8_t data)
{
	LED_PORT = data;
}

void ledLeftShift(uint8_t *data)
{
	*data = (*data >> 7) | (*data << 1);
	GPIO_Output(*data);
}

void ledRightShift(uint8_t *data)
{
	*data = (*data << 7) | (*data >> 1);
	GPIO_Output(*data);
}
