/*
 * rcc.c
 *
 *  Created on: Dec 19, 2024
 *      Author: elias
 */


#include "rcc.h"
//TODO: USE THE NEW MACROS TO WRITE/CLEAR/TOOGLE BITS

void rcc_enable_gpio(rcc_gpio_t gpio){
	RCC->AHBENR |= (1<< gpio);
}
//TODO: USE THE NEW MACROS TO WRITE/CLEAR/TOOGLE BITS

void rcc_enable_timer(rcc_tim_t tim){
	switch(tim){
		case RCC_TIM1:
			RCC->APB2ENR |= RCC_TIM1;
			break;
		case RCC_TIM3:
			RCC->APB1ENR |= RCC_TIM3;
			break;
		case RCC_TIM16:
			RCC->APB2ENR |= RCC_TIM16;
			break;
		case RCC_TIM17:
			RCC->APB2ENR |= RCC_TIM17;
			break;
	}

}
//TODO: USE THE NEW MACROS TO WRITE/CLEAR/TOOGLE BITS

void rcc_enable_usart(){
	RCC->APB2ENR |= RCC_USART1_EN;
}
