/***********************************/
/* Author : Ahmed Alaa			   */
/* Date : 8 August 2021			   */
/* version : V03 				   */
/***********************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"



void RCC_voidInitSysClock(void)
{
	#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	RCC_CR   = 0x00010000; /*Enable HSI with no bypass*/
	RCC_CFGR = 0x00000001; //select HSE clock as system clock 
	/*	wait until the HSE to be stable	*/
	while(GET_BIT(RCC_CR,17) == 0 );
	
	#elif  RCC_CLOCK_TYPE == RCC_HSE_RC
	RCC_CR   = 0x00050000;  /*Enable HSI with bypass*/
	RCC_CFGR = 0x00000001;	//select HSE clock as system clock 
	
	#elif  RCC_CLOCK_TYPE == RCC_HSI
	RCC_CR = 0x00000081; /*HSI Enable Trimming= 0*/
	RCC_CFGR = 0x00000000;	//select HSI clock as system clock 
	
	#elif  RCC_CLOCK_TYPE == RCC_PLL
	
	
	 #if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
		RCC_CFGR = 0x00000000; // HSI oscillator clock/2 selected as PLL input clock 
							   //HSI selected as system clock
							   
		switch(RCC_PLL_MUL_VAL)/*PLL multiplication factor 
								Caution: The PLL output frequency must not exceed 72 MHz*/
		{
			case 2:  RCC_CFGR = 0x00000000; break;
			case 3:  RCC_CFGR = 0x00040000; break;
			case 4:  RCC_CFGR = 0x00080000; break;
			case 5:  RCC_CFGR = 0x000c0000; break;
			case 6:  RCC_CFGR = 0x00100000; break;
			case 7:  RCC_CFGR = 0x00140000; break;
			case 8:  RCC_CFGR = 0x00180000; break;
			case 9:  RCC_CFGR = 0x001c0000; break;
			case 10: RCC_CFGR = 0x00200000; break;
			case 11: RCC_CFGR = 0x00240000; break;
			case 12: RCC_CFGR = 0x00280000; break;
			case 13: RCC_CFGR = 0x002c0000; break;
			case 14: RCC_CFGR = 0x00300000; break;
			case 15: RCC_CFGR = 0x00340000; break;
			case 16: RCC_CFGR = 0x00380000; break;
			//case 16: RCC_CFGR = 0x0000003c; break;
		}

	
	 #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
		RCC_CFGR = 0x00030002;	/*HSE clock divided by 2 and HSE oscillator clock selected
								as PLL input clock and PLL selected as system clock*/
								
		switch(RCC_PLL_MUL_VAL)/*PLL multiplication factor 
								Caution: The PLL output frequency must not exceed 72 MHz*/
		{
			case 2:  RCC_CFGR = 0x00030002; break;
			case 3:  RCC_CFGR = 0x00070000; break;
			case 4:  RCC_CFGR = 0x000b0000; break;
			case 5:  RCC_CFGR = 0x000f0000; break;
			case 6:  RCC_CFGR = 0x00130000; break;
			case 7:  RCC_CFGR = 0x00170000; break;
			case 8:  RCC_CFGR = 0x001b0000; break;
			case 9:  RCC_CFGR = 0x001f0000; break;
			case 10: RCC_CFGR = 0x00230000; break;
			case 11: RCC_CFGR = 0x00270000; break;
			case 12: RCC_CFGR = 0x002b0000; break;
			case 13: RCC_CFGR = 0x002f0000; break;
			case 14: RCC_CFGR = 0x00330000; break;
			case 15: RCC_CFGR = 0x00370000; break;
			case 16: RCC_CFGR = 0x003b0000; break;
			//case 16: RCC_CFGR = 0x003f0000; break;
		}
	 
	 #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		RCC_CFGR = 0x00010002; /* HSE clock not divided and HSE oscillator clock selected
							   as PLL input clock and PLL selected as system clock*/
							   
		switch(RCC_PLL_MUL_VAL)/*PLL multiplication factor 
								Caution: The PLL output frequency must not exceed 72 MHz*/
		{
			case 2:  RCC_CFGR = 0x00010000; break;
			case 3:  RCC_CFGR = 0x00050000; break;
			case 4:  RCC_CFGR = 0x00090000; break;
			case 5:  RCC_CFGR = 0x000d0000; break;
			case 6:  RCC_CFGR = 0x00110000; break;
			case 7:  RCC_CFGR = 0x00150000; break;
			case 8:  RCC_CFGR = 0x00190000; break;
			case 9:  RCC_CFGR = 0x001d0000; break;
			case 10: RCC_CFGR = 0x00210000; break;
			case 11: RCC_CFGR = 0x00250000; break;
			case 12: RCC_CFGR = 0x00290000; break;
			case 13: RCC_CFGR = 0x002d0000; break;
			case 14: RCC_CFGR = 0x00310000; break;
			case 15: RCC_CFGR = 0x00350000; break;
			case 16: RCC_CFGR = 0x00390000; break;
			//case 16: RCC_CFGR = 0x003d003c; break;
		}
								
		RCC_CR   = 0x01000000; /*Enable PLL */
		
		#else
			#warning "Wrong Multiplication Factor"
	 #endif
	
	#else  
		#error("you choose wrong clock type")
	
	#endif 
}


void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
		{
			switch(Copy_u8BusId)
			{
				case RCC_AHB 	: SET_BIT(RCC_AHBENR , Copy_u8PerId); break;
				case RCC_APB1 	: SET_BIT(RCC_APB1ENR , Copy_u8PerId); break;
				case RCC_APB2 	: SET_BIT(RCC_APB2ENR , Copy_u8PerId); break;
				//default 	 	: /*Return Error*/   break; // 34an b3d el compilar m4 by7bo defult fdya
			}

		}
	
	else
		{
			/*Return Error*/
		}
}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB 	: CLR_BIT(RCC_AHBENR , Copy_u8PerId); break;
			case RCC_APB1 	: CLR_BIT(RCC_APB1ENR , Copy_u8PerId); break;
			case RCC_APB2 	: CLR_BIT(RCC_APB2ENR , Copy_u8PerId); break;
			//default 	 	: /*Return Error*/   break; // 34an b3d el compilar m4 by7bo defult fdya
		}
		
	}
	
	else
	{
		/*Return Error*/
	}
}
