#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
	Parking::Parking() {
		filename = nullptr;
		mainmenu = Menu();
		submenu1 = Menu();
		closed = 1;
	}

	Parking::Parking(const char* filename) {
		if (filename != nullptr && filename != "" && filename[0] != '\0') {
			if (this->filename != nullptr) {
				delete[] this->filename;
				this->filename = nullptr;
			}
			this->filename = new char[strlen(filename)];
			strcpy(this->filename, filename);

			if (loadDataFile()) {
				mainmenu = Menu("Parking Menu, select an action:", 0);
				mainmenu.add("Park Vehicle");
				mainmenu.add("Return Vehicle");
				mainmenu.add("List Parked Vehicles");
				mainmenu.add("Close Parking (End of day)");
				mainmenu.add("Exit Program");
				submenu1 =Menu("Select type of the vehicle:", 1);
				submenu1.add("Car");
				submenu1.add("Motorcycle");
				submenu1.add("Cancel");
			}
			closed = 0;
		}
		else {
			cout << "Error in data file" << endl;
			this->filename = nullptr;
			mainmenu = Menu();
			submenu1 = Menu();
			closed = 1;
		}
	}

	Parking::~Parking() {
		if (this->filename != nullptr) {
			delete[] this->filename;
			this->filename = nullptr;
		}
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
						check = 1;
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

	bool Parking::isEmpty() {
		if (filename == nullptr) {
			return true;
		}
		else { return false; }
	}
	void Parking::parkingStatus() {
		cout << "****** Seneca Valet Parking ******" << endl;
	}

	void Parking::parkVehicle() {
			int option = submenu1.run();
			switch (option)
			{
			case 1:
				cout << "Parking Car" << endl;
				break;
			case 2:
				cout << "Parking Motorcycle" << endl;
				break;
			case 3:
				cout << "Cancelled parking" << endl;
				break;
			}
	}

	void Parking::returnVehicle() {
		cout << "Returning Vehicle" << endl;
	}

	void Parking::listParkedVehicle() {
		cout << "Listing Parked Vehicles" << endl;
	}

	bool Parking::closeParking() {
		if (closed != 1) {
			cout << "Closing Parking" << endl;
			closed = 1;
			return true;
		}
		else {
			cout << "Parking was closed, cannot close again!" << endl;
			return false;
		}
		
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
		if (!isEmpty()) {
			cout << "loading data from " << filename << endl;
			return true;
		}
		else {
			return false;
		}
	}

	void Parking::saveDataFile() {
		cout << "Saving data into " << filename << endl;
	}

	
}