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
 * v1.0		  05 may, 2024	     seif gendy	     	  Initial Creation
*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void MUSART1_voidInit(void)
{
    MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN9, GPIO_AF);  // Tx
    MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN10, GPIO_AF); // Rx

    MGPIO_voidSetAlternativeFunction(GPIO_PORTA, GPIO_PIN9, 7);
    MGPIO_voidSetAlternativeFunction(GPIO_PORTA, GPIO_PIN10, 7);

    USART1 -> CR1 = 0x200C;
    USART1 -> BRR = 0x341;
}

void MUSART1_voidSendDataSynchronous(u8 Copy_u8Data)
{
    USART1 -> DR = Copy_u8Data;
    while(GET_BIT(USART1 -> SR, 6) == 0);
    CLR_BIT(USART1 -> SR, 6);
}


void MUSART1_voidReceiveDataSynchronous(u8 * Copy_pu8ReceivedData)
{
    while(GET_BIT(USART1 -> SR, 5) == 0);
    *Copy_pu8ReceivedData = USART1 -> DR;
    CLR_BIT(USART1 -> SR, 5);
}
