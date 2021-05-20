//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 28th 2020
// Workshop:       	MS3
//==============================================
#include "ReadWritable.h"
#include <iostream>
using namespace std;
namespace sdds {

	ReadWritable::ReadWritable() {
		m_csvIO = false;
	}

	bool ReadWritable::isCsv() const {
		return m_csvIO;
	}

	void ReadWritable::setCsv(bool value) {
		m_csvIO = value;
	}

	ReadWritable::~ReadWritable() {

	}

	std::ostream& operator<<(std::ostream& ostr, const ReadWritable& rw) {
		return rw.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, ReadWritable& rw) {
		return rw.read(istr);
	}
}