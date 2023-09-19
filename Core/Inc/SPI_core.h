/*
 * SPI_core.h
 *
 *  Created on: Sep 14, 2023
 *      Author: E0162112
 */

#ifndef INC_SPI_CORE_H_
#define INC_SPI_CORE_H_

#include <stdint.h>
#include "SPI_cfg.h"

typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR;
}SPI_Registers_t;

typedef enum
{
	OFFSET_SPI_CR1_CPHA,
	OFFSET_SPI_CR1_CPOL,
	OFFSET_SPI_CR1_MSTR,
	OFFSET_SPI_CR1_BR,
	OFFSET_SPI_CR1_SPE = 6,
	OFFSET_SPI_CR1_LSBFIRST,
	OFFSET_SPI_CR1_SSI,
	OFFSET_SPI_CR1_SSM,
	OFFSET_SPI_CR1_RXONLY,
	OFFSET_SPI_CR1_DFF,
	OFFSET_SPI_CR1_CRCNEXT,
	OFFSET_SPI_CR1_CRCEN,
	OFFSET_SPI_CR1_BIDIOE,
	OFFSET_SPI_CR1_BIDIMODE,
}SPI_CR1_BitsOffset_t;

typedef enum
{
	OFFSET_SPI_CR2_RXDMAEN,
	OFFSET_SPI_CR2_TXDMAEN,
	OFFSET_SPI_CR2_SSOE,
	OFFSET_SPI_CR2_ERRIE = 5,
	OFFSET_SPI_CR2_RXNEIE,
	OFFSET_SPI_CR2_TXEIE,
}SPI_CR2_BitsOffset_t;

typedef enum
{
	OFFSET_SPI_SR_RXNE,
	OFFSET_SPI_SR_TXE,
	OFFSET_SPI_SR_CHSIDE,
	OFFSET_SPI_SR_UDR,
	OFFSET_SPI_SR_CRCERR,
	OFFSET_SPI_SR_MODF,
	OFFSET_SPI_SR_OVR,
	OFFSET_SPI_SR_BSY
} SPI_SR_BitsOffset_t;

#define SPI ((volatile SPI_Registers_t*)0x40013000)


void SPI_Init (SPI_ConfigParam_t SPI_Params);

#endif /* INC_SPI_CORE_H_ */
