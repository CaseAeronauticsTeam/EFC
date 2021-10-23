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


void start(TIM_TypeDef* _tim, TIM_TypeDef* _tim2, TIM_HandleTypeDef* _timHandler, ADC_HandleTypeDef* _adc);

void init(TIM_TypeDef* _tim, TIM_HandleTypeDef* _timHandler);

void launch(TIM_TypeDef* _tim, TIM_TypeDef* _tim2, TIM_HandleTypeDef* _timHandler, ADC_HandleTypeDef* _adc);


#ifdef __cplusplus
}
#endif
