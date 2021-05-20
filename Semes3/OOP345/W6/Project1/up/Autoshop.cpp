//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:				March 11th 2020
// Workshop:       	6
//==============================================
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
			out << endl;
		}
		out << "--------------------------------" << endl;
	}

	Autoshop::~Autoshop() {
		for (size_t i = 0; i < m_vehicles.size(); i++) {
			delete m_vehicles[i];
		}
	}

}