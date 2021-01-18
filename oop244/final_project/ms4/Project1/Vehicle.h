//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    Aug 2nd 2020
// Workshop:       	MS4
//==============================================
#ifndef VEHICLE_H
#define VEHICLE_H
#include "ReadWritable.h"
#include "Utils.h"
namespace sdds {
	class Vehicle : public ReadWritable {
	private:
		char license[9];
		char* makenModel;
		int parkingNum;
	public:
		Vehicle();
		Vehicle(const char*, const char*, int parkingNum = 0);
		Vehicle(const Vehicle& a) = delete;
		Vehicle& operator=(const Vehicle& b) = delete;
		~Vehicle();
		int getParkingSpot() const;
		void setParkingSpot(const int num);
		std::istream& read(std::istream& in = std::cin);
		std::ostream& write(std::ostream& out = std::cout) const;
		friend bool operator==(const Vehicle&, const char*);
		friend bool operator==(const Vehicle&, const Vehicle&);
	protected:
		void setEmpty();
		bool isEmpty() const;
		const char* getLicensePlate();
		const char* getMakeModel();
		void setMakeModel(const char*);

	};
	
}


#endif // !VEHICLE_H
