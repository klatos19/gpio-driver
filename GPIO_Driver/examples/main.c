//==============================================================================
// Copyright (c) Cletus Kum
// Project: GPIO driver
//------------------------------------------------------------------------------
//! @file
//! @brief Test program to validate the GPIO driver functionality
//! 
//! This file contains a simple test for the GPIO driver that initializes three 
//! GPIO pins on different ports (PORT_B, PORT_C, PORT_D), sets their direction 
//! to output, and toggles their state between HIGH and LOW in an infinite loop. 
//! It validates the GPIO initialization, writing, and the toggling of pin states.
//------------------------------------------------------------------------------
// Notes:
// Initial author: Cletus Kum
//==============================================================================

// Includes ====================================================================
#include <avr/io.h>
#include "gpio_driver.h"

// Define test configuration for GPIO pins
// GPIO_Config_t is the configuration structure for initializing GPIO pins
GPIO_Config_t gpioConfigB = {PORT_B, 0, OUTPUT, LOW}; // Pin 0 on PORT B, configured as output, initial state LOW
GPIO_Config_t gpioConfigC = {PORT_C, 1, OUTPUT, HIGH}; // Pin 1 on PORT C, configured as output, initial state HIGH
GPIO_Config_t gpioConfigD = {PORT_D, 2, OUTPUT, LOW}; // Pin 2 on PORT D, configured as output, initial state LOW

/**
 * @brief Main function to test the GPIO driver functionality.
 * 
 * This function initializes three GPIO pins on different ports (B, C, D), sets their
 * direction to output, and toggles their state between HIGH and LOW in an infinite loop.
 * It tests the GPIO initialization, writing, and the toggling of pin states.
 * 
 * The program operates as follows:
 * - Pin 0 on PORT B is toggled between LOW and HIGH.
 * - Pin 1 on PORT C is toggled between HIGH and LOW.
 * - Pin 2 on PORT D is toggled between LOW and HIGH.
 * 
 * @return int Returns 0 (not used in this context, as this is embedded code).
 */
int main(void) {
    // Initialize GPIO pins for PORT B, PORT C, and PORT D
    // The GPIO_Init function sets the direction (input/output) and the initial state (HIGH/LOW)
    GPIO_Init(&gpioConfigB); // Initialize Pin 0 on PORT B as output, initial state LOW
    GPIO_Init(&gpioConfigC); // Initialize Pin 1 on PORT C as output, initial state HIGH
    GPIO_Init(&gpioConfigD); // Initialize Pin 2 on PORT D as output, initial state LOW

    // Infinite loop to toggle GPIO pin states and test GPIO functionality
    while (1) {
        // Toggle states of the GPIO pins between HIGH and LOW
        // The GPIO_Write function is used to set the output state of the selected pin

        // Set Pin 0 on PORT B to HIGH
        GPIO_Write(&gpioConfigB, HIGH);
        // Set Pin 1 on PORT C to LOW
        GPIO_Write(&gpioConfigC, LOW);
        // Set Pin 2 on PORT D to HIGH
        GPIO_Write(&gpioConfigD, HIGH);

        // Simple delay (not accurate, just for visual effect)
        // Replace with a timer-based delay for accurate timing in production code
        for (volatile uint32_t i = 0; i < 100000; i++);

        // Set Pin 0 on PORT B to LOW
        GPIO_Write(&gpioConfigB, LOW);
        // Set Pin 1 on PORT C to HIGH
        GPIO_Write(&gpioConfigC, HIGH);
        // Set Pin 2 on PORT D to LOW
        GPIO_Write(&gpioConfigD, LOW);

        // Simple delay again to allow for visual state changes
        for (volatile uint32_t i = 0; i < 100000; i++);
    }

    return 0; // Return 0 (never reached in an embedded system with an infinite loop)
}
