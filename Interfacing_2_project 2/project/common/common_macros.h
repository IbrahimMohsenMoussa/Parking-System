/**
 * @file Common_Macros.h
 * @brief Commonly used bit manipulation macros for AVR platform.
 *
 * This file contains a collection of macros to perform common bit-level operations.
 * These macros simplify tasks such as setting, clearing, toggling, and checking bits
 * in various registers and memory locations. They also include macros for rotating
 * register values left or right.
 *
 * @date 22 Sept 2024
 * @author Mohamed Tarek
 */

#ifndef COMMON_MACROS
#define COMMON_MACROS

/*******************************************************************************
 *                                Macros                                       *
 *******************************************************************************/

/**
 * @brief Sets a specific bit in a register.
 *
 * This macro sets (writes 1 to) a specific bit in the given register.
 *
 * @param REG The register in which the bit is to be set.
 * @param BIT The bit number to set (0-7 for an 8-bit register).
 */
#define SET_BIT(REG, BIT) (REG |= (1 << BIT))

/**
 * @brief Clears a specific bit in a register.
 *
 * This macro clears (writes 0 to) a specific bit in the given register.
 *
 * @param REG The register in which the bit is to be cleared.
 * @param BIT The bit number to clear (0-7 for an 8-bit register).
 */
#define CLEAR_BIT(REG, BIT) (REG &= (~(1 << BIT)))

/**
 * @brief Toggles a specific bit in a register.
 *
 * This macro toggles (inverts) the value of a specific bit in the given register.
 * If the bit is 1, it becomes 0; if it is 0, it becomes 1.
 *
 * @param REG The register in which the bit is to be toggled.
 * @param BIT The bit number to toggle (0-7 for an 8-bit register).
 */
#define TOGGLE_BIT(REG, BIT) (REG ^= (1 << BIT))

/**
 * @brief Rotates the value of a register to the right by a specified number of bits.
 *
 * This macro performs a circular right shift on the value of the given register.
 * It moves each bit to the right and the rightmost bits wrap around to the leftmost positions.
 *
 * @param REG The register to rotate.
 * @param num The number of positions to rotate.
 */
#define ROR(REG, num) (REG = (REG >> num) | (REG << (8 - num)))

/**
 * @brief Rotates the value of a register to the left by a specified number of bits.
 *
 * This macro performs a circular left shift on the value of the given register.
 * It moves each bit to the left and the leftmost bits wrap around to the rightmost positions.
 *
 * @param REG The register to rotate.
 * @param num The number of positions to rotate.
 */
#define ROL(REG, num) (REG = (REG << num) | (REG >> (8 - num)))

/**
 * @brief Checks if a specific bit is set in a register.
 *
 * This macro checks whether a specific bit in the given register is set (1).
 * It returns a non-zero value (true) if the bit is set, and zero (false) otherwise.
 *
 * @param REG The register to check.
 * @param BIT The bit number to check (0-7 for an 8-bit register).
 * @return Non-zero if the bit is set; 0 if the bit is cleared.
 */
#define BIT_IS_SET(REG, BIT) (REG & (1 << BIT))

/**
 * @brief Checks if a specific bit is cleared in a register.
 *
 * This macro checks whether a specific bit in the given register is cleared (0).
 * It returns a non-zero value (true) if the bit is cleared, and zero (false) otherwise.
 *
 * @param REG The register to check.
 * @param BIT The bit number to check (0-7 for an 8-bit register).
 * @return Non-zero if the bit is cleared; 0 if the bit is set.
 */
#define BIT_IS_CLEAR(REG, BIT) (!(REG & (1 << BIT)))

/**
 * @brief Gets the value of a specific bit in a register.
 *
 * This macro retrieves the value of a specific bit in the given register.
 * It returns the value of the bit as either 0 or 1.
 *
 * @param REG The register from which the bit value is to be retrieved.
 * @param BIT_NO The bit number to retrieve (0-7 for an 8-bit register).
 * @return The value of the bit (0 or 1).
 */
#define GET_BIT(REG, BIT_NO) (((REG) & (1 << BIT_NO)) >> BIT_NO)

/**
 * @brief Maps a value from one range to another.
 *
 * This macro takes an input value `X` within the range [`IN_MIN`, `IN_MAX`] and maps it to an output value
 * in the range [`OUT_MIN`, `OUT_MAX`]. It performs a linear transformation to ensure that the proportion
 * of the value `X` within the input range is maintained in the output range.
 *
 * The formula used for mapping is:
 *
 *   OUT = ((X - IN_MIN) * (OUT_MAX - OUT_MIN)) / (IN_MAX - IN_MIN) + OUT_MIN
 *
 * Example use case: If you want to map an analog sensor value (e.g., a reading between 0 and 1023)
 * to a different range (e.g., 0 to 255 for PWM), you can use this macro to perform the mapping.
 *
 * @param X         The input value to be mapped.
 * @param IN_MIN    The minimum value of the input range.
 * @param IN_MAX    The maximum value of the input range.
 * @param OUT_MIN   The minimum value of the output range.
 * @param OUT_MAX   The maximum value of the output range.
 *
 * @return The mapped value in the output range.
 */
#define MAP(X,IN_MIN,IN_MAX,OUT_MIN,OUT_MAX) (((X) - (IN_MIN)) * ((OUT_MAX) - (OUT_MIN)) / ((IN_MAX) - (IN_MIN)) + (OUT_MIN))
#endif /* COMMON_MACROS */
