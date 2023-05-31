/***************************/
/*Author : ahmed alaa	*/
/*date : 26/8/2020 		*/
/*version : v02			*/
/***************************/

#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H


typedef struct
{
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
}MSTK_Type;

#define     MSTK    ((MSTK_Type*)0xE000E010)


#define     MSTK_SINGLE_INTERVAL    0
#define     MSTK_PERIOD_INTERVAL    1
#define AHB   0
#define AHB_8 1


#endif

