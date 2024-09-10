//#define F_CPU 16000000UL
//#include <avr/io.h>
////#include <util/delay.h>
//#include <stdio.h>
#include ".h"

int main(void)
{
	LCD_GotoXY(0,0);
	LCD_WriteString("Hello AVR");
	LCD_GotoXY(1,0);
	LCD_WriteString("Good 4bit");
}