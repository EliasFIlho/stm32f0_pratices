/*
 * timer.h
 *
 *  Created on: Dec 19, 2024
 *      Author: elias
 */

#ifndef DRIVERS_PERIPHERALS_TIMER_TIMER_H_
#define DRIVERS_PERIPHERALS_TIMER_TIMER_H_

#include "stm32f030x6.h"
#include "../rcc/rcc.h"



#define DELAY_PSC_S 8000000
#define DELAY_PSC_MS 8000
#define DELAY_PSC_US 8
#define TIMX_CR1_EN (1U << 0)
#define UIF_EVENT (1U << 0)


#define CCMRX_INPUT_IC1_BIT_0 (1U << 0)
#define CCMRX_INPUT_IC1_BIT_1 (1U << 1)
#define CCMRX_INPUT_IC2_BIT_0 (1U << 8)
#define CCMRX_INPUT_IC2_BIT_1 (1U << 9)

#define CCMRX_INPUT_IC3_BIT_0 (1U << 0)
#define CCMRX_INPUT_IC3_BIT_1 (1U << 1)

#define CCMRX_INPUT_IC4_BIT_0 (1U << 8)
#define CCMRX_INPUT_IC4_BIT_1 (1U << 9)



typedef enum{
	CH1,
	CH2,
	CH3,
	CH4
}TIM_CHANNEL;


void init_timer(rcc_tim_t timer);

void init_input_capture(TIM_TypeDef *TIMX, TIM_CHANNEL CH);

#endif /* DRIVERS_PERIPHERALS_TIMER_TIMER_H_ */
