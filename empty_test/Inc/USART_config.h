/***************************/
/*Author : ahmed alaa	*/
/*date : 05/03/2023 	*/
/*version : v02			*/
/***************************/

#ifndef USART_CONFIG_H
#define USART_CONFIG_H

/* 

	Baud rate to be implemented 
	
	For 8MHz:-
	9600-> 52.083 :-
	F=1
	M=34
	
	115200-> 4.34 :-
	F=5
	M=4



*/

/*options:	R115200
 *			R9600 */

#define baud_rate R9600

/* Defining Macros */

#define USART_U8_8_BIT_WORD					0
#define USART_U8_9_BIT_WORD					1

#define USART_U8_PARITY_DISABLED			0
#define USART_U8_PARITY_ENABLED				1

#define USART_U8_EVEN_PARITY				0
#define USART_U8_ODD_PARITY					1

#define USART_U8_PE_DISABLED				0
#define USART_U8_PE_ENABLED					1


/*******************/
#define USART_PARITY_MODE	USART_PARITY_ENABLED
#define USART_PARITY_TYPE	USART_EVEN_PARITY



#endif
