#include <string>
#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "vehicle.h"
#include "controller.h"

using namespace std;

Vehicle::Vehicle() {
  if (wiringPiSetup () == -1)
    return 1;

  const int STATUS_GPIO = 29;
  const int ENA_GPIO = 2;
  const int ENB_GPIO = 22;
  const int IN1_GPIO = 3;
  const int IN2_GPIO = 4;
  const int IN3_GPIO = 17;
  const int IN4_GPIO = 27;

  Controller controller(ENA_GPIO, ENB_GPIO, IN1_GPIO, IN2_GPIO, IN3_GPIO, IN4_GPIO);
  
  // initialize status indicator
  pinMode(STATUS_GPIO, OUTPUT);
  
  // turn on status indicator
  digitalWrite(STATUS_GPIO, HIGH); 

}

Vehicle::~Vehicle() {
  // turn off status indicator
  digitalWrite(STATUS_GPIO, LOW);
}

void Vehicle::process_keyboard_input(char input) {
}
