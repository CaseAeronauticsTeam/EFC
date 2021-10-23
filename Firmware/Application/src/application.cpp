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
//#include "stm32f7xx_hal.h"  // Commented out since last working


void start(TIM_HandleTypeDef* _tim, ADC_HandleTypeDef* _adc)
{
	init();
	launch(_tim, _adc);
}


void init()
{

}

void launch(TIM_HandleTypeDef* _tim, ADC_HandleTypeDef* _adc)
{
	TimServo servo = TimServo();
	servo.init(_tim, 1, 180);

	double theta = 0;
	uint16_t raw;

	while (1)
	{
		HAL_ADC_Start(_adc);
		HAL_ADC_PollForConversion(_adc, HAL_MAX_DELAY);
		raw = HAL_ADC_GetValue(_adc);

		theta = (((double)raw - (double)((2 << 10) - 1)) / (double)((2 << 10) - 1)) * 90.;

		servo.setPos(theta);

	}

//	double theta = 0;
//	uint16_t raw;
//	HAL_TIM_PWM_Start(_tim, TIM_CHANNEL_1);
//	while (1)
//	{
//		HAL_ADC_Start(_adc);
//		HAL_ADC_PollForConversion(_adc, HAL_MAX_DELAY);
//		raw = HAL_ADC_GetValue(_adc);
//		theta = (113. / 2.) * (double)raw / ((1 << 16) - 1);
//		TIM1->CCR1 = (double)((1 << 16) - 1) * (theta / (113. / 8.)) * 2;
//
////		TIM1->CCR1 = (double)(1 << 16 - 1) * (.84 * ((double)raw / (double)(1 << 16 -1)) + .99) / 2.;
//
////		TIM1->CCR1 = (raw / (113. / 2.));
////		TIM1->CCR1 = 1 << 16	;
//
//		HAL_Delay(.1);
//	}

}
