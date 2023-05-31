///***************************/
///*Author : ahmed alaa	*/
///*date : 23/3/2023 		*/
///*version : v04			*/
///***************************/

//Liberary
#include <stdio.h>
#include <string.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"


#include "Esp_config.h"
#include "Esp_interface.h"
#include "Esp_private.h"


#include "USART_interface.h"

u8 Quotes	[]= "\""	;
u8 Comma 	[]	 = {","};

void HEsp_voidInit()
{
	u8 Local_u8Result =0;

	//check for ok
	while(Local_u8Result == 0)
	{
		//Echo disable
		MUSART1_voidTransmit("ATE0\r\n");
		//if recieve OK then break while loop
		Local_u8Result = u8EspValidateCmd(ECHO_TIMEOUT,1);

	}

	Local_u8Result =0;

	//check for ok
	while(Local_u8Result== 0)
	{
		//set station mode
		MUSART1_voidTransmit("AT+CWMODE=1\r\n");
		//if recieve OK then break while loop
		Local_u8Result = u8EspValidateCmd(MODE_TIMEOUT,11);
	}

}
void HEsp_voidConnectOnWifi(u8 *Copy_u8Name, u8 *Copy_u8Password)	//AT+CWJAP_CUR="Name","Pass"
{
	u8 Local_u8Result = 0;
	u8 Local_u8Data[100] = {0};

	sprintf(Local_u8Data,"AT+CWJAP_CUR=%s%s%s,%s%s%s\r\n",Quotes,Copy_u8Name,Quotes,Quotes,Copy_u8Password,Quotes);


	//check for ok
	while(Local_u8Result== 0)
	{
		//send Name and pass
		MUSART1_voidTransmit(Local_u8Data);
		//if recieve OK then break while loop
		Local_u8Result = u8EspValidateCmd(ROUTER_TIMEOUT,2);
	}


}
void HEsp_voidConnectOnServer(u8 *Copy_u8IP)//AT+CIPSTART="TCP","162.253.155.226",80
{
	u8 Local_u8Result = 0;
	u8 Local_u8Data[100] = {0};

	sprintf(Local_u8Data,"AT+CIPSTART=%sTCP%s,%s%s%s,80\r\n",Quotes,Quotes,Quotes,Copy_u8IP,Quotes);


	//check for ok
	while(Local_u8Result== 0)
	{
		//send IP
		MUSART1_voidTransmit(Local_u8Data);
		//if recieve OK then break while loop
		Local_u8Result = u8EspValidateCmd(SERVER_TIMEOUT,3);
	}


}

u8 HEsp_voidSendDataPOST(u8 Copy_u8DataSize,u8 *Copy_u8WebSite,u8 *file_name,u8 length,u8 *data)
{
	x:;
	u8 Local_u8Result = 0;
	u8 Local_u8Data[100] = {0};

	sprintf(Local_u8Data,"AT+CIPSEND=%d\r\n",Copy_u8DataSize);


	//check for ok

		//send data size
		MUSART1_voidTransmit(Local_u8Data);
		//if recieve OK then break while loop
		Local_u8Result = u8EspValidateCmd(PREREQUEST_TIMEOUT,4);
		if(Local_u8Result== 0)
				{
					HEsp_voidConnectOnServer("69.197.143.14");
					goto x;
				}


	//delete saved data to write a new one
	for(int i=0;i<98;i++)
	{
		Local_u8Data[i]=0;
	}

/*	AT+CIPSEND=93
	POST /haaaa2.php HTTP/1.1
	Host: ahmedarm.freevar.com
	Content-Length: 2

	ok
	AT+CIPCLOSE*/
	//send to website
	sprintf(Local_u8Data,"POST /%s HTTP/1.1\r\nHost: %s\r\nContent-Length: %d\r\n\r\n%s\r\nAT+CIPCLOSE\r\n",file_name,Copy_u8WebSite,length,data);
	Local_u8Result=0;

	//check for ok

		//send data size
		MUSART1_voidTransmit(Local_u8Data);
		//if recieve OK then break while loop
		Local_u8Result = u8EspValidateCmd(REQUEST_TIMEOUT,44);
		if(Local_u8Result== 0)
		{
			HEsp_voidConnectOnServer("69.197.143.14");
			goto x;
		}
	return Local_u8Result;
}

