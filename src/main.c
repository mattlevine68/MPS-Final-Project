#include "stm32f769xx.h"
#include "init.h"

#include<stdint.h>
#include <stdlib.h>
#include <stdio.h>

void GPIO_Setup(void);
void ov5647_Snapshot(void); //Might not be void if needs to return value
GPIO_InitTypeDef GPIO_InitStruct;
int main(void){
	Sys_Init();

	// Add Handles for DCMI, DCMI DMA, I2C, Uart, Uart DMA, DMA2

	//Intialize Everything

	//Read GPIO Pin if variable = 1 take the picture and transmit

	//PIR Sensor Part

	GPIO_Setup();
	while(1){
		GPIO_PinState PIR = HAL_GPIO_ReadPin(GPIOJ, GPIO_PIN_0); //Constant checking
		if(PIR == 1) ov5647_Snapshot();
	}

}



GPIO_Setup(){
	//Input GPIO for values
	__HAL_RCC_GPIOJ_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

	//J0
	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOJ, &GPIO_InitStruct);

}

ov5647_Snapshot(){
	//Calls all the camera stuff
}
