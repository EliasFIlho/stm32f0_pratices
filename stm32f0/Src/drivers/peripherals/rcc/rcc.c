/*
 * rcc.c
 *
 *  Created on: Dec 19, 2024
 *      Author: elias
 */


#include "rcc.h"

void rcc_enable_gpio(rcc_gpio_t gpio){
	RCC->AHBENR |= (1<< gpio);
}

