/**
 * @file ultrasonic.h
 * @brief Ultrasonic Sensor Driver for measuring distance using ICU
 *
 * This file contains the function declarations for interfacing with an
 * ultrasonic sensor (e.g., HC-SR04) using the ICU (Input Capture Unit) of the AVR.
 *
 * @date 11 Oct 2024
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "../common/std_types.h"
#define ULTRASONIC_TRIGGER_PIN  GPIO_PD7
/**
 * @brief Initializes the Ultrasonic sensor.
 *
 * This function initializes the ICU, sets up the trigger pin, and configures the ultrasonic sensor.
 */
void Ultrasonic_init(void);

/**
 * @brief Triggers the Ultrasonic sensor to start a distance measurement.
 *
 * This function sends a trigger pulse to the ultrasonic sensor.
 */
void Ultrasonic_Trigger(void);

/**
 * @brief Reads the distance measured by the Ultrasonic sensor.
 *
 * This function calculates the distance based on the echo pulse duration and returns it.
 *
 * @return The measured distance in centimeters (cm).
 */
uint16 Ultrasonic_readDistance(void);

/**
 * @brief Callback function for ICU edge detection.
 *
 * This function is called by the ICU when an edge is detected (rising/falling) and
 * processes the echo pulse.
 */
void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */
