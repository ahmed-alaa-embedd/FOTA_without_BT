/***************************/
/*Author : ahmed alaa	*/
/*date : 23/3/2023 		*/
/*version : v04			*/
/***************************/
// nmt s7et mfe4 7aga 48ala 7ta dah kman m4 48al m3 en v4 w kman dah kano 48alen
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"


void MUSART1_voidInit(void)
{
	/*	baud rate = 115200		*/
	USART1 -> BRR = 0x45;

	SET_BIT((USART1-> CR[0]), 3);			/* Enabling Transmitter */
	SET_BIT((USART1-> CR[0]), 2);			/* Enabling Receiver */
	SET_BIT((USART1-> CR[0]), 13);			/* Enabling USART */

	USART1 -> SR = 0;						/* Clearing status register */
}

void MUSART1_voidTransmit(u8 arr[])
{
	u8 i = 0;
	while(arr[i] != '\0'){
		USART1 -> DR = arr[i];
		while((GET_BIT((USART1 -> SR), 6)) == 0);
		i++;
	}

}

u8 MUSART1_u8Receive(u32 Copy_u32timeout)
{
	u32 timeOut=0;

			u8 Loc_u8ReceivedData = 0;
			while((GET_BIT((USART1 -> SR), 5)) == 0)
			{
				timeOut++;
				if(timeOut==Copy_u32timeout)
				{
					Loc_u8ReceivedData = 255; //this var will not reach 255 as max value in ASCII table is 128
					break;
				}
			}

				/* If no Errors */
				if( Loc_u8ReceivedData == 0 )
				{
					return USART1 -> DR;
				}
				/* If Error Occurs */
				else
				{

					return Loc_u8ReceivedData;
				}

}

