/*
 * DMA_core.c
 *
 *  Created on: Sep 13, 2023
 *      Author: E0162112
 */


#include "DMA_core.h"
#include "DMA_cfg.h"
#include "Bit_Math.h"


void DMA_Init(DMA_config_t DMA_configParam[DMA_MAX_NUMBER_OF_CHANNELS])
{

	DMA->IFCR |= (0xffffffff);		//clear all interrupt flags
	for (uint8_t i= DMA_CHANNEL_1; i < DMA_MAX_NUMBER_OF_CHANNELS ; i++)
	{
		DMA->Channel[i].CCR =	(DMA_configParam[i].EN 		<< OFFSET_EN)|
								(DMA_configParam[i].TCIE 	<< OFFSET_TCIE)|
								(DMA_configParam[i].HTIE 	<< OFFSET_HTIE)|
								(DMA_configParam[i].TEIE	<< OFFSET_TEIE)|
								(DMA_configParam[i].DIR 	<< OFFSET_DIR)|
								(DMA_configParam[i].CIRC 	<< OFFSET_CIRC)|
								(DMA_configParam[i].PINC 	<< OFFSET_PINC)|
								(DMA_configParam[i].MINC 	<< OFFSET_MINC)|
								(DMA_configParam[i].PSIZE 	<< OFFSET_PSIZE)|
								(DMA_configParam[i].MSIZE 	<< OFFSET_MSIZE)|
								(DMA_configParam[i].PL 		<< OFFSET_PL)|
								(DMA_configParam[i].MEM2MEM << OFFSET_MEM2MEM);
	}
}

void DMA_EnableChannel (DMA_Channels_t channel)
{
	DMA->Channel[channel].CCR |= ((uint16_t)DMA_ENABLE << OFFSET_EN);
}

void DMA_DisableChannel (DMA_Channels_t channel)
{
	DMA->Channel[channel].CCR &= ~((uint16_t)DMA_ENABLE << OFFSET_EN);
}


void DMA_Start(DMA_Channels_t channel, uint32_t* DMA_SourceAddress, uint32_t* DMA_DestinationAddress, uint16_t DMA_BlockLength)
{
	DMA_DisableChannel(channel);

	if (READ_FROM_PERIPHERAL == READ_BIT(DMA->Channel[channel].CCR,OFFSET_DIR))
	{
		DMA->Channel[channel].CMAR = DMA_DestinationAddress;
		DMA->Channel[channel].CPAR = DMA_SourceAddress;
	}
	else
	{
		DMA->Channel[channel].CMAR = DMA_SourceAddress;
		DMA->Channel[channel].CPAR = DMA_DestinationAddress;
	}

	DMA->Channel[channel].CNDTR = DMA_BlockLength;

	DMA_EnableChannel(channel);

}
