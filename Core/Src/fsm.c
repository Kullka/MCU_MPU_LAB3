/*
 * fsm.c
 *
 *  Created on: Nov 3, 2022
 *      Author: loing
 */

#include "fsm.h"
#include "main.h"
#include "software_timer.h"
#include "led.h"

#define TIME_RETURN_AUTO 10

int status;
int side = 0;

int value0 = 15;
int value1 = 12;

void fsm_automatic() {
	switch(status) {
	case STATE0:
		if (timerFlag==1) {
			turn_off_all_singleLed();
			GPIOA->ODR &= ~(0x11<<3);
			turn_off_all_7seg();
			if (side==0) {
				display_7SEG1(value0/10);
				display_7SEG2(value0%10);
				turn_on_7seg(0);
				turn_on_7seg(1);
				side = 1;
				value0--;
			}
			else {
				display_7SEG1(value1/10);
				display_7SEG2(value1%10);
				turn_on_7seg(2);
				turn_on_7seg(3);
				side = 0;
				value1--;
				if (value1==0) {
					status = STATE1;
					value1 = durationYellow;
				}
			}
			set_timer(DURATION);
		}
		break;
	case STATE1:
		if (timerFlag==1) {
			turn_off_all_singleLed();
			GPIOA->ODR &= ~(0x21<<3);
			turn_off_all_7seg();
			if (side==0) {
				display_7SEG1(value0/10);
				display_7SEG2(value0%10);
				turn_on_7seg(0);
				turn_on_7seg(1);
				side = 1;
				value0--;
			}
			else {
				display_7SEG1(value1/10);
				display_7SEG2(value1%10);
				turn_on_7seg(2);
				turn_on_7seg(3);
				side = 0;
				value1--;
				if (value1==0) {
					value1 = durationRed;
					value0 = durationGreen;
					status = STATE2;
				}
			}
			set_timer(DURATION);
		}
		break;
	case STATE2:
		if (timerFlag==1) {
			turn_off_all_singleLed();
			GPIOA->ODR &= ~(0x5<<4);
			turn_off_all_7seg();
			if (side==0) {
				display_7SEG1(value0/10);
				display_7SEG2(value0%10);
				turn_on_7seg(0);
				turn_on_7seg(1);
				side = 1;
				value0--;
				if (value0==0) {
					status = STATE3;
					value0 = durationYellow;
				}
			}
			else {
				display_7SEG1(value1/10);
				display_7SEG2(value1%10);
				turn_on_7seg(2);
				turn_on_7seg(3);
				side = 0;
				value1--;
			}
			set_timer(DURATION);
		}
		break;
	case STATE3:
		if (timerFlag==1) {
			turn_off_all_singleLed();
			GPIOA->ODR &= ~(0x3<<5);
			turn_off_all_7seg();
			if (side==0) {
				display_7SEG1(value0/10);
				display_7SEG2(value0%10);
				turn_on_7seg(0);
				turn_on_7seg(1);
				side = 1;
				value0--;
			}
			else {
				display_7SEG1(value1/10);
				display_7SEG2(value1%10);
				turn_on_7seg(2);
				turn_on_7seg(3);
				side = 0;
				value1--;
				if (value1==0) {
					value1 = durationGreen;
					value0 = durationRed;
					status = STATE0;
				}
			}
			set_timer(DURATION);
		}
		break;
	default:
		break;
	}
}

void fsm_manual() {
	if (timerFlag==1) {
		switch(status) {
		case MODE_RED:
			GPIOA->ODR &= ~(0x9<<3);
			display_7SEG1(durationRed/10);
			display_7SEG2(durationRed%10);
			break;
		case MODE_GREEN:
			GPIOA->ODR &= ~(0x9<<4);
			display_7SEG1(durationGreen/10);
			display_7SEG2(durationGreen%10);
			break;
		case MODE_YELLOW:
			GPIOA->ODR &= ~(0x9<<5);
			display_7SEG1(durationYellow/10);
			display_7SEG2(durationYellow%10);
			break;
		default:
			break;
		}
		set_timer(DURATION_MANUAL);
	}
}
