/*
 * uart.h
 *
 *  Created on: Dec 19, 2024
 *      Author: elias
 */


//TODO: Create a error type to handle USART errors.

#ifndef DRIVERS_PERIPHERALS_UART_UART_H_
#define DRIVERS_PERIPHERALS_UART_UART_H_

#include <stdint.h>
#include "stm32f030x6.h"
#include "rcc.h"
#include "gpio.h"
#include <stddef.h>




typedef enum{
	USART_MODE_8_BITS,
	USART_MODE_9_BITS
}usart_frame_lenght_t;


typedef enum{
	STOP_BIT_1,
	STOP_BIT_2
}usart_stop_bit_n_t;


typedef enum{
	TRANSMITTER_ONLY,
	RECEIVER_ONLY,
	TRANSMITTER_AND_RECEIVER
}usart_directions;

typedef enum{
	USART_DIV_8,
	USART_DIV_16
}usart_clock_divider_t;


typedef enum{
	USART_ENABLE_RX_IRQ,
	USART_ENABLE_TX_IRQ,
	USART_ENABLE_BOTH_IRQ,
	USART_DISABLE_IRQ
}usart_irq_en_t;

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
	usart_directions directions;
	usart_irq_en_t irq_en_sel;

}usart_cfg_t;

void usart_init(usart_cfg_t* usart);
void usart_send_byte(uint8_t data);
void usart_send_buffer(uint8_t *data, size_t len);
uint8_t usart_read_byte();



#endif /* DRIVERS_PERIPHERALS_UART_UART_H_ */
