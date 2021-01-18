//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 14th 2020
// Workshop:       	7 (Part 1)
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "MotorVehicle.h"
#include "Truck.h"

using namespace std;

namespace sdds {
	Truck::Truck() {
		capacity = 0;
		current_weight = 0;
	}

	Truck::Truck(const char* plate, int year, double capacity, const char* address):MotorVehicle(plate,year) {
		this->current_weight = 0;
		this->capacity = capacity;
		moveTo(address);
	}

	bool Truck::addCargo(double cargo) {
		if ((this->current_weight) < this->capacity) {
			if ((this->current_weight + cargo) > this->capacity) {
				this->current_weight = this->capacity;
			}
			else {
				this->current_weight += cargo;
			}
			return true;
		}
		else {
			return false;
		}
	}

	bool Truck::unloadCargo() {
		if (this->current_weight != 0) {
			this->current_weight = 0;
			return true;
		}
		else {
			return false;
		}
	}

	std::ostream& Truck::write(std::ostream& os) {
		MotorVehicle::write(os);
		os << " | " << this->current_weight << "/" << this->capacity;
		return os;
	}

	std::istream& Truck::read(std::istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> this->capacity;
		cout << "Cargo: ";
		in >> this->current_weight;
		return in;
	}

	istream& operator>>(istream& in, Truck& v) {
		return v.read(in);
	}

	ostream& operator<<(ostream& os, Truck& v) {
		return v.write(os);
	}
}