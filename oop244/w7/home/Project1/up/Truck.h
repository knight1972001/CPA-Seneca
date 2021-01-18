//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 14th 2020
// Workshop:       	7 (Part 1)
//==============================================
#ifndef _TRUCK_H
#define _TRUCK_H
#include "MotorVehicle.h"
namespace sdds {
	class Truck : public MotorVehicle
	{
	private:
		double capacity;
		double current_weight;
	public:
		Truck();
		Truck(const char*, int, double, const char* address = "Factory");
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os);
		std::istream& read(std::istream& in);
	};
	std::istream& operator>>(std::istream& in, Truck& v);
	std::ostream& operator<<(std::ostream& os, Truck& v);
}
#endif // !TRUCK_H




