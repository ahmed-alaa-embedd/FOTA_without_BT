/***********************************/
/* Author : Ahmed Alaa			   */
/* Date : 8 August 2020			   */
/* version : V02 				   */
/***********************************/

#ifndef RCC_config_H
#define RCC_config_H

/*Options:	RCC_HSE_CRYSTAL
			RCC_HSE_RC
			RCC_HSI
			RCC_PLL

			*/
#define RCC_CLOCK_TYPE	RCC_HSE_CRYSTAL

/* Options:	RCC_PLL_IN_HSI_DIV_2
			RCC_PLL_IN_HSE_DIV_2
			RCC_PLL_IN_HSE
*/	
/*Note: select value only if you have PLL as input clock source*/
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT	RCC_PLL_IN_HSE_DIV_2
#endif 

/* Options: 2 to 16 */
/*Note: select value only if you have PLL as input clock source*/
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL		4
#endif

#endif
