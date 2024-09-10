#include "i2c_LCD.h"
uint8_t I2C_LCD_Data;

void LCD_Data4bit(uint8_t data)
{
	I2C_LCD_Data = (I2C_LCD_Data & 0x0f) | (data & 0xf0);			// 상위 4비트 출력
	LCD_EnablePin();												// LCD 동작 신호 전송
	I2C_LCD_Data = (I2C_LCD_Data & 0x0f) | ((data & 0x0f) << 4);	// 하위 4비트 출력
	LCD_EnablePin();												// LCD 동작 신호 전송
}
void LCD_EnablePin()
{
	//Enable Low
	I2C_LCD_Data &= ~(1<<LCD_E);
	I2C_TxByte(LCD_DEV_ADDR,I2C_LCD_Data);
	//Enable High
	I2C_LCD_Data |= (1<<LCD_E);
	I2C_TxByte(LCD_DEV_ADDR,I2C_LCD_Data);
	//Enable Low
	I2C_LCD_Data &= ~(1<<LCD_E);
	I2C_TxByte(LCD_DEV_ADDR,I2C_LCD_Data);
	
	_delay_us(1600);
}
void LCD_WriteCommand(uint8_t commadData)
{
	I2C_LCD_Data &= ~(1<<LCD_RS);
	I2C_LCD_Data &= ~(1<<LCD_RW);
	LCD_Data4bit(commadData);
}
void LCD_WriteData(uint8_t charData)
{
	I2C_LCD_Data |= (1<<LCD_RS);
	I2C_LCD_Data &= ~(1<<LCD_RW);
	LCD_Data4bit(charData);
}
void LCD_BackLightOn()
{
	I2C_LCD_Data |= (1<<LCD_BACKLIGHT);
	I2C_TxByte(LCD_DEV_ADDR,I2C_LCD_Data);
}
void LCD_GotoXY(uint8_t row, uint8_t col)
{
	col %= 16;		// 열 인덱스를 0부터 15까지로 제한 (16개의 열)
	row %= 2;		// 행 인덱스를 0 또는 1로 제한 (2개의 행)

	uint8_t address = (0x40 * row) + col;		// 주소 계산
	uint8_t command = 0x80 + address;			// 커맨드 값 계산 (주소 설정)
	LCD_WriteCommand(command);					// 주소 설정 커맨드를 LCD에 전송
}
void LCD_WriteString(char *string)
{
	for (uint8_t i=0; string[i]; i++)
	{
		LCD_WriteData(string[i]);		// 문자열의 각 문자를 LCD에 출력
	}
}
void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string)
{
	LCD_GotoXY(row, col);		// 지정된 위치로 커서 이동
	LCD_WriteString(string);	// 문자열을 해당 위치부터 LCD에 출력
}
void LCD_Init()
{
	I2C_Init();
	
	_delay_ms(20);								// 초기화 대기 시간 (충분한 대기 시간 필요)
	LCD_WriteCommand(0x03);						// 4비트 모드 설정
	_delay_ms(5);								// 초기화 대기 시간
	LCD_WriteCommand(0x03);						// 4비트 모드 설정
	_delay_ms(5);								// 초기화 대기 시간
	LCD_WriteCommand(0x03);						// 4비트 모드 설정
	
	LCD_WriteCommand(0x02);						// 4비트 모드 설정
	LCD_WriteCommand(COMMAND_4_BIT_MODE);						// 4비트 모드 설정
	
	LCD_WriteCommand(COMMAND_DISPLAY_OFF);		// 화면 OFF
	LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);	// 화면 지우기
	LCD_WriteCommand(COMMAND_DISPLAY_ON);		// 화면 ON
	LCD_WriteCommand(COMMAND_ENTRY_MODE);		// 입력 모드 설정
	LCD_BackLightOn();
}