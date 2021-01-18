//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    June 10th 2020
// Workshop:       	3 (Part 1)
//==============================================

#ifndef _WS3_TRAIN_H
#define _WS3_TRAIN_H
#include "Cargo.h"
namespace sdds {
	class Train {
		char name[MAX_DESC + 1];
		int id = 0;
		struct Cargo *obj=nullptr;
	public:
		Train();
		void initialize(const char* name, int id);
		bool isValid() const;
		void loadCargo(Cargo car);
		void unloadCargo();
		void display() const;	
	};
	void cpyString(const char* cp, char* cref);
	int getLength(const char* cp);
	
	

	
}


#endif // !_WS3_TRAIN_H
