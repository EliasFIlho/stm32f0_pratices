/*
 * uart.h
 *
 *  Created on: Dec 19, 2024
 *      Author: elias
 */

#ifndef DRIVERS_PERIPHERALS_UART_UART_H_
#define DRIVERS_PERIPHERALS_UART_UART_H_

#include <stdint.h>
#include "stm32f030x6.h"
#include "../rcc/rcc.h"
#include "../gpio/gpio.h"


#define USART_UE_BIT (1U << 0)
#define USART_M0_BIT (1U << 12)
#define USART_M1_BIT (1U << 28)
#define USART_OVER8_BIT (1U << 15)
#define USART_STOP_BIT0 (1U << 12)
#define USART_STOP_BIT1 (1U << 13)


typedef enum{
	MODE_8_BITS,
	MODE_9_BITS
}usart_frame_lenght_t;


typedef enum{
	STOP_BIT_1,
	STOP_BIT_2
}usart_stop_bit_n_t;


typedef enum{
	USART_DIV_8,
	USART_DIV_16
}usart_clock_divider_t;


/*
 * UART pins should be configured previous by the user to set the currently alternate function.
 * For the STM32F030 DEMO BOARD V1.1 use PA9 as TXD and PA10 as RXD
 * */



typedef struct{
	gpio_config_t *tx_pin;
	gpio_config_t *rx_pin;
	uint32_t baud_rate;
	usart_clock_divider_t usart_div;
	usart_frame_lenght_t mode;
	usart_stop_bit_n_t stop_bit_n;


}usart_cfg;

void uart_init();



#endif /* DRIVERS_PERIPHERALS_UART_UART_H_ */
