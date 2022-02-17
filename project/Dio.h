#ifndef DIO_H_
#define DIO_H_

#include "STD_Types.h"
#include "Bitwise.h"

typedef enum{A,B,C,D}PortType;
typedef enum{PinInput,PinOutput}PinDirectionType;
typedef enum{PinLow,PinHigh}PinStateType;
typedef enum{Deactive,Active}PullupStateType;
	
ReturnValueType Dio_PortSetDirection (PortType port,uint8 DirectionValue);
ReturnValueType Dio_PinSetDirection (PortType port , uint8 PinNumber,PinDirectionType PinDirection);
ReturnValueType Dio_GroupSetDirection(PortType port,uint8 GroupMask, uint8 GroupDirection);
ReturnValueType Dio_PortFlipDirection(PortType port);
ReturnValueType Dio_PinFlipDirection(PortType port,uint8 PinNumber);
ReturnValueType Dio_GroupFlipDirection(PortType port,uint8 GroupMask);

ReturnValueType Dio_PortWrite(PortType port,uint8 WriteValue);
ReturnValueType Dio_PinWrite(PortType port,uint8 PinNumber ,PinStateType PinState );
ReturnValueType Dio_GroupWrite(PortType port , uint8 GroupMask, uint8 WriteValue );
ReturnValueType Dio_PortFlip(PortType port);
ReturnValueType Dio_PinFlip(PortType port,uint8 PinNumber);
ReturnValueType Dio_GroupFlip(PortType port , uint8 GroupMask);

ReturnValueType Dio_PortRead(PortType port, uint8 * ReadValuePtr);
ReturnValueType Dio_PinRead (PortType port , uint8 PinNumber,PinStateType* PinState);
ReturnValueType Dio_GroupRead(PortType port , uint8 GroupMask ,uint8 * ReadValuePtr);

ReturnValueType Dio_PortPullupState (PortType port ,uint8 PullupState );
ReturnValueType Dio_PinPullupState (PortType port ,uint8 PinNumber ,PullupStateType PullupState);
ReturnValueType Dio_GroupPullupState (PortType port , uint8 GroupMask, uint8 PullupState);
ReturnValueType Dio_PortPullupStateFlip(PortType port );
ReturnValueType Dio_PinPullupStateFlip(PortType port,uint8 PinNumber );
ReturnValueType Dio_GroupPullupStateFlip (PortType port , uint8 GroupMask);

#endif /* DIO_H_ */