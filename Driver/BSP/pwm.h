#ifndef __PWM_H__
#define __PWM_H__

#include "stm32f1xx_hal.h"

void pwm_init(void);

void set_PWM_duty(unsigned channel,uint32_t duty);



#endif
