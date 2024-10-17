/*
 * buzzer.h
 *
 *  Created on: 8 Oct 2024
 *      Author: MSI
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#define BUZZER_PIN GPIO_PC5
#define BUZZER_POSTIVE_LOGIC

#ifndef BUZZER_POSTIVE_LOGIC
#define BUZZER_NEGATIVE_LOGIC
#endif
void Buzzer_init();
void Buzzer_off();
void Buzzer_on();

#endif /* BUZZER_H_ */
