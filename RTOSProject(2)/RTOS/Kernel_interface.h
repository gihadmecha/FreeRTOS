/****************************************************************************/
/****************************************************************************/
/*******************	Author: Amgad Samir				*********************/
/*******************	Layer: Kernel					*********************/
/*******************	Stack: OS						*********************/
/*******************	Version: 1.00					*********************/
/****************************************************************************/
/****************************************************************************/

#ifndef KERNEL_INTERFACE_H_
#define KERNEL_INTERFACE_H_

void RTOS_voidStart(void);

u8 RTOS_u8CreateTask(u8 Copy_u8Priority,void (*Copy_pvTaskFunc)(void),u16 Copy_u16Periodicity,u16 Copy_u16FirstDelay);

void RTOS_voidSuspendTask(u8 Copy_u8Priority);

void RTOS_voidResumeTask(u8 Copy_u8Priority);

void RTOS_voidDeleteTask(u8 Copy_u8Priority);




#endif

