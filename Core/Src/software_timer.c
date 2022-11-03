/*
 * software_timer.c
 *
 *  Created on: Nov 3, 2022
 *      Author: loing
 */

#include "software_timer.h"
#include "main.h"

int timerCounter;
int timerFlag;
int durationRed = 15;
int durationGreen = 12;
int durationYellow = 3;

void set_timer(int duration){
	timerCounter = duration/PERIOD;
	timerFlag = 0;
}

void timer_run() {
	if (timerCounter>0) {
		timerCounter--;
		if (timerCounter==0) {
			timerFlag = 1;
		}
	}
}

void set_led_duration(int mode){
	switch (mode) {
	case 1:
		durationRed = durationRed + 1;
		durationRed = durationRed % 100;
		break;
	case 2:
		durationYellow = durationYellow + 1;
		durationYellow = durationYellow % 100;
		break;
	case 3:
		durationGreen = durationGreen + 1;
		durationGreen = durationGreen % 100;
		break;
	}
}
