/**
* @file config.hpp
* @author Mitchel Walker
* @date 11/4/2021
*
* @brief This file contains configuration values and constants for the
* 		 Embedded Flight Controller project.
*
*/
#pragma once

// Select Target MCU for conditional includes in driver files
#define TARGET_STM32F4


namespace EFC {
	// Servo Timer Channels
	const int left_aileron_channel = 1;
	const int right_aileron_channel = 2;

	// Servo Angular Ranges
	const double left_aileron_range = 130.;
	const double right_aileron_range = 180.;

}
