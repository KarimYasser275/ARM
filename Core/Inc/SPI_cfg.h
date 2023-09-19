/*
 * SPI_cfg.h
 *
 *  Created on: Sep 14, 2023
 *      Author: E0162112
 */

#ifndef INC_SPI_CFG_H_
#define INC_SPI_CFG_H_

//#include "SPI_core.h"
#include <stdint.h>

typedef enum
{
	SPI_8BITS,
	SPI_16BITS,
}SPI_FrameSize_t;

typedef enum
{
	SPI_DISABLE = 0,
	SPI_ENABLE = 1,
}SPI_State_t;

typedef enum
{
	SPI_IDLE_LOW,
	SPI_IDLE_HIGH,
}SPI_ClockPolarityModes_t;

typedef enum
{
	SPI_READ_FIRST,
	SPI_READ_SECOND,
}SPI_ClockPhaseModes_t;

typedef enum
{
	SPI_SLAVE,
	SPI_MASTER,
}SPI_MasterSlaveMode_t;

typedef enum
{
	SPI_FpClk_DIV_2,
	SPI_FpClk_DIV_4,
	SPI_FpClk_DIV_8,
	SPI_FpClk_DIV_16,
	SPI_FpClk_DIV_32,
	SPI_FpClk_DIV_64,
	SPI_FpClk_DIV_128,
	SPI_FpClk_DIV_256,
}SPI_BaudRate_t;

typedef enum
{
	SPI_MSB_FIRST,
	SPI_LSB_FIRST,
}SPI_DataDirection_t;

typedef enum
{
	SPI_2_LINE_UNI,
	SPI_1_LINE_BI,
}SPI_BidirectionalMode_t;


typedef struct
{
	/*CR1*/
	SPI_ClockPhaseModes_t CPHA          :1;	    //clock phase
	SPI_ClockPolarityModes_t CPOL       :1;     //clock polarity
	SPI_MasterSlaveMode_t MSTR          :1;     //master selection
	SPI_BaudRate_t BR			        :3;     //baud rate
	SPI_State_t SPE		                :1;     //SPI enable
	SPI_DataDirection_t LSBFIRST        :1;     //0 MSB first , 1 LSB first
	uint16_t SSI		                :1;     //internal slave select
	SPI_State_t SSM		                :1;     //software slave management
	SPI_State_t RXONLY		            :1;     //receive only
	SPI_FrameSize_t DFF	                :1;     //data frame format
	SPI_State_t CRCNEXT	                :1;     //CRC transfer next
	SPI_State_t CRCEN	          	    :1;     //CRC enable
	SPI_State_t BIDIOE	                :1;     //Bidirectional output enable
	SPI_BidirectionalMode_t BIDIMODE    :1;     //bidirectional data mode (0: 2-line unidirectional data mode, 1:1-line bidirectional

	/*CR2*/
	SPI_State_t RXDMAEN					:1;		//Rx buffer DMA enable
	SPI_State_t TXDMAEN					:1;     //Tx buffer DMA enable
	SPI_State_t SSOE					:1;     //SS output enable
	uint16_t	Reserved				:2;		//Reserved bits
	SPI_State_t	ERRIE					:1;     //Error interrupt enable
	SPI_State_t RXNEIE					:1;     //RX buffer not empty interrupt enable
	SPI_State_t	TXEIE					:1;     //Tx buffer empty interrupt enable

}SPI_ConfigParam_t;

#endif /* INC_SPI_CFG_H_ */
