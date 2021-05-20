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
#define MAX_DESC 15
#define MAX_PRICE 999.999

#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
namespace sdds {
	struct Gift
	{
		char description[MAX_DESC];
		double price = 0;
		int unit = 0;
	};
	void gifting(char* desc);
	void gifting(double& price);
	void gifting(int& units);
	double getNum(double min, double max);
	void display(const Gift& theGift);
}
#endif // _WS2_GIFT_H
