#ifndef BUTTON2_H_
#define BUTTON2_H_

//#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR			DDRA
#define LED_PORT		PORTA
#define Button_DDR		DDRD
#define Button_PIN		PIND
#define Button_ON		0
#define Button_OFF		1
#define Button_Toggle	2


enum {PUSHED, RELEASED};
enum {NO_ACT, ACT_PUSHED,ACT_RELEASE};

typedef struct _button
{
	volatile uint8_t *ddr_s;
	volatile uint8_t *pin_s;
	uint8_t btnPin_s;
	uint8_t prevState_s;
}Button;

void Button_Init(Button *button, volatile uint8_t *ddr_p, volatile uint8_t *pin_p, uint8_t pinNumber_p);
uint8_t Button_getState(Button *button);



#endif /* BUTTON2_H_ */