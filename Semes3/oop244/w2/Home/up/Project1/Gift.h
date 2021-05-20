//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    June 7th 2020
// Workshop:       	2 (Part 2)
//==============================================
#ifndef _WS2_GIFT_H
#define _WS2_GIFT_H
namespace sdds {
	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.999;
	const int MAX_WRAP = 20;
	
	struct Gift
	{
		char m_description[MAX_DESC];
		double m_price = 0;
		int m_units = 0;
		int m_wrapLayers=0;
		struct Wrapping* m_wrap=nullptr;
	/*public:
		void getName(const char* p, char*& moi);*/
	};
	void getName(const char* p, Gift& theGift, int num);
	struct Wrapping 
	{
		char* m_pattern;
	};
	int getLength(const char* cp);
	void cpyString(const char* cp, char*& cref);

	void gifting(char* desc);
	void gifting(double& price);
	void gifting(int& units);
	double getNum(double min, double max);
	void display(const Gift& theGift);
	bool wrap(Gift& theGift);
	bool unwrap(Gift& theGift);
	void gifting(Gift& theGift);
	void inputWrapLayer(int& num);


}
#endif // _WS2_GIFT_H
