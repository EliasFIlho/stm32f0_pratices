/*
 * gpio.c
 *
 *  Created on: Dec 19, 2024
 *      Author: elias
 */


#include "gpio.h"


void gpio_init(rcc_gpio_t port){
	rcc_enable_gpio(port);
}

stm_error_t gpio_cfg_peripheral(gpio_config_t *cfg){


	if(cfg->pin > 15 || cfg->pin < 0){
		return STM_FAIL;
	}else{
		if(cfg->direction == OUTPUT){
			cfg->GPIOX->MODER |= (1 << (cfg->pin*2));
			cfg->GPIOX->MODER &= ~(1 << ((cfg->pin*2)+1));
			if(cfg->output_mode == OPEN_DRAIN){
				cfg->GPIOX->OTYPER |= (1 << cfg->pin);
			}else{
				cfg->GPIOX->OTYPER &= ~(1 << cfg->pin);
			}
			if(cfg->speed == HIGH_SPEED){
				cfg->GPIOX->OSPEEDR |= (1 << (cfg->pin*2));
				cfg->GPIOX->OSPEEDR |= (1 << ((cfg->pin*2)+1));
			}else if(cfg->speed == MEDIUM_SPEED){
				cfg->GPIOX->OSPEEDR |= (1 << (cfg->pin*2));
				cfg->GPIOX->OSPEEDR &= ~(1 << ((cfg->pin*2)+1));

			}else{
				cfg->GPIOX->OSPEEDR &= ~(1 << (cfg->pin)*2);
			}
			return STM_OK;
		}else if(cfg->direction == INPUT){
			cfg->GPIOX->MODER &= ~(1 << (cfg->pin*2));
			cfg->GPIOX->MODER &= ~(1 << ((cfg->pin*2)+1));
			if(cfg->pupdr == PULL_UP){
				cfg->GPIOX->PUPDR |= (1<<(cfg->pin)*2);
				cfg->GPIOX->PUPDR &= ~(1<<(((cfg->pin)*2)+1));

			}else if(cfg->pupdr == NO_PUPD){
				cfg->GPIOX->PUPDR &= ~(1<<(cfg->pin)*2);
				cfg->GPIOX->PUPDR &= ~(1<<(((cfg->pin)*2)+1));
			}else{
				cfg->GPIOX->PUPDR &= ~(1<<(cfg->pin)*2);
				cfg->GPIOX->PUPDR |= (1<<(((cfg->pin)*2)+1));
			}
			return STM_OK;
		}else{
			return STM_FAIL;
		}
	}

}

stm_error_t gpio_toggle_pin(GPIO_TypeDef *GPIOX, uint8_t pin){
	if(pin >= 0 && pin <=15){
		GPIOX->ODR ^= (1 << pin);
		return STM_OK;
	}else{
		return STM_FAIL;
	}
}

stm_error_t gpio_set_pin(GPIO_TypeDef *GPIOX, uint8_t pin){
	if(pin >= 0 && pin <=15){
		GPIOX->BSRR |= (1 << pin);
		return STM_OK;
	}else{
		return STM_FAIL;
	}
}

stm_error_t gpio_reset_pin(GPIO_TypeDef *GPIOX, uint8_t pin){
	if(pin >= 0 && pin <=15){
		GPIOX->BSRR |= (1 << (pin+16));
		return STM_OK;
	}else{
		return STM_FAIL;
	}
}
