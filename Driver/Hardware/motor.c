#include "motor.h"


void motor_init(void){
    motor_GPIO_init();

    pwm_init();

}


void set_motor_speed(uint32_t speed){
    set_PWM_duty(TIM_CHANNEL_1,speed);
    set_PWM_duty(TIM_CHANNEL_2,speed);
    set_PWM_duty(TIM_CHANNEL_3,speed);
    set_PWM_duty(TIM_CHANNEL_4,speed);

}   

void set_motor_dir(Motor_dir direction){
    switch (direction)
    {
    case Motor_Forward:{
					//右一，右二向前动
                    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
					//左一，左二向前动
                    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
					break;
				}
				case Motor_Backward:{
					//右一，右二向后动
                    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
					//左一，左二向后动
                    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
					break;
				}
				case Motor_Right:{
					//右一，右二向后动
                    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
					//左一，左二向前动
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
					break;
				}
				case Motor_Left:{
					//右一，右二向前动8f
					HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);
					//左一，左二向后动
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
                    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
					break;
				}

}
}