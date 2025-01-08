#include "TIM.h"

TIM_HandleTypeDef htim3;

void TIM3_Init(){
    TIM_ClockConfigTypeDef sClockConfig={0};
    TIM_MasterConfigTypeDef sMasterConfig={0};
    __HAL_RCC_TIM3_CLK_ENABLE();

    htim3.Instance=TIM3;
    htim3.Init.AutoReloadPreload=TIM_AUTORELOAD_PRELOAD_DISABLE;
    htim3.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
    htim3.Init.CounterMode=TIM_COUNTERMODE_UP;
    htim3.Init.Period=(10000-1);
    htim3.Init.Prescaler=(32-1);
    
    HAL_TIM_Base_Init(&htim3);

    sClockConfig.ClockSource=TIM_CLOCKSOURCE_INTERNAL;

    HAL_TIM_ConfigClockSource(&htim3,&sClockConfig);

    sMasterConfig.MasterOutputTrigger=TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode=TIM_MASTERSLAVEMODE_DISABLE;

    HAL_TIMEx_MasterConfigSynchronization(&htim3,&sMasterConfig);

    HAL_TIM_Base_Start(&htim3);

   // HAL_NVIC_SetPriority(TIM3_IRQn,3,3);
    //HAL_NVIC_EnableIRQ(TIM3_IRQn);

}


