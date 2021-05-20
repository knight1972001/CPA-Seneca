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
#include "Racecar.h"

using namespace std;

namespace sdds {
	Racecar::Racecar() : Car() {
		m_booster = 0;
	}

	Racecar::Racecar(std::istream& in) : Car(in) {
		m_booster = 0;
		std::string line; 
		std::getline(in, line);
		std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' ');
		line.erase(end_pos, line.end());
		if (!line.empty()) {
			m_booster = stod(line);
		}
	}

	void Racecar::display(std::ostream& out) const {
		stringstream os_to_stream;
		string carLine;
		Car::display(os_to_stream);
		carLine = os_to_stream.str();
		carLine = carLine.substr(0, 23);
		out << carLine;
		out << " " << setw(6) << left << setprecision(2) << fixed << this->topSpeed() << " |*";
	}

	double Racecar::topSpeed() const {
		return (Car::topSpeed() * (1 + m_booster));
	}
}