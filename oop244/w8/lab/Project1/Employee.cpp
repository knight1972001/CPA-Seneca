//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 22th 2020
// Workshop:       	8 (Part 1)
//==============================================
#include"Employee.h"
namespace sdds {
	Employee::Employee(double hourly_salary, int hours) : min_hours{hours }
	{
		this->hourly_salary = hourly_salary;
	}

	Employee::~Employee() {

	}

	double Employee::getHourlySalary() const {
		return this->hourly_salary;
	}

	int Employee::getMin_hours() const {
		return min_hours;
	}
	
	std::ostream& operator<<(std::ostream& out, const Employee& emp) {
		return emp.display(out);
	}
}