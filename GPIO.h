#ifndef GPIO_H
#define GPIO_H

#include <string>
using namespace std;

class GPIO {
	public:
		GPIO(string num);
		~GPIO();

		string get_num();
		int set_dir(string direction);
		int set_val(string value);
		int get_val(string& value);

	private:
		string gpio_num;
		int write_value_to_file(string file_name, string value);
		int read_value_from_file(string file_name, string& value);
		int export_gpio();
		int unexport_gpio();
};

#endif
