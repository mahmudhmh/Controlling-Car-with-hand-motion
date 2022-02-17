#include "LED.h"
void LED_Init(void)
{
	Dio_PinSetDirection(LED0Port,LED0Pin,PinOutput);
	Dio_PinSetDirection(LED1Port,LED1Pin,PinOutput);
	Dio_PinSetDirection(LED2Port,LED2Pin,PinOutput);
}
void LED_Write(PortType port,uint8 PinNumber,PinStateType PinState )
{
	Dio_PinWrite(port,PinNumber,PinState);
}
