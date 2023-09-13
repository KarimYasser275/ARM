/*
 * DMA_cfg.c
 *
 *  Created on: Sep 13, 2023
 *      Author: E0162112
 */


#include "DMA_cfg.h"
#include "DMA_core.h"


DMA_config_t DMA_config[7] ={
						{.EN = DMA_ENABLE, .TCIE =DMA_ENABLE,.HTIE = DMA_DISABLE,.TEIE = DMA_ENABLE, .DIR = READ_FROM_PERIPHERAL, \
						.CIRC = DMA_ENABLE, .PINC=DMA_DISABLE, .MINC = DMA_ENABLE, .PSIZE = _16BITS, .MSIZE = _32BITS, .PL = VERY_HIGH, .MEM2MEM = DMA_DISABLE},

						{.EN = DMA_ENABLE, .TCIE =DMA_ENABLE,.HTIE = DMA_DISABLE,.TEIE = DMA_ENABLE, .DIR = READ_FROM_PERIPHERAL, \
						.CIRC = DMA_ENABLE, .PINC=DMA_DISABLE, .MINC = DMA_ENABLE, .PSIZE = _16BITS, .MSIZE = _32BITS, .PL = HIGH, .MEM2MEM = DMA_ENABLE},

						{.EN = DMA_DISABLE, .TCIE =DMA_ENABLE,.HTIE = DMA_DISABLE,.TEIE = DMA_ENABLE, .DIR = READ_FROM_PERIPHERAL, \
						.CIRC = DMA_ENABLE, .PINC=DMA_DISABLE, .MINC = DMA_ENABLE, .PSIZE = _16BITS, .MSIZE = _16BITS, .PL = VERY_HIGH, .MEM2MEM = DMA_DISABLE},

						{.EN = DMA_DISABLE, .TCIE =DMA_ENABLE,.HTIE = DMA_DISABLE,.TEIE = DMA_ENABLE, .DIR = READ_FROM_PERIPHERAL, \
						.CIRC = DMA_ENABLE, .PINC=DMA_DISABLE, .MINC = DMA_ENABLE, .PSIZE = _16BITS, .MSIZE = _16BITS, .PL = VERY_HIGH, .MEM2MEM = DMA_DISABLE},

						{.EN = DMA_DISABLE, .TCIE =DMA_ENABLE,.HTIE = DMA_DISABLE,.TEIE = DMA_ENABLE, .DIR = READ_FROM_PERIPHERAL, \
						.CIRC = DMA_ENABLE, .PINC=DMA_DISABLE, .MINC = DMA_ENABLE, .PSIZE = _16BITS, .MSIZE = _16BITS, .PL = VERY_HIGH, .MEM2MEM = DMA_DISABLE},

						{.EN = DMA_DISABLE, .TCIE =DMA_ENABLE,.HTIE = DMA_DISABLE,.TEIE = DMA_ENABLE, .DIR = READ_FROM_PERIPHERAL, \
						.CIRC = DMA_ENABLE, .PINC=DMA_DISABLE, .MINC = DMA_ENABLE, .PSIZE = _16BITS, .MSIZE = _16BITS, .PL = VERY_HIGH, .MEM2MEM = DMA_DISABLE},

						{.EN = DMA_DISABLE, .TCIE =DMA_ENABLE,.HTIE = DMA_DISABLE,.TEIE = DMA_ENABLE, .DIR = READ_FROM_PERIPHERAL, \
						.CIRC = DMA_ENABLE, .PINC=DMA_DISABLE, .MINC = DMA_ENABLE, .PSIZE = _16BITS, .MSIZE = _16BITS, .PL = VERY_HIGH, .MEM2MEM = DMA_DISABLE},

						};