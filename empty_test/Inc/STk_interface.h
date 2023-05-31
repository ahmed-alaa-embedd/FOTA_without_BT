/***************************/
/*Author : ahmed alaa	*/
/*date : 26/8/2020 		*/
/*version : v01			*/
/***************************/


#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

/*Apply clock choice from config file 
	disable systick interrupt
	disable systick*/
	
void MSTK_VoidInit(void);

/**/
void MSTK_VoidSetBusyWait(u32 copy_u32ticks);

/*give u interrupt that ticks end
	takes time and function that return to after end*/
void MSTK_VoidSetIntervalSingle(u32 copyu32ticks,void (*copy_ptr)(void));
void MSTK_VoidSetIntervalPeriodic(u32 copyu32ticks,void (*copy_ptr)(void));
void MSTK_VoidStopInterval(void);
u32 MSTK_U32GetElapsedTime(void);
u32 MSTK_U32GetRemainingTime(void);



	


#endif

