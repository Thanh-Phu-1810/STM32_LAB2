/*
 * exercise5.c
 *
 *  Created on: Sep 25, 2024
 *      Author: Thanh Phu
 */
#include <exercise8.h>
const int MAX_LED = 6;
int led_buffer[6];
int index_led = 0;
int timer1_flag = 1;
int timer1_counter = 0;
int timer2_flag = 1;
int timer2_counter = 0;
int TIMER_CYCLE = 10;
void setTimer1(int time)
{
	timer1_counter = time / TIMER_CYCLE;
	timer1_flag = 0;
}
void setTimer2(int time)
{
	timer2_counter = time / TIMER_CYCLE;
	timer2_flag = 0;
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

	if(timer2_counter > 0)
    {
		timer2_counter--;
		if(timer2_counter <= 0)
		{
			timer2_flag = 1;
		}
	}
}
void updateClockBuffer()
{
	if(hour < 10)
	{
		led_buffer[1] = hour;
		led_buffer[0] = 0;
	}

	if(hour >= 10 && hour <= 24)
	{
		led_buffer[0] = hour / 10;
		led_buffer[1] = hour % 10;
	}

	if(minute < 10)
	{
		led_buffer[2] = 0;
		led_buffer[3] = minute;
	}

	if(minute >= 10 && minute <= 60)
	{
		led_buffer[2] = minute / 10;
		led_buffer[3] = minute % 10;
	}
	if(second < 10)
	{
		led_buffer[4] = 0;
		led_buffer[5] = second;
	}
	if(second >= 10 && second <= 60)
	{
		led_buffer[4] = second / 10;
		led_buffer[5] = second % 10;
	}
}

