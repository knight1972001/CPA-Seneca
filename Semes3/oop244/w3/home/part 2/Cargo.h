//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    June 10th 2020
// Workshop:       	3 (Part 1)
//==============================================

#ifndef _WS3_CARGO_H
#define _WS3_CARGO_H

const int MAX_NAME = 30;

namespace sdds {
	const int MAX_DESC = 20;

	struct Cargo {
		char cargoName[MAX_DESC + 1];
		double weight;
	};
}
#endif // !_WS3_CARGO_H
