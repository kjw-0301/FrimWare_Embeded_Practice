/*
 * Button2.c
 *
 * Created: 2024-05-27 오전 11:39:24
 *  Author: minkyu
 */ 
#include "Button2.h"
void Button_Init(Button *button, volatile uint8_t *ddr_p, volatile uint8_t *pin_p, uint8_t pinNumber_p)
{
	button->ddr_s = ddr_p; //즉 주소값을 받아 주소값을 할당
	button->pin_s = pin_p;
	button->btnPin_s = pinNumber_p;
	button->prevState_s = RELEASED; //RELEASED  = 1
	*button->ddr_s &= ~(1<<button->btnPin_s);
}
uint8_t Button_getState(Button *button)
{
	uint8_t curState = *button->pin_s & (1<<button->btnPin_s);
	if((curState == PUSHED) && (button->prevState_s == RELEASED))
	{
		_delay_ms(50);
		button -> prevState_s = PUSHED;
		return ACT_PUSHED;
	}
	else if((curState != PUSHED) && (button->prevState_s ==PUSHED))
	{
		_delay_ms(50);
		button->prevState_s = RELEASED;
		return ACT_RELEASE;
	}
	return NO_ACT;
}
