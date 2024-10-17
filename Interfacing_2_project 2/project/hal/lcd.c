/**
 * @file lcd.c
 * @brief LCD Hardware Abstraction Layer (HAL) implementation.
 *
 * This file provides the implementation for controlling a 2x16 character LCD.
 * It includes functions to send commands and characters to the LCD, initialize the LCD,
 * display strings, move the cursor, and perform other operations.
 *
 * @date 27 Sept 2024
 * @author Ibrahim Mohsen
 */

#include "../mcal/gpio.h"
#include "../common/common_macros.h"
#include "lcd.h"
#include <util/delay.h>
#include <stdlib.h>
#include <avr/io.h>

/**
 * @brief Sends a command to the LCD.
 *
 * This function sends a command to the LCD to perform specific operations
 * such as clearing the screen, setting display modes, or moving the cursor.
 *
 * @param a_lcdCommand The command to be sent to the LCD (e.g., LCD_CLEAR_SCREEN_COMMAND).
 */
void LCD_sendCommand(uint8 a_lcdCommand) {
	GPIO_ARR_setPinState(LCD_RS, LOW); /* Set RS to 0 for command mode */
	_delay_us(LCD_TA_DELAY_US); /* Delay for timing */
	GPIO_ARR_setPinState(LCD_E, HIGH); /* Enable the LCD */
	_delay_us(LCD_TA_DELAY_US); /* Delay for timing */

#ifdef LCD_8_BIT_MODE
    GPIO_writePort(LCD_DATA_PORT, a_lcdChar);  /* Send character to data port */
    _delay_us(LCD_TA_DELAY_US);          /* Delay for timing */
    GPIO_ARR_setPinState(LCD_E, LOW);    /* Disable the LCD to latch the character */
    _delay_us(LCD_TA_DELAY_US);          /* Delay for timing */
#else
	GPIO_ARR_setPinState(LCD_D4, GET_BIT(a_lcdCommand, 4));
	GPIO_ARR_setPinState(LCD_D5, GET_BIT(a_lcdCommand, 5));
	GPIO_ARR_setPinState(LCD_D6, GET_BIT(a_lcdCommand, 6));
	GPIO_ARR_setPinState(LCD_D7, GET_BIT(a_lcdCommand, 7));
	_delay_us(LCD_TA_DELAY_US);
	GPIO_ARR_setPinState(LCD_E, LOW); /* Disable the LCD to latch the character */
	_delay_us(LCD_TA_DELAY_US); /* Delay for timing */
	GPIO_ARR_setPinState(LCD_E, HIGH); /* Enable the LCD */
	GPIO_ARR_setPinState(LCD_D4, GET_BIT(a_lcdCommand, 0));
	GPIO_ARR_setPinState(LCD_D5, GET_BIT(a_lcdCommand, 1));
	GPIO_ARR_setPinState(LCD_D6, GET_BIT(a_lcdCommand, 2));
	GPIO_ARR_setPinState(LCD_D7, GET_BIT(a_lcdCommand, 3));
	_delay_us(LCD_TA_DELAY_US); /* Delay for timing */
	GPIO_ARR_setPinState(LCD_E, LOW); /* Disable the LCD to latch the character */
	_delay_us(LCD_TA_DELAY_US); /* Delay for timing */

#endif
}

/**
 * @brief Sends a character to the LCD to be displayed at the current cursor position.
 *
 * This function sends a single character to the LCD for display.
 * It sets the RS pin to 1 to indicate that the data is a character.
 *
 * @param a_lcdChar The ASCII character to be sent to the LCD.
 */
void LCD_displayChar(uint8 a_lcdChar) {
	GPIO_ARR_setPinState(LCD_RS, HIGH); /* Set RS to 1 for data mode */
	_delay_us(LCD_TA_DELAY_US); /* Delay for timing */
	GPIO_ARR_setPinState(LCD_E, HIGH); /* Enable the LCD */
	_delay_us(LCD_TA_DELAY_US); /* Delay for timing */
#ifdef LCD_8_BIT_MODE
    GPIO_writePort(LCD_DATA_PORT, a_lcdChar);  /* Send character to data port */
    _delay_us(LCD_TA_DELAY_US);          /* Delay for timing */
    GPIO_ARR_setPinState(LCD_E, LOW);    /* Disable the LCD to latch the character */
    _delay_us(LCD_TA_DELAY_US);          /* Delay for timing */
#else
	GPIO_ARR_setPinState(LCD_D4, GET_BIT(a_lcdChar, 4));
	GPIO_ARR_setPinState(LCD_D5, GET_BIT(a_lcdChar, 5));
	GPIO_ARR_setPinState(LCD_D6, GET_BIT(a_lcdChar, 6));
	GPIO_ARR_setPinState(LCD_D7, GET_BIT(a_lcdChar, 7));
	_delay_us(LCD_TA_DELAY_US);
	GPIO_ARR_setPinState(LCD_E, LOW); /* Disable the LCD to latch the character */
	_delay_us(LCD_TA_DELAY_US); /* Delay for timing */
	GPIO_ARR_setPinState(LCD_E, HIGH); /* Enable the LCD */
	GPIO_ARR_setPinState(LCD_D4, GET_BIT(a_lcdChar, 0));
	GPIO_ARR_setPinState(LCD_D5, GET_BIT(a_lcdChar, 1));
	GPIO_ARR_setPinState(LCD_D6, GET_BIT(a_lcdChar, 2));
	GPIO_ARR_setPinState(LCD_D7, GET_BIT(a_lcdChar, 3));
	_delay_us(LCD_TA_DELAY_US); /* Delay for timing */
	GPIO_ARR_setPinState(LCD_E, LOW); /* Disable the LCD to latch the character */
	_delay_us(LCD_TA_DELAY_US); /* Delay for timing */

#endif
}

