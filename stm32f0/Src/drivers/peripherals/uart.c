/*
 * uart.c
 *
 *  Created on: Dec 19, 2024
 *      Author: elias
 */


#include "uart.h"


static void usart_config_wl(usart_frame_lenght_t wl);
static void usart_config_boud_rate(uint32_t boud_rate, usart_clock_divider_t usart_div);
static void usart_config_stop_bits(usart_stop_bit_n_t stp_bits_n);
static void usart_config_oversampling(usart_clock_divider_t usart_div);
static void usart_config_directoins(usart_directions direction);
static void usart_config_enable();
static void usart_enable_interrupt(usart_irq_en_t irq_en);

/*
 * STEPS:
 *
 * Enable clock source to USART peripheral
 * Configure TX and RX pins using the GPIO driver
 * Configure word length
 * Configure the oversampling value
 * Configure boud rate
 * Select the number of stop bits
 * Select transmitter and receiver
 * Enable USART
 * */


void usart_init(usart_cfg_t *usart){
	rcc_enable_usart();
	// OK now i see that i need to change this RCC enable function for GPIO to be more modular
	// Until i don't do that lets write the port by hand before call usart_init :p
	//gpio_init(RCC_GPIOA);
	gpio_cfg_peripheral(usart->tx_pin);
	gpio_cfg_peripheral(usart->rx_pin);
	usart_config_wl(usart->mode);
	usart_config_oversampling(usart->usart_div);
	usart_config_boud_rate(usart->baud_rate,usart->usart_div);
	usart_config_stop_bits(usart->stop_bit_n);
	usart_config_directoins(usart->directions);
	usart_enable_interrupt(usart->irq_en_sel);
	usart_config_enable();
}




static void usart_config_wl(usart_frame_lenght_t wl){
	if(wl == USART_MODE_9_BITS){

		SET_BIT(USART1->CR1,USART_CR1_M_Pos);
	}else if(wl == USART_MODE_8_BITS){
		CLEAR_BIT(USART1->CR1,USART_CR1_M_Pos);
	}else{
		// Error handling
	}
}


static void usart_enable_interrupt(usart_irq_en_t irq_en){
	if(irq_en == USART_ENABLE_TX_IRQ){

		SET_BIT(USART1->CR1,USART_CR1_TCIE_Pos);
	}else if(irq_en == USART_ENABLE_RX_IRQ){
		SET_BIT(USART1->CR1,USART_CR1_RXNEIE_Pos);
	}else if(irq_en == USART_ENABLE_BOTH_IRQ){
		SET_BIT(USART1->CR1,USART_CR1_TCIE_Pos);
		SET_BIT(USART1->CR1,USART_CR1_RXNEIE_Pos);
	}else if(irq_en == USART_DISABLE_IRQ){
		CLEAR_BIT(USART1->CR1,USART_CR1_TCIE_Pos);
		CLEAR_BIT(USART1->CR1,USART_CR1_RXNEIE_Pos);
	}else{

		//Do Error handling
	}
}

static void usart_config_boud_rate(uint32_t boud_rate, usart_clock_divider_t usart_div){

	if(usart_div == USART_DIV_16){

		uint16_t usartdiv = (uint16_t)(SYS_CLK/boud_rate);
		SET_REG(USART1->BRR,usartdiv);


	}else if(usart_div == USART_DIV_8){
		uint16_t usartdiv = (uint16_t)(SYS_CLK/boud_rate);
		uint16_t mantissa = (usartdiv >> 4) & 0xFFF0;
		uint8_t fraction = (usartdiv & 0x0F) >> 1;
		SET_REG(USART1->BRR,(mantissa | fraction));

	}else{
		// Error handling
	}


}

static void usart_config_stop_bits(usart_stop_bit_n_t stp_bits_n){
	if(stp_bits_n == STOP_BIT_2){
		CLEAR_BIT(USART1->CR2,USART_CR2_STOP_Pos);
		SET_BIT(USART1->CR2,USART_CR2_STOP_Pos+1); // This plus one is bcs CMSIS headers dont have the define for bit 13 so i'm using the bit 12 define + 1
	}else if(stp_bits_n == STOP_BIT_1){
		CLEAR_BIT(USART1->CR2,USART_CR2_STOP_Pos);
		CLEAR_BIT(USART1->CR2,USART_CR2_STOP_Pos+1); // This plus one is bcs CMSIS headers dont have the define for bit 13 so i'm using the bit 12 define + 1
	}else{
		// Error handling
	}
}


void usart_config_enable(){
	SET_BIT(USART1->CR1 ,USART_CR1_UE_Pos);
}



static void usart_config_oversampling(usart_clock_divider_t usart_div){

	if(usart_div == USART_DIV_16){
		CLEAR_BIT(USART1->CR1,USART_CR1_OVER8_Pos);
	}else if(usart_div == USART_DIV_8){
		SET_BIT(USART1->CR1,USART_CR1_OVER8_Pos);
	}else{
		// Error handling
	}
}


static void usart_config_directoins(usart_directions direction){
	if(direction == TRANSMITTER_ONLY){
		SET_BIT(USART1->CR1,USART_CR1_TE_Pos);
	}else if(direction == RECEIVER_ONLY){
		SET_BIT(USART1->CR1,USART_CR1_RE_Pos);
	}else if(direction == BOTH){
        SET_BIT(USART1->CR1, USART_CR1_TE_Pos);
        SET_BIT(USART1->CR1, USART_CR1_RE_Pos);
    } else {
        // Error handling
    }
}




// TODO: Create a timeout and a error handler
void usart_send_byte(uint8_t data){
	while(!(USART1->ISR & USART_ISR_TXE));
	SET_REG(USART1->TDR,data);

}

// TODO: Create an error handler
void usart_send_buffer(uint8_t *data, size_t len){
	for(size_t i = 0; i< len;i++){
		usart_send_byte(data[i]);
	}
}





uint8_t usart_read_byte(){
	while(!(USART1->ISR & USART_ISR_RXNE));
	return USART1->RDR;
}














