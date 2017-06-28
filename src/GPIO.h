#ifndef GPIO_H
#define GPIO_H

#include <string>

using namespace std;

class GPIO {
  public:
    GPIO(string num);
    ~GPIO();

    int set_in();
    int set_out();
    int on();
    int off();

  private:
    string gpio_num;
    int export_gpio();
    int unexport_gpio();
    int set_dir(string direction);
    int set_val(string value);
    int write_value_to_file(string file_name, string value);
};

#endif
