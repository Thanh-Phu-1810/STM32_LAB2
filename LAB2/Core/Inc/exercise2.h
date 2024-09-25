/*
 * exercise2.h
 *
 *  Created on: Sep 24, 2024
 *      Author: Thanh Phu
 */

#ifndef INC_EXERCISE2_H_
#define INC_EXERCISE2_H_

extern int timer1_flag;
extern int timer2_flag;

extern int timer1_counter;
extern int timer2_counter;

void setTimer1(int time);
void setTimer2(int time);

void timerRun();

#endif /* INC_EXERCISE2_H_ */
