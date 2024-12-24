#include "pwm.h"

TIM_HandleTypeDef htim2;

void pwm_init(){
    __HAL_RCC_TIM2_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Mode=GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pin=GPIO_PIN_2|GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_3;  //channel:3,1,2,4
    GPIO_InitStruct.Speed=GPIO_SPEED_HIGH;

    HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);

    TIM_ClockConfigTypeDef sClockSourceConfig={0};
    TIM_MasterConfigTypeDef sMasterConfig={0};

    htim2.Instance=TIM2;
    htim2.Init.Prescaler=(uint32_t)(32-1);
    htim2.Init.Period=(uint32_t)(100-1);
    htim2.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
    htim2.Init.CounterMode=TIM_COUNTERMODE_UP;
    htim2.Init.AutoReloadPreload=TIM_AUTORELOAD_PRELOAD_DISABLE;
    HAL_TIM_Base_Init(&htim2);

    sClockSourceConfig.ClockSource=TIM_CLOCKSOURCE_INTERNAL;
    HAL_TIM_ConfigClockSource(&htim2,&sClockSourceConfig);

    sMasterConfig.MasterOutputTrigger=TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode=TIM_MASTERSLAVEMODE_DISABLE;
    HAL_TIMEx_MasterConfigSynchronization(&htim2,&sMasterConfig);

    HAL_TIM_Base_Start(&htim2);

    TIM_OC_InitTypeDef sConfigOc={0};
    sConfigOc.OCMode=TIM_OCMODE_PWM1;
    sConfigOc.Pulse=0;
    sConfigOc.OCPolarity=TIM_OCPOLARITY_HIGH;
    sConfigOc.OCFastMode=TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(&htim2,&sConfigOc,TIM_CHANNEL_1);

    HAL_TIM_PWM_ConfigChannel(&htim2,&sConfigOc,TIM_CHANNEL_2);

    HAL_TIM_PWM_ConfigChannel(&htim2,&sConfigOc,TIM_CHANNEL_3);

    HAL_TIM_PWM_ConfigChannel(&htim2,&sConfigOc,TIM_CHANNEL_4);

    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);

}


void set_PWM_duty(unsigned channel,uint32_t duty){
    __HAL_TIM_SetCompare(&htim2,channel,duty);

}