#include "Dio.h"
#define PushButton0Port B
#define PushButton1Port D
#define PushButton2Port D

#define PushButton0Pin 0
#define PushButton1Pin 6
#define PushButton2Pin 2

void PushButton_Init(void);
void PushButton_Read(PortType port,uint8 PinNumber, PinStateType * PinState);
