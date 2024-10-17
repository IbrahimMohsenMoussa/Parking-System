/*
 * led.h
 *
 *  Created on: 7 Oct 2024
 *      Author: MSI
 */

#ifndef LED_H_
#define LED_H_

typedef enum {
	LED_BLUE_1, LED_GREEN_2, LED_RED_3
} LED_ID;
#define LED_POSTIVE_LOGIC

#ifndef LED_POSTIVE_LOGIC
#define LED_NEGATIVE_LOGIC
#endif
void LED_init();
void LED_off(uint8);
void LED_on(uint8);
#endif /* LED_H_ */
