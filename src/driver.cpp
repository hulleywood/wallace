#include <string>
#include <iostream>
#include "driver.h"
#include "GPIO.h"

using namespace std;

Driver::Driver(string gpio_in_1_num, string gpio_in_2_num, string gpio_in_3_num, string gpio_in_4_num, string gpio_pwm_1_num, string gpio_pwm_2_num) {

  GPIO* gpio_in_1 = new GPIO(gpio_in_1_num);
  GPIO* gpio_in_2 = new GPIO(gpio_in_2_num);
  GPIO* gpio_in_3 = new GPIO(gpio_in_3_num);
  GPIO* gpio_in_4 = new GPIO(gpio_in_4_num);
  GPIO* gpio_pwm_1 = new GPIO(gpio_pwm_1_num);
  GPIO* gpio_pwm_2 = new GPIO(gpio_pwm_2_num);

}

Driver::~Driver() {

  delete gpio_in_1;
  delete gpio_in_2;
  delete gpio_in_3;
  delete gpio_in_4;
  delete gpio_pwm_1;
  delete gpio_pwm_2;

  gpio_in_1 = NULL;
  gpio_in_2 = NULL;
  gpio_in_3 = NULL;
  gpio_in_4 = NULL;
  gpio_pwm_1 = NULL;
  gpio_pwm_2 = NULL;

}
