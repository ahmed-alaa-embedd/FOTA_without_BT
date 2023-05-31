/***************************/
/*Author : ahmed alaa	*/
/*date : 05/03/2023 		*/
/*version : v02			*/
/***************************/

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H



void MUSART1_voidInit(void);

//u8 MUSART1_u8Transmit(u8 arr[],u16 Copy_u32timeout);
void MUSART1_voidTransmit(u8 arr[]);

u8 MUSART1_u8Receive(u32 Copy_u32timeout);

#endif






