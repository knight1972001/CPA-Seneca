//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 14th 2020
// Workshop:       	7 (Part 1)
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include "MotorVehicle.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
namespace sdds {
	MotorVehicle::MotorVehicle() {
		this->m_plate[0] = '\0';
		this->m_address[0] = '\0';
		this->m_year = 0;
	}

	MotorVehicle::MotorVehicle(const char* license, int year) {
		clear();
		strcpy(this->m_plate, license);
		this->m_year = year;
		strcpy(this->m_address, "Factory");
	}

	void MotorVehicle::clear() {
		this->m_plate[0] = '\0';
		this->m_address[0] = '\0';
		this->m_year = 0;
	}

	void MotorVehicle::moveTo(const char* address) {
		char old_address[64] = { 0 };
		strcpy(old_address, this->m_address);
		this->m_address[0] = '\0';
		strcpy(this->m_address, address);
		cout << "|" << right << setw(10) << this->m_plate << "| |" << right << setw(20) << old_address << " --->--- " << left << setw(20) << this->m_address  << "|" << endl;
	}

	std::ostream& MotorVehicle::write(std::ostream& os) const {
		os << "| " << this->m_year << " | " << this->m_plate << " | " << this->m_address;
		return os;
	}

	std::istream& MotorVehicle::read(std::istream& in) {
		cout << "Built year: ";
		in >> this->m_plate;
		cout << "License plate: ";
		in >> this->m_plate;
		cout << "Current location: ";
		in >> this->m_address;
		return in;
	}

	std::istream& operator>>(std::istream& in, MotorVehicle& v) {
		return v.read(in);
	}

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& v) {
		return v.write(os);
	}
}