void update7SEG(int index)
{
	switch(index)
		{
		    case 0:
		      if(index_led >= 0 && index_led <= 3)
		      {
		    	switch(led_buffer[index_led])
		    	{
		    	    case 0:
		    	    	 HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		    	    	 HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin, SET);
		    	    	 HAL_GPIO_WritePin(GPIOB, SEG_6_Pin, SET);
		    	    	 HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin , RESET);
		    	         break;
		    	    case 1:
		    	    	 HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		    	    	 HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin, SET);
		    	    	 HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, SET);
		    	    	 HAL_GPIO_WritePin(GPIOB, SEG_1_Pin | SEG_2_Pin, RESET);
		    	    	 break;
		    	    case 2:
		    	    	HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		    	        HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin, SET);
		    	    	HAL_GPIO_WritePin(GPIOB, SEG_2_Pin | SEG_5_Pin , SET);
		    	        HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin |SEG_3_Pin | SEG_4_Pin | SEG_6_Pin, RESET);
		    	        break;
		    	    case 3:
		    	    	HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		    	    	HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin, SET);
		    	        HAL_GPIO_WritePin(GPIOB, SEG_4_Pin | SEG_5_Pin , SET);
		    	    	HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin |SEG_2_Pin | SEG_3_Pin | SEG_6_Pin, RESET);
		    	    	break;
		    	    case 4:
		    	    	HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		    	    	HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin, SET);
		    	    	HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_3_Pin | SEG_4_Pin , SET);
						HAL_GPIO_WritePin(GPIOB, SEG_1_Pin |SEG_2_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
		    	    	break;
		    	    case 5:
		    	    	HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		    	    	HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin, SET);
		    	        HAL_GPIO_WritePin(GPIOB, SEG_1_Pin | SEG_4_Pin , SET);
		    	    	HAL_GPIO_WritePin(GPIOB, SEG_0_Pin |SEG_2_Pin | SEG_3_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
		    	        break;
		    	    case 6:
		    	    	HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		    	        HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin, SET);
		    	        HAL_GPIO_WritePin(GPIOB, SEG_1_Pin , SET);
		    	        HAL_GPIO_WritePin(GPIOB, SEG_0_Pin |SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
		    	        break;
		    	    case 7:
		    	    	HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		    	    	HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin, SET);
		    	    	HAL_GPIO_WritePin(GPIOB, SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, SET);
		    	        HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin, RESET);
		    	        break;
		    	    case 8:
		    	    	HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		    	    	HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin, SET);
		    	        HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin , RESET);
		    	        break;
		    	    case 9:
		    	    	HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		    	    	HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin, SET);
		    	    	HAL_GPIO_WritePin(GPIOB, SEG_4_Pin, SET);
		    	    	HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_5_Pin | SEG_6_Pin , RESET);
		    	    	break;
	                default:
	                	break;
		    	}
		    	index_led = 1;
		      }
		      break;
		    case 1:
		       if(index_led >= 0 && index_led <= 3)
		       {
		    	  switch(led_buffer[index_led])
		    	  {
		    	    case 0:
		    		    HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
		    		    HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin | EN3_Pin, SET);
		    		    HAL_GPIO_WritePin(GPIOB, SEG_6_Pin, SET);
		    		    HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin , RESET);
		    		    break;
		    		case 1:
		    			HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin | EN3_Pin, SET);
		    		    HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, SET);
		    		    HAL_GPIO_WritePin(GPIOB, SEG_1_Pin | SEG_2_Pin, RESET);
		    		    break;
		    		case 2:
						HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin | EN3_Pin, SET);
		    		    HAL_GPIO_WritePin(GPIOB, SEG_2_Pin | SEG_5_Pin , SET);
		    		    HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin |SEG_3_Pin | SEG_4_Pin | SEG_6_Pin, RESET);
		    		    break;
		    		case 3:
		    			HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
					    HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin | EN3_Pin, SET);
		    		    HAL_GPIO_WritePin(GPIOB, SEG_4_Pin | SEG_5_Pin , SET);
		    		    HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin |SEG_2_Pin | SEG_3_Pin | SEG_6_Pin, RESET);
		    		    break;
		    		case 4:
		    			HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin | EN3_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_3_Pin | SEG_4_Pin , SET);
						HAL_GPIO_WritePin(GPIOB, SEG_1_Pin |SEG_2_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
		    		    break;
		    		case 5:
		    			HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin | EN3_Pin, SET);
		    		    HAL_GPIO_WritePin(GPIOB, SEG_1_Pin | SEG_4_Pin , SET);
		    		    HAL_GPIO_WritePin(GPIOB, SEG_0_Pin |SEG_2_Pin | SEG_3_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
		    		    break;
					case 6:
						HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin | EN3_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_1_Pin , SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin |SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
		    		    break;
					case 7:
						HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin | EN3_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin, RESET);
						break;
					case 8:
						HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin | EN3_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin , RESET);
						break;
					case 9:
						HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin | EN3_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_4_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_5_Pin | SEG_6_Pin , RESET);
						break;
					default:
						break;
				}
		    	  index_led = 2;
			  }
		       break;
		    case 2:
			   if(index_led >= 0 && index_led <= 3)
			   {
				  switch(led_buffer[index_led])
				  {
					case 0:
						HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN3_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_6_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin , RESET);
						break;
					case 1:
						HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN3_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_1_Pin | SEG_2_Pin, RESET);
						break;
					case 2:
						HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN3_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_2_Pin | SEG_5_Pin , SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin |SEG_3_Pin | SEG_4_Pin | SEG_6_Pin, RESET);
						break;
					case 3:
						HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN3_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_4_Pin | SEG_5_Pin , SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin |SEG_2_Pin | SEG_3_Pin | SEG_6_Pin, RESET);
						break;
					case 4:
						HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN3_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_3_Pin | SEG_4_Pin , SET);
						HAL_GPIO_WritePin(GPIOB, SEG_1_Pin |SEG_2_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
						break;
					case 5:
						HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN3_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_1_Pin | SEG_4_Pin , SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin |SEG_2_Pin | SEG_3_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
						break;
					case 6:
						HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN3_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_1_Pin , SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin |SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
						break;
					case 7:
						HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN3_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin, RESET);
						break;
					case 8:
						HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN3_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin , RESET);
						break;
					case 9:
						HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN3_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_4_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_5_Pin | SEG_6_Pin , RESET);
						break;
					default:
						break;
				}
				  index_led = 3;
			  }
			   break;
		    case 3:
		    	if(index_led >= 0 && index_led <= 3)
			   {
				  switch(led_buffer[index_led])
				  {
					case 0:
						HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_6_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin , RESET);
						break;
					case 1:
						HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_1_Pin | SEG_2_Pin, RESET);
						break;
					case 2:
						HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_2_Pin | SEG_5_Pin , SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin |SEG_3_Pin | SEG_4_Pin | SEG_6_Pin, RESET);
						break;
					case 3:
						HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_4_Pin | SEG_5_Pin , SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin |SEG_2_Pin | SEG_3_Pin | SEG_6_Pin, RESET);
						break;
					case 4:
						HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_3_Pin | SEG_4_Pin , SET);
						HAL_GPIO_WritePin(GPIOB, SEG_1_Pin |SEG_2_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
						break;
					case 5:
						HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_1_Pin | SEG_4_Pin , SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin |SEG_2_Pin | SEG_3_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
						break;
					case 6:
						HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_1_Pin , SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin |SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, RESET);
						break;
					case 7:
						HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin, RESET);
						break;
					case 8:
						HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin , RESET);
						break;
					case 9:
						HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
						HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_4_Pin, SET);
						HAL_GPIO_WritePin(GPIOB, SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_5_Pin | SEG_6_Pin , RESET);
						break;
					default:
						break;
				}
				  index_led = 0;
			  }
		    default:
				break;
	       }
}

