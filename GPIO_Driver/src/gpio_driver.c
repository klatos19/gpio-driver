//==============================================================================
// Copyright (c) Cletus Kum
// Project: GPIO driver
//------------------------------------------------------------------------------
//! @file
//! @brief Implementation of the unified GPIO driver for AVR
//!
//! This file contains functions for GPIO initialization, writing, and reading.
//! It supports multiple ports (PORT_B, PORT_C, PORT_D) for GPIO operations.
//!
//! @see @ref gpio_driver.h for the interface description.
//------------------------------------------------------------------------------
// Notes:
// Initial author: Cletus Kum
//==============================================================================

// Includes ====================================================================
#include "gpio_driver.h"
#include <avr/io.h>

// Macros ======================================================================

// Definitions =================================================================

// Function Definitions =======================================================

/******************************************************************
 *                      GPIO INITIALIZATION                        *
 ******************************************************************/

/**
 * @brief Initializes a GPIO pin for a given port and configuration.
 *
 * This function configures the direction (input/output) and the
 * initial state (HIGH/LOW) of the selected GPIO pin on a specified port.
 *
 * @param config Pointer to the GPIO configuration structure.
 */
void GPIO_Init(GPIO_Config_t *config)
{
    switch (config->port)
    {
    case PORT_B:
        // Configure the direction of the pin
        if (config->mode == OUTPUT)
        {
            DDRB |= (1 << config->pinNumber); // Set as output
        }
        else
        {
            DDRB &= ~(1 << config->pinNumber); // Set as input
        }
        // Set the initial state of the pin
        if (config->initialState == HIGH)
        {
            PORTB |= (1 << config->pinNumber);
        }
        else
        {
            PORTB &= ~(1 << config->pinNumber);
        }
        break;

    case PORT_C:
        // Configure the direction of the pin
        if (config->mode == OUTPUT)
        {
            DDRC |= (1 << config->pinNumber);
        }
        else
        {
            DDRC &= ~(1 << config->pinNumber);
        }
        // Set the initial state of the pin
        if (config->initialState == HIGH)
        {
            PORTC |= (1 << config->pinNumber);
        }
        else
        {
            PORTC &= ~(1 << config->pinNumber);
        }
        break;

    case PORT_D:
        // Configure the direction of the pin
        if (config->mode == OUTPUT)
        {
            DDRD |= (1 << config->pinNumber);
        }
        else
        {
            DDRD &= ~(1 << config->pinNumber);
        }
        // Set the initial state of the pin
        if (config->initialState == HIGH)
        {
            PORTD |= (1 << config->pinNumber);
        }
        else
        {
            PORTD &= ~(1 << config->pinNumber);
        }
        break;
    }
}

/******************************************************************
 *                      GPIO WRITE FUNCTION                        *
 ******************************************************************/

/**
 * @brief Writes a state (HIGH or LOW) to the selected GPIO pin.
 *
 * This function sets the output state of a specified GPIO pin based on the
 * provided state (HIGH or LOW).
 *
 * @param config Pointer to the GPIO configuration structure.
 * @param state The state to be written to the GPIO pin (HIGH/LOW).
 */
void GPIO_Write(GPIO_Config_t *config, einitialState_t state)
{
    switch (config->port)
    {
    case PORT_B:
        if (state == HIGH)
        {
            PORTB |= (1 << config->pinNumber);
        }
        else
        {
            PORTB &= ~(1 << config->pinNumber);
        }
        break;

    case PORT_C:
        if (state == HIGH)
        {
            PORTC |= (1 << config->pinNumber);
        }
        else
        {
            PORTC &= ~(1 << config->pinNumber);
        }
        break;

    case PORT_D:
        if (state == HIGH)
        {
            PORTD |= (1 << config->pinNumber);
        }
        else
        {
            PORTD &= ~(1 << config->pinNumber);
        }
        break;
    }
}

/******************************************************************
 *                      GPIO READ FUNCTION                         *
 ******************************************************************/

/**
 * @brief Reads the current state (HIGH or LOW) of the selected GPIO pin.
 *
 * This function checks the input state of a specified GPIO pin and returns
 * the corresponding state (HIGH or LOW).
 *
 * @param config Pointer to the GPIO configuration structure.
 * @return The current state of the GPIO pin (0 for LOW, 1 for HIGH).
 */
uint8_t GPIO_Read(GPIO_Config_t *config)
{
    uint8_t pinState = 0;
    switch (config->port)
    {
    case PORT_B:
        pinState = (PINB & (1 << config->pinNumber)) ? 1 : 0;
        break;

    case PORT_C:
        pinState = (PINC & (1 << config->pinNumber)) ? 1 : 0;
        break;

    case PORT_D:
        pinState = (PIND & (1 << config->pinNumber)) ? 1 : 0;
        break;
    }
    return pinState;
}
