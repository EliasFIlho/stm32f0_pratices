/*
 * rcc.h
 *
 *  Created on: Dec 19, 2024
 *      Author: elias
 */

#ifndef DRIVERS_PERIPHERALS_RCC_RCC_H_
#define DRIVERS_PERIPHERALS_RCC_RCC_H_

#include <stdint.h>
#include "stm32f030x6.h"



typedef enum {
	RCC_GPIOA = 17,
	RCC_GPIOB,
	RCC_GPIOC,
	RCC_GPIOD,
	RCC_GPIOF= 22,
}rcc_gpio_t;


void rcc_enable_gpio(rcc_gpio_t gpio);

#endif /* DRIVERS_PERIPHERALS_RCC_RCC_H_ */
