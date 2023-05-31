/***************************/
/*Author : ahmed alaa	*/
/*date : 05/03/2023 		*/
/*version : v03			*/
/***************************/


#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR[3];
	volatile u32 GTPR;
}USART_Register;


#define 	USART1 		((volatile USART_Register *) 0x40013800)

#define R115200					1
#define R9600					2

/****--------UART--------*****/
#define USART_PARITY_ENABLED	1
#define USART_PARITY_DISABLED	0
#define USART_EVEN_PARITY		0
#define USART_ODD_PARITY		1


#endif
