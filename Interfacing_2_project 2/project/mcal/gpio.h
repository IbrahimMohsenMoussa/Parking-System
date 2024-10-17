/**
 * @file gpio.h
 * @brief Header file for GPIO control functions for AVR microcontrollers.
 *
 * This file provides macros, type definitions, and function prototypes
 * for configuring and manipulating GPIO pins on AVR microcontrollers.
 * The GPIO pins can be configured as inputs, outputs, or inputs with pull-up resistors,
 * and can be controlled or read.
 *
 * @date 9 Sept 2024
 * @author Ibrahim Mohsen
 */

#ifndef GPIO_H_
#define GPIO_H_


#include "../common/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/**
 * @brief Number of available ports.
 */
#define NUM_OF_PORTS           4

/**
 * @brief Number of pins per port.
 */
#define NUM_OF_PINS_PER_PORT   8

/**
 * @brief Total number of pins across all ports.
 */
#define NUM_OF_PINS            32

/**
 * @brief ID for Port A.
 */
#define PORTA_ID               0

/**
 * @brief ID for Port B.
 */
#define PORTB_ID               1

/**
 * @brief ID for Port C.
 */
#define PORTC_ID               2

/**
 * @brief ID for Port D.
 */
#define PORTD_ID               3

/**
 * @brief Macro for defining a GPIO pin structure.
 *
 * This macro creates a gpioStruct object that holds the memory addresses
 * for the pin, port, and DDR registers for a specific pin on a given port.
 *
 * @param port The port (e.g., A, B, C, D).
 * @param bit The pin number on the port (0-7).
 */
#define GPIO_PIN(port, bit) { &(PIN##port), &(PORT##port), &(DDR##port), bit }

/*******************************************************************************
 *                                Enums & Types                                *
 *******************************************************************************/

/**
 * @brief Enum for pin direction modes.
 *
 * This enum is used to specify the direction of a GPIO pin: input, output, or input with pull-up.
 */
typedef enum
    {
    PIN_INPUT, /**< Configure the pin as an input. */
    PIN_OUTPUT, /**< Configure the pin as an output. */
    PIN_INPUT_PULLUP /**< Configure the pin as an input with pull-up resistor enabled. */
    } pinDirection;

/**
 * @brief Enum for pin state values.
 *
 * This enum is used to represent the state of a GPIO pin: LOW (0) or HIGH (1).
 */
typedef enum
    {
    LOW, /**< Set the pin to low state (0). */
    HIGH /**< Set the pin to high state (1). */
    } pinState;

/**
 * @brief Structure for holding GPIO pin information.
 *
 * This structure holds pointers to the memory addresses of the PIN, PORT, and DDR registers
 * for a specific pin on a specific port. It also holds the pin number on that port.
 */
typedef struct
    {
	volatile uint8 *pin_addr; /**< Pointer to the PIN register for reading pin input. */
	volatile uint8 *port_addr; /**< Pointer to the PORT register for setting pin output. */
	volatile uint8 *ddr_addr; /**< Pointer to the DDR register for setting pin direction. */
	volatile uint8 pin; /**< The pin number (0-7) on the port. */
    } gpioStruct;

/*******************************************************************************
 *                                Functions Prototypes                         *
 *******************************************************************************/

/**
 * @brief Configures the direction of a GPIO pin.
 *
 * This function configures the specified pin on a given port as an input, output, or input with pull-up.
 *
 * @param a_port The port ID (PORTA_ID, PORTB_ID, etc.).
 * @param a_pin The pin number (0-7) on the specified port.
 * @param state The direction of the pin (PIN_INPUT, PIN_OUTPUT, or PIN_INPUT_PULLUP).
 */
void GPIO_setupPinDirection(uint8 a_port, uint8 a_pin, uint8 state);

/**
 * @brief Writes a value to a GPIO pin.
 *
 * This function sets the state of the specified pin on a given port to HIGH or LOW.
 *
 * @param a_port The port ID (PORTA_ID, PORTB_ID, etc.).
 * @param a_pin The pin number (0-7) on the specified port.
 * @param a_state The desired state (HIGH or LOW).
 */
