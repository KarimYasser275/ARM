/*
 * TEMP.c
 *
 *  Created on: Sep 9, 2023
 *      Author: E0162112
 */
#include <stdint.h>
#include "adc.h"
#include "TEMP.h"

extern ADC_HandleTypeDef hadc1;
uint16_t ADC_rawValue = 0;
/*Gets Temprature readings from ADC channel */
uint16_t TEMP_GetRawADC(void)
{

	HAL_ADC_PollForConversion(&hadc1, 1000);
	ADC_rawValue = HAL_ADC_GetValue(&hadc1);
	return ADC_rawValue;
}

/*Converts Raw ADC readings to actual temperature*/
float TEMP_ConvertToTemp(void)
{
	uint16_t rawTemp = TEMP_GetRawADC();
//	rawTemp = rawTemp * (3.3/4096);
	float Temp = 0;

//	Temp = ((V25_VALUE - rawTemp)/AVG_SLOPE) + 25 ;
	Temp = 357.558 - 0.187364 * (float)rawTemp;

	return Temp;

}
