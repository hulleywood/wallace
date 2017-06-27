#include <string>
#include <iostream>
#include "driver.h"

using namespace std;

int main() {

  const string gpio_in_1_num = "27";
  const string gpio_in_2_num = "22";
  const string gpio_in_3_num = "24";
  const string gpio_in_4_num = "25";
  const string gpio_pwm_1_num = "17";
  const string gpio_pwm_2_num = "4";

  Driver driver(gpio_in_1_num, gpio_in_2_num, gpio_in_3_num, gpio_in_4_num, gpio_pwm_1_num, gpio_pwm_2_num);

  return 0;

}
