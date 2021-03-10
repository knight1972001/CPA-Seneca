#include <iostream>
#include <iomanip>
#include <vector>
#include "Autoshop.h"

using namespace std;

namespace sdds {
	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;

		for (size_t i = 0; i < m_vehicles.size(); i++) {
			m_vehicles[i]->display(out);
		}
		out << "--------------------------------" << endl;
	}
}