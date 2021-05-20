//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:				Feb 11th 2020
// Workshop:       	4
//==============================================
#include <iostream>
#include "ConfirmationSender.h"

using namespace std;
namespace sdds {
	ConfirmationSender::ConfirmationSender() {
		this->reservations = nullptr;
		this->cnt = 0;
		this->cntUsed = 0;
	}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& confirm) {
		*this = confirm;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& confirm) {
		/*if (this != &confirm) {
			this->cnt = confirm.cnt;
			this->cntUsed = confirm.cntUsed;
			if (confirm.reservations != nullptr) {
				if (this->reservations != nullptr) {
					delete[] this->reservations;
					this->reservations = nullptr;
				}
				this->reservations = new const Reservation * [this->cnt];
				for (size_t i = 0; i < this->cnt; i++) {
					this->reservations[i] = confirm.reservations[i];
				}
			}
			else {
				this->reservations = nullptr;
			}
		}*/
		if (this != &confirm) {
			this->cnt = confirm.cnt;
			this->cntUsed = confirm.cntUsed;
			this->reservations = new const Reservation * [this->cnt];
			for (size_t i = 0; i < this->cnt; i++) {
				this->reservations[i] = confirm.reservations[i];
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& confirm)noexcept {
		*this = std::move(confirm);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& confirm) noexcept {
		if (this != &confirm) {
			this->cnt = confirm.cnt;
			this->cntUsed = confirm.cntUsed;
			this->reservations = confirm.reservations;
			confirm.reservations = nullptr;
			confirm.cnt = 0;
			confirm.cntUsed = 0;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		if (this->cnt != 0) {
			bool found = false;
			for (size_t i = 0; i < this->cnt && !found; i++) {
				if (this->reservations[i] == &res) {
					found = true;
					break;
				}
			}
			if (!found) {
				if ((this->cnt - this->cntUsed) > 0) {
					reservations[this->cntUsed] = &res;
					this->cntUsed++;
				}
				else {
					const Reservation** temp;
					temp = new const Reservation*[this->cnt];
					for (size_t i = 0; i < this->cnt; i++) {
						temp[i] = this->reservations[i];
					}

					delete[] this->reservations;
					this->reservations = nullptr;

					this->reservations = new const Reservation*[this->cnt+1];
					for (size_t i = 0; i < this->cnt; i++) {
						this->reservations[i] = temp[i];
					}
					this->reservations[this->cntUsed] = &res;
					this->cnt++;
					this->cntUsed++;

					delete[] temp;
					temp = nullptr;
				}
			}
		}
		else {
			if (this->reservations != nullptr) {
				delete[] this->reservations;
				this->reservations = nullptr;
			}
			this->reservations = new const Reservation*[1];
			this->cnt = 1;
			this->cntUsed = 1;
			this->reservations[0] = &res;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		if (this->cnt != 0) {
			for (size_t i = 0; i < this->cntUsed; i++) {
				if (this->reservations[i] == &res) {
					this->reservations[i] = nullptr;
					this->cntUsed--;
					for (size_t j = i; j < this->cntUsed; j++) {
						this->reservations[j] = this->reservations[j + 1];
					}
				}
			}
			
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& confirmationSenders) {
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		if (confirmationSenders.cntUsed > 0) {
			for (size_t i = 0; i < confirmationSenders.cntUsed; i++) {
				os << (*confirmationSenders.reservations[i]);
			}
		}
		else {
			os << "There are no confirmations to send!" << endl;
		}
		os << "--------------------------" << endl;
		return os;
	}

	ConfirmationSender::~ConfirmationSender() {
		if (this->reservations != nullptr) {
			delete[] this->reservations;
			this->reservations = nullptr;
			this->cnt = 0;
			this->cntUsed = 0;
		}
	}


}