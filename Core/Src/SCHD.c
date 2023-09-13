/*
 * SCHD.c
 *
 *  Created on: Aug 20, 2023
 *      Author: E0162112
 */
#include "stdint.h"
#include "SCHD.h"
#include "stm32f103xb.h"
#include "TEMP.h"
#include "main.h"

uint8_t Task_1_cnt = 0;
uint8_t Task_10_cnt = 0;
uint8_t Task_20_cnt = 0;

float Temprature = 0;

void Task_1 (void)
{
	Temprature = TEMP_ConvertToTemp();
}

void Task_10 (void)
{
	HAL_GPIO_TogglePin(LED_3_GPIO_Port, LED_2_Pin);
//	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);
	Task_10_cnt++;
}

void Task_20 (void)
{
	HAL_GPIO_TogglePin(LED_3_GPIO_Port, LED_3_Pin);
	Task_10_cnt++;
}
SCHD_ConfigParm_t SCHDParam [MAX_TASK_NUMBER]= {
                                                        {
                                                            .TaskPeriodUs = 20000, /* Period of Task 1 is 1 ms = 1000 us */
															.TaskFunc = Task_20,
															.TaskActiveFlag = 0U/* Pointer to function Task_1ms to execute its sequence */
                                                        },
                                                        {
                                                            .TaskPeriodUs = 10000, /* Period of Task 2 is 10 ms = 10000 us */
															.TaskActiveFlag = 0U,
															.TaskFunc = Task_10 /* Pointer to function Task_10ms to execute its sequence */
                                                        },
                                                        {
                                                            .TaskPeriodUs = 1000, /* Period of Task 3 is 20 ms = 20000 us */
															.TaskActiveFlag = 0U,
															.TaskFunc = Task_1 /* Pointer to function Task_20ms to execute its sequence */
                                                        }
};

void SCHD_Init(void)
{
   uint8_t index = MAX_TASK_NUMBER;
//   for( index = 0 ; index < MAX_TASK_NUMBER ; index++ )
//   {
//       SCHDParam[index].TaskActiveFlag = 1U;
//       SCHDParam[index].TaskCounter = 0U;
//       SCHDParam[index].TaskReadyFlag = false;
//   }
do
{
    SCHDParam[index-1].TaskActiveFlag = ACTIVE ;
    SCHDParam[index-1].TaskCounter = 0U;
    SCHDParam[--index].TaskReadyFlag = false;
} while(index >0);

}

void SCHD_InterruptHandler(void)
{
//    uint8_t index;

    uint8_t index = MAX_TASK_NUMBER;
    do
    {
        if( ++SCHDParam[index-1].TaskCounter >= (SCHDParam[index-1].TaskPeriodUs / SCHD_CFG_SCHD_TICK_MICRO_SECOND) )
        {
            if( SCHDParam[index-1].TaskActiveFlag == 1U )
            {
                SCHDParam[index-1].TaskReadyFlag = true;
                SCHDParam[index-1].TaskCounter = 0u;
            }
            else
            {
                /*Do nothing*/
            }
        }
        else
        {
            /*Do nothing*/
        }
        index--;
    } while(index >0);
}

_Bool SCHD_TaskReadyGet(SCHD_Tasks_t task)
{
    return SCHDParam[task].TaskReadyFlag;
}

void SCHD_TaskReadyToFalseSet(SCHD_Tasks_t task)
{
    SCHDParam[task].TaskReadyFlag = false;
}

void SCHD_TaskReadyToTrueSet(SCHD_Tasks_t task)
{
    SCHDParam[task].TaskReadyFlag = true;
}

void SCHD_Main(void)
{
//    uint8_t index;
//    for( index = MAX_TASK_NUMBER ; index > 0  ; index--  )
//    {
//        if(SCHD_TaskReadyGet(index-1) == true)
//        {
//            SCHDParam[index-1].TaskFunc();
//            SCHD_TaskReadyToFalseSet(index-1);
//        }
//        else
//        {
//            /*Do nothing*/
//        }
//    }
//	HAL_NVIC_DisableIRQ(TIM2_IRQn);
    uint8_t index = MAX_TASK_NUMBER ;

    do
        {
         if(SCHD_TaskReadyGet(index-1) == true)
        {
            SCHDParam[index-1].TaskFunc();
            SCHD_TaskReadyToFalseSet(index-1);
        }
        else
        {
            /*Do nothing*/
        }
        index--;
    } while(index >0);
//    HAL_NVIC_EnableIRQ(TIM2_IRQn);
}


