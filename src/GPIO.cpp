#include <fstream>
#include <string>
#include <iostream>
#include "GPIO.h"

GPIO::GPIO(string num) {
	gpio_num = num;
	export_gpio();
}

GPIO::~GPIO() {
	unexport_gpio();
}

string GPIO::get_num() {
	return gpio_num;
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

int GPIO::read_value_from_file(string file_name, string& value) {
	ifstream file_stream(file_name.c_str());

	if (file_stream < 0) {
		return -1;
	}

	file_stream >> value;
	file_stream.close();
	return 0;
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

int GPIO::get_val(string& value) {
	string file_name = "/sys/class/gpio/gpio" + gpio_num + "/value";
	string export_cmd = "/sys/class/gpio/unexport";
	return read_value_from_file(file_name, value);
}
