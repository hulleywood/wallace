#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "GPIO.h"

using namespace std;

class Driver {
  public:
    Driver(string gpio_in_1_num, string gpio_in_2_num, string gpio_in_3_num, string gpio_in_4_num, string gpio_pwm_1_num, string gpio_pwm_2_num);
    ~Driver();

  private:
    GPIO* gpio_in_1;
    GPIO* gpio_in_2;
    GPIO* gpio_in_3;
    GPIO* gpio_in_4;
    GPIO* gpio_pwm_1;
    GPIO* gpio_pwm_2;
};

#endif
