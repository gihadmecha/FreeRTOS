/****************************************************************************/
/****************************************************************************/
/*******************	Author: Amgad Samir				*********************/
/*******************	Layer: Kernel					*********************/
/*******************	Stack: OS						*********************/
/*******************	Version: 1.00					*********************/
/****************************************************************************/
/****************************************************************************/

#include "StdTypes.h"
#include "MemMap.h"

#include "Timers_Services.h"

#include "Kernel_private.h"
#include "Kernel_interface.h"
#include "Kernel_config.h"

#define OK		0
#define NOK		1

typedef struct
{
	u16 Periodicity;
	void (*TaskFunc)(void);
	u8 State;
}Task_t;

Task_t SystemTasks[TASK_NUM]={{NULL}};

void RTOS_voidStart(void)
{
	/*Configure timer to generate interrupt every 1 ms*/
	Timer1_SetInterruptTime_ms(1,&Scheduler);

	/*Enable global interrupts*/
	sei();
}

u8 RTOS_u8CreateTask(u8 Copy_u8Priority,void (*Copy_pvTaskFunc)(void),u16 Copy_u16Periodicity)
{
	u8 Local_u8ErrorState= OK;
	if(Copy_pvTaskFunc != NULL)
	{
		/*check if the given priority is available or not*/
		if(SystemTasks[Copy_u8Priority].TaskFunc == NULL)
		{
			SystemTasks[Copy_u8Priority].Periodicity= Copy_u16Periodicity;
			SystemTasks[Copy_u8Priority].TaskFunc= Copy_pvTaskFunc;
			SystemTasks[Copy_u8Priority].State= RESUMED;
		}
		else
		{
			/*priority is not available*/
		}
	}
	else
	{
		Local_u8ErrorState= NOK;
	}
	return Local_u8ErrorState;
}

void RTOS_voidSuspendTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].State=SUSPENDED;
}

void RTOS_voidResumeTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].State= RESUMED;
}

void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].TaskFunc= NULL;
}

static void Scheduler (void)
{
	volatile static u16 Local_u16SystickCounter=0;
	u8 Local_u8TaskCounter;
	Local_u16SystickCounter++;

	for(Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_NUM;Local_u8TaskCounter++)
	{
		if(SystemTasks[Local_u8TaskCounter].State==RESUMED)
		{
			if(Local_u16SystickCounter % SystemTasks[Local_u8TaskCounter].Periodicity ==0)
			{
				/*Invoke the task function if it is not NULL*/
				if(SystemTasks[Local_u8TaskCounter].TaskFunc != NULL)
				{
					SystemTasks[Local_u8TaskCounter].TaskFunc();
				}
			}
			else
			{
				/*Do nothing*/
			}
		}
		else
		{
			/*Task is suspended, Do nothing*/
		}
	}
}

