#include "GPIO.h"

void motor_GPIO_init(void){
    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Mode=GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pin=GPIO_PIN_4|GPIO_PIN_5;
    GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);

    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_InitStruct.Mode=GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pin=GPIO_PIN_1|GPIO_PIN_0;
    GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);

}


void JDYBL_GPIO_init(void){
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_AFIO_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Mode=GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pin=GPIO_PIN_9;
    GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);

    GPIO_InitStruct.Mode=GPIO_MODE_AF_INPUT;
    GPIO_InitStruct.Pin=GPIO_PIN_10;
    GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);
}

