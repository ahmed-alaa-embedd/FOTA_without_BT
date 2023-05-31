/***************************/
/*Author : ahmed alaa	*/
/*date : 23/03/2023 		*/
/*version : v04			*/
/***************************/

//Lib
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//MCAL
#include "RCC_interface.h"
#include "GPIO_int.h"
#include "USART_interface.h"
#include "Esp_interface.h"


/************** APP functions ************/
void main(void){

	/* Initialize the RCC to HSE */
	RCC_voidInitSysClock();

	//	/* Enable the clock for all ports */
	RCC_voidEnableClock(RCC_APB2, 2);		// Enable clock for GPIOA
	RCC_voidEnableClock(RCC_APB2, 14);		/* Enable USART1 Clock */

	//	/* Configure pins for UART */
	/* Setting A9 is the TX pin as Output alternate function push pull w max speed 50 MHz */
	MGPIO_VoidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_50MHZ_AFPP);
	/* Setting A10 is the RX pin as input floating */
	MGPIO_VoidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);

	//Configure pins for System
	MGPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);	//DataLED
	MGPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);	//ErrorLED

	//Initialize UART
	MUSART1_voidInit();

	// it go through all but it never get OK at first it receive A then 255 (no data)
	// \n didn't transmit
	// check hardware
	/* Configure for WIFI */
	HEsp_voidInit();

	HEsp_voidConnectOnWifi("WE_9A2B93","k6m21723");

	HEsp_voidConnectOnServer("69.197.143.14");

	//GET http://ahmedarm.freevar.com/status.txt  =42 letter + enter & ctr(j) &enter=45
	//u8 Data =HEsp_voidSendData(45,"ahmedarm.freevar.com");
	u8 Data = HEsp_voidSendDataPOST(93,"ahmedarm.freevar.com","haaaa2.php",2,"ok");



	while(1)
	{
		if(Data!=250)
		{
			if (Data == 95)
					{
						MGPIO_VoidSetPinValue(GPIOA,PIN1,HIGH);
						MGPIO_VoidSetPinValue(GPIOA,PIN0,LOW);
						HEsp_voidConnectOnServer("69.197.143.14");
						Data = HEsp_voidSendDataPOST(93,"ahmedarm.freevar.com","haaaa2.php",2,"ok");
					}
			//didn't stop in last line
			else if (Data == 50)
					{
						MGPIO_VoidSetPinValue(GPIOA,PIN1,LOW);
						MGPIO_VoidSetPinValue(GPIOA,PIN0,HIGH);
						Data=250;
					}
			else
					{
						MGPIO_VoidSetPinValue(GPIOA,PIN0,LOW);
						MGPIO_VoidSetPinValue(GPIOA,PIN1,LOW);
						HEsp_voidConnectOnServer("69.197.143.14");
						Data = HEsp_voidSendDataPOST(93,"ahmedarm.freevar.com","haaaa2.php",2,"ok");
					}
		}



		/*if (Data == 1)
		{
			MGPIO_VoidSetPinValue(GPIOA,PIN1,HIGH);
			MGPIO_VoidSetPinValue(GPIOA,PIN0,LOW);
			HEsp_voidConnectOnServer("69.197.143.14");
			Data =HEsp_voidSendData(45,"ahmedarm.freevar.com");
		}
		else if (Data == 35)
		{
			MGPIO_VoidSetPinValue(GPIOA,PIN1,LOW);
			MGPIO_VoidSetPinValue(GPIOA,PIN0,LOW);
			HEsp_voidConnectOnServer("69.197.143.14");
			Data =HEsp_voidSendData(45,"ahmedarm.freevar.com");
		}
		else
		{
			MGPIO_VoidSetPinValue(GPIOA,PIN0,HIGH);
			HEsp_voidConnectOnServer("69.197.143.14");
			Data =HEsp_voidSendData(45,"ahmedarm.freevar.com");
		}*/
	}

}
