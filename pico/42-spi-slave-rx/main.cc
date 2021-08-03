#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
//#include "hardware/adc.h"
//#include "hardware/clocks.h"
//#include "hardware/flash.h"
#include "hardware/gpio.h"
//#include "hardware/irq.h"
//#include "hardware/pwm.h"
#include "hardware/spi.h"
// #include "tusb.h" // if you want to use tud_cdc_connected()

#include "pi.h"


/*
typedef struct spi_t {
	spi_inst_t* inst;
	uint sck;
	uint cs;
} spi_t;

enum spi_type_e {
	SPI_MASTER_TX // master mode, transmit only
}; 

void pi_spi_init(spi_t* spi, uint sck, uint cs, spi_type_e SPI_MASTER_TX)
{
	spi->inst = inst;
	spi->scl = sck;
	gpio_set_function(sck,  GPIO_FUNC_SPI); // sck
	spi->cs = cs;

	switch(SPI_MASTER_TX) {
		case SPI_MASTER_TX: 
			gpio_set_function(sck+1, GPIO_FUNC_SPI); // mosi
			//gpio_set_function(sck+2, GPIO_FUNC_SPI); // miso, not requires
			gpio_put(cs, 1);
			pi_gpio_init(cs, OUTPUT);
			break;
	}


}
*/

#define SLAVE_SCK 	2
#define SLAVE_MOSI	3
#define SLAVE_CS	5

#define LED		25

int main() 
{
	stdio_init_all();
	pi_gpio_init(LED, OUTPUT);
	pi_max7219_init();
	pi_max7219_show_count(666);

	// set up slave
	uint baud = 100'000;
	spi_init(spi0, baud);
	spi_set_slave(spi0, true);
	gpio_set_function(SLAVE_SCK,  GPIO_FUNC_SPI);
	gpio_set_function(SLAVE_MOSI, GPIO_FUNC_SPI);
	gpio_set_function(SLAVE_CS, GPIO_FUNC_SPI);

	uint32_t count;
	while(1) {
		spi_read_blocking(spi0, 0x00, (unsigned char*) &count, 4);
		pi_gpio_toggle(LED);
		count = __builtin_bswap32(count); // big endian to little endian
		//count = 666;
		pi_max7219_show_count(count);
	}

}