/*AT+CIPSEND=45
GET http://ahmedarm.freevar.com/status.txt
=43 letter + enter %ctr(j)=44
* */
u8 HEsp_voidSendData(u8 Copy_u8DataSize,u8 *Copy_u8WebSite)
{
	u8 Local_u8Result = 0;
	u8 Local_u8Data[100] = {0};

	sprintf(Local_u8Data,"AT+CIPSEND=%d\r\n",Copy_u8DataSize);


	//check for ok
	while(Local_u8Result== 0)
	{
		//send data size
		MUSART1_voidTransmit(Local_u8Data);
		//if recieve OK then break while loop
		Local_u8Result = u8EspValidateCmd(PREREQUEST_TIMEOUT,5);
	}


	//delete saved data to write a new one
	for(int i=0;i<80;i++)
	{
		Local_u8Data[i]=0;
	}

	//send website
	sprintf(Local_u8Data,"GET http://%s/status.txt\r\n\r",Copy_u8WebSite);
	Local_u8Result=0;

	//check for ok
	while(Local_u8Result== 0)
	{
		//send data size
		MUSART1_voidTransmit(Local_u8Data);
		//if recieve OK then break while loop
		Local_u8Result = u8EspValidateCmd(REQUEST_TIMEOUT,55);
	}
	return Local_u8Result;
}


u8 u8EspValidateCmd(u32 Copy_u32timeout,u8 iteration) //private func
{
	// any delay between trans & recieve will lead to frame lost or package lost
	u8  static volatile Local_u8Response[1000] ={0};
	u16 i=0;
	u8 Local_u8Dummy = 0;
	u8 Local_u8Result = 0;

	while(Local_u8Dummy != 255)
	{
		Local_u8Dummy=MUSART1_u8Receive(Copy_u32timeout);
		Local_u8Response[i] = Local_u8Dummy;
		i++;
	}

	//check for ok
	for(i=0;i<50;i++)
	{
		if(Local_u8Response[i] == 'O' && Local_u8Response[i+1] == 'K' )
		{
			Local_u8Result = i;
			break;
		}
		//add check for error on putty
		else if(Local_u8Response[i] == '>')
		{
			Local_u8Result = 95;
			break;
		}
		else
		{
			Local_u8Result = 0;
		}

	}
	if(iteration==44)
		{
			for(i=0;i<999;i++)
			{
				if(Local_u8Response[i] == 'S' && Local_u8Response[i+1] == 'e'&& Local_u8Response[i+2] == 'n'&& Local_u8Response[i+3] == 't')
				{
					if(Local_u8Response[i+11] == ':')
					{
						if(Local_u8Response[i+12] == '0' && Local_u8Response[i+13] == '0'&& Local_u8Response[i+19] == '1'&& Local_u8Response[i+20] == 'F'&& Local_u8Response[i+21] == 'F')
						{
							Local_u8Result = 50;
							break;
						}
						Local_u8Result = 95;
						break;
					}
					else
					{
						Local_u8Result = 44;
						break;
					}

				}
				else
				{
					Local_u8Result = 0;
				}
			}

		}
//	else if(iteration==5 ||iteration==55 )
//	{
//		for(i=0;i<99;i++)
//		{
//			if(Local_u8Response[i] == '+' && Local_u8Response[i+1] == 'I' )
//			{
//				if(Local_u8Response[i+7] == '1')
//				{
//					Local_u8Result = 1;
//					break;
//				}
//				else if(Local_u8Response[i+7] == '0')
//				{
//					Local_u8Result = 35;
//					break;
//				}
//
//			}
//			else
//			{
//				Local_u8Result = 0;
//			}
//		}
//
//	}
	//delete saved data to write a new one
	for(int i=0;i<999;i++)
	{
		Local_u8Response[i]=0;
	}
	return Local_u8Result;
}

