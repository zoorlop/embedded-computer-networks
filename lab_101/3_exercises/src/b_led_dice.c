/*
 * b_led_dice.c
 *
 * this is the main application skeleton for the student exercises in task 3
 *
 */

// include the hal drivers
#include "stm32f7xx_hal.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "gpio.h"
#include "random_numbers.h"

// map the led to GPIO
	gpio_pin_t led_topleft = {PI_3, GPIOI, GPIO_PIN_3};
	gpio_pin_t led_midleft = {PA_15, GPIOA, GPIO_PIN_15};
	gpio_pin_t led_botleft = {PB_14, GPIOB, GPIO_PIN_14};
	gpio_pin_t led_mid = {PA_8, GPIOA, GPIO_PIN_8};
	gpio_pin_t led_topright = {PI_2, GPIOI, GPIO_PIN_2};
	gpio_pin_t led_midright = {PB_15, GPIOB, GPIO_PIN_15};
	gpio_pin_t led_botright = {PI_1, GPIOI, GPIO_PIN_1};

// this is the main method
int main()
{
	//Init board
		HAL_Init();
		init_sysclk_216MHz();
	
	//init pins 
		init_gpio(led_topleft, OUTPUT);
		init_gpio(led_midleft, OUTPUT);
		init_gpio(led_botleft, OUTPUT);
		init_gpio(led_mid, OUTPUT);
		init_gpio(led_topright, OUTPUT);
		init_gpio(led_midright, OUTPUT);
		init_gpio(led_botright, OUTPUT);
	
	// init random
	init_random();
	
	// loop forever ...
  while(1)
  {
		//Turn all LEDs off ready for rnd number
			write_gpio(led_topleft, LOW);
			write_gpio(led_midleft, LOW);
			write_gpio(led_botleft, LOW);
			write_gpio(led_mid, LOW);
			write_gpio(led_topright, LOW);
			write_gpio(led_midright, LOW);
			write_gpio(led_botright, LOW);
		
		//Find a random integer and place in rnd
			uint32_t rnd = (get_random_int() % 6) + 1;
		
		//Select correct case for the int in rnd var. 
		//Turn on appropiate LEDS
		switch(rnd) {
			case 1 :
				write_gpio(led_mid,HIGH);
				break;
			case 2 :
				write_gpio(led_topleft, HIGH);
				write_gpio(led_botright, HIGH);
				break;
			case 3 :
				write_gpio(led_topleft, HIGH);
				write_gpio(led_mid, HIGH);
				write_gpio(led_botright, HIGH);
				break;
			case 4 :
				write_gpio(led_topleft, HIGH);
				write_gpio(led_botleft, HIGH);
				write_gpio(led_topright, HIGH);
				write_gpio(led_botright, HIGH);
				break;
			case 5 :
				write_gpio(led_topleft, HIGH);
				write_gpio(led_botleft, HIGH);
				write_gpio(led_mid, HIGH);
				write_gpio(led_topright, HIGH);
				write_gpio(led_botright, HIGH);
				break;
			case 6 :
				write_gpio(led_topleft, HIGH);
				write_gpio(led_midleft, HIGH);
				write_gpio(led_botleft, HIGH);
				write_gpio(led_topright, HIGH);
				write_gpio(led_midright, HIGH);
				write_gpio(led_botright, HIGH);
				break;
			default : 				//If number if not 1 to 6 turn on all LEDS to show fault
				write_gpio(led_topleft, HIGH);
				write_gpio(led_midleft, HIGH);
				write_gpio(led_botleft, HIGH);
				write_gpio(led_mid, HIGH);
				write_gpio(led_topright, HIGH);
				write_gpio(led_midright, HIGH);
				write_gpio(led_botright, HIGH);
				break;
		}
		HAL_Delay(5000);
			
	}
}
