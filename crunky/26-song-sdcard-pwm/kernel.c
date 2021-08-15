#include <assert.h>
#include <stdio.h>
#include <bcm2835.h>
#include <../pico/fat32.h>

// PWM output on RPi Plug P1 pin 12 (which is GPIO pin 18)
// in alt fun 5.
// Note that this is the _only_ PWM pin available on the RPi IO headers
#define PIN RPI_GPIO_P1_12
// and it is controlled by PWM channel 0
#define PWM_CHANNEL 0
// This controls the max range of the PWM signal
#define RANGE 256


uint8_t* song;
uint32_t len;

void kernel_main(void)
{
	puts("\nPlaying song with PWM audio");

	fat32_init();
	file32_t file;
	char cooked_name[12];
	canfile(cooked_name, "song.raw");
	file32_init(&file, cooked_name);
	printf("Song %s\n", file32_found(&file) ? "found" : "unfound");
	len = file32_size(&file);
	song = malloc(len);
	assert(song);



	bcm2835_init();

	// Set the output pin to Alt Fun 5, to allow PWM channel 0 to be output there
	bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_ALT5);

	// PWM base frequency is 19.2MHz
	// freq = 19'200'000/DIVIDER/RANGE = 19'200'000/4/256 = 18750Hz
	bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16);
	bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_4);
	bcm2835_pwm_set_mode(PWM_CHANNEL, 1, 1);
	bcm2835_pwm_set_range(PWM_CHANNEL, RANGE);


	uint32_t offset = 0;
	while(file32_read(&file, song + offset))
		offset += 512;
	puts("Song finished reading.");

	// Vary the PWM m/s ratio between 1/RANGE and (RANGE-1)/RANGE
	int idx = 0;
	//int data = 1;
	while (1)
	{
		unsigned char data = song[idx++];
		if(idx == len) idx = 0;

		bcm2835_pwm_set_data(PWM_CHANNEL, data);
		bcm2835_delayMicroseconds(1000000/16000);
	}

	bcm2835_close();
}