/*
 * DMA_core.h
 *
 *  Created on: Sep 13, 2023
 *      Author: E0162112
 */

#ifndef SRC_DMA_CORE_H_
#define SRC_DMA_CORE_H_


#include<stdint.h>
#include "DMA_cfg.h"

typedef enum
{
	DMA_DISABLE,
	DMA_ENABLE,
}Enable_state;

typedef enum
{
	DMA_CHANNEL_1,
	DMA_CHANNEL_2,
	DMA_CHANNEL_3,
	DMA_CHANNEL_4,
	DMA_CHANNEL_5,
	DMA_CHANNEL_6,
	DMA_CHANNEL_7,
	DMA_MAX_NUMBER_OF_CHANNELS,
}DMA_Channels_t;

typedef enum
{
	OFFSET_EN		    ,
	OFFSET_TCIE	        ,
	OFFSET_HTIE	        ,
	OFFSET_TEIE	        ,
	OFFSET_DIR	        ,
	OFFSET_CIRC	        ,
	OFFSET_PINC	        ,
	OFFSET_MINC	        ,
	OFFSET_PSIZE	    ,
	OFFSET_MSIZE	= 10,
	OFFSET_PL		= 12,
	OFFSET_MEM2MEM 	= 14,
}CCRx_BitPosition_t;

typedef struct
{
	volatile uint32_t CCR;			//channel configuration register
	volatile uint32_t CNDTR;			//channel number of data register
	volatile uint32_t CPAR;			//channel peripheral address register
	volatile uint32_t CMAR;			//channel memory address register
	volatile uint32_t Reserved;		//reserved register
}DMA_t;


typedef struct
{
	volatile uint32_t ISR;			//Interrupt Status Register
	volatile uint32_t IFCR;			//Interrupt Flag Clear Register
	DMA_t Channel[7]; 		//channel control registers

}DMA_Registers_t;

#define DMA				((volatile DMA_Registers_t*)0x40020000)

void DMA_Init(DMA_config_t DMA_configParam[DMA_MAX_NUMBER_OF_CHANNELS]);

void DMA_Start(DMA_Channels_t channel, uint32_t* DMA_SourceAddress, uint32_t* DMA_DestinationAddress, uint16_t DMA_BlockLength);

void DMA_EnableChannel (DMA_Channels_t channel);

void DMA_DisableChannel (DMA_Channels_t channel);

void DMA_IRQ_HandlerSet(DMA_Channels_t channel, void* InterruptHandler);

#endif /* SRC_DMA_CORE_H_ */
