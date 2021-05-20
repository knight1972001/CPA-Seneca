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
#include "Car.h"
#include "Motorcycle.h"

namespace sdds {
	class Parking : public Menu{
	private:
		char *filename;
		int numOfSpot;
		Vehicle* parkingSpot[100];
		int numOfParked;
		Menu mainmenu;
		Menu submenu1;
		bool closed;
		bool isEmpty() const;
		void parkingStatus() const;
		void parkVehicle();
		void returnVehicle();
		void listParkedVehicle();
		bool closeParking();
		bool exitParkingApp();
		bool loadDataFile();
		void saveDataFile() const ;
	public:
		using Menu::Menu;
		Parking();
		Parking(const char* filename, int numOfSpot);
		Parking(const Parking& other) = delete;
		Parking& operator=(const Parking& other) = delete;
		~Parking();
		int run();
		void setEmptystate();
	};
}
#endif // !PARKING_H
