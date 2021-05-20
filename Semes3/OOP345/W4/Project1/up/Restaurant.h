//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:				Feb 11th 2020
// Workshop:       	4
//==============================================
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "Reservation.h"
namespace sdds {
	class Restaurant {
	private:
		Reservation* reservation;
		size_t cnt;
	public:
		Restaurant();
		Restaurant(const Restaurant& res);
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant& operator=(const Restaurant& res);
		Restaurant(Restaurant&& res) noexcept;

		Restaurant& operator=(Restaurant&& res) noexcept;
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant);
		~Restaurant();
	};
}
#endif // !RESTAURANT_H
