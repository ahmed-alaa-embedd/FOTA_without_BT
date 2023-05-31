/***************************/
/*Author : ahmed alaa	*/
/*date : 30/9/2020 		*/
/*version : v01			*/
/***************************/

#ifndef Esp_INTERFACE_H
#define Esp_INTERFACE_H

#include "STD_TYPES.h"

void HEsp_voidInit();
void HEsp_voidConnectOnWifi(u8 *Copy_u8Name, u8 *Copy_u8Password); //AT+CWJAP_CUR="Name","Pass"
void HEsp_voidConnectOnServer(u8 *Copy_u8IP); //AT+CIPSTART="TCP","162.253.155.226",80

/*AT+CIPSEND=45
GET http://ahmedarm.freevar.com/status.txt
=43 letter + enter %ctr(j)=45
 * */
u8 HEsp_voidSendData(u8 Copy_u8DataSize,u8 *Copy_u8WebSite);
u8 HEsp_voidSendDataPOST(u8 Copy_u8DataSize,u8 *Copy_u8WebSite,u8 *file_name,u8 length,u8 *data);
u8 HEsp_u8CheckData(void);


#endif
