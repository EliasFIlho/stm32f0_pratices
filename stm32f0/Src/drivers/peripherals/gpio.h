/*
 * gpio.h
 *
 *  Created on: Dec 19, 2024
 *      Author: elias
 */

#ifndef DRIVERS_PERIPHERALS_GPIO_GPIO_H_
#define DRIVERS_PERIPHERALS_GPIO_GPIO_H_


#include <stdint.h>
#include "stm32f030x6.h"
#include "commun.h"

#include "rcc.h"


typedef enum{
	STM_OK,
	STM_FAIL
}stm_error_t;

typedef enum{
	OUTPUT,
	INPUT,
	ALTERNATE_FUNCTION
}gpio_mode_t;

typedef enum{
	PUSH_PULL,
	OPEN_DRAIN
}gpio_output_mode_t;

typedef enum{
	LOW_SPEED,
	MEDIUM_SPEED,
	HIGH_SPEED
}gpio_output_speed_t;

typedef enum{
	NO_PUPD,
	PULL_UP,
	PULL_DOWN
}gpio_pupd_t;

typedef enum{
	AF0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7
}gpio_af_t;



typedef struct{
	GPIO_TypeDef *GPIOX;
	gpio_mode_t direction;
	gpio_output_mode_t output_mode;
	gpio_output_speed_t speed;
	gpio_pupd_t pupdr;
	uint8_t pin;
	gpio_af_t AF;
}gpio_config_t ;

void gpio_init(rcc_gpio_t port);
stm_error_t gpio_cfg_peripheral(gpio_config_t *cfg);
stm_error_t gpio_toggle_pin(GPIO_TypeDef *GPIOX, uint8_t pin);
stm_error_t gpio_set_pin(GPIO_TypeDef *GPIOX, uint8_t pin);
stm_error_t gpio_reset_pin(GPIO_TypeDef *GPIOX, uint8_t pin);
uint8_t gpio_read_pin(GPIO_TypeDef *GPIOX, uint8_t pin);
void gpio_select_alternate_function(GPIO_TypeDef *GPIOX,uint8_t pin,gpio_af_t AF);
#endif /* DRIVERS_PERIPHERALS_GPIO_GPIO_H_ */
