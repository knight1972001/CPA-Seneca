//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 22th 2020
// Workshop:       	8 (Part 1)
//==============================================
#ifndef _DOCTOR_H
#define _DOCTOR_H
#include <iostream>
#include "Employee.h"

namespace sdds {
	class Doctor : public Employee {
	private:
		char type[32];
		bool specialist;
	public:
		Doctor(const char* type, double hourly_salary, int hours, bool spec=false);
		virtual double getSalary(int workedHours) const;
		virtual std::ostream& display(std::ostream& out = std::cout) const;
		~Doctor();
	};
}
#endif // !_DOCTOR_H
