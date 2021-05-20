//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 28th 2020
// Workshop:       	MS2
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
namespace sdds {
	Parking::Parking() {
		filename = nullptr;
		mainmenu = Menu();
		submenu1 = Menu();
		closed = 1;
		numOfSpot = 0;
	}

	Parking::Parking(const char* filename, int numOfSpot) {
		setEmptystate();
		if (filename != nullptr && filename[0] != '\0') {
			this->filename = new char[strlen(filename) + 1];
			strcpy(this->filename, filename);
		}
		if (numOfSpot >= 10 && numOfSpot <= 100) {
				this->numOfSpot = numOfSpot;
		}else{
				this->numOfSpot = 0;
			}

			if (loadDataFile()) {
				mainmenu = Menu("Parking Menu, select an action:", 0);
				mainmenu.add("Park Vehicle");
				mainmenu.add("Return Vehicle");
				mainmenu.add("List Parked Vehicles");
				mainmenu.add("Close Parking (End of day)");
				mainmenu.add("Exit Program");
				submenu1 = Menu("Select type of the vehicle:", 1);
				submenu1.add("Car");
				submenu1.add("Motorcycle");
				submenu1.add("Cancel");
				closed = false;
			}else{
			cout << "Error in data file" << endl;
			this->filename = nullptr;
			mainmenu = Menu();
			submenu1 = Menu();
			closed = 1;
		}
	}

	Parking::~Parking() {
		setEmptystate();
	}

	void Parking::setEmptystate() {
		filename = nullptr;
		mainmenu = Menu();
		submenu1 = Menu();
		numOfSpot = 0;
		for (int i = 0; i < 100; i++) {
			parkingSpot[i] = nullptr;
		}
		numOfParked = 0;
	}

	int Parking::run() {
		if (!isEmpty()) {
			int check = 0;
			do {
				parkingStatus();
				int option = mainmenu.run();
				switch (option)
				{
				case 1:
					parkVehicle();
					break;
				case 2:
					returnVehicle();
					break;
				case 3:
					listParkedVehicle();
					break;
				case 4:
					if (closeParking()) {
						check = 1;
					}
					break;
				default:
					if (exitParkingApp()) {
						cout << "Exiting program!" << endl;
						check = 1;
						saveDataFile();
					}
					break;
				}
			} while (check == 0);
			return 0;
		}
		else {
			return 1;
		}
	}

	bool Parking::isEmpty() const {
		if (filename == nullptr) {
			return true;
		}
		else { return false; }
	}
	void Parking::parkingStatus() const {
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		std::cout.width(4); std::cout << std::left << numOfSpot - numOfParked << " *****" << endl;
		
	}

	void Parking::parkVehicle() {
		if (numOfSpot == numOfParked) {
			cout << "Parking is full" << endl;
		}
		else {
			int option = submenu1.run();
			if (option == 3) {
				cout << "Parking cancelled" << endl;
			}
			else {
				Vehicle* vehicelPark = nullptr;
				if (option == 1) {
					vehicelPark = new Car();
				}
				if (option == 2) {
					vehicelPark = new Motorcycle();
				}

				vehicelPark->setCsv(false);
				cin >> *vehicelPark;

				bool check = true;
				for (int i = 0; i < numOfSpot && check; i++) {
					if (parkingSpot[i] != nullptr && *parkingSpot[i] == *vehicelPark) {
						cout << "\nCan not park; license plate already in the system!" << endl;
						cout << *vehicelPark << endl;
						check = false;
					}
				}
				if (check && numOfParked < numOfSpot) {
					for (int i = 0; i < numOfSpot && check; i++) {
						if (parkingSpot[i] == nullptr) {
							parkingSpot[i] = vehicelPark;
							parkingSpot[i]->setParkingSpot(i + 1);
							cout << "\nParking Ticket" << endl;
							cout << *parkingSpot[i] << endl;
							numOfParked++;
							check = false;
						}
					}
				}
			}
		}
	}

	void Parking::returnVehicle() {
		cout << "Return Vehicle" << endl;
		char license_temp[61];
		bool check;
		cout << "Enter Licence Plate Number: ";
		do {
			check = false;
			cin >> license_temp;
			cin.ignore();
			if (strlen(license_temp) < 1 || strlen(license_temp) > 8) {
				cout << "Invalid Licence Plate, try again: ";
				check = true;
			}
		} while (check);
		upperCase(license_temp);

		bool match = true;
		for (int i = 0; i < numOfSpot && match; i++) {
			if (parkingSpot[i] != nullptr && *parkingSpot[i] == license_temp) {
				cout << "\nReturning: " << endl;
				parkingSpot[i]->setCsv(false);
				cout << *parkingSpot[i] << endl;
				delete parkingSpot[i];
				parkingSpot[i] = nullptr;
				numOfParked--;
				match = false;
			}
		}
		if (match) {
			cout << "\nLicense plate " << license_temp << " Not found\n" << endl;
		}
	}

	void Parking::listParkedVehicle() {
		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < numOfSpot; i++) {
			if (parkingSpot[i] != nullptr) {
				parkingSpot[i]->setCsv(false);
				cout << *parkingSpot[i];
				cout << "-------------------------------" << endl;
			}
		}
	}

	bool Parking::closeParking() {
		closed = false;
		if (numOfParked == 0) {
			cout << "Closing Parking" << endl;
			closed = true;
		}
		else {
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			if (yn()) {
				cout << "Closing Parking" << endl;
				for (int i = 0; i < numOfSpot; i++) {
					if (parkingSpot[i] != nullptr) {
						cout << endl << "Towing request" << endl;
						cout << "*********************" << endl;
						cout << *parkingSpot[i];
						delete parkingSpot[i];
						parkingSpot[i] = nullptr;
						numOfParked--;
					}
				}
				saveDataFile();
				closed = true;
			}
			else {
				cout << "Aborted!" << endl;
				closed = false;
			}
		}

		return closed;
	}

	bool Parking::exitParkingApp() {
		string check;
		int result = 0;
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		do {
			cin >> check;
			cin.ignore(1000, '\n');
			if (check == "Y" || check == "y") {
				result = 1;
			}
			else {
				if (check == "N" || check == "n") {
					result = 0;
				}
				else {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					result = 3;
				}
			}
		} while (result != 1 && result != 0);
		if (result == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Parking::loadDataFile() {
		bool check = true;
		ifstream input;
		if (!isEmpty()) {
			input.open(filename);
		}
		char vehicleType;
		Vehicle* vehicleP;
		numOfParked = 0;

		while (numOfParked < numOfSpot && check && input) {
			vehicleType = 'x';
			vehicleP = nullptr;
			input >> vehicleType;
			input.ignore();
			if (vehicleType == 'C') {
				vehicleP = new Car();
			}
			else if (vehicleType == 'M') {
				vehicleP = new Motorcycle();
			}

			if (vehicleP) {
				vehicleP->setCsv(true);
				input >> *vehicleP;
				if (input) {
					parkingSpot[vehicleP->getParkingSpot() - 1] = vehicleP;
					numOfParked++;
				}
				else {
					delete vehicleP;
					vehicleP = nullptr;
					check = false;
				}
			}
		}
		return check;
	}

	void Parking::saveDataFile() const {
		if (!isEmpty()) {
			ofstream fileout(filename);
			if (fileout) {
				for (int i = 0; i < numOfSpot; i++) {
					if (parkingSpot[i] != nullptr) {
						parkingSpot[i]->setCsv(true);
						fileout << *parkingSpot[i];
					}
				}
			}
		}
	}
}
