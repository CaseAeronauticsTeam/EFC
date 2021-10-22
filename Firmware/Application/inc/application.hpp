/**
* @file application.cpp
* @author Mitchel Walker
* @date 9/3/2021
*
* @brief This file contains the primary functionality for the Embedded Flight
* 	     Controller system
*
*/
#pragma once



#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f7xx.h>


void start(TIM_HandleTypeDef* _tim, ADC_HandleTypeDef* _adc);

void init();

void launch(TIM_HandleTypeDef* _tim, ADC_HandleTypeDef* _adc);


#ifdef __cplusplus
}
#endif
