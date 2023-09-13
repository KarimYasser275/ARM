/*
 * TEMP.h
 *
 *  Created on: Sep 9, 2023
 *      Author: E0162112
 */

#ifndef INC_TEMP_H_
#define INC_TEMP_H_

#define V25_VALUE			1.4
#define AVG_SLOPE			0.004478

uint16_t TEMP_GetRawADC(void);

float TEMP_ConvertToTemp(void);

#endif /* INC_TEMP_H_ */
