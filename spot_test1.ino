#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <math.h>
#include "my_kin_lib.h"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define MAX_GAMMA 50

#define SERVOMIN  100 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define MIN_PULSE  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define MAX_PULSE  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");

  pwm.begin();

  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  yield();
  delay(10);

    sit_stationary(pwm);
    delay(5000);
    stand_up_from_down(pwm);
    delay(2000);
    sit_down_from_stationary(pwm);
    delay(2000);
    tilt_right(pwm);
    delay(3000);
    sit_stationary_from_tilt_right(pwm);
    delay(2000);
    tilt_left(pwm);
    delay(3000);
    sit_stationary_from_tilt_left(pwm);
}

void loop() {
}
