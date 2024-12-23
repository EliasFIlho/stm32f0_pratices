/*
 * hc_sr04.c
 *
 *  Created on: Dec 19, 2024
 *      Author: elias
 */


#include "hc_sr04.h"

void static _trigger_io(GPIO_TypeDef *GPIOX, uint8_t pin);
void static _read_echo(GPIO_TypeDef *GPIOX, uint8_t pin);


stm_error_t hcsr04_init(gpio_config_t *echo, gpio_config_t *trigger){
	stm_error_t ret = gpio_cfg_peripheral(trigger);
	if(ret != STM_OK){
		return STM_FAIL;
	}else{
		return gpio_cfg_peripheral(echo);
	}

}

uint8_t hcsr04_read_distance_cm(gpio_config_t *echo, gpio_config_t *trigger){
	_trigger_io(trigger->GPIOX,trigger->pin);

	return 0;

}

void static _trigger_io(GPIO_TypeDef *GPIOX, uint8_t pin){
	gpio_set_pin(GPIOX, pin);
	delay_us(10);
	gpio_reset_pin(GPIOX, pin);
}
