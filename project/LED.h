#ifndef LED_H_
#define LED_H_
#include "Dio.h"
#define LED0Port C
#define LED1Port C
#define LED2Port D

#define LED0Pin 2
#define LED1Pin 7
#define LED2Pin 3
 
void LED_Init(void);
void LED_Write(PortType port,uint8 PinNumber,PinStateType PinState );




#endif /* LED_H_ */