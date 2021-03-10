#include<iostream>
#include<string>
#include<algorithm>
#include <iomanip>

#include "Car.h"

using namespace std;

namespace sdds {
	Car::Car() {
		c_maker = "";
		c_condition = "";
		c_topSpeed = 0;
	}

	Car::Car(std::istream& input) {
		for (std::string line; getline(input, line); )
		{
			std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' ');
			line.erase(end_pos, line.end());

			string tag = line.substr(0, line.find(","));
			line.erase(0, line.find(",") + 1);
			if (tag == "C" || tag == "c") {
				c_maker = line.substr(0, line.find(","));
				line.erase(0, line.find(",") + 1);
				string cond = line.substr(0, line.find(","));
				if (cond == "n") c_condition = "new";
				if (cond == "u") c_condition = "used";
				if (cond == "b") c_condition = "broken";
				line.erase(0, line.find(",") + 1);
				c_topSpeed = stod(line.substr(0, line.find(",")));
			}
		}
	}

	std::string Car::condition() const {
		return c_condition;
	}

	double Car::topSpeed() const {
		return c_topSpeed;  
	}

	void Car::display(std::ostream& out) const {
		out << "| " << setw(10) << right << c_maker << " |";
		out << " " << setw(6) << left << c_condition << " |";
		out << " " << setw(6) << left << setprecision(2) << fixed << c_topSpeed << " |" << endl;
	}
}