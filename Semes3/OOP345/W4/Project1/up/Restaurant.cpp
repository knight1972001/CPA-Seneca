//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:				Feb 11th 2020
// Workshop:       	4
//==============================================
#include <iostream>
#include "Restaurant.h"

using namespace std;
namespace sdds {
	Restaurant::Restaurant() {
		this->reservation = nullptr;
		cnt = 0;
	}

	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
		if (cnt > 0) {

			this->cnt = cnt;
			this->reservation = nullptr;
			this->reservation = new Reservation[this->cnt];
			for (size_t i = 0; i < this->cnt; i++) {
				this->reservation[i] = *reservations[i];
			}
		}
		else {
			this->reservation = nullptr;
			this->cnt = 0;
		}
	}

	size_t Restaurant::size() const {
		return this->cnt;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant) {
		static int CALL_CNT;
		os << "--------------------------" << endl;
		os << "Fancy Restaurant (" << ++CALL_CNT << ")" << endl;
		os << "--------------------------" << endl;
		if (restaurant.cnt > 0) {
			for (size_t i = 0; i < restaurant.size(); i++) {
				os << restaurant.reservation[i];
			}
		}
		else {
			os << "This restaurant is empty!" << endl;
		}
		os << "--------------------------" << endl;
		return os;
	}

	Restaurant& Restaurant::operator=(const Restaurant& res) {
		if (this != &res) {
			this->cnt = res.cnt;
			this->reservation = new Reservation[this->cnt];
			for (size_t i = 0; i < this->cnt; i++) {
				this->reservation[i] = res.reservation[i];
			}
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& res) noexcept {
		*this = std::move(res);
	}

	Restaurant::Restaurant(const Restaurant& res) {
		*this = res;
	}

	Restaurant& Restaurant::operator=(Restaurant&& res) noexcept {
		if (this != &res) {
			this->cnt = res.cnt;

			this->reservation = nullptr;
			this->reservation = res.reservation;

			res.reservation = nullptr;
			res.cnt = 0;
		}
		return *this;
	}



	Restaurant::~Restaurant() {
		if (this->reservation != nullptr) {
			delete[] this->reservation;
			this->reservation = nullptr;
			this->cnt = 0;
		}
	}

}