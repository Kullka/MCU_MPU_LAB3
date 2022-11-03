/*
 * led.h
 *
 *  Created on: Nov 3, 2022
 *      Author: loing
 */

#ifndef INC_LED_H_
#define INC_LED_H_

void turn_off_all_singleLed();
void reset_7SEG1();
void reset_7SEG2();
void display_7SEG1(int number);
void display_7SEG2(int number);
void turn_off_all_7seg();
void turn_on_7seg(int index);

#endif /* INC_LED_H_ */
