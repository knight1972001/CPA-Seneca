// Name:				Long Nguyen
// Seneca Student ID:	155176183
// Seneca email:		lnguyen97@myseneca.ca
// Date of completion:	Mar 21,2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <string>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	size_t Station::m_widthField = 0;
	size_t Station::id_generator = 0;

	Station::Station(const std::string& str) {
		if (str != "") {
			id_generator++;
			idStation = id_generator;
			Utilities utilities;

			size_t next_pos = 0;
			bool more = true;
			itemName = utilities.extractToken(str, next_pos, more);
			if (m_widthField < utilities.getFieldWidth()) {
				m_widthField = utilities.getFieldWidth();
			}
			serialNumber = stoi(utilities.extractToken(str, next_pos, more));
			numOfItems = stoi(utilities.extractToken(str, next_pos, more));
			description = utilities.extractToken(str, next_pos, more);
		}
	}

	const std::string& Station::getItemName() const {
		return itemName;
	}

	size_t Station::getNextSerialNumber() {
		return serialNumber++;
	}

	size_t Station::getQuantity() const {
		return numOfItems;
	}

	void Station::updateQuantity() {
		if ((numOfItems - 1) >= 0) {
			numOfItems--;
		}
	}

	void Station::display(std::ostream& os, bool full) const {
		if (!full) {
			os << "[" << right << std::setw(3) << std::setfill('0') << idStation << "]" << setfill(' ');
			os << " Item: " << left << setw(m_widthField) << itemName << setfill(' ');
			os << " [" << right << std::setw(6) << std::setfill('0') << serialNumber << "]" << endl;
		}
		else {
			os << "[" << right << std::setw(3) << std::setfill('0') << idStation << "] " << setfill(' ');
			os << "Item: " << left << setw(m_widthField) << itemName << setfill(' ');
			os << " [" << right << std::setw(6) << std::setfill('0') << serialNumber << "]" << setfill(' ');
			os << " Quantity: " << left << setw(m_widthField) << numOfItems;
			os << right << " Description: " << description << endl;
		}
	}
}