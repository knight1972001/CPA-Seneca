//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 28th 2020
// Workshop:       	MS2
//==============================================
#ifndef PARKING_H
#define PARKING_H
#include "Menu.h"
#include "Utils.h"
namespace sdds {
	class Parking {
	private:
		char *filename;
		Menu mainmenu;
		Menu submenu1;
		int closed;
		bool isEmpty() const;
		void parkingStatus() const;
		void parkVehicle();
		void returnVehicle();
		void listParkedVehicle();
		bool closeParking();
		bool exitParkingApp();
		bool loadDataFile();
		void saveDataFile();
	public:
		Parking();
		Parking(const char* filename);
		Parking(const Parking& other) = delete;
		Parking& operator=(const Parking& other) = delete;
		~Parking();
		int run();
		void setEmptystate();
	};
}
#endif // !PARKING_H
