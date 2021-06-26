/* Inspired from
https://smist08.wordpress.com/2021/04/16/assembly-language-on-the-raspberry-pi-pico/
*/

.syntax unified
.cpu cortex-m0plus
.thumb
/*
@ .syntax unified
 .fpu softvfp 
@ .thumb
*/


.section .boot2, "ax"
.word 0x4b32b500, 0x60582021, 0x21026898, 0x60984388
.word 0x611860d8, 0x4b2e6158, 0x60992100, 0x61592102
.word 0x22f02101, 0x492b5099, 0x21016019, 0x20356099
.word 0xf844f000, 0x42902202, 0x2106d014, 0xf0006619
.word 0x6e19f834, 0x66192101, 0x66182000, 0xf000661a
.word 0x6e19f82c, 0x6e196e19, 0xf0002005, 0x2101f82f
.word 0xd1f94208, 0x60992100, 0x6019491b, 0x60592100
.word 0x481b491a, 0x21016001, 0x21eb6099, 0x21a06619
.word 0xf0006619, 0x2100f812, 0x49166099, 0x60014814
.word 0x60992101, 0x2800bc01, 0x4700d000, 0x49134812
.word 0xc8036008, 0x8808f380, 0xb5034708, 0x20046a99
.word 0xd0fb4201, 0x42012001, 0xbd03d1f8, 0x6618b502
.word 0xf7ff6618, 0x6e18fff2, 0xbd026e18, 0x40020000
.word 0x18000000, 0x00070000, 0x005f0300, 0x00002221
.word 0x180000f4, 0xa0002022, 0x10000100, 0xe000ed08
.word 0x00000000, 0x00000000, 0x00000000, 0x7a4eb274




.section .vectors, "ax"
.align 2 

.global __vectors
__vectors:
/* 	.word __StackTop  */
	.word 0x20042000 
.word _reset_handler






.section .text
.type _reset_handler,%function /* vital for getting the correct offset */
.thumb_func
_reset_handler:
	@ mov r0, r0 @ just for testing purposes
	bl main


/*
.thumb_func
.global main_asm
.align 4
main_asm:
BL main  
*/

.data
.align 4