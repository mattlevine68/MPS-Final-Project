#include "stm32f769xx.h"
#include "init.h"

#include<stdint.h>
#include <stdlib.h>
#include <stdio.h>
//Member Functions
void GPIO_Setup();
void ov5647_Snapshot(); //Might not be void if needs to return value
void DCMI_Init();
//Member Varibales
GPIO_InitTypeDef GPIO_InitStruct;
UART_HandleTypeDef huart3;
DCMI_HandleTypeDef hdcmi;


int main(void){
	Sys_Init();
	HAL_Init();
	DCMI_Init();
	initUart(&huart3, 115200,  USART3);

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



void GPIO_Setup(){
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

void ov5647_Snapshot(){
	//Calls all the camera stuff
}

void DCMI_Init(){
	hdcmi.Instance =DCMI;
	hdcmi.Init.PCKPolarity = DCMI_PCKPOLARITY_RISING;
	hdcmi.Init.VSPolarity = DCMI_VSPOLARITY_LOW;
	hdcmi.Init.HSPolarity = DCMI_HSPOLARITY_LOW;
	hdcmi.Init.CaptureRate = DCMI_CR_ALL_FRAME;
	hdcmi.Init.ExtendedDataMode = DCMI_EXTEND_DATA_8B;
	hdcmi.Init.JPEGMode = DCMI_JPEG_ENABLE;
	hdcmi.Init.ByteSelectMode = DCMI_BSM_ALL;
	hdcmi.Init.ByteSelectStart = DCMI_OEBS_ODD;
	hdcmi.Init.LineSelectMode = DCMI_LSM_ALL;
	hdcmi.Init.LineSelectStart = DCMI_OELS_ODD;

	HAL_DCMI_Init(&hdcmi);
}

