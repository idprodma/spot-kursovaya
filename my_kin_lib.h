#ifndef MY_KIN_LIB_H
#define MY_KIN_LIB_H

#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

void stand_stationary(Adafruit_PWMServoDriver pwm);

void stand_up_from_down(Adafruit_PWMServoDriver pwm);

void sit_stationary(Adafruit_PWMServoDriver pwm);

void sit_down_from_stationary(Adafruit_PWMServoDriver pwm);

void tilt_right(Adafruit_PWMServoDriver pwm);

void tilt_right_stationary(Adafruit_PWMServoDriver pwm);

void sit_stationary_from_tilt_right(Adafruit_PWMServoDriver pwm);

void tilt_left(Adafruit_PWMServoDriver pwm);

void tilt_left_stationary(Adafruit_PWMServoDriver pwm);

void sit_stationary_from_tilt_left(Adafruit_PWMServoDriver pwm);

#endif
