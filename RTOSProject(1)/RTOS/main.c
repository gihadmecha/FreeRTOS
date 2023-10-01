#include "StdTypes.h"

#include "Kernel_interface.h"
#include "DIO_Interface.h"

void LED1 (void);
void LED2 (void);

void main(void)
{
	DIO_Init();	// A0 as output for LED1, A1 as output for LED2

	RTOS_u8CreateTask(0,&LED1,1000);
	RTOS_u8CreateTask(1,&LED2,2000);
	RTOS_voidSuspendTask(1);

	RTOS_voidStart();

	while(1)
	{

	}
}

void LED1 (void)
{
	DIO_TogglePin(PINA0);
	RTOS_voidResumeTask(1);
}

void LED2 (void)
{
	DIO_TogglePin(PINA1);

}
