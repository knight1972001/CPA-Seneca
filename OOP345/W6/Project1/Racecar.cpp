#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <sstream>
#include "Racecar.h"

using namespace std;

namespace sdds {
	Racecar::Racecar() {
		m_booster = 0;
	}

	Racecar::Racecar(std::istream& in) : Car(in) {
		string line;
		getline(in, line);
		std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' ');
		line.erase(end_pos, line.end());
		if (!line.empty()) {
			m_booster = stod(line);
		}
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*" << endl;
	}

	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);
	}
}