/**
 * @brief Initializes the LCD in 8-bit mode with 2 display lines.
 *
 * This function configures the LCD by setting the appropriate modes (2-line, 8-bit),
 * turning off the cursor, and clearing the display. It should be called once during initialization.
 */
void LCD_init() {
	GPIO_ARR_setPinDirection(LCD_RS, PIN_OUTPUT); /* Set RS pin as output */
	GPIO_ARR_setPinDirection(LCD_E, PIN_OUTPUT); /* Set E pin as output */
	_delay_ms(20); /* Wait for LCD to power up */
#ifdef LCD_8_BIT_MODE
    GPIO_setupPortDirection(LCD_DATA_PORT, PORT_OUTPUT);  /* Set data port as output */
    LCD_sendCommand(LCD_TWO_LINE_EIGHT_BIT_COMMAND);  /* Set LCD to 2 lines, 8-bit mode */
#else
	GPIO_ARR_setPinDirection(LCD_D4, PIN_OUTPUT);
	GPIO_ARR_setPinDirection(LCD_D5, PIN_OUTPUT);
	GPIO_ARR_setPinDirection(LCD_D6, PIN_OUTPUT);
	GPIO_ARR_setPinDirection(LCD_D7, PIN_OUTPUT);
	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);
#endif

	LCD_sendCommand(LCD_CURSOR_OFF_COMMAND); /* Turn off cursor */
	LCD_sendCommand(LCD_CLEAR_SCREEN_COMMAND); /* Clear the LCD screen */
	LCD_moveCursor(0,0);
}

/**
 * @brief Displays a string on the LCD starting from the current cursor position.
 *
 * This function sends a null-terminated string to the LCD. The string is displayed starting
 * at the current cursor location. The function will not display more than the maximum number
 * of columns allowed by the LCD.
 *
 * @param a_lcdString Pointer to the null-terminated string to be displayed.
 * @return LCD_ERROR Returns SUCSSES if the string fits within the display, otherwise returns EXCEEDMAXCOLUMNS.
 */
uint8 LCD_displayString(const char *a_lcdString) {
	int i = 0;
	while (a_lcdString[i] != '\0') {
		LCD_displayChar(a_lcdString[i]); /* Send each character in the string */
		if (i == LCD_MAX_COLUMNS_INDEX) /* Stop if maximum column index is reached */
			break;
		i++;
	}
	return i < LCD_COLUMNS ? SUCSSES : EXCEEDMAXCOLUMNS; /* Return appropriate status */
}

/**
 * @brief Moves the LCD cursor to a specific position.
 *
 * This function moves the cursor to the specified row and column on the LCD.
 * It calculates the appropriate memory address in the LCD and sends the cursor
 * position command.
 *
 * @param a_lcdRow The row to move the cursor to (0 to LCD_ROWS-1).
 * @param a_lcdCol The column to move the cursor to (0 to LCD_MAX_COLUMNS_INDEX).
 */
void LCD_moveCursor(uint8 a_lcdRow, uint8 a_lcdCol) {
	uint8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch (a_lcdRow) {
	case 0:
		lcd_memory_address = a_lcdCol;
		break;
	case 1:
		lcd_memory_address = a_lcdCol + LCD_ROW_1_OFFSET;
		break;
	case 2:
		lcd_memory_address = a_lcdCol + LCD_ROW_2_OFFSET;
		break;
	case 3:
		lcd_memory_address = a_lcdCol + LCD_ROW_3_OFFSET;
		break;
	}

	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/**
 * @brief Displays a string starting at a specified row and column on the LCD.
 *
 * This function moves the cursor to the given row and column, then displays the provided string.
 *
 * @param row The row to start displaying the string (0 to LCD_ROWS-1).
 * @param col The column to start displaying the string (0 to LCD_MAX_COLUMNS_INDEX).
 * @param Str Pointer to the null-terminated string to be displayed.
 */
void LCD_displayStringRowColumn(uint8 row, uint8 col, const char *Str) {
	LCD_moveCursor(row, col); /* Move to specified row and column */
	LCD_displayString(Str); /* Display the string at the new cursor location */
}

/**
 * @brief Displays an integer on the LCD.
 *
 * This function converts an integer to its ASCII string representation and
 * displays the string on the LCD.
 *
 * @param data The integer value to be displayed.
 */
void LCD_intgerToString(int data) {
	char buff[16]; /* Buffer to hold ASCII representation of the integer */
	itoa(data, buff, 10); /* Convert integer to string (base 10) */
	LCD_displayString(buff); /* Display the resulting string on the LCD */
}

/**
 * @brief Clears the entire LCD display.
 *
 * This function sends the clear screen command to the LCD, clearing all the displayed
 * characters and resetting the cursor to the home position.
 */
void LCD_clearScreen(void) {
	LCD_sendCommand(LCD_CLEAR_SCREEN_COMMAND); /* Send clear display command */
}
