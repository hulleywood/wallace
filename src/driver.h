#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <wiringPi.h>
#include <softPwm.h>

using namespace std;

class Driver {
  public:
    Driver(int left_motor_1_gpio_, int left_motor_2_gpio_, int right_motor_1_gpio_, int right_motor_2_gpio_, int left_pwm_gpio_, int right_pwm_gpio_);
    ~Driver();

    void accelerate();
    void decelerate();
    void steer_left();
    void steer_right();
    void stop();

    // limits
    static const int max_speed = 100;
    static const int min_speed = 0;
    static const int max_acceleration = 5;

    // gpio mappings
    int left_motor_1_gpio;
    int left_motor_2_gpio;
    int right_motor_1_gpio;
    int right_motor_2_gpio;
    int left_pwm_gpio;
    int right_pwm_gpio;

    // current state
    int acceleration;
    int left_speed;
    int right_speed;
    string direction;

    void set_direction_forward();
    void set_direction_backward();
    void log_status();
};

#endif
