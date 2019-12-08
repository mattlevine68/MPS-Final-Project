 /*
 * stm327xx_hal_msp.c
 *
 *  Created on: Dec 8, 2019
 *      Author: levinm7
 */

#include "stm32f769xx.h"
#include "stm32f7xx_hal.h"

void HAL_MspInit(void){
	  __HAL_RCC_PWR_CLK_ENABLE();
	  __HAL_RCC_SYSCFG_CLK_ENABLE();
}

void HAL_DCMI_MspInit(DCMI_HandleTypeDef* hdcmi){
	if(hdcmi->Instance==DCMI){
		__HAL_RCC_DCMI_CLK_ENABLE();
		//Configure GPIO
	    __HAL_RCC_GPIOE_CLK_ENABLE();
	    __HAL_RCC_GPIOA_CLK_ENABLE();
	    __HAL_RCC_GPIOC_CLK_ENABLE();
	    __HAL_RCC_GPIOD_CLK_ENABLE();
	    __HAL_RCC_GPIOG_CLK_ENABLE();

	    //Find Pins for Config on Camera
	}
}

void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c){
	if(hi2c->Instance==I2C1){
		__HAL_RCC_I2C1_CLK_ENABLE();
	}
}
