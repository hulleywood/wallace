#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>

using namespace std;

int main() {

  if (wiringPiSetup () == -1)
    return 1;

  const int pin = 29;
  const int max_pwm = 100;

  softPwmCreate(pin, LOW, max_pwm);

  for (int i = 0; i < max_pwm; i++) {
    softPwmWrite(pin, i);
    delay(10);
  }

  for (int i = max_pwm; i > 0; i--) {
    softPwmWrite(pin, i);
    delay(10);
  }

  cout << "Exiting..." << endl;

  return 0;
}
