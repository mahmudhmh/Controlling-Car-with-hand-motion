#include "PushButton.h"
void PushButton_Init(void)
{
	Dio_PinSetDirection(PushButton0Port,PushButton0Pin,PinInput);
	Dio_PinSetDirection(PushButton1Port,PushButton1Pin,PinInput);
	Dio_PinSetDirection(PushButton2Port,PushButton2Pin,PinInput);
}
void PushButton_Read(PortType port,uint8 PinNumber, PinStateType * PinState)
{
	Dio_PinRead(port,PinNumber,PinState);
}
