#include "lcd.h"
int main(void)
{
	LCD_Init();
	LCD_GotoXY(0,0);
	LCD_WriteString("Hello AVR");
	LCD_GotoXY(1,0);
	LCD_WriteString("4bit Good");
}