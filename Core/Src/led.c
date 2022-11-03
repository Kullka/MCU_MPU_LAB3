/*
 * led.c
 *
 *  Created on: Nov 3, 2022
 *      Author: loing
 */


#include "led.h"
#include "main.h"

void turn_off_all_singleLed() {
	GPIOA->ODR |= (0x3F<<3);
}

void reset_7SEG1() {
	GPIOB->ODR |= 0x7F;
}

void reset_7SEG2() {
	GPIOB->ODR |= (0x7F<<7);
}

void display_7SEG1(int number) {
	reset_7SEG1();
		switch(number) {
			case 0:
				GPIOB->ODR &= ~0x7E; // 0 = 0b1111110, but in order to turn on we need to get inverse this binary number
				break ;
			case 1:
				GPIOB->ODR &= ~0x30; // similarly
				break ;
			case 2:
				GPIOB->ODR &= ~0x5B; // similarly
				break ;
			case 3:
				GPIOB->ODR &= ~0x4F; // similarly
				break ;
			case 4:
				GPIOB->ODR &= ~0x66; // similarly
				break ;
			case 5:
				GPIOB->ODR &= ~0x6D; // similarly
				break ;
			case 6:
				GPIOB->ODR &= ~0x7D; // similarly
				break ;
			case 7:
				GPIOB->ODR &= ~0x07; // similarly
				break ;
			case 8:
				GPIOB->ODR &= ~0x7F; // similarly
				break ;
			case 9:
				GPIOB->ODR &= ~0x67; // similarly
				break ;
			default:
				GPIOB->ODR &= ~0x77; // similarly
				break ;
		}
}

void display_7SEG2(int number) {
	reset_7SEG2();
		switch(number) {
			case 0:
				GPIOB->ODR &= ~(0x3F<<7); // 0 = 0b1111110, but in order to turn on we need to get inverse this binary number
				break ;
			case 1:
				GPIOB->ODR &= ~(0x06<<7); // similarly
				break ;
			case 2:
				GPIOB->ODR &= ~(0x5B<<7); // similarly
				break ;
			case 3:
				GPIOB->ODR &= ~(0x4F<<7); // similarly
				break ;
			case 4:
				GPIOB->ODR &= ~(0x66<<7); // similarly
				break ;
			case 5:
				GPIOB->ODR &= ~(0x6D<<7); // similarly
				break ;
			case 6:
				GPIOB->ODR &= ~(0x7D<<7); // similarly
				break ;
			case 7:
				GPIOB->ODR &= ~(0x07<<7); // similarly
				break ;
			case 8:
				GPIOB->ODR &= ~(0x7F<<7); // similarly
				break ;
			case 9:
				GPIOB->ODR &= ~(0x67<<7); // similarly
				break ;
			default:
				GPIOB->ODR &= ~(0x77<<7); // similarly
				break ;
		}
}

void turn_off_all_7seg() {
	GPIOA->ODR |= (0xF<<9);
}

void turn_on_7seg(int index){
	int shift = index+9;
	GPIOA->ODR &= ~(1<<shift);
}
