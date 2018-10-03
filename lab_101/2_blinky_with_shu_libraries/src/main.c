/*
 * main.c
 *
 * this is the main blinky application (this code is dependent on the
 * extra shu libraries such as the pinmappings list and the clock configuration
 * library)
 *
 * author:    Dr. Alex Shenfield
 * date:      01/09/2018
 * purpose:   55-604481 embedded computer networks : lab 101
 */

// include the hal drivers
#include "stm32f7xx_hal.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "gpio.h"

// map the led to GPIO PI1 (again, this is the inbuilt led)
gpio_pin_t led_red = {PI_1, GPIOI, GPIO_PIN_1};
gpio_pin_t led_yellow = {PB_14, GPIOB, GPIO_PIN_14};
gpio_pin_t led_green = {PB_15, GPIOB, GPIO_PIN_15};

// this is the main method
int main()
{
  // we need to initialise the hal library and set up the SystemCoreClock 
  // properly
  HAL_Init();
  init_sysclk_216MHz();
  
  // initialise the gpio pins
  init_gpio(led_red, OUTPUT);
  init_gpio(led_yellow, OUTPUT);
	init_gpio(led_green, OUTPUT);
	
  // loop forever ...
  while(1)
  {
    // red on, yellow off
			write_gpio(led_red,HIGH);
			write_gpio(led_yellow, LOW);
    // wait for 4 second
			HAL_Delay(4000);
		
		// yellow on 
			write_gpio(led_yellow, HIGH);
    // wait for 1 second
			HAL_Delay(1000);
		
		// red and yellow off, green on 
			write_gpio(led_red, LOW);
			write_gpio(led_yellow, LOW);
			write_gpio(led_green, HIGH);
    // wait for 4 seconds
			HAL_Delay(4000);
		
		// yellow on, green off 
			write_gpio(led_yellow, HIGH);
			write_gpio(led_green, LOW);
    // wait for 2 seconds
			HAL_Delay(2000);	
		
  }
}
