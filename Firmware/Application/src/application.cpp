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
	init(_tim, _timHandler);
	launch(_tim, _timHandler, _adc);

}


void init(TIM_TypeDef* _tim, TIM_HandleTypeDef* _timHandler)
{
	leftAileron.init(_tim, _timHandler, 1, 180);
	rightAileron.init(_tim, _timHandler, 2, 130);
}

void launch(TIM_TypeDef* _tim, TIM_HandleTypeDef* _timHandler, ADC_HandleTypeDef* _adc)
{

	while (1)
	{


	}

}
