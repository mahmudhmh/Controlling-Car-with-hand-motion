#ifndef LCD_H_
#define LCD_H_
#define F_CPU 16000000UL
#include "Dio.h"
#include <avr/io.h>
#include <util/delay.h>
#define LCDC_Port B // B1,B2,B3
#define LCD_RS 1
#define LCD_RW 2
#define LCD_E 3
#define LCDC_Mask 0x0E //ctrl 

#define LCDD_Port A  //A4 ---> A7
#define LCD_Mask 0xF0 // data
#define LCD_Align 4


void LCD_Init(void);
void LCD_Command(uint8 command);
void LCD_Data(uint8 Data);
void LCD_Enable(void);
void LCD_DataString(uint8* DataString);
void LCD_Postion(uint8 Row , uint8 Column );
#endif /* LCD_H_ */