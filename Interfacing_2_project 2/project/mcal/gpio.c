/**
 * @file gpio.c
 * @brief Implementation of GPIO control functions for AVR microcontrollers.
 *
 * This file provides functionality for configuring, reading, and controlling
 * GPIO pins, using values stored in program memory (flash).
 *
 * @date 9 Sept 2024
 * @author Ibrahim Mohsen
 */

#include "gpio.h"
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "../common/common_macros.h"
#include "../common/std_types.h"
/**
 * @brief Reads a 16-bit pointer from program memory and returns it as a pointer to RAM.
 *
 * This function reads a 16-bit address (pointer) stored in flash memory (program memory)
 * and converts it into a pointer to RAM.
 *
 * @param __addr16 The 16-bit address in program memory to read.
 * @return Pointer to the corresponding location in RAM.
 */
static uint8*
PGM_readPtrToRam(const uint16_t a_addr16)
    {
    uint16_t ram_addr;

    /* Use inline assembly to read two bytes from program memory (flash)*/
    __asm__ volatile (
	    "lpm %A0, Z+" "\n\t" /* Load the low byte from program memory into ram_addr */
	    "lpm %B0, Z" "\n\t" /* Load the high byte from program memory into ram_addr */
	    : "=r" (ram_addr) /* Output: ram_addr is where the 16-bit address is stored */
	    : "z" (a_addr16) /* Input: Z register holds the flash memory address (__addr16) */
    );

    /* Return the loaded 16-bit address as a pointer to RAM*/
    return (uint8*) ram_addr;
    }

/**
 * @brief Array of GPIO pin structures stored in program memory.
 *
 * This array holds the GPIO pin configuration (port and pin) for different ports (A, B, C, D).
 * These configurations are stored in program memory (flash) to save RAM space.
 */
gpioStruct ioPins[NUM_OF_PINS] PROGMEM =
    {
    /* Port A*/
    GPIO_PIN(A, PA0),/*pin =0*/
GPIO_PIN(A, PA1),
GPIO_PIN(A, PA2),
GPIO_PIN(A, PA3),
GPIO_PIN(A, PA4),
GPIO_PIN(A, PA5),
GPIO_PIN(A, PA6),
GPIO_PIN(A, PA7),

/* Port B*/
GPIO_PIN(B, PB0),/*pin =8*/
GPIO_PIN(B, PB1),
GPIO_PIN(B, PB2),
GPIO_PIN(B, PB3),
GPIO_PIN(B, PB4),
GPIO_PIN(B, PB5),
GPIO_PIN(B, PB6),
GPIO_PIN(B, PB7),

/* Port C*/
GPIO_PIN(C, PC0),/*pin =16*/
GPIO_PIN(C, PC1),
GPIO_PIN(C, PC2),
GPIO_PIN(C, PC3),
GPIO_PIN(C, PC4),
GPIO_PIN(C, PC5),
GPIO_PIN(C, PC6),
GPIO_PIN(C, PC7),

/* Port D*/
GPIO_PIN(D, PD0),/*pin =24*/
GPIO_PIN(D, PD1),
GPIO_PIN(D, PD2),
GPIO_PIN(D, PD3),
GPIO_PIN(D, PD4),
GPIO_PIN(D, PD5),
GPIO_PIN(D, PD6),
GPIO_PIN(D, PD7)
}
;
/**
 * @brief Sets the Direction of a GPIO PORT in the memory mapped registers
 *
 * @param port_num Port_ID PORTA_ID, PORTB_IB ,...etc
 * @param a_value The desired direction PORT_INPUT,PORT_OUTPUT or the desired value
 */
void GPIO_setupPortDirection(uint8 port_num, uint8 direction)
    {
    /*
     * Check if the input number is greater than NUM_OF_PORTS value.
     * In this case the input is not valid port number
     */
    if (port_num >= NUM_OF_PORTS)
	{
	/* Do Nothing */
	}
    else
	{
	/* Setup the port direction as required */
	switch (port_num)
	    {
	case PORTA_ID:
	    DDRA = direction;
	    break;
	case PORTB_ID:
	    DDRB = direction;
	    break;
	case PORTC_ID:
	    DDRC = direction;
	    break;
	case PORTD_ID:
	    DDRD = direction;
	    break;
	    }
	}
    }
/**
 * @brief Sets the Value of a GPIO PORT in the memory mapped registers
 *
 * @param port_num Port_ID PORTA_ID, PORTB_IB ,...etc
 * @param a_value The desired 8-bit  value to be set into the port.
 */

