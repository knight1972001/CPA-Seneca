//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    Aug 7th 2020
// Workshop:       	MS5
//==============================================
#include"Motorcycle.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
	Motorcycle::Motorcycle() {
		Vehicle::setEmpty();
		hasSideCar = false;
	}

	Motorcycle::Motorcycle(const char* license, const char* makeModel, int parkingNum, bool hasSideCar) :Vehicle(license, makeModel,parkingNum){
		this->hasSideCar = hasSideCar;
	}
	
	istream& Motorcycle::read(istream& in) {
		if (isCsv()) {
			Vehicle::read(in);
			int check = 0;
			do {
				in >> check;
				in.ignore();
				if (check == 0 || check == 1) {
					if (check == 0) {
						hasSideCar = false;
					}
					else {
						hasSideCar = true;
					}
				}
				else {
					cout << "Invaild Input, Re-type: ";
					check = 2;
				}
			} while (check != 0 && check != 1);

		}
		else {
			cout << "\nMotorcycle information entry" << endl;
			Vehicle::read(in);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			hasSideCar = yn();
		}
		return in;
	}

	std::ostream& Motorcycle::write(std::ostream& out) const {
		if (isEmpty()) {
			out << "Invalid Motorcycle Object" << endl;
		}
		else {
			if (isCsv()) {
				out << "M,";
				Vehicle::write(out);
				out << int(hasSideCar) << endl;
			}
			else {
				out << "Vehicle type: Motorcycle" << endl;
				Vehicle::write(out);
				if (hasSideCar) {
					out << "With Sidecar" << endl;
				}
			}
		}
		return out;
	}

	Motorcycle::~Motorcycle() {

	}
}