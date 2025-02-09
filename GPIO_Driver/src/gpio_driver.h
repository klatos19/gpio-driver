//================================================ ============================= 
// Copyright (c) Cletus Kum 
// Project: GPIO driver
//------------------------------------------------ ----------------------------- 
//! @file 
//! @brief Interface description of GPIO driver modules 
//! 
//! This file describes the interface of the GPIO driver modules. 
//! It handles initialization, reading, and writing to GPIO pins on AVR microcontrollers.
//! 
//! @see @ref Section_GPIODriver for descriptive information. 
//! @see @ref gpio_driver.c for implementation details. 
//------------------------------------------------ ----------------------------- 
// Notes 
// Initial author: Cletus Kum
//================================================ ============================= 
//------------------------------------------------ ----------------------------- 
//! @addtogroup Group_GPIODriver GPIO_DRIVER_GROUP 
//! @section Section_GPIODriver GPIO_DRIVER_SECTION 
//! 
//! GPIO driver module description 
//! 
//! @see @ref gpio_driver.h for descriptive information. 
//! @see @ref gpio_driver.c for implementation details. 
//------------------------------------------------ ----------------------------- 

#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

// Includes ************************************************ ********************

/* Include standard libraries or other header files */
#include <avr/io.h>
#include <stdint.h>

// Macros ************************************************ *********************

// Pin numbers enumeration for easy reference
#define PIN_0   0
#define PIN_1   1
#define PIN_2   2
#define PIN_3   3
#define PIN_4   4
#define PIN_5   5
#define PIN_6   6
#define PIN_7   7

// GPIO Port enumeration
typedef enum {
    PORT_B = 0, 
    PORT_C, 
    PORT_D
} eport_t;

// GPIO Pin mode enumeration
typedef enum {
    INPUT = 0, 
    OUTPUT
} emode_t;

// GPIO Pin state enumeration
typedef enum {
    LOW = 0, 
    HIGH
} einitialState_t;

/******************************************************************
 *                    GPIO CONFIGURATION STRUCT                   *
 ******************************************************************/

typedef struct {
    uint8_t pinNumber;           ///< Pin number (0-7 for an 8-bit port)
    eport_t port;                ///< Port (PORT_B, PORT_C, PORT_D)
    emode_t mode;                ///< Mode (INPUT/OUTPUT)
    einitialState_t initialState; ///< Initial state (HIGH/LOW)
} GPIO_Config_t;

/******************************************************************
 *                   FUNCTION PROTOTYPES                          *
 ******************************************************************/

// Function to initialize GPIO
void GPIO_Init(GPIO_Config_t *config);

// Function to write value to GPIO pin
void GPIO_Write(GPIO_Config_t *config, einitialState_t state);

// Function to read value from GPIO pin
uint8_t GPIO_Read(GPIO_Config_t *config);

#ifdef __cplusplus
}
#endif

#endif /* GPIO_DRIVER_H */
