#include "SYSTEM/sys/sys.h"
#include "SYSTEM/usart/usart.h"
#include "SYSTEM/delay/delay.h"
#include "FreeRTOS.h"
#include "Task.h"
#include "motor.h"
#include "oled.h"

#define LED_CLK()       __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED_GPIO        GPIOB
#define LED_PIN         GPIO_PIN_5

void vTestTask(void* parameter){
  while(1){
    
  }

}

void led_init(void);                       /* LED初始化函数声明 */

int main(void)
{
    HAL_Init();                         /* 初始化HAL库 */
    Stm32_Clock_Init(RCC_PLL_MUL9); /* 设置时钟, 72Mhz */
    led_init();                         /* LED初始化 */
    
    OLED_GPIO_Init();

    OLED_Init();

    OLED_ALL_Clear();

    OLED_Draw_16_8_ASCII(2,2,32);

    //uart_init(115200);
    //printf("running...\r\n");
    //motor_init();

    //set_motor_speed(30);

    //set_motor_dir(Motor_Forward);

    BaseType_t xReturn;
    TaskHandle_t  TestTask_Handle=NULL;
    //xReturn=xTaskCreate(vTestTask, "vTestTask", configMINIMAL_STACK_SIZE, NULL, 2, &TestTask_Handle);

    /*if(xReturn!=pdPASS){
      printf("TaskCreateFailed\n");
    }*/

    //vTaskStartScheduler();                    /* 启动任务调度 */
    
    while(1)
    { 
        HAL_GPIO_WritePin(LED_GPIO,LED_PIN,GPIO_PIN_SET);
        delay_ms(500);
        HAL_GPIO_WritePin(LED_GPIO,LED_PIN,GPIO_PIN_RESET);
				delay_ms(500);
    }
}

/**
 * @brief       初始化LED相关IO口, 并使能时钟
 * @param       无
 * @retval      无
 */
void led_init(void)
{
    GPIO_InitTypeDef gpio_initstruct;
    LED_CLK();                                             /* IO口时钟使能 */

    gpio_initstruct.Pin = LED_PIN;                         /* LED0引脚 */
    gpio_initstruct.Mode = GPIO_MODE_OUTPUT_PP;            /* 推挽输出 */
    gpio_initstruct.Pull = GPIO_PULLUP;                    /* 上拉 */
    gpio_initstruct.Speed = GPIO_SPEED_FREQ_HIGH;          /* 高速 */
    HAL_GPIO_Init(LED_GPIO, &gpio_initstruct);             /* 初始化LED0引脚 */
}
