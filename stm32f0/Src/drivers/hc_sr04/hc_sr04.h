/*
 * hc_sr04.h
 *
 *  Created on: Dec 19, 2024
 *      Author: elias
 */

#ifndef DRIVERS_HC_SR04_HC_SR04_H_
#define DRIVERS_HC_SR04_HC_SR04_H_
#include "stm32f030x6.h"
#include "commun.h"

#include "../peripherals/gpio/gpio.h"
#include "../peripherals/systick/systick.h"
#include "../peripherals/timer/timer.h"

#define SOUND_SPEED 0.0343
stm_error_t hcsr04_init(gpio_config_t *echo, gpio_config_t *trigger);
uint16_t hcsr04_read_distance_cm(gpio_config_t *trigger);
uint16_t hcsr04_read_echo_time_lenght();

#endif /* DRIVERS_HC_SR04_HC_SR04_H_ */
