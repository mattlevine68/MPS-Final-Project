#include "stm32f769xx.h"
#include "init.h"

#include<stdint.h>
#include <stdlib.h>
#include <stdio.h>
//Member Functions
void GPIO_Setup(void);
void ov5647_Snapshot(void); //Might not be void if needs to return value
void DCMI_Init(void);
void I2C1_Init(void)
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



void GPIO_Setup(void){
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

void ov5647_Snapshot(void){
	//Calls all the camera stuff
}

void DCMI_Init(void){
	//need to add msp init
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

void I2C1_Init(void){
	//need to add msp init
	hi2c1.Instance = I2C1;
	hi2c1.Init.Timing = 0x1060669A;
	hi2c1.Init.OwnAddress1 = 0;
	hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c1.Init.OwnAddress2 = 0;
	hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
}
