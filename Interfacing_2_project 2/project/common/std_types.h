/**
 * @file std_types.h
 * @brief Standard type definitions and common macros for AVR platform.
 *
 * This file contains typedefs and macros that abstract platform-specific data types.
 * It provides standardized types for different variable sizes, boolean types, and
 * commonly used constants like TRUE, FALSE, NULL, and logic levels.
 *
 * @date 22 Sept 2024
 * @author Mohamed Tarek
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/**
 * @brief Boolean data type definition.
 *
 * This typedef defines a boolean type for use in logic operations. It is an unsigned char.
 * The values of `boolean` can be either TRUE (1) or FALSE (0).
 */
typedef unsigned char boolean;

/**
 * @brief Macro for the FALSE boolean value.
 *
 * This macro defines FALSE as 0. It is used in logic operations to indicate a false condition.
 */
#ifndef FALSE
#define FALSE       (0u) /**< FALSE boolean value (0). */
#endif

/**
 * @brief Macro for the TRUE boolean value.
 *
 * This macro defines TRUE as 1. It is used in logic operations to indicate a true condition.
 */
#ifndef TRUE
#define TRUE        (1u) /**< TRUE boolean value (1). */
#endif

/**
 * @brief Macro for logic high state.
 *
 * This macro defines a logic high state (1). It is typically used to represent
 * a high signal or voltage level in digital systems.
 */
#define LOGIC_HIGH        (1u) /**< Logic high state (1). */

/**
 * @brief Macro for logic low state.
 *
 * This macro defines a logic low state (0). It is typically used to represent
 * a low signal or voltage level in digital systems.
 */
#define LOGIC_LOW         (0u) /**< Logic low state (0). */

/**
 * @brief Macro for a null pointer.
 *
 * This macro defines a null pointer (`NULL_PTR`) as a pointer to address 0. It is used
 * to indicate the absence of a valid memory reference.
 */
#define NULL_PTR    ((void*)0) /**< Null pointer definition. */

/*******************************************************************************
 *                                Data Types                                   *
 *******************************************************************************/

/**
 * @typedef uint8_t
 * @brief 8-bit unsigned integer type.
 *
 * This typedef defines an unsigned 8-bit integer, representing values from 0 to 255.
 */
typedef unsigned char         uint8;          /**< Unsigned 8-bit integer (0 to 255). */

/**
 * @typedef sint8_t
 * @brief 8-bit signed integer type.
 *
 * This typedef defines a signed 8-bit integer, representing values from -128 to +127.
 */
typedef signed char           sint8;          /**< Signed 8-bit integer (-128 to +127). */

/**
 * @typedef uint16_t
 * @brief 16-bit unsigned integer type.
 *
 * This typedef defines an unsigned 16-bit integer, representing values from 0 to 65535.
 */
typedef unsigned short        uint16;         /**< Unsigned 16-bit integer (0 to 65535). */

/**
 * @typedef sint16_t
 * @brief 16-bit signed integer type.
 *
 * This typedef defines a signed 16-bit integer, representing values from -32768 to +32767.
 */
typedef signed short          sint16;         /**< Signed 16-bit integer (-32768 to +32767). */

/**
 * @typedef uint32_t
 * @brief 32-bit unsigned integer type.
 *
 * This typedef defines an unsigned 32-bit integer, representing values from 0 to 4294967295.
 */
typedef unsigned long         uint32;         /**< Unsigned 32-bit integer (0 to 4294967295). */

/**
 * @typedef sint32_t
 * @brief 32-bit signed integer type.
 *
 * This typedef defines a signed 32-bit integer, representing values from -2147483648 to +2147483647.
 */
typedef signed long           sint32;         /**< Signed 32-bit integer (-2147483648 to +2147483647). */

/**
 * @typedef uint64_t
 * @brief 64-bit unsigned integer type.
 *
 * This typedef defines an unsigned 64-bit integer, representing values from 0 to 18446744073709551615.
 */
typedef unsigned long long    uint64;         /**< Unsigned 64-bit integer (0 to 18446744073709551615). */

/**
 * @typedef sint64_t
 * @brief 64-bit signed integer type.
 *
 * This typedef defines a signed 64-bit integer, representing values from -9223372036854775808 to +9223372036854775807.
 */
typedef signed long long      sint64;         /**< Signed 64-bit integer (-9223372036854775808 to +9223372036854775807). */

/**
 * @typedef float32_t
 * @brief 32-bit floating-point type.
 *
 * This typedef defines a 32-bit floating-point number (single precision).
 */
typedef float                 float32;        /**< 32-bit floating-point number. */

/**
 * @typedef float64_t
 * @brief 64-bit floating-point type.
 *
 * This typedef defines a 64-bit floating-point number (double precision).
 */
typedef double                float64;        /**< 64-bit floating-point number. */

#endif /* STD_TYPES_H_ */
