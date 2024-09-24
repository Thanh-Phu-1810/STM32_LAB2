/*
 * exercise1.c
 *
 *  Created on: Sep 24, 2024
 *      Author: Thanh Phu
 */
#include "exercise1.h"
int timer1_flag = 0;
int timer1_counter = 0;
void setTimer1(int time)
{
	timer1_counter = time;
	timer1_flag = 0;
}
void timerRun()
{
	if(timer1_counter > 0)
	{
		timer1_counter--;
		if(timer1_counter <= 0)
		{
			timer1_flag = 1;
		}
	}
}

