/*
 * exercise9.c
 *
 *  Created on: Sep 30, 2024
 *      Author: Thanh Phu
 */
#include "exercise9.h"

//int index_led_matrix = 0;
int timer_flag = 0;
int timer_counter = 0;
void setTimer(int time)
{
	timer_counter = time;
	timer_flag = 0;
}
void timerRun()
{
	if(timer_counter > 0)
	{
		timer_counter--;
		if(timer_counter <= 0)
		{
			timer_flag = 1;
		}
	}
}
uint8_t matrix_buffer[8] = {0x18, 0x3C, 0x66, 0x66, 0x7E, 0x7E, 0x66, 0x66};
void updateLEDMatrix(int index)
{
   resetAllLEDMatrix();
   switch(index)
   {
       case 0:
    	   HAL_GPIO_WritePin(GPIOB, ROW0_Pin, RESET);
    	   displayLEDMatrix(matrix_buffer[index]);
    	   break;
       case 1:
    	   HAL_GPIO_WritePin(GPIOB, ROW1_Pin, RESET);
		   displayLEDMatrix(matrix_buffer[index]);
		   break;
       case 2:
    	   HAL_GPIO_WritePin(GPIOB, ROW2_Pin, RESET);
    	   displayLEDMatrix(matrix_buffer[index]);
    	   break;
       case 3:
    	   HAL_GPIO_WritePin(GPIOB, ROW3_Pin, RESET);
		   displayLEDMatrix(matrix_buffer[index]);
		   break;
       case 4:
    	   HAL_GPIO_WritePin(GPIOB, ROW4_Pin, RESET);
		   displayLEDMatrix(matrix_buffer[index]);
		   break;
       case 5:
    	   HAL_GPIO_WritePin(GPIOB, ROW5_Pin, RESET);
		   displayLEDMatrix(matrix_buffer[index]);
		   break;
       case 6:
    	   HAL_GPIO_WritePin(GPIOB, ROW6_Pin, RESET);
		   displayLEDMatrix(matrix_buffer[index]);
		   break;
       case 7:
    	   HAL_GPIO_WritePin(GPIOB, ROW7_Pin, RESET);
		   displayLEDMatrix(matrix_buffer[index]);
	       break;
       default:
    	   break;
   }
}
void resetAllLEDMatrix()
{
	HAL_GPIO_WritePin(GPIOB, ROW2_Pin | ROW3_Pin | ROW4_Pin | ROW5_Pin | ROW6_Pin | ROW7_Pin | ROW0_Pin | ROW1_Pin, SET);
}
void displayLEDMatrix(uint8_t index)
{
	switch(index)
	{
	    case 0x18:
	    	HAL_GPIO_WritePin(GPIOA, ENM0_Pin | ENM1_Pin | ENM2_Pin | ENM5_Pin | ENM6_Pin | ENM7_Pin , SET);
	    	HAL_GPIO_WritePin(GPIOA, ENM3_Pin | ENM4_Pin , RESET);
            break;
	    case 0x3C:
	    	HAL_GPIO_WritePin(GPIOA, ENM0_Pin | ENM1_Pin | ENM6_Pin | ENM7_Pin , SET);
			HAL_GPIO_WritePin(GPIOA, ENM2_Pin | ENM3_Pin | ENM4_Pin | ENM5_Pin , RESET);
			break;
	    case 0x66:
	    	HAL_GPIO_WritePin(GPIOA, ENM0_Pin | ENM3_Pin | ENM4_Pin | ENM7_Pin , SET);
			HAL_GPIO_WritePin(GPIOA, ENM1_Pin | ENM2_Pin | ENM5_Pin | ENM6_Pin , RESET);
			break;
	    case 0x7E:
	    	HAL_GPIO_WritePin(GPIOA, ENM0_Pin | ENM7_Pin , SET);
	    	HAL_GPIO_WritePin(GPIOA, ENM1_Pin | ENM2_Pin | ENM3_Pin | ENM4_Pin | ENM5_Pin | ENM6_Pin , RESET);
	    	break;
	    default:
	    	break;
	}
}


