/**********************************************************************/
/******************** Name    : Mohamed Ibrahim **********************/
/******************** Date    : 3/8/2023       **********************/
/******************** SWC  	  : OS              **********************/
/******************** TARGET  : ATmega32        **********************/
/******************** Version : V1.0            **********************/
/*********************************************************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

#include "TIMER0_interface.h"
#include "OS_config.h"

typedef enum{
	TASK_DORMANT,
	TASK_READY,
	TASK_RUNNING,
	TASK_SUSPENDED,
	TASK_WAITING
}EN_TaskState_t;

typedef struct
{
	void (*pf)(void);
	u16 Periodicty;
	EN_TaskState_t State;
	u8 first_delay;
	u8 ticksToWait;
}ST_task_t;

//#define OS_u8_MAX_NUMBER_TASKS                       2



void OS_voidInit(void);
void OS_voidStartScheduler(void);
void OS_voidSuspendScheduler(void);


u8    OS_u8CreatTask(u8 Copy_u8Priority,u16 Copy_u16Periodicty, u8 Copy_u8InitialDelay,void (*Copy_pf)(void));
void   OS_u8SuspendTask(u8 Copy_u8TaskId);
void   OS_u8ResumeTask(u8 Copy_u8TaskId);

void   OS_u8DeleteTask(u8 Copy_u8TaskId);

#endif
