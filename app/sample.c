/*
*********************************************************************************************************
*                                               sample.c
*
* Description:	This sample program uses the ucos linux port to start 5 simple tasks.
*
* Author: Philip Mitchell
*
*********************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include "ucos_ii.h"
#include <core.h>
#include <string.h>

int led_pin = 1;
int btn_pin = 5;

void hardware_init()
{
	 pinMode(led_pin, OUTPUT);
}
/* Function common to all tasks */

void MyTask( void *p_arg )
{

	char* sTaskName = (char*)p_arg;
	static flag1 = 1;
#if OS_CRITICAL_METHOD == 3 
    OS_CPU_SR     cpu_sr = 0;
#endif

	while(1)
	{
		/* printf uses mutex to get terminal access, therefore must enter critical section */
		OS_ENTER_CRITICAL();
		printf( "Name: %s\n", sTaskName );
		if(!strcmp(sTaskName,"Task 1"))
		{
			if(flag1 == 1)
			{
				flag1 = 0;
				printf("HIGH\n");
				digitalWrite(led_pin, HIGH);
			}
			else
			{
				flag1 = 1;
				printf("LOW\n");
				digitalWrite(led_pin, LOW);
			}
		}		
		OS_EXIT_CRITICAL();

		/* Delay so other tasks may execute. */
		OSTimeDly(50);
	}/* while */

}


int main (void)
{
	/* pthreads allocates its own memory for task stacks. This UCOS linux port needs a minimum stack size
		in order to pass the function information within the port. */
	hardware_init();
	INT8U Stk1[ OSMinStkSize() ];
	INT8U Stk2[ OSMinStkSize() ];
	INT8U Stk3[ OSMinStkSize() ];
	INT8U Stk4[ OSMinStkSize() ];
	INT8U Stk5[ OSMinStkSize() ];

	char sTask1[] = "Task 1";
	char sTask2[] = "Task 2";
	char sTask3[] = "Task 3";
	char sTask4[] = "Task 4";
//	char sTask5[] = "Task 5";

	OSInit();

	OSTaskCreate( MyTask, sTask1, (void*)Stk1, 4 );
//	OSTaskCreate( MyTask, sTask2, (void*)Stk2, 5 );
//	OSTaskCreate( MyTask, sTask3, (void*)Stk3, 6 );
//	OSTaskCreate( MyTask, sTask4, (void*)Stk4, 7 );
//	OSTaskCreate( MyTask, sTask5, (void*)Stk5, 8 );

    OSStart();

    return 0;
}

