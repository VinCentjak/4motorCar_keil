#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "pwm.h"
#include "GPIO.h"

typedef enum{
	Motor_Forward=0,
	Motor_Backward,
	Motor_Left,
	Motor_Right
}Motor_dir;


void motor_init(void);

void set_motor_speed(uint32_t speed);

void set_motor_dir(Motor_dir direction);

#endif
