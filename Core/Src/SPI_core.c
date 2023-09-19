/*
 * SPI_core.c
 *
 *  Created on: Sep 14, 2023
 *      Author: E0162112
 */

#include "SPI_core.h"
#include "SPI_cfg.h"
#include"Bit_Math.h"

extern void __HAL_RCC_SPI1_CLK_ENABLE();

void SPI_Init (SPI_ConfigParam_t SPI_Params)
{
	SPI->CR1 = 0x000000;
	SPI->CR2 = 0x000000;
	/*Configure SPI*/
	SPI->CR1 = 	 (SPI_Params.CPHA << OFFSET_SPI_CR1_CPHA)
				|(SPI_Params.CPOL << OFFSET_SPI_CR1_CPOL)
				|(SPI_Params.MSTR <<OFFSET_SPI_CR1_MSTR)
				|(SPI_Params.BR << OFFSET_SPI_CR1_BR)
				|(SPI_Params.LSBFIRST << OFFSET_SPI_CR1_LSBFIRST)
				|(SPI_Params.SSI << OFFSET_SPI_CR1_SSI)
				|(SPI_Params.SSM << OFFSET_SPI_CR1_SSM)
				|(SPI_Params.RXONLY << OFFSET_SPI_CR1_RXONLY)
				|(SPI_Params.DFF << OFFSET_SPI_CR1_DFF)
				|(SPI_Params.CRCNEXT << OFFSET_SPI_CR1_CRCNEXT)
				|(SPI_Params.CRCEN << OFFSET_SPI_CR1_CRCEN)
				|(SPI_Params.BIDIOE << OFFSET_SPI_CR1_BIDIOE)
				|(SPI_Params.BIDIMODE << OFFSET_SPI_CR1_BIDIMODE);

	SPI->CR2 =	 (SPI_Params.RXDMAEN << OFFSET_SPI_CR2_RXDMAEN)
				|(SPI_Params.TXDMAEN << OFFSET_SPI_CR2_TXDMAEN)
				|(SPI_Params.SSOE << OFFSET_SPI_CR2_SSOE)
				|(SPI_Params.ERRIE << OFFSET_SPI_CR2_ERRIE)
				|(SPI_Params.RXNEIE << OFFSET_SPI_CR2_RXNEIE)
				|(SPI_Params.TXEIE << OFFSET_SPI_CR2_TXEIE);

	/*Enable SPI*/
	SPI->CR1 |=	 (SPI_Params.SPE << OFFSET_SPI_CR1_SPE);

}

void SPI_SendData(uint16_t SPI_data)
{
	while(((SPI->DR)>>OFFSET_SPI_SR_TXE)&1 != 0); //wait till transmit buffer is empty
	SPI->DR =SPI_data;

}

uint16_t SPI_ReadData(void)
{
	uint16_t SPI_data;
	while(((SPI->DR)>>OFFSET_SPI_SR_TXE)&1 != 0); //wait
	SPI_data = SPI->DR;

	return SPI_data;

}
