#include "uart_interrupt.h"
//9600 BPS설정
//2배속 모드
//비동기, 8비트 데이터, 패리티비트 X , 스탑비트 1bit
void UART0_Init()
{
	UBRR0H = 0;
	UBRR0L = 207;			//9600bps
	
	//UCSRnC 레지스터 초기화 : 0000 0110
	UCSR0A |= (1<<U2X0);	//2배속
	UCSR0C |= 0x06;			//비동기, 8비트 데이터, 패리티비트 X , 스탑비트 1bit
	
	UCSR0B |= (1<<RXEN0);	//수신가능
	UCSR0B |= (1<<TXEN0);	//송신가능
	
	UCSR0B |= (1<<RXCIE0);	//수신 인터럽트 활성화
	
}
void UART0_Transmit(char data)
{
	while(!(UCSR0A &(1<<UDRE0))); //송신가능 하냐고 물음 UDRn레지스터가 비어있는지 확인.
	UDR0 = data;
}
unsigned UART0_Receive()
{
	while(!(UCSR0A &(1<<RXC0)));	//수신대기
	return UDR0;
}