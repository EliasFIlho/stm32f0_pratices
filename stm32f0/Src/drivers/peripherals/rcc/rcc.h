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
#include "commun.h"


#define RCC_TIM1_EN (1U << 11)
#define RCC_TIM3_EN (1U << 1)
#define RCC_TIM6_EN (1U << 4)
#define RCC_TIM7_EN (1U << 5)
#define RCC_TIM14_EN (1U << 8)
#define RCC_TIM15_EN (1U << 16)
#define RCC_TIM16_EN (1U << 17)
#define RCC_TIM17_EN (1U << 18)

#define RCC_USART1_EN (1U << 14)


typedef enum {
	RCC_GPIOA = 17,
	RCC_GPIOB,
	RCC_GPIOC,
	RCC_GPIOD,
	RCC_GPIOF= 22,
}rcc_gpio_t;


typedef enum {
	RCC_TIM1 = RCC_TIM1_EN,
	RCC_TIM3 = RCC_TIM3_EN,
	RCC_TIM16 = RCC_TIM16_EN,
	RCC_TIM17 = RCC_TIM17_EN
}rcc_tim_t;


void rcc_enable_gpio(rcc_gpio_t gpio);
void rcc_enable_timer(rcc_tim_t tim);
void rcc_enable_usart();
#endif /* DRIVERS_PERIPHERALS_RCC_RCC_H_ */
