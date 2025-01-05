/*
 * systick.h
 *
 *  Created on: Dec 19, 2024
 *      Author: elias
 */

#ifndef DRIVERS_PERIPHERALS_SYSTICK_SYSTICK_H_
#define DRIVERS_PERIPHERALS_SYSTICK_SYSTICK_H_

#include <stdint.h>
#include "stm32f030x6.h"
#include "commun.h"
#define SYST_CSR_ENABLE (1<<0)
#define SYST_CSR_CLKSOURCE (1<<2)
#define SYST_CSR_COUNTFLAG (1 << 16)

#define SYSTICK_LOAD_VALUE_S 8000000
#define SYSTICK_LOAD_VALUE_MS 8000
#define SYSTICK_LOAD_VALUE_US 8


//8Mhz = 8 000 000/sec
//		  8 000	/msec
//		  8		/usec





void delay_ms_sys(uint32_t delay_time);
void delay_s_sys(uint32_t delay_time);
void delay_us_sys(uint32_t delay_time);

#endif /* DRIVERS_PERIPHERALS_SYSTICK_SYSTICK_H_ */
