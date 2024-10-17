#include "../hal/ultrasonic.h"
#include "../hal/lcd.h"
#include "../hal/led.h"
#include "../hal/buzzer.h"
#include <util/delay.h>

#define DISTANCE_DANGER 5               /**< @brief Distance threshold for danger state in cm */
#define DISTANCE_WARNING_MAX 10         /**< @brief Maximum distance for warning state in cm */
#define DISTANCE_SAFE_MAX 15            /**< @brief Maximum distance for safe state in cm */
#define DISTANCE_DETECTED_MAX 20        /**< @brief Maximum distance for detected state in cm */

/**
 * @brief Displays the normal distance reading on the LCD.
 *
 * This function moves the cursor to the start of the LCD,
 * then displays the current distance measured by the ultrasonic sensor
 * along with the unit 'cm'.
 */
void LCD_dispDataNorm(void);

/**
 * @brief Displays a "STOP" danger message on the LCD.
 *
 * This function moves the cursor to the start of the LCD,
 * then displays a "STOP" message to warn the user of immediate danger.
 */
void LCD_dispDataDanger(void);

/**
 * @brief Handles the system behavior when in the danger state.
 *
 * In the danger state, the buzzer is activated, and all LEDs blink.
 * The blinking effect is achieved by alternating the LEDs on and off with delays.
 */
void handleDangerState(void);

/**
 * @brief Handles the system behavior when in the warning state.
 *
 * In the warning state, the distance is displayed on the LCD, and all LEDs are turned on.
 * The buzzer remains off.
 */
void handleWarningState(void);

/**
 * @brief Handles the system behavior when in the safe state.
 *
 * In the safe state, the distance is displayed on the LCD. The red and green LEDs are turned on,
 * while the blue LED remains off. The buzzer is not activated.
 */
void handleSafeState(void);

/**
 * @brief Handles the system behavior when in the detected state.
 *
 * In the detected state, the distance is displayed on the LCD, and only the red LED is turned on.
 * The green and blue LEDs are turned off, and the buzzer is off.
 */
void handleDetectedState(void);

/**
 * @brief Handles the system behavior when in the idle state.
 *
 * In the idle state, the distance is displayed on the LCD, and all LEDs and the buzzer are turned off.
 */
void handleIdleState(void);

/**
 * @brief State machine handler function.
 *
 * This function determines the current system state based on the measured distance and calls
 * the corresponding handler function for each state. The state transitions are as follows:
 * - DANGER: distance <= DISTANCE_DANGER
 * - WARNING: distance between DISTANCE_DANGER+1 and DISTANCE_WARNING_MAX
 * - SAFE: distance between DISTANCE_WARNING_MAX+1 and DISTANCE_SAFE_MAX
 * - DETECTED: distance between DISTANCE_SAFE_MAX+1 and DISTANCE_DETECTED_MAX
 * - IDLE: distance > DISTANCE_DETECTED_MAX
 */
void StateMachineHandler(void);

/**
 * @enum STATE_MACHINE
 * @brief Enum defining the different states of the system based on distance.
 *
 * The states are:
 * - IDLE: No object detected (distance > 20 cm)
 * - DETECTED: Object detected between 16 cm and 20 cm
 * - SAFE: Object detected between 11 cm and 15 cm
 * - WARNING: Object detected between 6 cm and 10 cm
 * - DANGER: Object detected at a dangerously close distance (≤ 5 cm)
 */
typedef enum {
    IDLE,       /**< No object detected (distance > 20 cm) */
    DETECTED,   /**< Object detected between 16 cm and 20 cm */
    SAFE,       /**< Object detected between 11 cm and 15 cm */
    WARNING,    /**< Object detected between 6 cm and 10 cm */
    DANGER      /**< Object detected at a dangerously close distance (≤ 5 cm) */
} STATE_MACHINE;

/**
 * @var g_distance
 * @brief Global variable to store the current distance measured by the ultrasonic sensor.
 *
 * This value is updated continuously in the main loop and used by the state machine handler
 * to determine the current system state.
 */
uint16 g_distance = 0;

/**
 * @var g_stateMachine
 * @brief Global variable to store the current state of the state machine.
 *
 * The state machine is updated based on the measured distance, and this variable holds
 * the current state (IDLE, DETECTED, SAFE, WARNING, or DANGER).
 */
STATE_MACHINE g_stateMachine = IDLE;

/**
 * @brief Main application entry point.
 *
 * Initializes all hardware components and continuously monitors the distance
 * to manage the state machine.
 *
 * @return This function does not return a value.
 */
int main(void) {
    /* Initialize hardware components */
    LED_init();            /**< Initialize the LED module */
    Ultrasonic_init();     /**< Initialize the ultrasonic sensor */
    LCD_init();            /**< Initialize the LCD display */
    Buzzer_init();         /**< Initialize the buzzer */

    /* Ensure the buzzer and LEDs are off initially */
    Buzzer_off();          /**< Turn off the buzzer */
    LED_off(LED_RED_3);    /**< Turn off the red LED */
    LED_off(LED_GREEN_2);  /**< Turn off the green LED */
    LED_off(LED_BLUE_1);   /**< Turn off the blue LED */

    /* Main loop to continuously read distance and update the state machine */
    for (;;) {
        /* Read the current distance from the ultrasonic sensor */
        g_distance = Ultrasonic_readDistance();

        /* Handle the state machine logic based on the distance */
        StateMachineHandler();
    }
}

/**
 * @brief State machine handler.
 *
 * This function determines the current state based on the measured distance and invokes
 * the corresponding handler function based on the determined state.
 */
