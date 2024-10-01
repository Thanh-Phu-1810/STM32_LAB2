/*
 * exercise9.h
 *
 *  Created on: Sep 30, 2024
 *      Author: Thanh Phu
 */

#ifndef INC_EXERCISE9_H_
#define INC_EXERCISE9_H_
#include "main.h"
extern int timer_flag;
extern int timer_counter;
extern void setTimer(int time);
extern void timerRun();
extern const int MAX_LED_MATRIX;
extern int index_led_matrix;
extern uint8_t matrix_buffer[8];
void updateLEDMatrix(int index);
void displayLEDMatrix(uint8_t index);
void resetAllLEDMatrix();


#endif /* INC_EXERCISE9_H_ */
