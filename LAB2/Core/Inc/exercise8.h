/*
 * exercise5.h
 *
 *  Created on: Sep 25, 2024
 *      Author: Thanh Phu
 */

#ifndef INC_EXERCISE8_H_
#define INC_EXERCISE8_H_

#include "main.h"
int hour;
int minute;
int second;
extern const int MAX_LED;
extern int index_led;
extern int led_buffer[6];
extern int timer1_flag;
extern int timer2_flag;
extern int timer2_counter;
extern int timer1_counter;
extern int TIMER_CYCLE;
void setTimer1(int time);
void setTimer2(int time);
void timerRun();
void updateClockBuffer();
void update7SEG(int index);
void displayLEDMatrix(int index);



#endif /* INC_EXERCISE8_H_ */
