
#ifndef LED_H_
#define LED_H_

#include "common.h"

#define LED_DDR	DDRC
#define LED_PORT PORTC

//LED 초기화
void ledInit();
void GPIO_Output(uint8_t data);
void ledLeftShift(uint8_t *data);
void ledRightShift(uint8_t *data);


#endif /* LED_H_ */