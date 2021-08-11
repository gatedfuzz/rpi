#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
//#include "hardware/adc.h"
//#include "hardware/clocks.h"
#include "hardware/flash.h"
#include "hardware/gpio.h"
#include "hardware/irq.h"
#include "hardware/sync.h"
#include <math.h>


#include "crc8.h"
#include "fat32.h"
#include "pi.h"
#include "ssd1306.h"
// #include "tusb.h" // if you want to use tud_cdc_connected()

#define ALARM 0
#define DELAY (200'000)

//#define ADDRESS (XIP_BASE+ FLASH_TARGET_OFFSET)
#define FLASH_TARGET_OFFSET (256 * 1024)
#define ADDRESS (XIP_BASE+ FLASH_TARGET_OFFSET)
static_assert(FLASH_PAGE_SIZE == 256);
/*
   void write_flash_data(uint32_t page, const uint8_t* data) // data must be of size 4096 or more
   {
//puts("Doing flash_range_program");
uint32_t ints = save_and_disable_interrupts();
//flash_range_erase(FLASH_TARGET_OFFSET + page*FLASH_PAGE_SIZE, FLASH_PAGE_SIZE); // takes too long
flash_range_program(FLASH_TARGET_OFFSET + page*FLASH_PAGE_SIZE, data, FLASH_PAGE_SIZE);
restore_interrupts(ints);
//puts("Should be flashed now");
}
*/


/* acknowledge that transmitter can proceed
*/
void ack(void)
{
	putchar('A');
}

uint32_t size = 0;

void incoming(void)
{
	uint8_t data[FLASH_PAGE_SIZE];
	char c;
	size = 0;
	ssd1306_print("RX...\n");
	//show_scr();
	for(int i = 0;  i<4; i++) {
		uart_read_blocking(uart0, (uint8_t*) &c, 1);
		//c = getchar();
		size += (c << (i*8));
	}


	char msg[80];
	sprintf(msg, "size %d\n", size);
	ssd1306_print(msg);
	//show_scr();

	// erase SECTORS
	static_assert(FLASH_SECTOR_SIZE == 4096);
	int erasure_size = ceil(size/FLASH_SECTOR_SIZE) * FLASH_SECTOR_SIZE;
	uint32_t ints = save_and_disable_interrupts();
	flash_range_erase(FLASH_TARGET_OFFSET, erasure_size); // takes too long
	restore_interrupts(ints);
	ack();

	// read chunks of data
	static_assert(FLASH_PAGE_SIZE==256);
	uint8_t block[256];
	int unread = size;
	uint32_t offset = FLASH_TARGET_OFFSET;
	while(unread >0) {
		uart_read_blocking(uart0, block, 256);
		uint32_t ints = save_and_disable_interrupts();
		flash_range_program(offset, block, 256);
		restore_interrupts(ints);
		unread -= 256;
		offset += 256;
		ack();
	}

	ssd1306_print("OK\n");
	//show_scr();
}

void outgoing(void)
{
	//printf("%"
	ssd1306_print("Sending contents\n");
	//show_scr();
#if 1
	uart_write_blocking(uart0, (const uint8_t*) &size, 4);
#else
	uint32_t x = size;
	for(int i = 0; i< 4; i++) {
		//nt32_t y = x >> 24;
		//uart_tx_wait_blocking(uart0);
		putchar(x);
		x >>= 8;
	}
#endif

	//return;
	//uint32_t page = 0;
	//uint8_t data[4096];
	for(int i = 0 ; i < size; i++) {
		uart_write_blocking(uart0, (const uint8_t*)(ADDRESS+i), 1);
		//uart_write_blocking(uart0, ADDRESS+i, 1);
		//putchar(buf[i]);
	}
	ssd1306_print("Done\n");
	//show_scr();
	//write(fd1, &cmd, 1);
}

static void alarm_0_irq() 
{
	pi_alarm_rearm(ALARM, DELAY);
	show_scr();
	//printf("Alarm IRQ fired %d\n", i++);
}
void erase_flash(uint32_t size)
{
	return;
	// erase SECTORS
	static_assert(FLASH_SECTOR_SIZE == 4096);
	int erasure_size = ceil(size/FLASH_SECTOR_SIZE) * FLASH_SECTOR_SIZE;
	uint32_t ints = save_and_disable_interrupts();
	flash_range_erase(FLASH_TARGET_OFFSET, erasure_size); // takes too long
	restore_interrupts(ints);
}


void may_use_sdcard(void)
{
	//return;

	fat32_init();

	char datafile[12];
	canfile(datafile, "flash.dat");
	File file(datafile);
	uint8_t block[512];
	//erase_flash(file.size());
	unsigned char crc = 0;
	puts("Reading file");


	uint8_t page[4096];
	uint32_t offset = FLASH_TARGET_OFFSET;
	int nread = 0;

	unsigned char crc_file = 0;
	while(nread < file.size()) {
		// read a page from file
		int num_bytes_in_page_read = 0;
		for(int i = 0; i< 4096/512; i++) {
			num_bytes_in_page_read += file.read(page + i*512);
		}
		if(num_bytes_in_page_read<4096) 
			memset(page + num_bytes_in_page_read, 0, 4096-num_bytes_in_page_read); // kindly fill the remainder with 0
		crc_file = crc8_dallas_chunk(crc_file, page, num_bytes_in_page_read);
		nread += num_bytes_in_page_read;

		// write page to flash 
		uint32_t ints = save_and_disable_interrupts();
		flash_range_erase(FLASH_TARGET_OFFSET+offset, 4096);
		flash_range_program(offset, page, 4096);
		restore_interrupts(ints);
		offset += 4096;
	}
	puts("File was written. Contents are:");
	uart_write_blocking(uart0, (const uint8_t *) ADDRESS, file.size());


	printf("\nCRC on file: %d\n", crc_file);
	printf("CRC on flash: %d\n", crc8_dallas((const unsigned char*) ADDRESS, file.size()));

	while(1);
}

int main() 
{
	stdio_init_all();
	// while(!tud_cdc_connected()) sleep_ms(250); // wait for usb serial 

	printf("ADDRESS = %d\n", ADDRESS);
	printf("XIP_BASE = %d\n", XIP_BASE);
	printf("FLASH_TARGET_OFFSET = %d\n", FLASH_TARGET_OFFSET);
	printf("FLASH_PAGE_SIZE = %d\n", FLASH_PAGE_SIZE); // 256
	printf("FLASH_SECTOR_SIZE = %d\n", FLASH_SECTOR_SIZE); // 4096
	//printf(" = %d\n", );


	may_use_sdcard();
#define BTN  14 // GPIO number, not physical pin
#define LED  25 // GPIO of built-in LED
	gpio_init(BTN);
	gpio_set_dir(BTN, GPIO_IN);
	gpio_pull_up(BTN);
	// gpio_get() gets state of pin

	gpio_init(LED);
	gpio_set_dir(LED, GPIO_OUT);
	init_display(64, 4);

	pi_alarm_init(ALARM, alarm_0_irq, DELAY);

	ssd1306_print("transfer prog\n");
	//show_scr();
	int i = 0;
	for(;;) {
		char c;
		uart_read_blocking(uart0, (uint8_t*) &c, 1); 
		//char c = getchar();
		switch(c) {
			case 'T' : incoming(); break;
			case 'R' : outgoing(); break;
		}
		/*
		   gpio_put(LED, 1);
		   sleep_ms(100);
		   gpio_put(LED, 0);
		   sleep_ms(1000);	
		   */
	}

	return 0;
}

