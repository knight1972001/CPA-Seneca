//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    June 3rd 2020
// Workshop:       	2 (Part 1)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
#include "Gift.h"

using namespace std;
using namespace sdds;

	void Gift::display(const Gift& theGift)
	{
		cout << "Gift Details:" << endl;
		cout << " Description: " << theGift.m_description << endl;
		cout << "       Price: " << theGift.m_price << endl;
		cout << "       Units: " << theGift.m_units << endl;
		cout << endl;
	}

	void gifting(char* desc)
	{
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> desc;
	}
	void Gift::gifting(double& price)
	{
		price = getNum(0, MAX_PRICE);
	}

	void Gift::gifting(int& units)
	{
		bool done = false;
		while (!done) {
			cout << "Enter gift units: ";
			cin >> units;
			if (cin.fail()) 
			{
				cin.clear();
				cout << "Invalid Integer, try again: ";
			}
			else {
				if (units < 1) {
					cout << "Gift units must be at least 1" << endl;
				}
				else {
					done = true;
				}
			}
		}
	}

	double Gift::getNum(double min, double max) {
		double val;
		bool done = false;
		while (!done) {
			cout << "Enter gift price: ";
			cin >> val;
			if (cin.fail()) {
				cin.clear();
				cout << "Invalid Integer, try again: ";
			}
			else {
				if (val < min || val > max) {
					cout << "Gift price must be between " << min << " and " << max << endl;
				}
				else {
					done = true;
				}
			}
		}
		return val;
	}

	bool Gift::wrap(Gift& theGift) {
		return 0;
	}


	bool Gift::unwrap(Gift& theGift) {
		return 0;

	}

	void Gift::gifting(Gift& theGift) {

	}

	void Gift::display(const Gift& theGift) {

	}
