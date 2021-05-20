// Name:				Long Nguyen
// Seneca Student ID:	155176183
// Seneca email:		lnguyen97@myseneca.ca
// Date of completion:	Apr 8th, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef WORKSTATION_H
#define WORKSTATION_H
#include <iostream>
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"
namespace sdds {
extern std::deque<CustomerOrder> pending;
extern std::deque<CustomerOrder> completed;
extern std::deque<CustomerOrder> incomplete;

	class Workstation : public Station {
	private:
		std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation;
	public:
		Workstation(const std::string& str);
		Workstation(const Workstation& ws) = delete;
		Workstation& operator=(const Workstation& ws) = delete;

		Workstation(Workstation&& ws) = delete;
		Workstation& operator=(Workstation&& ws) = delete;

		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}
#endif // !WORKSTATION_H
