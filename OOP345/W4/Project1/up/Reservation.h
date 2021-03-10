//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:				Feb 11th 2020
// Workshop:       	4
//==============================================
#ifndef Reservation_H
#define Reservation_H
#include <iostream>
#include <string>
namespace sdds {
	class Reservation {
	private:
		std::string res_id;
		std::string name;
		std::string email;
		int numOfPeople;
		int day;
		int hour;
		//enum TimeOfDay { morning, afternoon, evening, drink } time;
	public:
		Reservation();
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res);
		~Reservation();
	};
}
#endif // !Reservation_H
