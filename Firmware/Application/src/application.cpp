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

	uint8_t tx_buf = 0;
	uint16_t rx_buf = 0;


	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
	 HAL_SPI_Transmit(&hspi1, (uint8_t *)&tx_buf, 1, 100);
	 HAL_SPI_Receive(&hspi1, (uint8_t *)&rx_buf, 2, 100);
	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
}

void launch()
{

	double thetaL = 0;
	double thetaR = 0;
	uint16_t raw;


	while (1)
	{
		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
		raw = HAL_ADC_GetValue(&hadc1);

		if (!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13))
		{
			// Assign Left Aileron Servo to ADC
			thetaL = (((double)raw - (double)((1 << 11) - 1)) / (double)((1 << 11) - 1)) * 90.;
			leftAileron.setAngle(thetaL);

			// Cycle Right Aileron Servo slowly
			thetaR = thetaR < 90 ? (thetaR + .0002) : -90;
			rightAileron.setAngle(thetaR);
		}
		else  // "Kill"
		{
			leftAileron.setAngle(0);
			rightAileron.setAngle(0);
		}

	}

}
