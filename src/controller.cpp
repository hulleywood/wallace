#include <string>
#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include "controller.h"

using namespace std;

Controller::Controller(int ENA_GPIO_, int ENB_GPIO_, int IN1_GPIO_, int IN2_GPIO_, int IN3_GPIO_, int IN4_GPIO_) {

  // right wheel speed
  ENA_GPIO = ENA_GPIO_;

  // left wheel speed
  ENB_GPIO = ENB_GPIO_;

  // right wheel direction
  IN1_GPIO = IN1_GPIO_;
  IN2_GPIO = IN2_GPIO_;

  // left wheel direction
  IN3_GPIO = IN3_GPIO_;
  IN4_GPIO = IN4_GPIO_;

  // set max range for PWM pins
  softPwmCreate(ENA_GPIO, LOW, MAX_SPEED);
  softPwmCreate(ENB_GPIO, LOW, MAX_SPEED);

  // set all motor pins to output mode
  pinMode(IN1_GPIO, OUTPUT);
  pinMode(IN2_GPIO, OUTPUT);
  pinMode(IN3_GPIO, OUTPUT);
  pinMode(IN4_GPIO, OUTPUT);
  
  // ensure car isn't moving on construction
  stop(); 
}

Controller::~Controller() {
  // ensure car stops on destruction
  stop();

  // TODO does wiringPi deal with unexporting GPIOs?
}

void Controller::update_motor_speeds() {
  softPwmWrite(ENA_GPIO, right_speed);
  softPwmWrite(ENB_GPIO, left_speed);
  log_status();
}

void Controller::accelerate() {
  left_speed += MAX_ACCELERATION;
  right_speed += MAX_ACCELERATION;
  
  // reset left_speed to MAX_SPEED if it exceeds the value
  if (left_speed > MAX_SPEED) {
    left_speed = MAX_SPEED;
  }

  // reset right_speed to MAX_SPEED if it exceeds the value
  if (right_speed > MAX_SPEED) {
    right_speed = MAX_SPEED;
  }

  update_motor_speeds();
}

void Controller::decelerate() {
  left_speed -= MAX_ACCELERATION;
  right_speed -= MAX_ACCELERATION;

  // reset left_speed to MAX_SPEED if it exceeds the value
  if (left_speed < MIN_SPEED) {
    left_speed = MIN_SPEED;
  }

  // reset right_speed to MAX_SPEED if it exceeds the value
  if (right_speed < MIN_SPEED) {
    right_speed = MIN_SPEED;
  }

  update_motor_speeds();
}

void Controller::steer_left() {
  // increase right speed to go left
  right_speed += MAX_ACCELERATION

  // if right speed is too fast, decrease left speed by amount over to keep relative difference
  if (right_speed > MAX_SPEED) {
    int overage = right_speed - MAX_SPEED;
    left_speed -= overage;
    right_speed = MAX_SPEED;
  }

  update_motor_speeds();
}

void Controller::steer_right() {
  // increase left speed to go right
  left_speed += MAX_ACCELERATION

  // if left speed is too fast, decrease right speed by amount over to keep relative difference
  if (left_speed > MAX_SPEED) {
    int overage = left_speed - MAX_SPEED;
    right_speed -= overage;
    left_speed = MAX_SPEED;
  }

  update_motor_speeds();
}

void Controller::stop() {
  // set all motors to off
  digitalWrite(IN1_GPIO, LOW);
  digitalWrite(IN2_GPIO, LOW);
  digitalWrite(IN3_GPIO, LOW);
  digitalWrite(IN4_GPIO, LOW);

  // update speeds and acceleration to 0
  acceleration = 0;
  left_speed = 0;
  right_speed = 0;
  log_status();
}

void Controller::set_direction_forward() {
  // right wheel forward
  digitalWrite(IN1_GPIO, HIGH);
  digitalWrite(IN2_GPIO, LOW);

  // left wheel forward
  digitalWrite(IN3_GPIO, LOW);
  digitalWrite(IN4_GPIO, HIGH);

  // set direction variable for logging purposes
  direction = "forward";
  log_status();
}

void Controller::set_direction_backward() {
  // right wheel backward
  digitalWrite(IN1_GPIO, LOW);
  digitalWrite(IN2_GPIO, HIGH);

  // left wheel backward
  digitalWrite(IN3_GPIO, HIGH);
  digitalWrite(IN4_GPIO, LOW);

  // set direction variable for logging purposes
  direction = "backward";
  log_status();
}

void Controller::log_status() {
  cout << "direction: " << direction << ", left_speed: " << left_speed << ", right_speed: " << right_speed << endl;
}

