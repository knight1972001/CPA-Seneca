//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:				March 11th 2020
// Workshop:       	6
//==============================================
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>

#include "Car.h"

using namespace std;

namespace sdds {
	Car::Car() {
		c_maker = "";
		c_condition = "";
		c_topSpeed = 0;
	}

	Car::Car(std::istream& input) {
		std::string line; 
		std::getline(input, line, ',');//ignore tag

		std::getline(input, line, ',');

		c_maker = line.substr(0, line.find(","));
		while (true) {
			if (c_maker[0] != ' ') {
				if (c_maker[c_maker.length() - 1] != ' ') {
					break;
				}
				else {
					c_maker.erase(c_maker.length() - 1, c_maker.find(' ') + 1);
				}
			}
			else {
				c_maker.erase(0, c_maker.find(' ') + 1);
			}
		}

		std::getline(input, line,',');
		std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' ');
		line.erase(end_pos, line.end());
		string cond = line.substr(0, line.find(","));

		if (cond == "n" || cond == "u" || cond == "b" || cond == "") {
			if (cond == "n" || cond == "") c_condition = "new";
			if (cond == "u") c_condition = "used";
			if (cond == "b") c_condition = "broken";
		}
		else {
			throw std::string("Invalid record!");
		}

		std::getline(input, line, ',');
		end_pos = std::remove(line.begin(), line.end(), ' ');
		line.erase(end_pos, line.end());

		if (line.find_first_not_of("0123456789.,") == string::npos) {
			c_topSpeed = stod(line.substr(0, line.find(",")));
		}
		else {
			c_topSpeed = 0;
			throw std::string("Invalid record!");
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
		out << " " << setw(6) << left << setprecision(2) << fixed << c_topSpeed << " |";
	}
}