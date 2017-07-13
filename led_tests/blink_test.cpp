#include <iostream>
#include <wiringPi.h>

using namespace std;

int main (void) {

  if (wiringPiSetup () == -1)
    return 1;

  const int pin = 29;

  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH); 

  delay(1000);

  digitalWrite(pin, LOW); 
  
  cout << "Exiting..." << endl;

  return 0;
}
