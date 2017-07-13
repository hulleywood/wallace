#include <string>
#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "driver.h"

using namespace std;

Driver::Driver(int left_motor_1_gpio_, int left_motor_2_gpio_, int right_motor_1_gpio_, int right_motor_2_gpio_, int left_pwm_gpio_, int right_pwm_gpio_) {

  left_motor_1_gpio = left_motor_1_gpio_;
  left_motor_2_gpio = left_motor_2_gpio_;
  right_motor_1_gpio = right_motor_1_gpio_;
  right_motor_2_gpio = right_motor_2_gpio_;
  left_pwm_gpio = left_pwm_gpio_;
  right_pwm_gpio = right_pwm_gpio_;

  softPwmCreate(left_pwm_gpio, LOW, max_speed);
  softPwmCreate(right_pwm_gpio, LOW, max_speed);

  pinMode(left_motor_1_gpio, OUTPUT);
  pinMode(left_motor_2_gpio, OUTPUT);
  pinMode(right_motor_1_gpio, OUTPUT);
  pinMode(right_motor_2_gpio, OUTPUT);
  
  // ensure car isn't moving on construction
  stop(); 
}

Driver::~Driver() {
  // ensure car stops on destruction
  stop();
}

void Driver::accelerate() {
  left_speed += max_acceleration;
  right_speed += max_acceleration;

  if (left_speed > max_speed) {
    left_speed = max_speed;
  }

  if (right_speed > max_speed) {
    right_speed = max_speed;
  }

  softPwmWrite(left_pwm_gpio, left_speed);
  softPwmWrite(right_pwm_gpio, right_speed);
  log_status();
}

void Driver::decelerate() {
  left_speed -= max_acceleration;
  right_speed -= max_acceleration;

  if (left_speed < min_speed) {
    left_speed = min_speed;
  }

  if (right_speed < min_speed) {
    right_speed = min_speed;
  }

  softPwmWrite(left_pwm_gpio, left_speed);
  softPwmWrite(right_pwm_gpio, right_speed);
  log_status();
}

void Driver::steer_left() {
  // check if left can increase or right should decrease
  // update left_speed and right_speed prior to pwm update
}

void Driver::steer_right() {
  // check if left can increase or right should decrease
  // update left_speed and right_speed prior to pwm update
}

void Driver::stop() {
  // set all motors to off
  digitalWrite(left_motor_1_gpio, LOW);
  digitalWrite(left_motor_2_gpio, LOW);
  digitalWrite(right_motor_1_gpio, LOW);
  digitalWrite(right_motor_2_gpio, LOW);

  // update speed and acceleration to 0
  acceleration = 0;
  left_speed = 0;
  right_speed = 0;
  log_status();
}

void Driver::set_direction_forward() {
  digitalWrite(left_motor_1_gpio, LOW);
  digitalWrite(left_motor_2_gpio, HIGH);
  digitalWrite(right_motor_1_gpio, HIGH);
  digitalWrite(right_motor_2_gpio, LOW);
  direction = "forward";
  log_status();
}

void Driver::set_direction_backward() {
  digitalWrite(left_motor_1_gpio, HIGH);
  digitalWrite(left_motor_2_gpio, LOW);
  digitalWrite(right_motor_1_gpio, LOW);
  digitalWrite(right_motor_2_gpio, HIGH);
  direction = "backward";
  log_status();
}

void Driver::log_status() {
  cout << "direction: " << direction << ", left_speed: " << left_speed << ", right_speed: " << right_speed << endl;
}

