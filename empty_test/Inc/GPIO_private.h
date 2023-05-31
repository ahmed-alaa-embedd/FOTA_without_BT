/***********************************/
/* Author : Ahmed Alaa			   */
/* Date : 12 8 2020			   	   */
/* version : V03 				   */
/***********************************/


#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#define GPIOA_BASE_ADDRESS	 0x40010800
#define GPIOB_BASE_ADDRESS	 0x40010c00
#define GPIOC_BASE_ADDRESS	 0x40011000

		/*Registers address for portA*/
#define GPIOA_CRL			 *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x00))
#define GPIOA_CRH			 *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_IDR			 *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_ODR			 *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x0c))
#define GPIOA_BSRR			 *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x10))
#define GPIOA_BRR			 *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x14))
#define GPIOA_LCK			 *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x18))


		/*Registers address for portB*/
#define GPIOB_CRL			 *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x00))
#define GPIOB_CRH			 *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x04))
#define GPIOB_IDR			 *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x08))
#define GPIOB_ODR			 *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x0c))
#define GPIOB_BSRR			 *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x10))
#define GPIOB_BRR			 *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x14))
#define GPIOB_LCK			 *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x18))


		/*Registers address for portC*/
#define GPIOC_CRL			 *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x00))
#define GPIOC_CRH			 *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x04))
#define GPIOC_IDR			 *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x08))
#define GPIOC_ODR			 *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x0c))
#define GPIOC_BSRR			 *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x10))
#define GPIOC_BRR			 *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x14))
#define GPIOC_LCK			 *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x18))


#endif
