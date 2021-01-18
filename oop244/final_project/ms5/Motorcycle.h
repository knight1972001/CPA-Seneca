//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    Aug 7th 2020
// Workshop:       	MS5
//==============================================
#ifndef _MOTORCYCLE_H
#define _MOTORCYCLE_H
#include "Vehicle.h"

namespace sdds {
	class Motorcycle :public Vehicle {
	private:
		bool hasSideCar;
	public:
		Motorcycle();
		Motorcycle(const char*, const char*, int parkingNum = 0, bool hasSideCar = false);
		Motorcycle(const Motorcycle& a) = delete;
		Motorcycle& operator=(const Motorcycle& a) = delete;
		std::istream& read(std::istream& in = std::cin);
		std::ostream& write(std::ostream& out = std::cout) const;
		virtual ~Motorcycle();
	};
}

#endif // !_MOTORCYCLE_H
