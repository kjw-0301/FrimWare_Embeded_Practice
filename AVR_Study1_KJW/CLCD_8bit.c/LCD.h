#ifdef LCD_H_
#define LCD_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>

#define LCD_DATA_DDR	DDRF
#define LCD_DATA_POT	PORTF
#define LCD_DATA_PIN	PINF
#define LCD_RS_DDR		DDRE
#define	LCD_RW_DDR		DDRE
#define LCD_E_DDR		DDRE
#define LCD_RS_PORT		PORTE
#define LCD_RW_PORT		PORTE
#define LCD_E_PORT		PORTE
#define LCD_RS			5
#define LCD_RW			6
#define LCD_E			7



#endif LCD_H_
