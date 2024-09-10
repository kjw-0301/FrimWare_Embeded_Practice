//#define  F_CPU 16000000UL
//#include <avr/io.h>
//#include <util/delay.h>
//#include <stdio.h>
#include "lcd.h"

int main(void)
{
	LCDInit();
	LCD_GotoXY(0,0);
	LCD_WriteString("Hello AVR");
	LCD_GotoXY(1,0);
	LCD_WriteString("Good ATMega128A");
	/* Replace with your application code */
	while (1)
	{
	}
}

