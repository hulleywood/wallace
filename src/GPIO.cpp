#include <fstream>
#include <string>
#include <iostream>
#include "GPIO.h"

using namespace std;

GPIO::GPIO(string num) {
	gpio_num = num;
	export_gpio();
}

GPIO::~GPIO() {
	unexport_gpio();
}

int GPIO::set_in() {
  return set_dir("in");
}

int GPIO::set_out() {
  return set_dir("out");
}

int GPIO::on() {
  return set_val("1");
}

int GPIO::off() {
  return set_val("0");
}

int GPIO::export_gpio() {
  string file_name = "/sys/class/gpio/export";
  return write_value_to_file(file_name, gpio_num);
}

int GPIO::unexport_gpio() {
  string file_name = "/sys/class/gpio/unexport";
  return write_value_to_file(file_name, gpio_num);
}

int GPIO::set_dir(string direction) {
  string file_name = "/sys/class/gpio/gpio" + gpio_num + "/direction";
  return write_value_to_file(file_name, direction);
}

int GPIO::set_val(string value) {
  string file_name = "/sys/class/gpio/gpio" + gpio_num + "/value";
  return write_value_to_file(file_name, value);
}

int GPIO::write_value_to_file(string file_name, string value) {
	ofstream file_stream(file_name.c_str());

	if (file_stream < 0) {
		return -1;
	}

	file_stream << value;
	file_stream.close();
	return 0;
}
