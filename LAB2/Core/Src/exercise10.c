/*
 * exercise9.c
 *
 *  Created on: Sep 30, 2024
 *      Author: Thanh Phu
 */
#include <exercise10.h>

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
uint16_t ENM_Pin[8] = {ENM0_Pin, ENM1_Pin, ENM2_Pin, ENM3_Pin, ENM4_Pin, ENM5_Pin, ENM6_Pin, ENM7_Pin}; //unit16_t lưu các số nguyên không dấu 16 bit (các số có thể lưu từ 0 -> 2^16)
void updateLEDMatrix(int index)
{
   resetAllLEDMatrix();
   switch(index)
   {
       case 0:
    	   HAL_GPIO_WritePin(GPIOB, ROW0_Pin, RESET);
    	   matrix_buffer[index] = (matrix_buffer[index] << 1) | (matrix_buffer[index] >> 7); // dịch sang trái tạo hiểu ứng ảnh animation từ phải sang trái
    	   displayLEDMatrix(matrix_buffer[index]);
    	   break;
       case 1:
    	   HAL_GPIO_WritePin(GPIOB, ROW1_Pin, RESET);
    	   matrix_buffer[index] = (matrix_buffer[index] << 1) | (matrix_buffer[index] >> 7);
		   displayLEDMatrix(matrix_buffer[index]);
		   break;
       case 2:
    	   HAL_GPIO_WritePin(GPIOB, ROW2_Pin, RESET);
    	   matrix_buffer[index] = (matrix_buffer[index] << 1) | (matrix_buffer[index] >> 7);
    	   displayLEDMatrix(matrix_buffer[index]);
    	   break;
       case 3:
    	   HAL_GPIO_WritePin(GPIOB, ROW3_Pin, RESET);
    	   matrix_buffer[index] = (matrix_buffer[index] << 1) | (matrix_buffer[index] >> 7);
		   displayLEDMatrix(matrix_buffer[index]);
		   break;
       case 4:
    	   HAL_GPIO_WritePin(GPIOB, ROW4_Pin, RESET);
    	   matrix_buffer[index] = (matrix_buffer[index] << 1) | (matrix_buffer[index] >> 7);
		   displayLEDMatrix(matrix_buffer[index]);
		   break;
       case 5:
    	   HAL_GPIO_WritePin(GPIOB, ROW5_Pin, RESET);
    	   matrix_buffer[index] = (matrix_buffer[index] << 1) | (matrix_buffer[index] >> 7);
		   displayLEDMatrix(matrix_buffer[index]);
		   break;
       case 6:
    	   HAL_GPIO_WritePin(GPIOB, ROW6_Pin, RESET);
    	   matrix_buffer[index] = (matrix_buffer[index] << 1) | (matrix_buffer[index] >> 7);
		   displayLEDMatrix(matrix_buffer[index]);
		   break;
       case 7:
    	   HAL_GPIO_WritePin(GPIOB, ROW7_Pin, RESET);
    	   matrix_buffer[index] = (matrix_buffer[index] << 1) | (matrix_buffer[index] >> 7);
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

    for(int col = 0; col < 8; col++)  //chạy col để kiểm tra bit 1 trong index và bật COL đúng vị trí đó
    {
    	if(index & (1 << (7 - col)))  //(1 << (7 - col)): chèn bit 1 vào đúng vị trí phụ thuộc vào biến col trong dãy 7 bit
    	{
    		HAL_GPIO_WritePin(GPIOA, ENM_Pin[col], RESET); //Bật COL

    	}
    	if(!(index & (1 << (7 - col))))
    	{
    		HAL_GPIO_WritePin(GPIOA, ENM_Pin[col], SET);  // Tắt COL
    	}
    }
}


