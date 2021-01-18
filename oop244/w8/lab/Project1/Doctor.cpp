//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 22th 2020
// Workshop:       	8 (Part 1)
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Doctor.h"

using namespace std;
namespace sdds {
	Doctor::Doctor(const char* type, double hourly_salary, int hours, bool spec) :Employee(hourly_salary, hours) {
		this->type[0] = '\0';
		strcpy(this->type, type);
		this->specialist = spec;
	}

	double Doctor::getSalary(int workedHours) const {
		double salary = 0;
		if (workedHours <= this->getMin_hours()) {
			salary = this->getHourlySalary() * (double)workedHours;
		}
		else {
			salary = (this->getMin_hours() * (double)this->getHourlySalary()) + ((workedHours-this->getMin_hours())*this->getHourlySalary()*1.5);
		}
		if (this->specialist) {
			salary += 2000;
		}
		return salary;
	}

	ostream& Doctor::display(ostream& os)const {
		os << "Doctor" << endl;
		os << right << setw(16) << "Type: " << this->type;
		if (this->specialist) {
			os << " (specialist)" << endl;
		}
		else {
			os << endl;
		}
		os << right << setw(16) << "Pay Rate: " << this->getHourlySalary() << endl;
		os << right << setw(16) << "Min Hours: " << this->getMin_hours() << endl;

		return os;
	}
	Doctor::~Doctor() {

	}
}