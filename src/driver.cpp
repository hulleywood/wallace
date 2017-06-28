#include <string>
#include <iostream>
#include "driver.h"
#include "GPIO.h"

using namespace std;

Driver::Driver(string left_motor_1_gpio, string left_motor_2_gpio, string right_motor_1_gpio, string right_motor_2_gpio, string left_pwm_gpio, string right_pwm_gpio) {

  int max_speed = 50; // need to play with this
  int min_speed = 0;
  int max_acceleration = 5; // need to play with this

  GPIO* left_motor_1 = new GPIO(left_motor_1_gpio);
  GPIO* left_motor_2 = new GPIO(left_motor_2_gpio);
  GPIO* right_motor_1 = new GPIO(right_motor_1_gpio);
  GPIO* right_motor_2 = new GPIO(right_motor_2_gpio);
  GPIO* left_pwm = new GPIO(left_pwm_gpio);
  GPIO* right_pwm = new GPIO(right_pwm_gpio);

  left_motor_1->set_out();
  left_motor_2->set_out();
  right_motor_1->set_out();
  right_motor_2->set_out();
  left_pwm->set_out();
  right_pwm->set_out();

  stop(); // ensure car isn't moving on construction

}

Driver::~Driver() {

  stop(); // ensure car stops on destruction

  delete left_motor_1;
  delete left_motor_2;
  delete right_motor_1;
  delete right_motor_2;
  delete left_pwm;
  delete right_pwm;

  left_motor_1 = NULL;
  left_motor_2 = NULL;
  right_motor_1 = NULL;
  right_motor_2 = NULL;
  left_pwm = NULL;
  right_pwm = NULL;

}

void Driver::set_speed() {
  // use pwms to set speed based on left/right attrs
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
  left_motor_1->off();
  left_motor_2->off();
  right_motor_1->off();
  right_motor_2->off();

  // update speed and acceleration to 0
  acceleration = 0;
  left_speed = 0;
  right_speed = 0;
}

void Driver::set_direction_forward() {
  left_motor_1->on();
  left_motor_2->off();
  right_motor_1->off();
  right_motor_2->on();
}

void Driver::set_direction_backward() {
  left_motor_1->off();
  left_motor_2->on();
  right_motor_1->on();
  right_motor_2->off();
}

