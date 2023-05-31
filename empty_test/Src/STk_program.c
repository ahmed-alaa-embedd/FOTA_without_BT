/***************************/
/*Author : ahmed alaa	*/
/*date : 26/8/2020 		*/
/*version : v04			*/
/***************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STk_interface.h"
#include "STk_private.h"
#include "STk_config.h"




//Global variable pointer to function
static void (*CALLBACK)(void);

//Global variable check for repeating delay
static u8 MSTK_Repeat;

void MSTK_VoidInit(void)
{
#if CLKSOURCE==AHB_8	/* Disable counter - Set clock source AHB/8   */

	MSTK->CTRL = 0 ;
#elif CLKSOURCE==AHB

	MSTK_CTRL = 0x00000004 ;/* Disable counter - Set clock source AHB*/

#else
	/*REPORT ERROR*/

#endif

}

void MSTK_VoidSetBusyWait(u32 copy_u32ticks)
{
	//1 Tick = 1 Micro sec

	MSTK->LOAD = copy_u32ticks; /* Load ticks to load register */

	SET_BIT(MSTK->CTRL, 0);	/* start count*/

	/* Wait till flag is raised */
	while(GET_BIT(MSTK->CTRL,16)==0)
	{
		asm("NOP");
	}

	/*Stop timer and no repeating*/
	MSTK->CTRL=0;
	MSTK->LOAD = 0;
	MSTK->VAL=0;

}


void MSTK_VoidSetIntervalSingle(u32 copyu32ticks,void (*copy_ptr)(void))
{
	//1 Tick = 1 Micro sec

	/*Disable timer*/
	CLR_BIT(MSTK->CTRL,0) ;
	MSTK->VAL =0;

	/* Load ticks to load register */
	MSTK->LOAD = copyu32ticks;

	/* start count*/
	SET_BIT(MSTK->CTRL,0) ;

	// point to the passed function
	CALLBACK = copy_ptr;

	// single repeat
	MSTK_Repeat=MSTK_SINGLE_INTERVAL;

	SET_BIT(MSTK->CTRL,1) ;			 //enable interrupt


}
void MSTK_VoidSetIntervalPeriodic(u32 copyu32ticks,void (*copy_ptr)(void))
{
	//1 Tick = 1 Micro sec

	MSTK->LOAD = copyu32ticks; 			/* Load ticks to load register */

	MSTK_Repeat=MSTK_PERIOD_INTERVAL;	// Periodic repeat

	CALLBACK = copy_ptr;				// point to the passed function

	SET_BIT(MSTK->CTRL,0) ;				/* start count*/

	SET_BIT(MSTK->CTRL,1) ;				//enable interrupt

}
void MSTK_VoidStopInterval(void)
{
	CLR_BIT(MSTK->CTRL,1);	/* Disable STK Interrupt */

	/*Stop timer and no repeating*/
	MSTK->CTRL=0;
	MSTK->LOAD = 0;
	MSTK->VAL=0;

}
u32 MSTK_U32GetElapsedTime(void)
{
	u32 ElapsedTime ;
	ElapsedTime = MSTK->LOAD - MSTK->VAL;


	return ElapsedTime;
}
u32 MSTK_U32GetRemainingTime(void)
{
	u32 RemainingTime = MSTK->VAL;


	return RemainingTime;
}

void SysTick_Handler()	/*mwgoda f el .c m4 f el main */
{

	if(MSTK_Repeat == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(MSTK->CTRL, 1);
		/*Stop timer and no repeating*/

		MSTK->CTRL=0;
		MSTK->LOAD = 0;
		MSTK->VAL=0;
	}



	CALLBACK();
}
