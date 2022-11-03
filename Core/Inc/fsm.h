/*
 * fsm_automatic.h
 *
 *  Created on: Nov 3, 2022
 *      Author: loing
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

extern int status;
extern int side;
extern int value0;
extern int value1;

enum Auto_led {STATE0, STATE1, STATE2, STATE3};
enum Mode {MODE_RED = 5, MODE_GREEN, MODE_YELLOW};

void fsm_automatic();
void fsm_manual();

#endif /* INC_FSM_H_ */
