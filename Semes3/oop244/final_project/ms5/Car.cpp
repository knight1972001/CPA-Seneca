//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    Aug 7th 2020
// Workshop:       	MS5
//==============================================
#include "Car.h"
#include <iostream>
#include <cstring>

using namespace std;
namespace sdds {
	Car::Car() {
		Vehicle::setEmpty();
		Carwash = false;
	}

	Car::Car(const char* license, const char* makeModel, int parkingNum, bool Carwash): Vehicle(license,makeModel,parkingNum){
		this->Carwash = Carwash;
	}

	istream& Car::read(istream& in) {
		if (isCsv()) {
			Vehicle::read(in);
			int check = 0;
			do {
				in >> check;
				in.ignore();
				if (check == 0 || check == 1) {
					if (check == 0) {
						Carwash = false;
					}
					else {
						Carwash = true;
					}
				}
				else {
					cout << "Invaild Input, Re-type: ";
					check = 2;
				}
			} while (check != 0 && check != 1);
			
		}
		else {
			cout << "\nCar information entry" << endl;
			Vehicle::read(in);
			cout << "Carwash while parked? (Y)es/(N)o: ";
			Carwash = yn();
		}
		return in;
	}

	ostream& Car::write(ostream& out) const {
		if (isEmpty()) {
			out << "Invalid Car Object" << endl;
		}
		else {
			if (isCsv()) {
				out << "C,";
				Vehicle::write(out);
				out << int(Carwash) << std::endl;
			}
			else {
				out << "Vehicle type: Car" << endl;
				Vehicle::write(out);
				if (Carwash) {
					out << "With Carwash" << endl;
				}
				else {
					out << "Without Carwash" << endl;
				}
			}
		}
		return out;
	}

	Car::~Car() {
	
	}
}