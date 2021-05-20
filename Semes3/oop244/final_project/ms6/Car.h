//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    Aug 7th 2020
// Workshop:       	MS5
//==============================================
#ifndef _CAR_H
#define _CAR_H
#include "Vehicle.h"
namespace sdds {
	class Car : public Vehicle {
	private:
		bool Carwash;
	public:
		Car();
		Car(const char*, const char*, int parkingNum = 0, bool Carwash = false);
		Car(const Car& a) = delete;
		Car& operator=(const Car& a) = delete;
		std::istream& read(std::istream& is = std::cin);
		std::ostream& write(std::ostream& out = std::cout) const;
		virtual ~Car();
	};
}
#endif // !_CAR_H
