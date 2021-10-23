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



static TimServo leftAileron = TimServo();
static TimServo rightAileron = TimServo();


void start(TIM_TypeDef* _tim, TIM_HandleTypeDef* _timHandler, ADC_HandleTypeDef* _adc)
{
	init();
	launch(_tim, _timHandler, _adc);

}


void init()
{
	leftAileron.init(_tim, _timHandler, 1, 180);
	rightAileron.init(_tim, _timHandler, 2, 130);
}

void launch(TIM_TypeDef* _tim, TIM_HandleTypeDef* _timHandler, ADC_HandleTypeDef* _adc)
{

	double thetaL = 0;
	double thetaR = 0;
	uint16_t raw;


	while (1)
	{
		HAL_ADC_Start(_adc);
		HAL_ADC_PollForConversion(_adc, HAL_MAX_DELAY);
		raw = HAL_ADC_GetValue(_adc);

		if (!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13))
		{
			// Assign Left Aileron Servo to ADC
			thetaL = (((double)raw - (double)((1 << 11) - 1)) / (double)((1 << 11) - 1)) * 90.;
			leftAileron.setAngle(thetaL);

			// Cycle Right Aileron Servo slowly
			thetaR = thetaR < 80 ? (thetaR + .0002) : -90;
			rightAileron.setAngle(thetaR);
		}
		else  // "Kill"
		{
			leftAileron.setAngle(0);
			rightAileron.setAngle(0);
		}

	}

}
