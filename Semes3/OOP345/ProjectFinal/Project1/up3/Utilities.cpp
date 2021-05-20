// Name:				Long Nguyen
// Seneca Student ID:	155176183
// Seneca email:		lnguyen97@myseneca.ca
// Date of completion:	Mar 21,2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <string>

#include "Utilities.h"
using namespace std;

namespace sdds {
	char Utilities::m_delimiter = ' ';

	Utilities::Utilities() {
		m_widthField = 1;
	}
	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		string extractToken = str.substr(next_pos);
		size_t pos = extractToken.find(m_delimiter);
		if (pos != std::string::npos) {
			extractToken = extractToken.substr(0, pos);
			if (extractToken == "") {
				more = false;
				throw "Delimiter is found at " + next_pos;
			}
			next_pos += pos + 1;
			more = true;
		}
		else {
			more = false;
		}
		if (m_widthField < extractToken.length()) {
			m_widthField = extractToken.length();
		}
		return extractToken;
	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}