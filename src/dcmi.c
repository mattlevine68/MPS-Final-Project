#include "dcmi.h"

// Initialize Hardware Resources
// Peripheral's clock enable
// Peripheral's GPIO Configuration
void HAL_DCMI_MspInit(DCMI_HandleTypeDef *hdcmi){
	GPIO_InitTypeDef  GPIO_InitStruct;
  if(hdcmi->Instance==DCMI){
    __HAL_RCC_DCMI_CLK_ENABLE();
  }
}
