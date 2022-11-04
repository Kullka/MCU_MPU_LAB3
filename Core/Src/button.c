/*
 * button.c
 *
 *  Created on: Nov 3, 2022
 *      Author: loing
 */


#include "software_timer.h"
#include "main.h"
#include "button.h"
#include "led.h"
#include "fsm.h"

int button[NO_BUTTONS] = {0x1<<13, 0x1<<14, 0x1<<15};
int keyReg0[NO_BUTTONS];
int keyReg1[NO_BUTTONS];
int keyReg2[NO_BUTTONS];
int keyReg3[NO_BUTTONS];
int timerForKeyPress = TIME_CHANGE_TO_AUTO;

void key1Process() {
	turn_off_all_singleLed();
	turn_off_all_7seg();
	turn_on_7seg(2);
	turn_on_7seg(3);
	switch(status) {
	case MODE_RED:
		GPIOA->ODR &= ~(0x9<<5);
		status = MODE_YELLOW;
		set_timer(DURATION_MANUAL);
		break;
	case MODE_YELLOW:
		GPIOA->ODR &= ~(0x9<<4);
		status = MODE_GREEN;
		set_timer(DURATION_MANUAL);
		break;
	case MODE_GREEN:
		status = STATE0;
		value0 = durationRed;
		value1 = durationGreen;
		side = 0;
		set_timer(DURATION);
		break;
	default:
		GPIOA->ODR &= ~(0x9<<3);
		status = MODE_RED;
		set_timer(DURATION_MANUAL);
		break;
	}

}

void key2Process() {
	switch(status) {
	case MODE_RED:
		set_led_duration(1);
		break;
	case MODE_YELLOW:
		set_led_duration(2);
		break;
	case MODE_GREEN:
		set_led_duration(3);
		break;
	default:
		break;
	}
}

void key3Process() {
	if (status == MODE_RED || status == MODE_GREEN || status == MODE_YELLOW) {
		status = STATE0;
		value0 = durationRed;
		value1 = durationGreen;
		side = 0;
	}
	else ;
}

void getKeyInput() {
	for (int i=0; i<NO_BUTTONS; i++) {
		keyReg0[i] = keyReg1[i];
		keyReg1[i] = keyReg2[i];
//		switch (i) {
//		case 0:
//			keyReg2[i] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
//			break;
//		case 1:
//			keyReg2[i] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
//			break;
//		case 2:
//			keyReg2[i] = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);
//		default:
//			break;
//		}
		keyReg2[i] = HAL_GPIO_ReadPin(GPIOA, button[i]);
		if ( (keyReg0[i]==keyReg1[i]) && (keyReg1[i]==keyReg2[i]) ) {
			if (keyReg3[i]!=keyReg2[i]) {
				keyReg3[i] = keyReg2[i];
				if (keyReg2[i] == PRESSED_STATE) {
					switch(i) {
					case 0:
						key1Process();
						break;
					case 1:
						key2Process();
						break;
					case 2:
						key3Process();
						break;
					default:
						break;
					}
					timerForKeyPress = TIME_CHANGE_TO_AUTO;
				}
			}
			else {
				timerForKeyPress--;
				if (timerForKeyPress==0) {
					if (keyReg2[i]==PRESSED_STATE) {
						switch(i) {
						case 0:
							key1Process();
							break;
						case 1:
							key2Process();
							break;
						case 2:
							key3Process();
							break;
						default:
							break;
						}
						timerForKeyPress = TIME_INCREASE_VALUE;
					}
				}
			}
		}
	}
}
