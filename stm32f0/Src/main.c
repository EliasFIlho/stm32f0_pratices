#include <stdint.h>
#include "stm32f030x6.h"
#include "drivers/peripherals/rcc/rcc.h"
#include "drivers/peripherals/gpio/gpio.h"
#include "drivers/peripherals/systick/systick.h"
#include "drivers/peripherals/timer/timer.h"

int main(void)
{
	gpio_config_t gpio_cfg ={
		.GPIOX = GPIOA,
		.direction = OUTPUT,
		.output_mode = PUSH_PULL,
		.pupdr = NO_PUPD,
		.speed = LOW_SPEED,
		.pin = 4
	};

	gpio_init(RCC_GPIOA);
	gpio_cfg_peripheral(&gpio_cfg);
	init_timer(RCC_TIM3);

	while(1){
		gpio_toggle_pin(gpio_cfg.GPIOX, gpio_cfg.pin);
		delay_ms_sys(100);

	}
}
