#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "../driver.h"

using namespace std;

int main() {

  if (wiringPiSetup () == -1)
    return 1;

  const int STATUS_GPIO = 29;
  const int ENA_GPIO = 2;
  const int ENB_GPIO = 22;
  const int IN1_GPIO = 3;
  const int IN2_GPIO = 4;
  const int IN3_GPIO = 17;
  const int IN4_GPIO = 27;

  Driver driver(ENA_GPIO, ENB_GPIO, IN1_GPIO, IN2_GPIO, IN3_GPIO, IN4_GPIO);
  
  // turn on status indicator
  pinMode(STATUS_GPIO, OUTPUT);
  digitalWrite(STATUS_GPIO, HIGH); 

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
  digitalWrite(STATUS_GPIO, LOW);

  return 0;
}
