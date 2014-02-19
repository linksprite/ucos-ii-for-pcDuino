/*
*********************************************************************************************************
*                                                uC/OS-II
*                                          The Real-Time Kernel
*                                               Linux Port
*
* File: os_cpu_c.c
* By: Philip Mitchell
* Email: mitchell_philip@hotmail.com
* Version: v1.00
*
*********************************************************************************************************
*/

#ifndef OS_CPU_LINUX_PORT
#ifdef OS_CPU_GLOBALS
#define OS_CPU_EXT
#else
#define OS_CPU_EXT extern
#endif

#include <signal.h>
#include <stddef.h>

/*
*********************************************************************************************************
*                                              DATA TYPES
*                                         (Compiler Specific)
*********************************************************************************************************
*/
typedef unsigned char  		BOOLEAN;
typedef unsigned char  		INT8U;
typedef signed   char  		INT8S;
typedef unsigned short int  INT16U;
typedef signed   short int  INT16S;
typedef unsigned int  		INT32U;
typedef signed   int  		INT32S;
typedef float          		FP32;
typedef INT32U  			OS_STK;
//typedef sigset_t			OS_CPU_SR;
#ifndef OS_CPU_SR
#define OS_CPU_SR	sigset_t new_cpu_sr; int
#endif

/*
*********************************************************************************************************
*                                          Processor Specifics
*********************************************************************************************************
*/

#define OS_SYSTEM_RESET_EN	0

/* Extra functionality of this port. It is a user definable system reset function */
#if OS_SYSTEM_RESET_EN > 0
void OSSystemReset(void);
#endif

/* Extra functionality of this port. Minimum stack size. Pthreads creates its own stack for each thread(task) but a minimum size is needed internally for the ports use. */
int OSMinStkSize();

void OSIntCtxSw(void);
void OSStartHighRdy(void);
void OSCtxSw();

#define OS_CRITICAL_METHOD 3

/* Block interrupts by blocking the alarm signal */
#define OS_ENTER_CRITICAL() { cpu_sr = cpu_sr; sigset_t mask; sigemptyset( &mask ); sigaddset( &mask, SIGALRM ); sigprocmask( SIG_SETMASK, &mask, &new_cpu_sr ); }

/* Unblock the alarm signal */
#define OS_EXIT_CRITICAL() { sigprocmask(SIG_SETMASK, &new_cpu_sr, NULL); }

/* Stack grows high to low */
#define  OS_STK_GROWTH      1

/* OS_TASK_SW below performs task switching exactly as the alarm signal does */
#define OS_TASK_SW() { OSCtxSw(); } 

#endif /* OS_CPU_LINUX_PORT */
