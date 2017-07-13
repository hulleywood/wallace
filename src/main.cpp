#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "driver.h"

using namespace std;

int main() {

  if (wiringPiSetup () == -1)
    return 1;

  const int statusPin = 29;
  const int left_motor_1_gpio = 17;
  const int left_motor_2_gpio = 27;
  const int right_motor_1_gpio = 3;
  const int right_motor_2_gpio = 4;
  const int left_pwm_gpio = 22;
  const int right_pwm_gpio = 2;

  Driver driver(left_motor_1_gpio, left_motor_2_gpio, right_motor_1_gpio, right_motor_2_gpio, left_pwm_gpio, right_pwm_gpio);
  
  // turn on status indicator
  pinMode(statusPin, OUTPUT);
  digitalWrite(statusPin, HIGH); 

  driver.set_direction_forward();

  for (int steps = 0; steps < 10; steps++) {
    driver.accelerate();
    driver.log_status();
    delay(100);
  }

  delay(1000);

  for (int steps = 0; steps < 10; steps++) {
    driver.decelerate();
    driver.log_status();
    delay(100);
  }

  driver.set_direction_backward();

  for (int steps = 0; steps < 10; steps++) {
    driver.accelerate();
    driver.log_status();
    delay(100);
  }

  delay(1000);

  for (int steps = 0; steps < 10; steps++) {
    driver.decelerate();
    driver.log_status();
    delay(100);
  }

  // turn all motors off
  driver.stop();
  driver.log_status();

  digitalWrite(statusPin, LOW); // turn off status indicator

  return 0;
}
