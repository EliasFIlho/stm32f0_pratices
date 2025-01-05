/*
 * tests.h
 *
 *  Created on: Jan 5, 2025
 *      Author: elias
 */

#ifndef TESTS_TESTS_H_
#define TESTS_TESTS_H_


#include <stdint.h>
#include "stm32f030x6.h"
#include "../drivers/peripherals/systick.h"
#include "../drivers/peripherals/gpio.h"
#include "../drivers/peripherals/uart.h"
#include "../drivers/peripherals/timer.h"

void GPIO_TEST_TOOGLE_PIN();
void GPIO_TEST_POLLING_READ();
void GPIO_TEST_INTERRUPT_READ();
void USART_TEST_TRANSMITTE_SINGLE_BYTE();
void USART_TEST_TRANSMITTE_BUFFER();
void USART_TEST_RECEIVER();
void USART_TEST_INTERRUPT();
void TIMER_TEST_INPUT_CAPTURE();


#endif /* TESTS_TESTS_H_ */