void GPIO_writePort(uint8 port_num, uint8 value)
    {

    if (port_num >= NUM_OF_PORTS)
	{
	/* Do Nothing */
	}
    else
	{

	switch (port_num)
	    {
	case PORTA_ID:
	    PORTA = value;
	    break;
	case PORTB_ID:
	    PORTB = value;
	    break;
	case PORTC_ID:
	    PORTC = value;
	    break;
	case PORTD_ID:
	    PORTD = value;
	    break;
	    }
	}
    }
/**
 * @brief Sets the direction of a GPIO pin.
 *
 * Configures the direction (input, output, or input with pull-up) of a specified pin on a given port.
 *
 * @param a_port The port ID (PORTA_ID, PORTB_ID, etc.)
 * @param a_pin The pin number on the port.
 * @param a_state The desired direction (PIN_INPUT, PIN_OUTPUT, PIN_INPUT_PULLUP).
 */
void GPIO_setupPinDirection(uint8 a_port, uint8 a_pin, uint8 a_state)
    {
    switch (a_port)
	{
    case PORTA_ID:
	switch (a_state)
	    {
	case PIN_INPUT:
	    CLEAR_BIT(DDRA, a_pin);
	    break;
	case PIN_OUTPUT:
	    SET_BIT(DDRA, a_pin);
	    break;
	case PIN_INPUT_PULLUP:
	    CLEAR_BIT(DDRA, a_pin);
	    SET_BIT(PORTA, a_pin);
	    break;
	    }
	break;

    case PORTB_ID:
	switch (a_state)
	    {
	case PIN_INPUT:
	    CLEAR_BIT(DDRB, a_pin);
	    break;
	case PIN_OUTPUT:
	    SET_BIT(DDRB, a_pin);
	    break;
	case PIN_INPUT_PULLUP:
	    CLEAR_BIT(DDRB, a_pin);
	    SET_BIT(PORTB, a_pin);
	    break;
	    }
	break;

    case PORTC_ID:
	switch (a_state)
	    {
	case PIN_INPUT:
	    CLEAR_BIT(DDRC, a_pin);
	    break;
	case PIN_OUTPUT:
	    SET_BIT(DDRC, a_pin);
	    break;
	case PIN_INPUT_PULLUP:
	    CLEAR_BIT(DDRC, a_pin);
	    SET_BIT(PORTC, a_pin);
	    break;
	    }
	break;

    case PORTD_ID:
	switch (a_state)
	    {
	case PIN_INPUT:
	    CLEAR_BIT(DDRD, a_pin);
	    break;
	case PIN_OUTPUT:
	    SET_BIT(DDRD, a_pin);
	    break;
	case PIN_INPUT_PULLUP:
	    CLEAR_BIT(DDRD, a_pin);
	    SET_BIT(PORTD, a_pin);
	    break;
	    }
	break;
	}
    }

/**
 * @brief Writes a value to a GPIO pin.
 *
 * Sets the logic state (HIGH or LOW) of a specified pin on a given port.
 *
 * @param a_port The port ID (PORTA_ID, PORTB_ID, etc.)
 * @param a_pin The pin number on the port.
 * @param a_state The desired state (HIGH or LOW).
 */
void GPIO_writePin(uint8 a_port, uint8 a_pin, uint8 a_state)
    {
    switch (a_port)
	{
    case PORTA_ID:
	if (a_state == LOW)
	    {
	    CLEAR_BIT(PORTA, a_pin);
	    }
	else
	    {
	    SET_BIT(PORTA, a_pin);
	    }
	break;

    case PORTB_ID:
	if (a_state == LOW)
	    {
	    CLEAR_BIT(PORTB, a_pin);
	    }
	else
	    {
	    SET_BIT(PORTB, a_pin);
	    }
	break;

    case PORTC_ID:
	if (a_state == LOW)
	    {
	    CLEAR_BIT(PORTC, a_pin);
	    }
	else
	    {
	    SET_BIT(PORTC, a_pin);
	    }
	break;

    case PORTD_ID:
	if (a_state == LOW)
	    {
	    CLEAR_BIT(PORTD, a_pin);
	    }
	else
	    {
	    SET_BIT(PORTD, a_pin);
	    }
	break;
	}
    }

/**
 * @brief Toggles the state of a GPIO pin.
 *
 * Switches the logic state of a specified pin on a given port (HIGH to LOW, or LOW to HIGH).
 *
 * @param a_port The port ID (PORTA_ID, PORTB_ID, etc.)
 * @param pin The pin number on the port.
 */
