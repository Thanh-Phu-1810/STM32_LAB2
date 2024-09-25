/*
 * exercise3.c
 *
 *  Created on: Sep 25, 2024
 *      Author: Thanh Phu
 */
#include <exercise4.h>

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {8, 8, 8, 8};
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




