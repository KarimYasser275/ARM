/*
 * DMA_cfg.h
 *
 *  Created on: Sep 13, 2023
 *      Author: E0162112
 */

#ifndef SRC_DMA_CFG_H_
#define SRC_DMA_CFG_H_

#include <stdint.h>

typedef enum
{
	READ_FROM_PERIPHERAL,
	READ_FROM_MEMORY,
}DMA_DataDirection_t;

typedef enum
{
	_8BITS ,
	_16BITS,
	_32BITS,
}DMA_Size_t;

typedef enum
{
	LOW,
	MEDIUM,
	HIGH,
	VERY_HIGH,
}DMA_PriorityLevel_t;


typedef struct
{
	/*CCRx*/
	uint32_t EN		:1;		//Enable DMA channel
	uint32_t TCIE	:1;		//transfer complete interrupt enable
	uint32_t HTIE	:1;		//Half transfer interrupt enable
	uint32_t TEIE	:1;		//transfer error interrupt enable
	uint32_t DIR	:1;		//Data direction
	uint32_t CIRC	:1;		//Circular enable/disable
	uint32_t PINC	:1;		//Peripheral increase
	uint32_t MINC	:1;		//memory increase
	uint32_t PSIZE	:2;		//peripheral size
	uint32_t MSIZE	:2;		//memory size
	uint32_t PL		:2;		//priority level
	uint32_t MEM2MEM:1;		//memory to memory

}DMA_config_t;

#endif /* SRC_DMA_CFG_H_ */
