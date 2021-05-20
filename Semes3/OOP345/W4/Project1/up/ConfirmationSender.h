//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:				Feb 11th 2020
// Workshop:       	4
//==============================================
#ifndef CONFIRMATION_H
#define CONFIRMATION_H
#include "Reservation.h"
namespace sdds {
	class ConfirmationSender {
	private:
		const Reservation** reservations;
		size_t cnt;
		size_t cntUsed;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& confirm);
		ConfirmationSender(ConfirmationSender&& confirm) noexcept;
		ConfirmationSender& operator=(const ConfirmationSender& confirm);
		ConfirmationSender& operator=(ConfirmationSender&& confirm) noexcept ;

		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& confirmationSenders);
		~ConfirmationSender();
	};
}
#endif // !CONFIRMATION_H
