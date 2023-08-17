/*********************************************************************/
/******************** Name    : Mohamed Ibrahim **********************/
/******************** Date    : 3/8/2023       **********************/
/******************** SWC  	  : OS              **********************/
/******************** TARGET  : ATmega32        **********************/
/******************** Version : V1.0            **********************/
/*********************************************************************/

#include "BIT_MATH.h"
#include "OS_config.h"
#include "OS_interface.h"
#include "OS_private.h"
#include "STD_TYPES.h"

#include "TIMER0_interface.h"

ST_task_t OS_arrTasks[OS_u8_MAX_NUMBER_TASKS];

//static void  OS_voidScheduler(void);

void OS_voidInit(void)
{
	/* Initialize Timer */
	TIMER0_voidInit(TIMER0_NORMAL_MODE);
}

void OS_voidStartScheduler(void)
{
	TIMER0_voidSetIntervalPeriodic(PERIODIC_TIME , OS_voidScheduler );
}

void OS_voidSuspendScheduler(void)
{
	TIMER0_voidStop();
}


u8    OS_u8CreatTask(u8 Copy_u8Priority,u16 Copy_u16Periodicty, u8 Copy_u8InitialDelay,void (*Copy_pf)(void))
{
	u8 Local_ErrorState = STD_TYPES_NOK;
	//
	if((Copy_u8Priority < OS_u8_MAX_NUMBER_TASKS) && (Copy_pf != NULL) && (Copy_u16Periodicty != 0))
	{
		OS_arrTasks[Copy_u8Priority].Periodicty = Copy_u16Periodicty;
		OS_arrTasks[Copy_u8Priority].pf         = Copy_pf;
		OS_arrTasks[Copy_u8Priority].first_delay = Copy_u8InitialDelay;
		OS_arrTasks[Copy_u8Priority].ticksToWait = OS_arrTasks[Copy_u8Priority].first_delay + OS_arrTasks[Copy_u8Priority].Periodicty;
		Local_ErrorState = STD_TYPES_OK;
	}
	return Local_ErrorState;
}

void   OS_u8SuspendTask(u8 Copy_u8TaskId)
{
	OS_arrTasks[Copy_u8TaskId].State = TASK_SUSPENDED;
}

void   OS_u8ResumeTask(u8 Copy_u8TaskId)
{
	OS_arrTasks[Copy_u8TaskId].State = TASK_WAITING;
}


void   OS_u8DeleteTask(u8 Copy_u8TaskId)
{
	OS_arrTasks[Copy_u8TaskId].pf = NULL;
}


static void  OS_voidScheduler(void)
{
	u8 Local_u8Counter;
	for(Local_u8Counter = 0;Local_u8Counter < OS_u8_MAX_NUMBER_TASKS ;Local_u8Counter++)
	{
		OS_arrTasks[Local_u8Counter].ticksToWait--;

		if(OS_arrTasks[Local_u8Counter].ticksToWait == 0 && OS_arrTasks[Local_u8Counter].State != TASK_SUSPENDED)
		{
			OS_arrTasks[Local_u8Counter].ticksToWait = OS_arrTasks[Local_u8Counter].Periodicty;
			OS_arrTasks[Local_u8Counter].pf();
		}else{}
	}
}
