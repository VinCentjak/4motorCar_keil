
#include "uart.h"



uint8_t RxBuff[RxBuffSize];

void uart1_init(){

    huatr1.Instance=USART1;
    huatr1.Init.BaudRate=9600;
    huatr1.Init.HwFlowCtl=UART_HWCONTROL_NONE;
    huatr1.Init.Mode=UART_MODE_TX_RX;
    huatr1.Init.OverSampling=UART_OVERSAMPLING_16;
    huatr1.Init.Parity=UART_PARITY_NONE;
    huatr1.Init.StopBits=UART_STOPBITS_1;
    huatr1.Init.WordLength=UART_WORDLENGTH_8B;

    HAL_UART_Init(&huatr1);
    

    JDYBL_GPIO_init();
 
    HAL_UART_Receive_IT(&huatr1,RxBuff,RxBuffSize);

    HAL_NVIC_EnableIRQ(USART1_IRQn);

    HAL_NVIC_SetPriority(USART1_IRQn,3,3);

    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_2);

    __HAL_RCC_USART1_CLK_ENABLE();

}   

void USART1_IRQHandler(void){

    HAL_UART_IRQHandler(&huatr1);
    while(HAL_UART_GetState(&huatr1)!=HAL_UART_STATE_READY);
    while(HAL_UART_Receive_IT(&huatr1,RxBuff,RxBuffSize)!=HAL_OK);

} 

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
    if(huart->Instance==USART1){
        

    }

}