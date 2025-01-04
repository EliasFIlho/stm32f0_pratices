/*
 * uart.c
 *
 *  Created on: Dec 19, 2024
 *      Author: elias
 */


#include "uart.h"


static void usart_config_wl(usart_frame_lenght_t wl);
static void usart_config_boud_rate(uint32_t boud_rate, usart_clock_divider_t usart_div);

void uart_init(usart_cfg *usart){
	rcc_enable_usart();
	gpio_cfg_peripheral(usart->tx_pin);
	gpio_cfg_peripheral(usart->rx_pin);
	usart_config_wl(usart->mode);

}




static void usart_config_wl(usart_frame_lenght_t wl){
	if(wl == MODE_9_BITS){
		// Do 9 bits
	}else{
		// Do 8 bits
	}
}


static void usart_config_boud_rate(uint32_t boud_rate, usart_clock_divider_t usart_div){
	if(usart_div == USART_DIV_16){
		//Do the 16 calculation and assign to BRR
	}else{
		//Do the 8 calculation and assign to BRR

	}


}
