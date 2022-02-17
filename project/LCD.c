#include "LCD.h"

void LCD_Init(void)
{
	Dio_GroupSetDirection(LCDC_Port,LCDC_Mask,LCDC_Mask); //output ctrl kolo b 1	
	Dio_GroupSetDirection(LCDD_Port,LCD_Mask,LCD_Mask); // output data kolo b 1
	LCD_Command(0x33);
	LCD_Command(0x32);
	LCD_Command(0x28);
	LCD_Command(0x0C);
	LCD_Command(0x06);
	LCD_Command(0x01);
}
void LCD_Command(uint8 command)
{
	Dio_PinWrite(LCDC_Port,LCD_RS,PinLow); // set rs b 0 ya3ny low
	uint8 SendValue = (command & LCD_Mask) | (PORTA & ~LCD_Mask);  // bhafez 3la el value bta3t port A 
	Dio_PortWrite(LCDD_Port,SendValue) ; //btktb f port a
	LCD_Enable();
	SendValue = (command<<4 ) |  (PORTA & ~LCD_Mask); //btgeb tany rakm f el hex
	Dio_PortWrite(LCDD_Port,SendValue) ; // btktb tany f port a
	LCD_Enable(); 
}
void LCD_Data(uint8 Data) //btt3aml b el data elly f el RS
{
	Dio_PinWrite(LCDC_Port,LCD_RS,PinHigh);
	uint8 SendValue = (Data & LCD_Mask) | (PORTA & ~LCD_Mask);
	Dio_PortWrite(LCDD_Port,SendValue) ;
	LCD_Enable();
	SendValue = (Data<<4 ) |  (PORTA & ~LCD_Mask);
	Dio_PortWrite(LCDD_Port,SendValue) ;
	LCD_Enable();
}	
void LCD_Enable(void) // btakhod el data elly 3ala el port 3n tare2 badeha high to low
{
	Dio_PinWrite(LCDC_Port,LCD_E,PinHigh); 
	_delay_ms(10);
	Dio_PinWrite(LCDC_Port,LCD_E,PinLow);
}
void LCD_DataString(uint8* DataString)
{
	while (*DataString)
	{
		LCD_Data(*DataString++); //hyo2af 3la el /0 l7d ma yla2y el null
	}
}
void LCD_Postion(uint8 Row , uint8 Column )
{
		
	uint8 Position = 0;
	//Row 1 begin from 0x80 to 0x8f
	//Row 2 begin from 0xC0 to 0xCf

	switch (Row)
	{
		case 0x01:
		Position = 0x80+ Column-1 ;
		break;
		case 0x02:
		Position = 0xC0+ Column-1 ;
		break;
		default:
		Position = 0x80 ;
		break;
	}
	LCD_Command(Position);

}
