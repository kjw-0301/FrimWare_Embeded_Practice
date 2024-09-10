#ifndef LED_H_
#define LED_H_

#include <avr/io.h>

#define LED_DDR DDRC
#define LED_PORT PORTC

typedef struct
{
	volatile uint8_t *port; //LED 연결 포트
	uint8_t pinNumber;		//LED 연결 핀 번호
	}LED_S;
	
void ledInit(LED_S *led);
void ledON(LED_S *led);
void ledOFF(LED_S *led);

#endif /* LED_H_ */