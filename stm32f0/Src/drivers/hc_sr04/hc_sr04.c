/*
 * hc_sr04.c
 *
 *  Created on: Dec 19, 2024
 *      Author: elias
 */



#include "hc_sr04.h"

void static _trigger_io(GPIO_TypeDef *GPIOX, uint8_t pin);
volatile uint16_t first_time = 0;
volatile uint16_t second_time = 0;
volatile uint8_t capture_complete = 0;

/*This Library will be limit the echo pin to PA6.
Witch means that for now if the echo pin was != from PA6 the function will return a error
if i have any motivation i can try to create a dynamic timer chooser based on GPIO PIN
*/

stm_error_t hcsr04_init(gpio_config_t *echo, gpio_config_t *trigger){
	if(echo->pin != 6 || echo->GPIOX != GPIOA){
		return STM_FAIL;
	}else{

		stm_error_t ret = gpio_cfg_peripheral(trigger);
		if(ret != STM_OK){
			return STM_FAIL;
		}else{

		}

		ret = gpio_cfg_peripheral(echo);
		if(ret != STM_OK){
				return STM_FAIL;
		}else{
			gpio_select_alternate_function(echo->GPIOX,echo->pin,AF1);

		}
		init_input_capture(TIM3, CH1, BOTH_EDGE);
	}
	return STM_OK;

}

/*
 *
 * T = D/V
 * D = T*V
 *
 * */

uint16_t hcsr04_read_distance_cm(gpio_config_t *trigger){
	_trigger_io(trigger->GPIOX,trigger->pin);
	uint32_t timeout = 1000000;
	while(capture_complete == 0){
		timeout--;
		if(timeout == 0){
			return 0;
		}
	}
	uint16_t dif = second_time - first_time;
	if (dif < 0) {
		dif = UINT32_MAX - first_time + second_time;
	}
	second_time = 0;
	first_time = 0;
	return (uint16_t)((dif * SOUND_SPEED)/2);
}


uint16_t hcsr04_read_echo_time_lenght(gpio_config_t *trigger){
	_trigger_io(trigger->GPIOX,trigger->pin);
		uint32_t timeout = 1000000;
		while(capture_complete == 0){
			timeout--;
			if(timeout == 0){
				return 0;
			}
		}
		uint16_t dif = second_time - first_time;
		if (dif < 0) {
			dif = UINT32_MAX - first_time + second_time;
		}
		second_time = 0;
		first_time = 0;
		return dif;

}


void static _trigger_io(GPIO_TypeDef *GPIOX, uint8_t pin){
	gpio_set_pin(GPIOX, pin);
	delay_us_sys(10);
	gpio_reset_pin(GPIOX, pin);
}

//TODO: USE THE NEW MACROS TO WRITE/CLEAR/TOOGLE BITS

void TIM3_IRQHandler(void){
	if(TIM3->SR & SR_CC1IF_BIT){
		/*Save the first and second time*/
		if(first_time == 0){
			first_time = TIM3->CCR1;
		}else{
			second_time = TIM3->CCR1;
			capture_complete = 1;
		}


		TIM3->SR &= ~SR_CC1IF_BIT;
	}

}
