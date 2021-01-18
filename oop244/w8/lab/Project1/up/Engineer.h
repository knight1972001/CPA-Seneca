//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 22th 2020
// Workshop:       	8 (Part 1)
//==============================================
#ifndef _ENGINEER_H
#define _ENGINEER_H
#include <iostream>
#include "Employee.h"
namespace sdds {
	class Engineer : public Employee {
	private:
		int level;
	public:
		Engineer(double hourly_salary, int level);
		virtual double getSalary(int workedHours) const;
		virtual std::ostream& display(std::ostream& os = std::cout) const;
		~Engineer();
	};
}
#endif // !_ENGINEER_H
