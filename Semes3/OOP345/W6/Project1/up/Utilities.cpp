//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:				March 11th 2020
// Workshop:       	6
//==============================================
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		Vehicle* temp = nullptr;
		std::string temp_line;
		std::stringstream temp_stream;

		getline(in, temp_line);
		if (!temp_line.empty()) {
			while (true) {
				if (temp_line[0] != ' ') {
					if (temp_line[temp_line.length() - 1] != ' ') {
						break;
					}
					else {
						temp_line.erase(temp_line.length() - 1, temp_line.find(' ') + 1);
					}
				}
				else {
					temp_line.erase(0, temp_line.find(' ') + 1);
				}
			}
			temp_stream << temp_line;
			if (temp_stream.str().at(0) == 'c' || temp_stream.str().at(0) == 'C') {
				temp = new Car(temp_stream);
			}
			else {
				if (temp_stream.str().at(0) == 'r' || temp_stream.str().at(0) == 'R') {
					temp = new Racecar(temp_stream);
				}
				else {
					throw std::string("Unrecognized record type: [") + (temp_stream.str().at(0)) + "]";
				}
			}
			
		}
		return temp;
	}
}