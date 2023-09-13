/*
 * SCHD.h
 *
 *  Created on: Aug 20, 2023
 *      Author: E0162112
 */

#ifndef INC_SCHD_H_
#define INC_SCHD_H_
#define false   0U
#define true	1U

typedef enum
{
	ACTIVE  = 1U  ,
	INACTIVE = 0U
}SCHD_State_t;

#define SCHD_CFG_SCHD_TICK_MICRO_SECOND 500

typedef void (*TaskFunction)(void);

typedef enum SCHD_Tasks_e
{
    TASK_0 = 0U,
    TASK_1 = 1U,
    TASK_2 = 2U,
    MAX_TASK_NUMBER = 3U
}SCHD_Tasks_t;

typedef struct SCHD_ConfigParm_s
{
    TaskFunction TaskFunc;      /**< pointer to a function to execute each task sequence */
    uint16_t TaskPeriodUs;      /**< define the perio of each Task */
    SCHD_State_t TaskActiveFlag;     /**< define the active flag of each task */
    uint8_t TaskCounter;        /**< define the counter of each task */
    _Bool TaskReadyFlag;        /**< define the ready flag of each task */
} SCHD_ConfigParm_t;


void SCHD_Init(void);
void SCHD_InterruptHandler(void);
_Bool SCHD_TaskReadyGet(SCHD_Tasks_t task);
void SCHD_TaskReadyToFalseSet(SCHD_Tasks_t task);
void SCHD_TaskReadyToTrueSet(SCHD_Tasks_t task);
void SCHD_Main(void);
void Task_1 (void);
void Task_10 (void);
void Task_20 (void);

#endif /* INC_SCHD_H_ */
