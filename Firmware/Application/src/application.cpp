/**
* @file application.cpp
* @author Mitchel Walker
* @date 9/3/2021
*
* @brief This file contains the primary functionality for the Embedded Flight
* 	     Controller system
*
*/

#include "application.hpp"
#include "TimServo.hpp"


void start(TIM_TypeDef* _tim, TIM_HandleTypeDef* _timHandler, ADC_HandleTypeDef* _adc)
{
	init();
	launch(_tim, _timHandler, _adc);
}


void init()
{

}

void launch(TIM_TypeDef* _tim, TIM_HandleTypeDef* _timHandler, ADC_HandleTypeDef* _adc)
{
	TimServo servo = TimServo();
	servo.init(_tim, _timHandler, 1, 180);

	double theta = 0;
	uint16_t raw;

	while (1)
	{
		HAL_ADC_Start(_adc);
		HAL_ADC_PollForConversion(_adc, HAL_MAX_DELAY);
		raw = HAL_ADC_GetValue(_adc);

		theta = (((double)raw - (double)((1 << 11) - 1)) / (double)((1 << 11) - 1)) * 90.;

		servo.setAngle(theta);

	}

}
