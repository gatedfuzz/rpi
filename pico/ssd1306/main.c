#include "pico/stdlib.h"
#include "ssd1306.h"
#include <stdio.h>
#include "pi.h"


const uint8_t splash1_data[];

#define ALARM 0
#define DELAY (2*1000000)

static void alarm_0_irq() 
{
	pi_alarm_rearm(ALARM, DELAY);
	char msg[80];
	static volatile int i = 0;
	sprintf(msg, "Count %d\n", i++);
	ssd1306_print(msg);
	//show_scr();
}

#define PIN 17

int main()
{
	//init_i2c();

	int h = 32;
	if(1) h = 64;
	int sda = 6;
	sda = 4;
	init_display(h, 4);

	ssd1306_print("HELLO PICO...\n"); // demonstrate some text
	show_scr();
	sleep_ms(2000);
	fill_scr(0); // empty the screen


	pi_gpio_out(PIN);
	//GpioOut pin(17); // used to test speed of writing

	sleep_ms(2000);
	fill_scr(0);
	setCursorx(0);
	setCursory(0);
	ssd1306_print("Testing cursor");
	show_scr();
	sleep_ms(2000);
	setCursorx(0);
	ssd1306_print("Overwritten   ");
	show_scr();
	sleep_ms(2000);

	// test for both drawing bitmap and cell display handling of output
	clear_scr();
	drawBitmap(0, 0, splash1_data, 64, 64, 1);
	show_scr();
	sleep_ms(2000);
	
	pi_alarm_init(ALARM, alarm_0_irq, DELAY);

	for(;;) {
		pi_gpio_high(PIN);
		ssd1306_display_cell();
		pi_gpio_low(PIN);
		//pin.off();
		sleep_ms(1);
	}

	return 0;
}
