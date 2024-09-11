#include "uart_interrupt.h"

//출력 스트림 <stdio.h> 표준
FILE OUTPUT = FDEV_SETUP_STREAM(UART0_Transmit, NULL, _FDEV_SETUP_WRITE);
char rxBuff[100] = {0}; //수신버퍼(초기화)
uint8_t rxFlag = 0;

ISR(USART0_RX_vect) //Rx 인터럽트 발생시 다음 ISR함수 호출
{
	static uint8_t rxHead = 0;	//수신된 데이터 인덱스
	uint8_t rxData = UDR0;
	
	if(rxData == '\n' || rxData == '\r')	//수신 데이터가 개행(\n), 리턴(\r) 
	{
		rxBuff[rxHead] = '\0'; //Null 추가
		rxHead = 0;
		rxFlag = 1;
	}
	else 
	{
		rxBuff[rxHead] = rxData; //한 비트씩 들어오기 때문에 rxHead라는 배열의 인덱스를통해서 rxBuff에 rxData저장.
		rxHead++;
	}
}


int main(void)
{
	UART0_Init();
	uint8_t rxData;
	stdout = &OUTPUT;
	sei();
	
    while (1) 
	{
		if(rxFlag == 1)
		{
			rxFlag = 0;
			printf(rxBuff);
		}
    }
}

