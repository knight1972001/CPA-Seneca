//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 22th 2020
// Workshop:       	8 (Part 1)
//==============================================
#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include <iostream>
namespace sdds {
	class Employee {
	private:
		const int min_hours;
		double hourly_salary;
	protected:
		double getHourlySalary() const;
		int getMin_hours() const;
	public:
		Employee(double hourly_salary, int min_hours);
		virtual double getSalary(int workedHours) const = 0;
		virtual std::ostream& display(std::ostream& out = std::cout) const = 0;
		virtual ~Employee();
	};
	std::ostream& operator<<(std::ostream& out, const Employee& emp);
}
#endif // !_EMPLOYEE_H