void GPIO_writePin(uint8 a_port, uint8 a_pin, uint8 a_state);

/**
 * @brief Toggles the state of a GPIO pin.
 *
 * This function toggles the state of the specified pin on a given port.
 * If the pin is currently HIGH, it will be set to LOW, and vice versa.
 *
 * @param a_port The port ID (PORTA_ID, PORTB_ID, etc.).
 * @param pin The pin number (0-7) on the specified port.
 */
void GPIO_tooglePin(uint8 a_port, uint8 pin);

/**
 * @brief Reads the current state of a GPIO pin.
 *
 * This function reads the current logic level (HIGH or LOW) of the specified pin on a given port.
 *
 * @param a_port The port ID (PORTA_ID, PORTB_ID, etc.).
 * @param pin The pin number (0-7) on the specified port.
 * @return The current state of the pin (1 for HIGH, 0 for LOW).
 */
uint8 GPIO_readPin(uint8 a_port, uint8 pin);

/**
 * @brief Sets the state of a GPIO pin stored in program memory.
 *
 * This function sets the state (HIGH or LOW) of the specified pin stored in program memory.
 * The pin configuration is read from the `ioPins` array, which is stored in flash memory.
 *
 * @param a_pin The index of the pin in the `ioPins` array stored in flash memory.
 * @param a_value The desired state (HIGH or LOW).
 */
void GPIO_ARR_setPinState(uint8 a_pin, uint8 a_value);

/**
 * @brief Configures the direction of a GPIO pin stored in program memory.
 *
 * This function sets the direction (input, output, or input with pull-up) of the specified pin stored in program memory.
 * The pin configuration is read from the `ioPins` array, which is stored in flash memory.
 *
 * @param a_pin The index of the pin in the `ioPins` array stored in flash memory.
 * @param a_state The desired direction (PIN_INPUT, PIN_OUTPUT, or PIN_INPUT_PULLUP).
 */
void GPIO_ARR_setPinDirection(uint8 a_pin, uint8 a_state);

/**
 * @brief Reads the current state of a GPIO pin stored in program memory.
 *
 * This function reads the current logic level (HIGH or LOW) of the specified pin stored in program memory.
 * The pin configuration is read from the `ioPins` array, which is stored in flash memory.
 *
 * @param a_pin The index of the pin in the `ioPins` array stored in flash memory.
 * @return The current state of the pin (1 for HIGH, 0 for LOW).
 */
uint8 GPIO_ARR_readPin(uint8 a_pin);
/**
 * @brief Sets the Value of a GPIO PORT in the memory mapped registers
 *
 * @param port_num Port_ID PORTA_ID, PORTB_IB ,...etc
 * @param a_value The desired 8-bit  value to be set into the port.
 */

void GPIO_writePort(uint8 port_num, uint8 value);
/**
 * @brief Sets the Direction of a GPIO PORT in the memory mapped registers
 *
 * @param port_num Port_ID PORTA_ID, PORTB_IB ,...etc
 * @param a_value The desired direction PORT_INPUT,PORT_OUTPUT or the desired value
 */
void GPIO_setupPortDirection(uint8 port_num, uint8 direction);
/**
 * @enum GPIO_PortDirectionType
 * @brief Defines the possible directions for a GPIO port.
 *
 * This enum is used to set the direction of an entire GPIO port (input or output).
 * It provides two possible values:
 * - `PORT_INPUT`: Configures the port as an input port.
 * - `PORT_OUTPUT`: Configures the port as an output port.
 *
 * Example usage:
 * @code
 * GPIO_PortDirectionType portDirection = PORT_OUTPUT;
 * @endcode
 */
typedef enum
    {
    PORT_INPUT, /**< Set the entire port to input mode (all pins are inputs). */
    PORT_OUTPUT = 0xFF /**< Set the entire port to output mode (all pins are outputs). */
    } GPIO_PortDirectionType;

/**
 * @brief Enumeration for all GPIO pins across all ports (A, B, C, D).
 *
 * This enum defines all GPIO pins available on ports A, B, C, and D. Each pin is represented
 * by its port and pin number, allowing easy access to individual pins using the enum names.
 */
