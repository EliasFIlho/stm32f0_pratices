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


//TODO: USE THE NEW MACROS TO WRITE/CLEAR/TOOGLE BITS

uint8_t gpio_read_pin(GPIO_TypeDef *GPIOX, uint8_t pin){
	return ((GPIOX->IDR & (1 << pin))>> pin);
}

//TODO: USE THE NEW MACROS TO WRITE/CLEAR/TOOGLE BITS

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
		}else if(cfg->direction == ALTERNATE_FUNCTION){
			cfg->GPIOX->MODER |= (1 << ((cfg->pin*2)+1));
			cfg->GPIOX->MODER &= ~(1 << (cfg->pin*2));
			gpio_select_alternate_function(cfg->GPIOX,cfg->pin,cfg->AF);
			return STM_OK;
		}else{
			return STM_FAIL;
		}
	}

}

//TODO: USE THE NEW MACROS TO WRITE/CLEAR/TOOGLE BITS

void gpio_select_alternate_function(GPIO_TypeDef *GPIOX, uint8_t pin, gpio_af_t AF){
	if(pin <= 15){
		if(pin <= 7){
			GPIOX->AFR[0] &= ~(7 << (pin * 4));
			GPIOX->AFR[0] |= (AF << (pin * 4));
		}else{
			GPIOX->AFR[1] &= ~(7 << ((pin - 8) * 4));
			GPIOX->AFR[1] |= (AF << ((pin - 8) * 4));
		}
	}else{

	}
}
//TODO: USE THE NEW MACROS TO WRITE/CLEAR/TOOGLE BITS

stm_error_t gpio_toggle_pin(GPIO_TypeDef *GPIOX, uint8_t pin){
	if(pin >= 0 && pin <=15){
		GPIOX->ODR ^= (1 << pin);
		return STM_OK;
	}else{
		return STM_FAIL;
	}
}
//TODO: USE THE NEW MACROS TO WRITE/CLEAR/TOOGLE BITS

stm_error_t gpio_set_pin(GPIO_TypeDef *GPIOX, uint8_t pin){
	if(pin >= 0 && pin <=15){
		SET_BIT(GPIOX->BSRR,pin);
		return STM_OK;
	}else{
		return STM_FAIL;
	}
}
//TODO: USE THE NEW MACROS TO WRITE/CLEAR/TOOGLE BITS

stm_error_t gpio_reset_pin(GPIO_TypeDef *GPIOX, uint8_t pin){
	if(pin >= 0 && pin <=15){
		SET_BIT(GPIOX->BSRR,pin+16);
		return STM_OK;
	}else{
		return STM_FAIL;
	}
}
