//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 22th 2020
// Workshop:       	8 (Part 1)
//==============================================
#include "Engineer.h"
#include <iostream>
#include <iomanip>
using namespace std;
namespace sdds {
	Engineer::Engineer(double hourly_salary, int level) : Employee(hourly_salary, 30) {
		this->level = level;
	}

	double Engineer::getSalary(int workedHours) const {
		double salary = 0;
		salary = (double)workedHours * this->getHourlySalary();
		for (int i = 0; i < this->level; i++) {
			salary += 40;
		}
		if (workedHours < this->getMin_hours()) {
			salary *= 0.8;
		}
		return salary;
	}

	std::ostream& Engineer::display(std::ostream& os) const {
		os << "Engineer" << endl;
		os << right << setw(20) << "Level: " << this->level << endl;
		os << right << setw(20) << "Pay Rate: " << this->getHourlySalary() << endl;
		os << right << setw(20) << "Min Hours: " << this->getMin_hours() << endl;
		return os;
	 }
	Engineer::~Engineer() {

	}

}