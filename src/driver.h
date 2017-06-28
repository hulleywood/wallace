#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "GPIO.h"

using namespace std;

class Driver {
  public:
    Driver(string left_motor_1_gpio, string left_motor_2_gpio, string right_motor_1_gpio, string right_motor_2_gpio, string left_pwm_gpio, string right_pwm_gpio);
    ~Driver();

    void set_speed();
    void steer_left();
    void steer_right();
    void stop();

  private:
    GPIO* left_motor_1;
    GPIO* left_motor_2;
    GPIO* right_motor_1;
    GPIO* right_motor_2;
    GPIO* left_pwm;
    GPIO* right_pwm;

    // limits
    int max_speed;
    int min_speed;
    int max_acceleration;

    // current state
    int acceleration;
    int left_speed;
    int right_speed;

    void set_direction_forward();
    void set_direction_backward();
};

#endif