void GPIO_tooglePin(uint8 a_port, uint8 pin)
    {
    switch (a_port)
	{
    case PORTA_ID:
	TOGGLE_BIT(PORTA, pin);
	break;
    case PORTB_ID:
	TOGGLE_BIT(PORTB, pin);
	break;
    case PORTC_ID:
	TOGGLE_BIT(PORTC, pin);
	break;
    case PORTD_ID:
	TOGGLE_BIT(PORTD, pin);
	break;
	}
    }

/**
 * @brief Reads the state of a GPIO pin.
 *
 * Returns the current logic state (HIGH or LOW) of a specified pin on a given port.
 *
 * @param a_port The port ID (PORTA_ID, PORTB_ID, etc.)
 * @param pin The pin number on the port.
 * @return The current state of the pin (1 for HIGH, 0 for LOW).
 */
uint8 GPIO_readPin(uint8 a_port, uint8 pin)
    {
    switch (a_port)
	{
    case PORTA_ID:
	return GET_BIT(PINA, pin);
    case PORTB_ID:
	return GET_BIT(PINB, pin);
    case PORTC_ID:
	return GET_BIT(PINC, pin);
    case PORTD_ID:
	return GET_BIT(PIND, pin);
    default:
	return 0;
	}
    }

/**
 * @brief Sets the state of a GPIO pin stored in program memory.
 *
 * This function uses the `PGM_readPtrToRam` function to read the pin's port and pin address from
 * program memory and set the pin's state (HIGH or LOW).
 *
 * @param a_pin The index of the pin in the `ioPins` array stored in flash memory.
 * @param a_value The desired state (HIGH or LOW).
 */
void GPIO_ARR_setPinState(uint8 a_pin, uint8 a_value)
    {
    if (a_pin > NUM_OF_PINS)
	return;
    volatile uint8 *port = (volatile uint8*) PGM_readPtrToRam(
	    (uint16) (&ioPins[a_pin].port_addr));
    uint8 pin = pgm_read_byte(&(ioPins[a_pin].pin));

    if (a_value == HIGH)
	{
	SET_BIT(*port, pin);
	}
    else
	{
	CLEAR_BIT(*port, pin);
	}
    }

/**
 * @brief Sets the direction of a GPIO pin stored in program memory.
 *
 * This function uses the `PGM_readPtrToRam` function to read the pin's DDR address from
 * program memory and set the pin's direction (input, output, or input with pull-up).
 *
 * @param a_pin The index of the pin in the `ioPins` array stored in flash memory.
 * @param a_state The desired direction (PIN_INPUT, PIN_OUTPUT, PIN_INPUT_PULLUP).
 */
void GPIO_ARR_setPinDirection(uint8 a_pin, uint8 a_state)
    {
    if (a_pin > NUM_OF_PINS)
	return;
    volatile uint8 *ddr = (volatile uint8*) PGM_readPtrToRam(
	    (uint16) (&ioPins[a_pin].ddr_addr));
    volatile uint8 *port = (volatile uint8*) PGM_readPtrToRam(
	    (uint16) (&ioPins[a_pin].port_addr));
    uint8 pin = pgm_read_byte(&(ioPins[a_pin].pin));

    if (a_state == PIN_INPUT)
	{
	CLEAR_BIT(*ddr, pin);
	}
    else if (a_state == PIN_OUTPUT)
	{
	SET_BIT(*ddr, pin);
	}
    else if (a_state == PIN_INPUT_PULLUP)
	{
	CLEAR_BIT(*ddr, pin);
	SET_BIT(*port, pin);
	}
    }

/**
 * @brief Reads the state of a GPIO pin stored in program memory.
 *
 * This function reads the state of a specified pin stored in program memory.
 *
 * @param a_pin The index of the pin in the `ioPins` array stored in flash memory.
 * @return The current state of the pin (1 for HIGH, 0 for LOW).
 */
uint8 GPIO_ARR_readPin(uint8 a_pin)
    {
    if (a_pin > NUM_OF_PINS)
	return 0;
    volatile uint8 *pin_addr = (volatile uint8*) PGM_readPtrToRam(
	    (uint16) (&ioPins[a_pin].pin_addr));
    uint8 pin = pgm_read_byte(&(ioPins[a_pin].pin));
    return GET_BIT(*pin_addr, pin);
    }
