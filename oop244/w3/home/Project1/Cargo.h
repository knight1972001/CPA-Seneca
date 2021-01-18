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

namespace sdds {
	const int MAX_NAME = 30;
	const double MIN_WEIGHT = 44.2222;
	const double MAX_WEIGHT = 777.555;

	const int MAX_DESC = 20;

	class Cargo {
		char cargoName[MAX_DESC + 1];
		double weight;
	public:
		void initialize(const char* desc, double weight);
		const char* getDesc() const;
		double getWeight() const;
		void setDesc(const char* description);
		void setWeight(double weight);

	};
}
#endif // !_WS3_CARGO_H
