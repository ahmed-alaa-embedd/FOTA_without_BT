/*****************************************/
/* Author  :  Ahmed ALAA                 */
/* Date    : 16/9/2020                   */
/* Version :  V01            			 */
/*****************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void MSPI1_voidInit(); /*Home Work*/
void MSPI1_voidSendRecieveSynch(u8 copy_u8DatatoTransmit,u8 *copy_u8DataToRecieve);
void MSPI1_voidSendRecieveASynch(u8 copy_u8DatatoTransmit,void (*CallBack)(u8));

#endif
