//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:			Feb 20th 2020
// Workshop:       	5
//==============================================
#include<iostream>
#include<string>
#include <iomanip>
#include <algorithm>
#include "Movie.h"

using namespace std;

namespace sdds {
	Movie::Movie() {
		m_title = "";
		m_year = 0;
		m_description = "";
	}

	Movie::Movie(const std::string& strMovie) {
		string original = strMovie;
		m_title = original.substr(0, original.find(","));
		//trim m_title
		while (true) {
			if (m_title[0] != ' ') {
				if (m_title[m_title.length() - 1] != ' ') {
					break;
				}
				else {
					m_title.erase(m_title.length() - 1, m_title.find(' ') + 1);
				}
			}
			else {
				m_title.erase(0, m_title.find(' ') + 1);
			}
		}

		//year
		original.erase(0, original.find(",") + 1);
		m_year = stoi(original.substr(0, original.find(",")));

		//m_description
		original.erase(0, original.find(",") + 1);
		m_description = original;
		while (true) {
			if (m_description[0] != ' ') {
				if (m_description[m_description.length() - 1] != ' ') {
					break;
				}
				else {
					m_description.erase(m_description.length() - 1, m_description.find(' ') + 1);
				}
			}
			else {
				m_description.erase(0, m_description.find(' ') + 1);
			}
		}
	}

	const std::string& Movie::title() const {
		return m_title;
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		os << setw(40) << right << movie.m_title << " |";
		os << " " << setw(4) << right << movie.m_year << " |";
		os << " " << movie.m_description << endl;
		return os;
	}
}