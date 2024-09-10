#include "lcd.h"


void LCD_Data(uint8_t data)
{
	LCD_DATA_PORT = data;
	
}
//void LCD_Data_4bit(uint8_t data);
void LCD_WritePin()
{
	LCD_RW_PORT &= ~(1<<LCD_RW);	//RW핀 Low ->
}
void LCD_ReadPin()
{
	LCD_RW_PORT |= (1<<LCD_RW);	//RW핀 High -> 읽기모드
}
void LCD_EnablePin()
{
	LCD_E_PORT &= ~(1<<LCD_E);	//Enable핀을 LOW로 설정
	LCD_E_PORT |= (1<<LCD_E);	//Enable핀을 High로 설정 -> 동작 신호를 전송
	LCD_E_PORT &= ~(1<<LCD_E);	//Enable핀을 LOW로 설정
	_delay_us(1600);
}
void LCD_WriteCommand(uint8_t commandData)
{
	LCD_RS_PORT &= ~(1<<LCD_RS); //RS핀 Low -> 명령어모드 전송
	LCD_WritePin();				 //데이터 쓰기모드
	LCD_Data(commandData);		 //명령어 데이터핀에 출력
	LCD_EnablePin();			 //LCD 동작신호 전송
}
void LCD_WriteData(uint8_t charData)
{
	LCD_RS_PORT |= (1<<LCD_RS);	//RS핀 High -> 텍스트모드 전송
	LCD_WritePin();
	LCD_Data(charData);
	LCD_EnablePin();
}
void LCD_GotoXY(uint8_t row, uint8_t col)
{
	col %= 16;
	row %= 2;
	uint8_t address = (0x40 * row) + col;	//주소계산
	uint8_t command = 0x80 + address;		//command 값 계산(주소설정)
	LCD_WriteCommand(command);				//주소 command 전송
}
void LCD_WriteString(char *string)
{
	for(uint8_t i = 0; string[i];i++)
	{
		LCD_WriteData(string[i]);		//string Display
	}

}
void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string)
{
	LCD_GotoXY(row,col);
	LCD_WriteString(string);
}
void LCDInit()
{
	LCD_DATA_DDR = 0xff;
	LCD_RS_DDR |= (1<<LCD_RS);
	LCD_RW_DDR |= (1<<LCD_RW);
	LCD_E_DDR |=(1<<LCD_E);
	
	_delay_ms(20);
	LCD_WriteCommand(COMMAND_8_BIT_MODE);
	_delay_ms(5);
	LCD_WriteCommand(COMMAND_8_BIT_MODE);
	_delay_ms(1);
	LCD_WriteCommand(COMMAND_8_BIT_MODE);
	LCD_WriteCommand(COMMAND_8_BIT_MODE);
	LCD_WriteCommand(COMMAND_DISPLAY_OFF);
	LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
	LCD_WriteCommand(COMMAND_DISPLAY_ON);
	LCD_WriteCommand(COMMAND_ENTRY_MODE);
}
