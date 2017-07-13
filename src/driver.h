#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <wiringPi.h>
#include <softPwm.h>

using namespace std;

class Driver {
  public:
    Driver(int ENA_GPIO_, int ENB_GPIO_, int IN1_GPIO_, int IN2_GPIO_, int IN3_GPIO_, int IN4_GPIO_);
    ~Driver();

    void accelerate();
    void decelerate();
    void steer_left();
    void steer_right();
    void stop();

    void set_direction_forward();
    void set_direction_backward();
    void log_status();

  private
  
    // limits
    static const int MAX_SPEED = 100;
    static const int MIN_SPEED = 0;
    static const int MAX_ACCELERATION = 5;

    // gpio mappings
    int ENA_GPIO;
    int ENB_GPIO;
    int IN1_GPIO;
    int IN2_GPIO;
    int IN3_GPIO;
    int IN4_GPIO;

    // current state
    int acceleration;
    int left_speed;
    int right_speed;
    string direction;

    void update_motor_speeds();

};

#endif
