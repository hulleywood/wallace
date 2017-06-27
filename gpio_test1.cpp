#include <iostream>
#include <unistd.h>
#include "GPIO.h"

using namespace std;

int main (void) {

	GPIO* gpio18 = new GPIO("18");
	gpio18->set_dir("out");

	gpio18->set_val("1");
	usleep(1000000);
	gpio18->set_val("0");
	
	cout << "Exiting....." << endl;
	delete gpio18;
	gpio18 = NULL;
	return 0;
}
