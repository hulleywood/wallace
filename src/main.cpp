#include <string>
#include <iostream>
#include "driver.h"

using namespace std;

int main() {

  const string left_motor_1_gpio = "24";
  const string left_motor_2_gpio = "25";
  const string right_motor_1_gpio = "27";
  const string right_motor_2_gpio = "22";
  const string left_pwm_gpio = "17";
  const string right_pwm_gpio = "4";

  Driver driver(left_motor_1_gpio, left_motor_2_gpio, right_motor_1_gpio, right_motor_2_gpio, left_pwm_gpio, right_pwm_gpio);

  return 0;

}
