#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "../driver.h"

using namespace std;

int main() {

  if (wiringPiSetup () == -1)
    return 1;

  const int statusPin = 29;

  const int ENA_GPIO = 2;
  const int IN1_GPIO = 3;
  const int IN2_GPIO = 4;

  const int ENB_GPIO = 22;
  const int IN3_GPIO = 17;
  const int IN4_GPIO = 27;

  Driver driver(left_motor_1_gpio, left_motor_2_gpio, right_motor_1_gpio, right_motor_2_gpio, left_pwm_gpio, right_pwm_gpio);
  
  // turn on status indicator
  pinMode(statusPin, OUTPUT);
  digitalWrite(statusPin, HIGH); 

  // set direction to forward
  driver.set_direction_forward();

  // accelerate for 10 * 100ms
  for (int steps = 0; steps < 10; steps++) {
    driver.accelerate();
    delay(100);
  }

  delay(1000);

  // decelerate for 10 * 100ms
  for (int steps = 0; steps < 10; steps++) {
    driver.decelerate();
    delay(100);
  }

  // set direction backward
  driver.set_direction_backward();

  // accelerate for 10 * 100ms
  for (int steps = 0; steps < 10; steps++) {
    driver.accelerate();
    delay(100);
  }

  delay(1000);

  // decelerate for 10 * 100ms
  for (int steps = 0; steps < 10; steps++) {
    driver.decelerate();
    delay(100);
  }

  // turn all motors off
  driver.stop();
  
  // turn off status indicator
  digitalWrite(statusPin, LOW);

  return 0;
}
