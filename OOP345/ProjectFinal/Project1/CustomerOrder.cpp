// Name:				Long Nguyen
// Seneca Student ID:	155176183
// Seneca email:		lnguyen97@myseneca.ca
// Date of completion:	Apr 8th, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "Station.h"
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	size_t CustomerOrder::m_widthField = 0;
	CustomerOrder::CustomerOrder() {
		m_cntItem = 0;
		m_lstItem = nullptr;
	}

	CustomerOrder::CustomerOrder(std::string& string) {
		if (string != "") {
			m_cntItem = 0;
			m_lstItem = nullptr;
			Utilities utilities;
			size_t next_pos = 0;
			bool more = true;
			Item* temp[20];
			m_name = utilities.extractToken(string, next_pos, more);
			m_product = utilities.extractToken(string, next_pos, more);
			while (more) {
				std::string tempStr = utilities.extractToken(string, next_pos, more);
				temp[m_cntItem] = new Item(tempStr);
				m_cntItem++;
			}
			m_lstItem = new Item* [m_cntItem];
			for (size_t i = 0; i < m_cntItem; i++) {
				m_lstItem[i] = temp[i];
			}
			if (m_widthField < utilities.getFieldWidth()) {
				m_widthField = utilities.getFieldWidth();
			}
		}
	}

	CustomerOrder::CustomerOrder(const CustomerOrder& obj) {
		throw "ERROR: Cannot make copies.";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& obj) noexcept {
		*this = std::move(obj);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& obj) noexcept {
		if (this != &obj) {
			this->m_name = obj.m_name;
			this->m_product = obj.m_product;
			this->m_cntItem = obj.m_cntItem;
			this->m_lstItem = obj.m_lstItem;
			obj.m_cntItem = 0;
			obj.m_lstItem = nullptr;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		if (this->m_lstItem != nullptr) {
			delete[] this->m_lstItem;
			this->m_lstItem = nullptr;
			this->m_cntItem = 0;
		}
	}

	bool CustomerOrder::isFilled() const {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_isFilled==false) {
				return false;
			}
		}
		return true;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName.compare(itemName) == 0) {
				return m_lstItem[i]->m_isFilled;
			}
		}
		return true;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == station.getItemName()) {
				if (station.getQuantity() == 0) {
					os << "Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "] " << endl;
				}
				else {
					m_lstItem[i]->m_isFilled = true;
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					station.updateQuantity();
					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << endl;
		for (size_t i = 0; i < m_cntItem; i++) {
			os << "[" << right << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] " << setfill(' ');
			os << left << setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
			if (m_lstItem[i]->m_isFilled) {
				os << "FILLED" << endl;
			}
			else {
				os << "TO BE FILLED" << endl;
			}
		}
	}
}