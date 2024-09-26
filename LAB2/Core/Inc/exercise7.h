/*
 * exercise5.h
 *
 *  Created on: Sep 25, 2024
 *      Author: Thanh Phu
 */

#ifndef INC_EXERCISE7_H_
#define INC_EXERCISE7_H_

#include "main.h"
int hour;
int minute;
int second;
extern const int MAX_LED;
extern int index_led;
extern int led_buffer[6];
extern int timer_flag;
extern int timer_counter;
extern int TIMER_CYCLE;
void setTimer(int time);
void timerRun();
void updateClockBuffer();
void update7SEG(int index);



#endif /* INC_EXERCISE7_H_ */
