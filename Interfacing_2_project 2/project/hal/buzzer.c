#include"../mcal/gpio.h"
#include"../common/std_types.h"
#include"buzzer.h"

void Buzzer_init() {

		GPIO_ARR_setPinDirection(BUZZER_PIN, PIN_OUTPUT);

}

void Buzzer_on() {
#ifdef BUZZER_POSTIVE_LOGIC
	GPIO_ARR_setPinState(BUZZER_PIN, LOGIC_HIGH);
#else
	GPIO_ARR_setPinState(BUZZER_PIN,LOGIC_LOW);
#endif

}

void Buzzer_off() {
#ifdef BUZZER_POSTIVE_LOGIC
	GPIO_ARR_setPinState(BUZZER_PIN, LOGIC_LOW);
#else
	GPIO_ARR_setPinState(BUZZER_PIN,LOGIC_HIGH);
#endif

}
