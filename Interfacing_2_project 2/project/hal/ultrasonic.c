#include "ultrasonic.h"
#include "../mcal/icu.h"
#include "../mcal/gpio.h"
#include "../mcal/atmega32_regs.h"
#include <util/delay.h>
#include <avr/interrupt.h>

/**
 * @brief Global variable to store the duration of the echo pulse in timer ticks.
 *
 * This variable stores the high pulse duration (time between trigger and received echo)
 * measured by the Input Capture Unit (ICU).
 */
static volatile uint16 g_timeHigh = 0;

/**
 * @brief Global variable to track the number of edges detected by the ICU.
 *
 * Used to determine whether a rising or falling edge is detected.
 * - `0`: Rising edge detected (start of echo pulse)
 * - `1`: Falling edge detected (end of echo pulse)
 */
static volatile uint8 g_edgeCount = 0;

/**
 * @brief Global flag indicating whether a valid echo pulse has been received.
 *
 * Set to `1` when the echo pulse measurement is complete and the distance is ready to be calculated.
 * Cleared to `0` once the distance is processed.
 */
static volatile uint8 g_readyFlag = 0;

/**
 * @brief Initializes the ultrasonic sensor by setting up the ICU and the trigger pin.
 *
 * This function initializes the ICU to detect the echo pulse duration from the ultrasonic sensor.
 * It configures the ICU to initially detect a rising edge (start of the pulse) and sets up the
 * ultrasonic sensor's trigger pin as an output.
 *
 * It also enables global interrupts for proper ICU operation.
 *
 * @return void
 */
void Ultrasonic_init(void) {
    ICU_ConfigType icuConfig = { F_CPU_8, RAISING };  /**< ICU configuration: prescaler and rising edge */
    ICU_init(&icuConfig);                             /**< Initialize the ICU with the given configuration */

    /* Set callback for edge processing function (to be called when ICU detects edges) */
    ICU_setCallBack(Ultrasonic_edgeProcessing);

    /* Configure the ultrasonic trigger pin as output */
    GPIO_ARR_setPinDirection(ULTRASONIC_TRIGGER_PIN, PIN_OUTPUT);

    /* Enable global interrupts */
    sei();
}

/**
 * @brief Sends a trigger pulse to the ultrasonic sensor.
 *
 * The ultrasonic sensor requires a 10µs high pulse on its trigger pin to start measuring the distance.
 * This function generates that pulse by setting the trigger pin high for 10µs and then setting it low.
 *
 * @return void
 */
void Ultrasonic_Trigger(void) {
    /* Set the trigger pin high */
    GPIO_ARR_setPinState(ULTRASONIC_TRIGGER_PIN, LOGIC_HIGH);

    /* Wait for 10 microseconds */
    _delay_us(10);

    /* Set the trigger pin low */
    GPIO_ARR_setPinState(ULTRASONIC_TRIGGER_PIN, LOGIC_LOW);
}

/**
 * @brief Reads the distance measured by the ultrasonic sensor in centimeters.
 *
 * This function triggers the ultrasonic sensor, waits for the echo to be processed, and calculates
 * the distance based on the time taken for the echo pulse to return.
 *
 * The distance is calculated using the formula: \f$Distance = \frac{timeHigh}{117.647}\f$
 * where `timeHigh` is the duration of the echo pulse measured in timer ticks.
 *
 * @return The measured distance in centimeters.
 */
uint16 Ultrasonic_readDistance(void) {
    uint16 l_distance = 0;  /**< Local variable to store the calculated distance */

    /* Trigger the ultrasonic sensor to start measurement */
    Ultrasonic_Trigger();

    /* Enable ICU interrupt to start edge detection */
    ICU_interruptOn();

    /* Wait for the echo pulse to be processed (handled by the ICU interrupt) */
    while (!g_readyFlag);  /**< Wait until the echo pulse is processed */

    /* Disable ICU interrupt after measurement is done */
    ICU_interruptOff();

    /* Reset the ready flag for the next measurement */
    g_readyFlag = LOGIC_LOW;

    /* Calculate the distance in centimeters based on the timeHigh value */
    l_distance = (uint16) ((g_timeHigh) / 117);  /**< Calculate the distance */

    return l_distance;
}

/**
 * @brief ICU callback function to process rising and falling edges of the echo pulse.
 *
 * This function is called by the ICU interrupt service routine whenever an edge (rising or falling)
 * is detected. On the first call (rising edge), it resets the timer and switches to detect the falling edge.
 * On the second call (falling edge), it calculates the time duration of the echo pulse and signals
 * that the distance measurement is ready.
 *
 * @return void
 */
void Ultrasonic_edgeProcessing(void) {
    if (g_edgeCount == 0) {
        /* Rising edge detected: start measuring the echo pulse */
        ICU_clearTimerValue();                      /**< Clear the ICU timer */
        ICU_setEdgeDetectionType(FALLING);          /**< Switch to falling edge detection */
        g_edgeCount++;                              /**< Increment edge count */
    } else if (g_edgeCount == 1) {
        /* Falling edge detected: echo pulse received, calculate timeHigh */
        g_timeHigh = ICU_getInputCaptureValue();    /**< Store the time duration of the echo pulse */
        g_readyFlag = LOGIC_HIGH;                   /**< Set the ready flag to indicate valid measurement */
        ICU_setEdgeDetectionType(RAISING);          /**< Reset to rising edge detection for next measurement */
        g_edgeCount = 0;                            /**< Reset edge count for next cycle */
    }
}
