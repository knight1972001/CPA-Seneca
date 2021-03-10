#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "Utilities.h"
#include "Car.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		Vehicle* temp = nullptr;
		std::string temp_line;
		std::stringstream temp_stream;

		getline(in, temp_line);
		if (!temp_line.empty()) {
			std::string::iterator end_pos = std::remove(temp_line.begin(), temp_line.end(), ' ');
			temp_line.erase(end_pos, temp_line.end());
			temp_stream << temp_line;
			if (temp_stream.str().at(0) == 'c' || temp_stream.str().at(0) == 'C') {
				temp = new Car(temp_stream);
			}
		}
		return temp;
	}
}