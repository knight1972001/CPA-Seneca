//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    June 3rd 2020
// Workshop:       	2 (Part 1)
//==============================================
#ifndef _WS2_GIFT_H
#define _WS2_GIFT_H


namespace sdds {
#define MAX_DESC 15
#define MAX_PRICE 999.999
#define MAX_WRAP 20
	struct Gift
	{
		char m_description[MAX_DESC];
		double m_price = 0;
		int m_units = 0;
		class Wrapping
		{
			char* m_pattern;
		};
		Wrapping* m_wrap;
		int* m_wrapLayers;
	public:
		void gifting(char* desc);
		void gifting(double& price);
		void gifting(int& units);
		double getNum(double min, double max);
		void display(const Gift& theGift);
		bool wrap(Gift& theGift);
		bool unwrap(Gift& theGift);
		void gifting(Gift& theGift);
		//void display(const Gift& theGift);

	};
}
#endif // _WS2_GIFT_H
