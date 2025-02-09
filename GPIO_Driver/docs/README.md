# GPIO Driver Library for AVR

## Introduction

This repository contains a unified GPIO driver library for AVR microcontrollers, designed to simplify the process of configuring, reading from, and writing to GPIO pins. The library supports multiple ports (PORT_B, PORT_C, PORT_D) and provides functions to initialize pins, set their direction (input/output), and toggle their state (HIGH/LOW). It is intended to be used in embedded systems development with AVR-based platforms.

### Key Features:
- Easy configuration of GPIO pins.
- Supports multiple ports (PORT_B, PORT_C, PORT_D).
- Functions for setting pins as input/output and writing/reading HIGH/LOW states.

## Installation

To use this library in your project, follow these steps:

1. **Clone or Download the Repository**:
   You can either clone this repository using Git or download the ZIP file and extract it.
   ```bash
   git clone https://github.com/yourusername/gpio-driver-avr.git
Include the Library in Your Project: Copy the gpio_driver.c and gpio_driver.h files into your project directory. Include the header file in your source files to use the GPIO driver.


API Documentation
Functions
GPIO_Init(GPIO_Config_t *config)
Description: Initializes a GPIO pin for the given port and configuration (input/output and initial state).
Parameters:
config: Pointer to a GPIO_Config_t structure that holds the configuration details.
**Returns**: None.
GPIO_Write(GPIO_Config_t *config, einitialState_t state)
Description: Writes a state (HIGH or LOW) to the specified GPIO pin.
Parameters:
config: Pointer to the GPIO_Config_t structure with the pin configuration.
state: The state to be written to the pin (HIGH or LOW).
Returns: None.
GPIO_Read(GPIO_Config_t *config)
Description: Reads the current state (HIGH or LOW) of the specified GPIO pin.
Parameters:
config: Pointer to the GPIO_Config_t structure with the pin configuration.
Returns: uint8_t - The current state of the pin (1 for HIGH, 0 for LOW).

**Macros**
PORT_B, PORT_C, PORT_D: These macros represent the available GPIO ports.
OUTPUT, INPUT: These macros represent the direction for the GPIO pin (output or input).
HIGH, LOW: These macros represent the states of the GPIO pin (high or low).

Contribution
If you want to contribute to this project, feel free to fork the repository, make changes, and create a pull request. All contributions are welcome!

License
This project is licensed under the MIT License - see the LICENSE file for details.




