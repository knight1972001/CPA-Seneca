//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    Aug 2nd 2020
// Workshop:       	MS4
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include "Vehicle.h"
#include <cstring>
#include <iostream>
#include <cctype>
using namespace std;
namespace sdds {
	Vehicle::Vehicle() {
		setEmpty();
	}

	Vehicle::Vehicle(const char* license, const char* makeModel, int parkingNum) {
		if (license != nullptr && license[0] != '\0' && makeModel != nullptr && makeModel[0] != '\0' && strlen(license)<8 && strlen(makeModel)>=2 && parkingNum>=0) {
			setEmpty();
			strcpy(this->license, license);
			this->makenModel = new char[strlen(makeModel)+1];
			strcpy(this->makenModel, makeModel);
			this->parkingNum = parkingNum;
			upperCase(this->license);
		}
		else {
			setEmpty();
		}
	}

	Vehicle::~Vehicle() {
		if (makenModel != nullptr) {
			delete[] makenModel;
			makenModel = nullptr;
		}
	}

	int Vehicle::getParkingSpot() const {
		return parkingNum;
	}

	void Vehicle::setParkingSpot(const int num) {
		parkingNum = num;
	}

	std::istream& Vehicle::read(std::istream& in) {
		if (isCsv()) {
			in >> parkingNum;
			in.ignore();
			in.getline(license, 9, ',');
			upperCase(license);
			char makeModel[61];
			in.getline(makeModel, 61, ',');
			setMakeModel(makeModel);
		}
		else {
			cout << "Enter Licence Plate Number: ";
			do {
				in >> license;
				in.ignore();
				if (strlen(license) > 8) {
					cout << "Invalid Licence Plate, try again: ";
				}
			} while (strlen(license) > 8);

			cout << "Enter Make and Model: ";
			char makeModel[61];
			do {
				in >> makeModel;
				in.ignore();
				if (strlen(makeModel) < 2 || strlen(makeModel) > 60) {
					cout << "Invalid Make and model, try again: ";
				}
			} while (strlen(makeModel) < 2 || strlen(makeModel) > 60);
			setMakeModel(makeModel);
			parkingNum = 0;
			upperCase(license);
		}
		if (in.fail()) {
			setEmpty();
			in.clear();
		}
		return in;
	}

	std::ostream& Vehicle::write(std::ostream& out) const {
		if (isEmpty()) {
			out << "Invalid Vehicle Object" << endl;
		}
		else {
			if (isCsv()) {
				out << parkingNum << "," << license << "," << makenModel << ",";
			}
			else {
				out << "Parking Spot Number: ";
				if (parkingNum == 0) {
					out << "N/A" << endl;
				}
				else {
					out << parkingNum << endl;
				}

				out << "Licence Plate: " << license << endl;

				out << "Make and Model: " << makenModel << endl;

			}
		}
		return out;
	}

	void Vehicle::setEmpty() {
		license[0] = '\0';
		makenModel = nullptr;
		parkingNum = 0;
	}

	bool Vehicle::isEmpty() const {
		if (license != nullptr && license[0] != '\0' && makenModel != nullptr && makenModel[0] != '\0' && strlen(license) < 8 && strlen(makenModel) >= 2 && parkingNum >= 0) {
			return false;
		}
		else {
			return true;
		}
	}

	const char* Vehicle::getLicensePlate() {
		return license;
	}

	const char* Vehicle::getMakeModel() {
		return makenModel;
	}

	void Vehicle::setMakeModel(const char* makeModel) {
		if (makeModel != nullptr && makeModel[0] != '\0') {
			if (this->makenModel != nullptr) {
				delete[] makenModel;
				makenModel = nullptr;
			}
			this->makenModel = new char[strlen(makeModel) + 1];
			strcpy(this->makenModel, makeModel);
		}
		else {
			setEmpty();
		}
	}

	bool operator==(const Vehicle& vehicle, const char* plate) {
		if (plate != nullptr && plate[0] != '\0') {
			return compareChar(vehicle.license, plate);
		}
		else {
			return false;
		}
	}

	bool operator==(const Vehicle& v1, const Vehicle& v2) {
		return compareChar(v1.license, v2.license);
	}
}