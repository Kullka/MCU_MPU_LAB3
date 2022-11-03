/*
 * software_timer.h
 *
 *  Created on: Nov 3, 2022
 *      Author: loing
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define PERIOD 10
#define DURATION 500
#define DURATION_MANUAL 100

extern int timerCounter;
extern int timerFlag;
extern int durationRed;
extern int durationGreen;
extern int durationYellow;

void set_timer(int duration);
void timer_run();
void set_led_duration(int mode);

#endif /* INC_SOFTWARE_TIMER_H_ */
