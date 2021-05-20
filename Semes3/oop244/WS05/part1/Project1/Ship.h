//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    June 23th 2020
// Workshop:       	5 (Part 1)
//==============================================
#ifndef _SHIP_H
#define _SHIP_H
#include"Engine.h"
namespace sdds {

	const double MIN_STD_POWER = 90.111;
	const double MAX_STD_POWER = 99.999;
	const int MAX_ENGINE = 10;
	class Ship {
	private:
		Engine m_engines[MAX_ENGINE];
		char m_type[TYPE_MAX_SIZE+1];
		int m_engCnt;
		double m_power;
	public:
		Ship();
		Ship(const char* type, const Engine *engine, const int engcnt);
		explicit operator bool() const {
			if (this->m_type!=nullptr && this->m_power != 0 && this->m_engCnt > 0)
			{
				return true;
			}
			else {
				return false;
			}
		}
		Ship& operator+=(Engine engine);
		bool operator<(double power) const;
		void display() const;
		double getPower() const;
	};
	bool operator<(double power, const Ship& theShip);

}


#endif // !_SHIP_H
