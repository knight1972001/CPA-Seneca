//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 14th 2020
// Workshop:       	7 (Part 1)
//==============================================
#ifndef _MOTOR_H
#define _MOTOR_H
#include <iostream>
namespace sdds {
	class MotorVehicle
	{
	private:
		char m_plate[32];
		char m_address[64];
		int m_year;
	public:
		MotorVehicle();
		MotorVehicle(const char*, int);
		void clear();
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};

	std::istream& operator>>(std::istream& in, MotorVehicle& v);
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& v);
}


#endif // !_MOTOR_H


