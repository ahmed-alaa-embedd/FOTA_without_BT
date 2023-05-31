/***********************************/
/* Author : Ahmed Alaa			   */
/* Date : 12 8 2020			  	   */
/* version : V02				   */
/***********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_private.h"
#include "GPIO_int.h"



void MGPIO_VoidSetPinDirection(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8MODE)
{
	switch(copy_u8PORT)
	{
		case GPIOA:
			if(copy_u8PIN <= 7)			/* if PIN<7 CRH is not activated as else cancel 
										   the 2nd condition  */
				{
					GPIOA_CRL &= ~((0b1111)<<(copy_u8PIN*4));  /*we CLR first as 0 OR 1 will 
															 always be 1 so we cant overwrite */
					GPIOA_CRL |= ((copy_u8MODE)<<(copy_u8PIN*4));
				}
			else if(copy_u8PIN <= 15)	
				{
					copy_u8PIN = copy_u8PIN-8;
					GPIOA_CRH &= ~((0b1111)<<(copy_u8PIN*4));  
					GPIOA_CRH |= ((copy_u8MODE)<<(copy_u8PIN*4));
				}
				break;
		case GPIOB:
			if(copy_u8PIN <= 7)		/* if PIN<7 CRH is not activated as else cancel 
										   the 2nd condition  */
				{
					GPIOB_CRL &= ~((0b1111)<<(copy_u8PIN*4));  /*we CLR first as 0 OR 1 will 
															  always be 1 so we cant overwrite*/ 
					GPIOB_CRL |= ((copy_u8MODE)<<(copy_u8PIN*4));
				}
			else if(copy_u8PIN <= 15)
				{
					copy_u8PIN = copy_u8PIN-8;	/*pins enters is more than 7 so we use PIN-8
												to start in CRH from pin 0*/
					GPIOB_CRH &= ~((0b1111)<<(copy_u8PIN*4));  
					GPIOB_CRH |= ((copy_u8MODE)<<(copy_u8PIN*4));
				}
				break;
		
		case GPIOC:
			if(copy_u8PIN <= 7)  /* if PIN<7 CRH is not activated as else cancel 
										   the 2nd condition  */ 
				{
					GPIOC_CRL &= ~((0b1111)<<(copy_u8PIN*4));  /*we CLR first as 0 OR 1 will 
															   always be 1 so we cant overwrite*/
					GPIOC_CRL |= ((copy_u8MODE)<<(copy_u8PIN*4));
				}
			else if(copy_u8PIN <= 15)
				{
					copy_u8PIN = copy_u8PIN-8;
					GPIOC_CRH &= ~((0b1111)<<(copy_u8PIN*4));  
					GPIOC_CRH |= ((copy_u8MODE)<<(copy_u8PIN*4));
				}
				break;
		default: break;
	}
}

void MGPIO_VoidSetPortDirection(u8 copy_u8PORT, u32 copy_u32MODE)
{
	switch(copy_u8PORT)
		{
			case GPIOA:


						GPIOA_CRL &= 0;  /*we CLR first as 0 OR 1 will
																 always be 1 so we cant overwrite */
						GPIOA_CRL |= copy_u32MODE;




						GPIOA_CRH &= 0;  /*we CLR first as 0 OR 1 will
													 always be 1 so we cant overwrite */
						GPIOA_CRH |= copy_u32MODE;

					break;
			case GPIOB:

						GPIOB_CRL &= 0;  /*we CLR first as 0 OR 1 will
																  always be 1 so we cant overwrite*/
						GPIOB_CRL |= copy_u32MODE;



						GPIOB_CRH &= 0;
						GPIOB_CRH |= copy_u32MODE;

					break;

			case GPIOC:

						GPIOC_CRL &= 0;  /*we CLR first as 0 OR 1 will
																   always be 1 so we cant overwrite*/
						GPIOC_CRL |= copy_u32MODE;



						GPIOC_CRH &= 0;
						GPIOC_CRH |= copy_u32MODE;

					break;
			default: break;
		}
}

void MGPIO_VoidSetPortValue(u8 copy_u8PORT, u16 copy_u16VALUE)
{
	switch(copy_u8PORT)
		{
			case GPIOA:

				GPIOA_ODR &= 0;
				GPIOA_ODR |= copy_u16VALUE;


						break;
			case GPIOB:

				GPIOB_ODR &= 0;
				GPIOB_ODR |= copy_u16VALUE;

						break;

			case GPIOC:

				GPIOC_ODR &= 0;
				GPIOC_ODR |= copy_u16VALUE;


						break;
			default: break;
		}
}

void MGPIO_VoidSetPinValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8VALUE)
{
	switch(copy_u8PORT)
	{
		case GPIOA:
			if(copy_u8VALUE == HIGH)	 	//set pin value high
				{
					SET_BIT(GPIOA_ODR , copy_u8PIN);
				}
			else if(copy_u8VALUE == LOW)	//set pin value low
				{
					CLR_BIT(GPIOA_ODR , copy_u8PIN);
				}
					break;
		case GPIOB:
			if(copy_u8VALUE == HIGH)		//set pin value high
				{
					SET_BIT(GPIOB_ODR , copy_u8PIN);
				}
			else if(copy_u8VALUE == LOW)	//set pin value LOW
				{
					CLR_BIT(GPIOB_ODR , copy_u8PIN);
				}
					break;
		
		case GPIOC:
			if(copy_u8VALUE == HIGH)		//set pin value high
				{
					SET_BIT(GPIOC_ODR , copy_u8PIN);
				}
			else if(copy_u8VALUE == LOW)	//set pin value low
				{
					CLR_BIT(GPIOC_ODR , copy_u8PIN);
				}
					break;
		default: break;
	}
}


u8 MGPIO_u8GetPinValue(u8 copy_u8PORT, u8 copy_u8PIN)
{
	u8 LOC_u8Result = 0;
	
	switch(copy_u8PORT)
	{
		case GPIOA:
					LOC_u8Result = GET_BIT(GPIOA_IDR , copy_u8PIN);
					break;
		case GPIOB:
					LOC_u8Result = GET_BIT(GPIOB_IDR , copy_u8PIN);
					break;
		
		case GPIOC:
					LOC_u8Result = GET_BIT(GPIOC_IDR , copy_u8PIN);
					break;
		default: break;
	}
	return LOC_u8Result;
}
