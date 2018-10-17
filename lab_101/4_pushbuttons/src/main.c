/*
 * main.c
 *
 * this is the main push button application (this code is dependent on the
 * extra shu libraries such as the pinmappings list and the clock configuration
 * library)
 *
 * author:    Alex Shenfield
 * date:      01/09/2018
 * purpose:   55-604481 embedded computer networks : lab 101
 */

// include the hal drivers
#include "stm32f7xx_hal.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "gpio.h"

// map the led to GPIO PI_1 (the inbuilt led) and the push button to PI_11 
// (the user button)
gpio_pin_t led = {PI_1, GPIOI, GPIO_PIN_1};
//gpio_pin_t pb1 = {PI_11, GPIOI, GPIO_PIN_11};
gpio_pin_t pb1 = {PB_14, GPIOB, GPIO_PIN_14};

// this is the main method
int main()
{
  // we need to initialise the hal library and set up the SystemCoreClock 
  // properly
  HAL_Init();
  init_sysclk_216MHz();
  
  // initialise the gpio pins
  init_gpio(led, OUTPUT);
  init_gpio(pb1, INPUT);
  
  // loop forever ...
  while(1)
  {
		//read the pushbutton and debounce it
		int button_state = read_gpio(pb1);
		HAL_Delay(50);
		button_state = button_state & read_gpio(pb1);
		
		// if the button is pressed ...
		if(button_state)
			{
				// toggle the led on the gpio pin
				toggle_gpio(led);
			}
	}
}
