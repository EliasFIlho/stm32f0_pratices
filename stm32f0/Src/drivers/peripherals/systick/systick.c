/*
 * systick.c
 *
 *  Created on: Dec 19, 2024
 *      Author: elias
 */


#include "systick.h"

void delay_us(uint32_t delay_time){
	SysTick->LOAD = SYSTICK_LOAD_VALUE_US;
	SysTick->VAL = 0;
	SysTick->CTRL |= (SYST_CSR_CLKSOURCE | SYST_CSR_ENABLE);

	for(int i=0;i<delay_time;i++){
		while((SysTick->CTRL & SYST_CSR_COUNTFLAG) == 0);
	}
	SysTick->CTRL = 0;
}

void delay_ms(uint32_t delay_time){
	SysTick->LOAD = SYSTICK_LOAD_VALUE_MS;
	SysTick->VAL = 0;
	SysTick->CTRL |= (SYST_CSR_CLKSOURCE | SYST_CSR_ENABLE);

	for(int i=0;i<delay_time;i++){
		while((SysTick->CTRL & SYST_CSR_COUNTFLAG) == 0);
	}
	SysTick->CTRL = 0;
}

void delay_s(uint32_t delay_time){
	SysTick->LOAD = SYSTICK_LOAD_VALUE_S;
	SysTick->VAL = 0;
	SysTick->CTRL |= (SYST_CSR_CLKSOURCE | SYST_CSR_ENABLE);

	for(int i=0;i<delay_time;i++){
		while((SysTick->CTRL & SYST_CSR_COUNTFLAG) == 0);
	}
	SysTick->CTRL = 0;
}