void StateMachineHandler(void) {
    /* Determine the state based on the distance */
    if (g_distance <= DISTANCE_DANGER) {
        g_stateMachine = DANGER; /**< Set state to DANGER if distance is ≤ 5 cm */
    } else if (g_distance <= DISTANCE_WARNING_MAX) {
        g_stateMachine = WARNING; /**< Set state to WARNING if distance is between 6 cm and 10 cm */
    } else if (g_distance <= DISTANCE_SAFE_MAX) {
        g_stateMachine = SAFE; /**< Set state to SAFE if distance is between 11 cm and 15 cm */
    } else if (g_distance <= DISTANCE_DETECTED_MAX) {
        g_stateMachine = DETECTED; /**< Set state to DETECTED if distance is between 16 cm and 20 cm */
    } else {
        g_stateMachine = IDLE; /**< Set state to IDLE if distance is greater than 20 cm */
    }

    /* Invoke the appropriate handler function based on the current state */
    switch (g_stateMachine) {
        case DANGER:
            handleDangerState(); /**< Handle danger state */
            break;
        case WARNING:
            handleWarningState(); /**< Handle warning state */
            break;
        case SAFE:
            handleSafeState(); /**< Handle safe state */
            break;
        case DETECTED:
            handleDetectedState(); /**< Handle detected state */
            break;
        case IDLE:
            handleIdleState(); /**< Handle idle state */
            break;
    }
}

/**
 * @brief Handles the danger state.
 *
 * In the danger state, the buzzer is activated, and all LEDs blink in a pattern.
 * The blinking effect is achieved by alternating the LEDs on and off with delays.
 */
void handleDangerState(void) {
    LCD_dispDataDanger(); /**< Display danger message on the LCD */
    Buzzer_on();          /**< Turn on the buzzer */
    LED_on(LED_RED_3);    /**< Turn on the red LED */
    LED_on(LED_GREEN_2);  /**< Turn on the green LED */
    LED_on(LED_BLUE_1);   /**< Turn on the blue LED */
    _delay_ms(200);       /**< Delay to create a blinking effect */
    Buzzer_off();         /**< Turn off the buzzer */
    LED_off(LED_RED_3);   /**< Turn off the red LED */
    LED_off(LED_GREEN_2); /**< Turn off the green LED */
    LED_off(LED_BLUE_1);  /**< Turn off the blue LED */
    _delay_ms(200);       /**< Delay to create a blinking effect */
}

/**
 * @brief Handles the warning state.
 *
 * In the warning state, the distance is displayed on the LCD, and all LEDs are turned on.
 * The buzzer remains off.
 */
void handleWarningState(void) {
    LCD_dispDataNorm();   /**< Display normal distance on the LCD */
    Buzzer_off();         /**< Ensure the buzzer is off */
    LED_on(LED_RED_3);    /**< Turn on the red LED */
    LED_on(LED_GREEN_2);  /**< Turn on the green LED */
    LED_on(LED_BLUE_1);   /**< Turn on the blue LED */
}

/**
 * @brief Handles the safe state.
 *
 * In the safe state, the distance is displayed on the LCD. The red and green LEDs are turned on,
 * while the blue LED remains off. The buzzer is not activated.
 */
void handleSafeState(void) {
    LCD_dispDataNorm();   /**< Display normal distance on the LCD */
    Buzzer_off();         /**< Ensure the buzzer is off */
    LED_on(LED_RED_3);    /**< Turn on the red LED */
    LED_on(LED_GREEN_2);  /**< Turn on the green LED */
    LED_off(LED_BLUE_1);  /**< Turn off the blue LED */
}

/**
 * @brief Handles the detected state.
 *
 * In the detected state, the distance is displayed on the LCD, and only the red LED is turned on.
 * The green and blue LEDs are turned off, and the buzzer is off.
 */
void handleDetectedState(void) {
    LCD_dispDataNorm();   /**< Display normal distance on the LCD */
    Buzzer_off();         /**< Ensure the buzzer is off */
    LED_on(LED_RED_3);    /**< Turn on the red LED */
    LED_off(LED_GREEN_2); /**< Turn off the green LED */
    LED_off(LED_BLUE_1);  /**< Turn off the blue LED */
}

/**
 * @brief Handles the idle state.
 *
 * In the idle state, the distance is displayed on the LCD, and all LEDs and the buzzer are turned off.
 */
void handleIdleState(void) {
    LCD_dispDataNorm();   /**< Display normal distance on the LCD */
    Buzzer_off();         /**< Ensure the buzzer is off */
    LED_off(LED_RED_3);   /**< Turn off the red LED */
    LED_off(LED_GREEN_2); /**< Turn off the green LED */
    LED_off(LED_BLUE_1);  /**< Turn off the blue LED */
}

/**
 * @brief Displays the normal distance reading on the LCD.
 *
 * This function moves the cursor to the start of the LCD,
 * then displays the current distance measured by the ultrasonic sensor
 * along with the unit 'cm'.
 */
void LCD_dispDataNorm(void) {
    LCD_moveCursor(0, 0);                  /**< Move the cursor to the start */
    LCD_displayString("Distance= ");       /**< Display label for distance */
    LCD_intgerToString(g_distance);        /**< Display the current distance */
    LCD_displayString("cm");               /**< Display the unit 'cm' */
}

/**
 * @brief Displays a "STOP" danger message on the LCD.
 *
 * This function moves the cursor to the start of the LCD,
 * then displays a "STOP" message to warn the user of immediate danger.
 */
void LCD_dispDataDanger(void) {
    LCD_moveCursor(0, 0);                  /**< Move the cursor to the start */
    LCD_displayString("      STOP      "); /**< Display the "STOP" message */
}
