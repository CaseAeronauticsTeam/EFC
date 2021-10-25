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

extern SPI_HandleTypeDef hspi1;
extern TIM_HandleTypeDef htim1;
extern ADC_HandleTypeDef hadc1;


void start()
{
	init();
	launch();

}


void init()
{
	leftAileron.init(TIM1, &htim1, 1, 180);
	rightAileron.init(TIM1, &htim1, 2, 130);
}

void launch()
{


	while (1)
	{


	}

}
