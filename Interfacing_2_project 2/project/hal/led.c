#include"../mcal/gpio.h"
#include"../common/std_types.h"
#include"led.h"
uint8 LED_pins[] = { GPIO_PC2, GPIO_PC1, GPIO_PC0 };
void LED_init() {
	for (int i; i < sizeof(LED_pins); i++) {
		GPIO_ARR_setPinDirection(LED_pins[i], PIN_OUTPUT);
	}
}

void LED_on(uint8 a_ledid) {
#ifdef LED_POSTIVE_LOGIC
	GPIO_ARR_setPinState(LED_pins[a_ledid], LOGIC_HIGH);
#else
	GPIO_ARR_setPinState(LED_pins[a_ledid],LOGIC_LOW);
#endif

}

void LED_off(uint8 a_ledid) {
#ifdef LED_POSTIVE_LOGIC
	GPIO_ARR_setPinState(LED_pins[a_ledid], LOGIC_LOW);
#else
	GPIO_ARR_setPinState(LED_pins[a_ledid],LOGIC_HIGH);
#endif

}

