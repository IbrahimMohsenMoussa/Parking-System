/**
 * @file lcd.h
 * @brief LCD Hardware Abstraction Layer (HAL) interface.
 *
 * This file provides the declarations for interfacing with a 2x16 character LCD
 * display using a microcontroller. It includes definitions for LCD control pins,
 * various LCD commands, and essential functions for sending data and commands to the LCD.
 *
 * @date 27 Sept 2024
 * @author Ibrahim Mohsen
 */

#ifndef LCD_H_
#define LCD_H_

#include "../common/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/**
 *  @brief LCD configuration either 8 bit or 4 bit .
 *  if 8 bit uncomment the macro definition below if 4 bit leave it as is
 *
#define LCD_8_BIT_MODE
**/

/**
 * @brief GPIO pin connected to the Register Select (RS) pin of the LCD.
 *
 * The RS pin selects between sending commands (RS=0) and data (RS=1) to the LCD.
 */
#define LCD_RS GPIO_PA1

/**
 * @brief GPIO pin connected to the Enable (E) pin of the LCD.
 *
 * The E pin is used to latch data on the data pins when transitioning from high to low.
 */
#define LCD_E   GPIO_PA2
#ifdef LCD_8_BIT_MODE
/**
 * @brief The ID of the GPIO port used for data transmission to the LCD.
 *
 * This should correspond to the microcontroller port where the LCD's data lines (D0-D7) are connected.
 */

#define LCD_DATA_PORT PORTC_ID
#else
/**
 * @brief The ID of the GPIO pins used for data transmission to the LCD.
 *
 * This should correspond to the microcontroller pins where the LCD's data lines (D4-D7) are connected.
 */
#define LCD_D4 GPIO_PA3
#define LCD_D5 GPIO_PA4
#define LCD_D6 GPIO_PA5
#define LCD_D7 GPIO_PA6
#endif
/**
 * @brief Delay in microseconds for the TA (Enable) signal timing.
 *
 * A small delay is required between setting the Enable pin high and low to latch data/commands.
 */
#define LCD_TA_DELAY_US 1

/**
 * @brief Command to configure the LCD for 2 lines and 8-bit data mode.
 */
#define LCD_TWO_LINE_EIGHT_BIT_COMMAND 0x38
/**
 * @brief Command to configure the LCD for 2 lines and 4-bit data mode.
 */
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
/**
 * @brief Commands to init the LCD for 2 lines and 4-bit data mode.
 */
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32


/**
 * @brief Command to turn off the LCD cursor.
 */
#define LCD_CURSOR_OFF_COMMAND 0x0c

/**
 * @brief Command to clear the entire LCD display.
 */
#define LCD_CLEAR_SCREEN_COMMAND 0x01

/**
 * @brief Number of display rows on the LCD.
 */
#define LCD_ROWS 2

/**
 * @brief Number of character columns on the LCD.
 */
#define LCD_COLUMNS 16

/**
 * @brief Maximum column index for the LCD.
 *
 * Since columns are indexed from 0, the maximum index is 15 for a 16-column display.
 */
#define LCD_MAX_COLUMNS_INDEX 15

/**
 * @brief Command to set the cursor location.
 *
 * This command is used in combination with row/column offsets to move the cursor to a specific position.
 */
#define LCD_SET_CURSOR_LOCATION 0x80

/**
 * @brief Memory offset for the first row of the LCD.
 *
 * This value is used to calculate cursor positions for the first row.
 */
#define LCD_ROW_1_OFFSET 0x40

/**
 * @brief Memory offset for the second row of the LCD.
 *
 * This value is used to calculate cursor positions for the second row.
 */
#define LCD_ROW_2_OFFSET 0x10

/**
 * @brief Memory offset for the third row of the LCD (if applicable for larger displays).
 */
#define LCD_ROW_3_OFFSET 0x50

/*******************************************************************************
 *                               Function Prototypes                           *
 *******************************************************************************/

/**
 * @brief Sends a character to the LCD to be displayed at the current cursor position.
 *
 * @param data The character to send (ASCII value).
 */
void LCD_displayChar(uint8 data);

/**
 * @brief Sends a command to the LCD.
 *
 * Commands are used to configure the LCD (e.g., clear the screen, set cursor position).
 *
 * @param command The command to send (refer to defined command constants).
 */
void LCD_sendCommand(uint8 command);

/**
 * @brief Initializes the LCD in 8-bit mode with 2 display lines.
 *
 * This function should be called during system initialization to configure the LCD.
 */
void LCD_init();

/**
 * @brief Displays a string on the LCD starting from the current cursor position.
 *
 * @param str Pointer to a null-terminated string to be displayed on the LCD.
 * @return LCD_ERROR Indicates if the string exceeds the maximum column limit (returns EXCEEDMAXCOLUMNS) or success (returns SUCCESS).
 */
uint8 LCD_displayString(const char* str);

/**
 * @brief Moves the LCD cursor to a specific position.
 *
 * The cursor is moved to the given row and column.
 *
 * @param a_lcdRow The row number (0 or 1).
 * @param a_lcdCol The column number (0 to 15).
 */
void LCD_moveCursor(uint8 a_lcdRow, uint8 a_lcdCol);
void LCD_intgerToString( int);
/*******************************************************************************
 *                               Data Types                                    *
 *******************************************************************************/

/**
 * @enum LCD_ERROR
 * @brief Defines possible error codes for LCD operations.
 *
 * These error codes are used to signal whether a certain operation was successful or if an issue occurred (e.g., exceeding column limits).
 */
typedef enum {
    SUCSSES,         /**< Indicates successful completion of an operation. */
    EXCEEDMAXCOLUMNS /**< Indicates that the operation exceeded the maximum column limit of the LCD. */
} LCD_ERROR;
void LCD_displayStringRowColumn(uint8 row, uint8 col, const char *Str);
#endif /* LCD_H_ */
