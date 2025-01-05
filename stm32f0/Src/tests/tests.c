/*
 * tests.c
 *
 *Herer will be defined all the tests to be called on main file
 *The goal is to create several routines to test peripherals so we can make sure that the driver works well
 *
 *  Created on: Jan 5, 2025
 *      Author: elias
 */


#include "tests.h"


void GPIO_TEST_TOOGLE_PIN(){
	gpio_init(RCC_GPIOA);
	gpio_config_t led_pin = {
				.GPIOX = GPIOA,
				.direction = OUTPUT,
				.output_mode = PUSH_PULL,
				.pupdr = NO_PUPD,
				.speed = LOW_SPEED,
				.pin = 4
		};

		gpio_cfg_peripheral(&led_pin);

		while(1){
			gpio_toggle_pin(led_pin.GPIOX, led_pin.pin);
			delay_ms_sys(500);
		}

}


void USART_TEST_TRANSMITTE_SINGLE_BYTE(){
	gpio_init(RCC_GPIOA);
	gpio_config_t tx_pin = {
					.GPIOX = GPIOA,
					.direction = ALTERNATE_FUNCTION,
					.pin = 9,
					.AF = AF1
			};
	gpio_config_t rx_pin = {
						.GPIOX = GPIOA,
						.direction = ALTERNATE_FUNCTION,
						.pin = 10,
						.AF = AF1
				};
	usart_cfg_t usart = {
		.baud_rate = 9600,
		.directions = TRANSMITTER_ONLY,
		.irq_en_sel = USART_DISABLE_IRQ,
		.mode = USART_MODE_8_BITS,
		.rx_pin = &rx_pin,
		.tx_pin = &tx_pin,
		.stop_bit_n = STOP_BIT_1,
		.usart_div = USART_DIV_16,
	};
	usart_init(&usart);



	while(1){
		usart_send_byte('G');
		delay_ms_sys(300);
	}



}
void USART_TEST_TRANSMITTE_BUFFER(){
	gpio_init(RCC_GPIOA);
		gpio_config_t tx_pin = {
						.GPIOX = GPIOA,
						.direction = ALTERNATE_FUNCTION,
						.pin = 9,
						.AF = AF1
				};
		gpio_config_t rx_pin = {
							.GPIOX = GPIOA,
							.direction = ALTERNATE_FUNCTION,
							.pin = 10,
							.AF = AF1
					};
		usart_cfg_t usart = {
			.baud_rate = 9600,
			.directions = TRANSMITTER_ONLY,
			.irq_en_sel = USART_DISABLE_IRQ,
			.mode = USART_MODE_8_BITS,
			.rx_pin = &rx_pin,
			.tx_pin = &tx_pin,
			.stop_bit_n = STOP_BIT_1,
			.usart_div = USART_DIV_16,
		};
		usart_init(&usart);
		char *data = "elias\n";
		while(1){
			usart_send_buffer(data, 6);
			delay_ms_sys(500);
		}

}

void GPIO_TEST_POLLING_READ(){}
void GPIO_TEST_INTERRUPT_READ(){}

void TIMER_TEST_INPUT_CAPTURE(){

}
