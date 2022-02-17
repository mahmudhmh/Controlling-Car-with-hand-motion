#include "ADC.h"
void Adc_Init(void) 
{
// 	DDRA &=~ (1<<PA1) ; // 1
// 	ADCSRA |= (1<<ADEN) ; // 2
// 	ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);
// 	SetBit(ADMUX,REFS0) ;
// 	ClearBit(ADMUX,REFS1);
// 	SetBit(ADMUX,MUX0);
// 	ADMUX &= ~ (1<<MUX1) & ~ (1<<MUX2) & ~ (1<<MUX3) & ~ (1<<MUX4);
	ADCSRA |= (1<<ADEN) ;
 	SetBit(ADMUX,REFS0) ;
 	ClearBit(ADMUX,REFS1);
	ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);
}

void Adc_ChannelInit(uint8 ADC_Channel)
{
	
			Dio_PinSetDirection(A,ADC_Channel,PinInput);
			ADMUX= (ADMUX & ~0x1F) | (ADC_Channel & 0x1F) ;
	
}
void Adc_ReadChannel(uint8 ADC_Channel , uint16* Adc_Data)
{
	ADCSRA |= (1<<ADSC) ;
	while (GetBit(ADCSRA,ADIF) == 0);
	*Adc_Data = ADCL ;
	*Adc_Data |= (uint16) (ADCH<<8) ;
}