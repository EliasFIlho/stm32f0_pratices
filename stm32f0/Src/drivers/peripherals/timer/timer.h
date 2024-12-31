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
#define CCER_CC1E (1U << 0)
#define CCMRX_INPUT_IC2_BIT_0 (1U << 8)
#define CCMRX_INPUT_IC2_BIT_1 (1U << 9)

#define CCMRX_INPUT_IC3_BIT_0 (1U << 0)
#define CCMRX_INPUT_IC3_BIT_1 (1U << 1)

#define CCMRX_INPUT_IC4_BIT_0 (1U << 8)
#define CCMRX_INPUT_IC4_BIT_1 (1U << 9)


#define CCER_CC1P_BIT (1U << 1)
#define CCER_CC1NP_BIT (1U << 3)

#define DIER_UIE_BIT (1U << 0)
#define DIER_CC1IE_BIT (1U << 1)
#define DIER_CC2IE_BIT (1U << 2)
#define DIER_CC3IE_BIT (1U << 3)
#define DIER_CC4IE_BIT (1U << 4)
#define DIER_TIE_BIT (1U << 6)
#define DIER_UDE_BIT (1U << 8)
#define DIER_CC1DE_BIT (1U << 9)
#define DIER_CC2DE_BIT (1U << 10)
#define DIER_CC3DE_BIT (1U << 11)
#define DIER_CC4DE_BIT (1U << 12)
#define DIER_TDE_BIT (1U << 14)

#define SR_CC1IF_BIT (1U << 1)

typedef enum{
	CH1,
	CH2,
	CH3,
	CH4
}TIM_CHANNEL;

typedef enum{
	RISING,
	FALLING,
	BOTH
}edge_t;

void init_timer(rcc_tim_t timer);

void init_input_capture(TIM_TypeDef *TIMX, TIM_CHANNEL CH,edge_t edge);

#endif /* DRIVERS_PERIPHERALS_TIMER_TIMER_H_ */
