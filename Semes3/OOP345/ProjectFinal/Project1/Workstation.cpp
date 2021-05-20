// Name:				Long Nguyen
// Seneca Student ID:	155176183
// Seneca email:		lnguyen97@myseneca.ca
// Date of completion:	Apr 8th, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include "Workstation.h"

using namespace std;


namespace sdds {
	std::deque<CustomerOrder> pending;
	std::deque<CustomerOrder> completed;
	std::deque<CustomerOrder> incomplete;

	Workstation::Workstation(const std::string& str) : Station(str) {
		m_pNextStation = nullptr;
	}

	void Workstation::fill(std::ostream& os) {
		if (!m_orders.empty()) {
			if (!m_orders.front().isFilled()) {
				m_orders.front().fillItem(*this, os);
			}
		}
	}

	bool Workstation::attemptToMoveOrder() {
		if (!m_orders.empty()) {
			if (m_orders.front().isItemFilled(getItemName())) {
				if (m_pNextStation != nullptr) {
					*m_pNextStation += std::move(m_orders.front());
					m_orders.pop_front();
					return true;
				}
				else {
					completed.push_back(std::move(m_orders.front()));
					m_orders.pop_front();
					return true;
				}
			}

			if (this->getQuantity() <= 0) {
				if (m_pNextStation != nullptr) {
					*m_pNextStation += std::move(m_orders.front());
					m_orders.pop_front();
					return true;
				}
				else {
					incomplete.push_back(std::move(m_orders.front()));
					m_orders.pop_front();
					return true;
				}
			}
			return false;
		}
		else {
			return false;
		}
	}

	void Workstation::setNextStation(Workstation* station) {
		this->m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const {
		os << this->getItemName() << " --> ";
		if (m_pNextStation) {
			os  << m_pNextStation->getItemName() << endl;
		}
		else {
			os << "End of Line" << endl;
		}
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}