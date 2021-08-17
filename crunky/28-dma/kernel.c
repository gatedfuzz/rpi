#include <gpio.h>
#include <timers.h>


void kernel_main(void)
{
	const int bcm_pin = 26;
	gpio_sel(bcm_pin, OUTPUT); // set its pin mode to OUTPUT
	u32 delay = 250;
	while(1) {
		gpio_set(bcm_pin); // set the pin high
		delay_ms(delay);  
		gpio_clr(bcm_pin); // turn the pin off
		delay_ms(delay);
	}
}
