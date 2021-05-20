//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:				March 11th 2020
// Workshop:       	6
//==============================================
#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle {
	private:
		std::string c_maker;
		std::string c_condition;
		double c_topSpeed;
	public:
		Car();
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}
#endif // !CAR_H