typedef enum
    {
    /**<Port A pins (GPIO_PA0 to GPIO_PA7)*/
    GPIO_PA0 = 0, /**< Pin GPIO_PA0, corresponding to pin 0 in Port A */
    GPIO_PA1 = 1, /**< Pin GPIO_PA1, corresponding to pin 1 in Port A */
    GPIO_PA2 = 2, /**< Pin GPIO_PA2, corresponding to pin 2 in Port A */
    GPIO_PA3 = 3, /**< Pin GPIO_PA3, corresponding to pin 3 in Port A */
    GPIO_PA4 = 4, /**< Pin GPIO_PA4, corresponding to pin 4 in Port A */
    GPIO_PA5 = 5, /**< Pin GPIO_PA5, corresponding to pin 5 in Port A */
    GPIO_PA6 = 6, /**< Pin GPIO_PA6, corresponding to pin 6 in Port A */
    GPIO_PA7 = 7, /**< Pin GPIO_PA7, corresponding to pin 7 in Port A */

    /**<Port B pins (GPIO_PB0 to GPIO_PB7)*/
    GPIO_PB0 = 8, /**< Pin GPIO_PB0, corresponding to pin 0 in Port B */
    GPIO_PB1 = 9, /**< Pin GPIO_PB1, corresponding to pin 1 in Port B */
    GPIO_PB2 = 10, /**< Pin GPIO_PB2, corresponding to pin 2 in Port B */
    GPIO_PB3 = 11, /**< Pin GPIO_PB3, corresponding to pin 3 in Port B */
    GPIO_PB4 = 12, /**< Pin GPIO_PB4, corresponding to pin 4 in Port B */
    GPIO_PB5 = 13, /**< Pin GPIO_PB5, corresponding to pin 5 in Port B */
    GPIO_PB6 = 14, /**< Pin GPIO_PB6, corresponding to pin 6 in Port B */
    GPIO_PB7 = 15, /**< Pin GPIO_PB7, corresponding to pin 7 in Port B */

    /**<Port C pins (GPIO_PC0 to GPIO_PC7)*/
    GPIO_PC0 = 16, /**< Pin GPIO_PC0, corresponding to pin 0 in Port C */
    GPIO_PC1 = 17, /**< Pin GPIO_PC1, corresponding to pin 1 in Port C */
    GPIO_PC2 = 18, /**< Pin GPIO_PC2, corresponding to pin 2 in Port C */
    GPIO_PC3 = 19, /**< Pin GPIO_PC3, corresponding to pin 3 in Port C */
    GPIO_PC4 = 20, /**< Pin GPIO_PC4, corresponding to pin 4 in Port C */
    GPIO_PC5 = 21, /**< Pin GPIO_PC5, corresponding to pin 5 in Port C */
    GPIO_PC6 = 22, /**< Pin GPIO_PC6, corresponding to pin 6 in Port C */
    GPIO_PC7 = 23, /**< Pin GPIO_PC7, corresponding to pin 7 in Port C */

    /**<Port D pins (GPIO_PD0 to GPIO_PD7)*/
    GPIO_PD0 = 24, /**< Pin GPIO_PD0, corresponding to pin 0 in Port D */
    GPIO_PD1 = 25, /**< Pin GPIO_PD1, corresponding to pin 1 in Port D */
    GPIO_PD2 = 26, /**< Pin GPIO_PD2, corresponding to pin 2 in Port D */
    GPIO_PD3 = 27, /**< Pin GPIO_PD3, corresponding to pin 3 in Port D */
    GPIO_PD4 = 28, /**< Pin GPIO_PD4, corresponding to pin 4 in Port D */
    GPIO_PD5 = 29, /**< Pin GPIO_PD5, corresponding to pin 5 in Port D */
    GPIO_PD6 = 30, /**< Pin GPIO_PD6, corresponding to pin 6 in Port D */
    GPIO_PD7 = 31 /**< Pin GPIO_PD7, corresponding to pin 7 in Port D */
    } GPIO_PINS_ARR;

#endif /* GPIO_H_ */
