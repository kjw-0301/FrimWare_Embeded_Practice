#include "lcd.h"

void LCD_Data(uint8_t data)
{
	LCD_DATA_PORT = data; // 데이터 핀에 8비트 출력
}

void LCD_Data4bit(uint8_t data)
{
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) | (data & 0xf0); // 상위 4비트 출력
	LCD_EnablePin(); // LCD 동작 신호 전송
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) | ((data & 0x0f) << 4); // 하위 4비트 출력
	LCD_EnablePin(); // LCD 동작 신호 전송
}
void LCD_WritePin()
{	// LOW
	LCD_RW_PORT &= ~(1<<LCD_RW); // RW핀을 LOW -> 쓰기모드로 진입
}
void LCD_ReadPin()
{
	LCD_RW_PORT |= (1<<LCD_RW); // RW핀을 High -> 읽기 모드
}
void LCD_EnablePin()
{
	LCD_E_PORT &= ~(1<<LCD_E); // E핀을 Low로 설정
	LCD_E_PORT |= (1<<LCD_E); // E핀을 High로 설정 -> 동작 신호를 전송
	LCD_E_PORT &= ~(1<<LCD_E); // E핀을 Low로 설정
	_delay_us(1600);
}
void LCD_WriteCommand(uint8_t commandData)
{
	LCD_RS_PORT &= ~(1<<LCD_RS); // RS핀을 Low로 설정 -> 명령어모드 진입
	LCD_WritePin(); // 데이터 쓰기모드
	LCD_Data4bit(commandData); // 명령어를 데이터핀에 출력
	//LCD_EnablePin(); // LCD 동작신호 전송
}
void LCD_WriteData(uint8_t charData)
{
	LCD_RS_PORT |= (1<<LCD_RS); // RS핀을 High로 설정 -> 문자모드 진입
	LCD_WritePin(); // 데이터 쓰기모드
	LCD_Data4bit(charData); // 명령어를 데이터핀에 출력
	//LCD_EnablePin(); // LCD 동작신호 전송
}
void LCD_GotoXY(uint8_t row, uint8_t col)
{
	col %= 16;
	row %= 2;
	uint8_t address = (0x40 * row) + col; // 주소계산
	uint8_t command = 0x80 + address; // command 값 계산(주소 설정)
	LCD_WriteCommand(command); // 주소 command 전송
}
void LCD_WriteString(char *string)
{
	for (uint8_t i = 0; string[i]; i++)
	{
		LCD_WriteData(string[i]); // string Display
	}
}
void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string)
{
	LCD_GotoXY(row, col);
	LCD_WriteString(string);
}
void LCDInit()
{
	LCD_DATA_DDR = 0xff;
	LCD_RS_DDR |= (1<<LCD_RS);
	LCD_RW_DDR |= (1<<LCD_RW);
	LCD_E_DDR |= (1<<LCD_E);
	
	_delay_ms(20);
	LCD_WriteCommand(0x03);
	_delay_ms(5);
	LCD_WriteCommand(0x03);
	_delay_ms(5);
	LCD_WriteCommand(0x03);
	LCD_WriteCommand(0x02);
	LCD_WriteCommand(COMMAND_4_BIT_MODE);
	
	LCD_WriteCommand(COMMAND_DISPLAY_OFF);
	LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
	LCD_WriteCommand(COMMAND_DISPLAY_ON);
	LCD_WriteCommand(COMMAND_ENTRY_MODE);