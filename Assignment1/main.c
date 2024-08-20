/**************************************************************
 * main.c
 * rev 1.0 20-Aug-2024 owner
 * Assignment1
 * ***********************************************************/

#include "pico/stdlib.h"
#include <stdbool.h>
#include <stdio.h> 

int main(void) {
  // Initialise components and variables

    stdio_init_all(); 

    const int red_PIN = 11 ;  // Initialise the red, green and blue pins
    const int green_PIN = 12;
    const int blue_PIN = 13; 

    const int SW1 = 2;   // Initialise the switches
    const int SW2 = 3;
    const int SW3 = 4;  

    // Set the direction of the red, green and blue pins to output
    gpio_init(red_PIN);   
    gpio_set_dir(red_PIN, GPIO_OUT);

    gpio_init(green_PIN);
    gpio_set_dir(green_PIN, GPIO_OUT); 

    gpio_init(blue_PIN);
    gpio_set_dir(blue_PIN, GPIO_OUT);

    // Set the direction of the switches to input

    gpio_init(SW1);
    gpio_set_dir(SW1, GPIO_IN);
    
    gpio_init(SW2);
    gpio_set_dir(SW2, GPIO_IN);
    
    gpio_init(SW3);
    gpio_set_dir(SW3, GPIO_IN);

    gpio_pull_up(SW1);          // Enable pull-up resistor

    // Initialise the state of the LEDs
    bool red_state = false;
    bool green_state = false;
    bool blue_state = false;

while (true) {
  if (gpio_get(SW1) == 0) {                                              // Check if the SW1 is pressed
            red_state = !red_state;                                      // Toggle the state of the red LED
            gpio_put(red_PIN, red_state);                                // Set the state of the red LED
            printf("Red LED is  %s\n", red_state ? "on" : "off");        // Print the state of the red LED
        }
  if (gpio_get(SW2) == 0) {                                              // Check if the SW2 is pressed
            green_state = !green_state;                                  // Toggle the state of the green LED
            gpio_put(green_PIN, green_state);                            // Set the state of the green LED
            printf("Green LED is  %s\n", green_state ? "on" : "off");    // Print the state of the green LED
        }

  if (gpio_get(SW3) == 0) {                                              // Check if the SW3 is pressed
            blue_state = !blue_state;                                    // Toggle the state of the blue LED
            gpio_put(blue_PIN, blue_state);                              // Set the state of the blue LED
            printf("Blue LED is %s\n", blue_state ? "on" : "off");       // Print the state of the blue LED
        }      
        sleep_ms(300);
  }
}



