#include <stdint.h>
#include "stm32f030x6.h"
#include "drivers/peripherals/rcc/rcc.h"
#include "drivers/peripherals/gpio/gpio.h"
#include "drivers/peripherals/systick/systick.h"
#include "drivers/peripherals/timer/timer.h"
#include "drivers/hc_sr04/hc_sr04.h"

int main(void)
{
	gpio_config_t trigger ={
		.GPIOX = GPIOA,
		.direction = OUTPUT,
		.output_mode = PUSH_PULL,
		.pupdr = NO_PUPD,
		.speed = LOW_SPEED,
		.pin = 7
	};
	gpio_config_t echo ={
			.GPIOX = GPIOA,
			.direction = ALTERNATE_FUNCTION,
			.output_mode = PUSH_PULL,
			.pupdr = NO_PUPD,
			.speed = LOW_SPEED,
			.pin = 6
	};

	gpio_init(RCC_GPIOA);
	init_timer(RCC_TIM3);
	hcsr04_init(&echo, &trigger);
	uint16_t distance = 0;
	while(1){
		distance = hcsr04_read_distance_cm(&trigger);
		delay_ms_sys(100);

	}
}
