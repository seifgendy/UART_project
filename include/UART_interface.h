/*****************************************************************************************
 * Author:				seif gendy
 * Creation Data:		05 may, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  05 may, 2024	   seif gendy   		  Initial Creation
*****************************************************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void MUSART1_voidInit(void);
void MUSART1_voidSendDataSynchronous(u8 Copy_u8Data);
void MUSART1_voidReceiveDataSynchronous(u8 * Copy_pu8ReceivedData);

#endif