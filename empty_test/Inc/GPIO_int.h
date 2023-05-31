/***********************************/
/* Author : Ahmed Alaa			   */
/* Date : 12 8 2020			  	   */
/* version : V02 				   */
/***********************************/


#ifndef DIO_INIT_H
#define DIO_INIT_H



#define HIGH	1
#define LOW		0

#define GPIOA	0
#define GPIOB	1
#define GPIOC	2


#define	PIN0	0
#define	PIN1	1
#define	PIN2	2
#define	PIN3	3
#define	PIN4	4
#define	PIN5	5
#define	PIN6	6
#define	PIN7	7
#define	PIN8	8
#define	PIN9	9
#define	PIN10	10
#define	PIN11	11
#define	PIN12	12
#define	PIN13	13
#define	PIN14	14
#define	PIN15	15

#define INOUT_ANALOG		0b0000
#define INPUT_FLOATING		0b0100
#define INPUT_PULLUP_DOWN	0b1000

/*PIN MODE*/

#define OUTPUT_SPEED_10MHZ_PP	0b0001
#define OUTPUT_SPEED_10MHZ_OD	0b0101
#define OUTPUT_SPEED_10MHZ_AFPP	0b1001
#define OUTPUT_SPEED_10MHZ_AFOD	0b1101

#define OUTPUT_SPEED_2MHZ_PP	0b0010
#define OUTPUT_SPEED_2MHZ_OD	0b0110
#define OUTPUT_SPEED_2MHZ_AFPP	0b1010
#define OUTPUT_SPEED_2MHZ_AFOD	0b1110

#define OUTPUT_SPEED_50MHZ_PP	0b0011
#define OUTPUT_SPEED_50MHZ_OD	0b0111
#define OUTPUT_SPEED_50MHZ_AFPP	0b1011
#define OUTPUT_SPEED_50MHZ_AFOD	0b1111

/*PORT MODE*/

#define PORT_OUTPUT_SPEED_10MHZ_PP		0x11111111
#define PORT_OUTPUT_SPEED_10MHZ_OD		0x55555555
#define PORT_OUTPUT_SPEED_10MHZ_AFPP	0x99999999
#define PORT_OUTPUT_SPEED_10MHZ_AFOD	0xdddddddd

#define PORT_OUTPUT_SPEED_2MHZ_PP		0x22222222
#define PORT_OUTPUT_SPEED_2MHZ_OD		0x66666666
#define PORT_OUTPUT_SPEED_2MHZ_AFPP		0xaaaaaaaa
#define PORT_OUTPUT_SPEED_2MHZ_AFOD		0xeeeeeeee

#define PORT_OUTPUT_SPEED_50MHZ_PP		0x33333333
#define PORT_OUTPUT_SPEED_50MHZ_OD		0x77777777
#define PORT_OUTPUT_SPEED_50MHZ_AFPP	0xbbbbbbbb
#define PORT_OUTPUT_SPEED_50MHZ_AFOD	0xffffffff



void MGPIO_VoidSetPinDirection(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8MODE);

void MGPIO_VoidSetPinValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8VALUE);

void MGPIO_VoidSetPortDirection(u8 copy_u8PORT, u32 copy_u32MODE);

void MGPIO_VoidSetPortValue(u8 copy_u8PORT, u16 copy_u16VALUE);



u8 MGPIO_U8GetPinValue(u8 copy_u8PORT, u8 copy_u8PIN);











#endif

