//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    June 7th 2020
// Workshop:       	2 (Part 2)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>
#include "Gift.h"

using namespace std;

namespace sdds {
	void gifting(char* desc)
	{
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> desc;
		cin.ignore(2000, '\n');

	}
	void gifting(double& price)
	{
		price = getNum(0, MAX_PRICE);
	}

	void gifting(int& units)
	{
		bool done = false;
		while (!done) {
			cout << "Enter gift units: ";
			cin >> units;
			if (cin.fail()) {
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

	double getNum(double min, double max) {
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

	void display(const Gift& theGift)
	{
		cout << "Gift Details:" << endl;
		cout << " Description: " << theGift.m_description << endl;
		cout << "       Price: " << theGift.m_price << endl;
		cout << "       Units: " << theGift.m_units << endl;
		if (theGift.m_wrapLayers == 0)
		{
			cout << "Unwrapped!" << endl;
		}else
		{
			cout << "Wrap Layers: " << theGift.m_wrapLayers << endl;
			for (int i = 0; i < theGift.m_wrapLayers; i++)
			{
				cout << "Wrap #" << i + 1 << " -> " << theGift.m_wrap[i].m_pattern << endl;
			}
		}
		
		
	}
	
	void getName(const char* p, Gift& theGift, int num) {
		
		theGift.m_wrap[num].m_pattern = nullptr;
		cpyString(p, theGift.m_wrap[num].m_pattern);

		/*theGift.m_wrap->m_pattern = nullptr;
		cpyString(p, theGift.m_wrap->m_pattern);*/
	}

	//////////////////
	bool wrap(Gift& theGift) {
		if (theGift.m_wrapLayers == 0)
		{
			char pattern[50];
			cout << "Wrapping gifts..." << endl;

			do {
				cout << "Enter the number of wrapping layers for the Gift: ";
				inputWrapLayer(theGift.m_wrapLayers);

				if (theGift.m_wrapLayers < 1)
				{
					cout << "Layers at minimum must be 1, try again." << endl;
				}
			} while (theGift.m_wrapLayers < 1);

			theGift.m_wrap = new Wrapping[theGift.m_wrapLayers];

			for (int i = 0; i < theGift.m_wrapLayers; i++)
			{
				cout << "Enter wrapping pattern #" << i + 1 << ": ";
				cin >> pattern;
				cin.ignore(2000, '\n');
				getName(pattern, theGift, i);
				
				//getName(pattern, theGift);
			}

			return true;
		}
		else
		{
			cout << "Gift is already wrapped!" << endl;
			return false;
		}
	}

	bool unwrap(Gift& theGift) {
		if (theGift.m_wrapLayers != 0)
		{
			cout << "Gift being unwrapped." << endl;
			delete[]theGift.m_wrap->m_pattern;
			theGift.m_wrap->m_pattern = nullptr;
			delete[]theGift.m_wrap;
			theGift.m_wrap = nullptr;
			theGift.m_wrapLayers = 0;
			return true;
		}
		else {
			cout << "Gift isn't wrapped! Cannot unwrap." << endl;
			return false;
		}
	}

	void gifting(Gift& theGift) {
		cout << "Preparing a gift..." << endl;
		gifting(theGift.m_description);
		gifting(theGift.m_price);
		gifting(theGift.m_units);
		wrap(theGift);
	}

	int getLength(const char* cp) {
		int i = 0;
		while (cp[i] != '\0') {
			i++;
		}
		return i;
	}

	void cpyString(const char* cp, char*& cref) 
	{
		if (cref != nullptr) {
			delete[] cref;
		}
		cref = new char[getLength(cp) + 1];
		int a = getLength(cp);
		for (int i = 0; i < a; i++)
		{
			cref[i] = cp[i];
			if (i + 1 == a)
			{
				cref[i + 1] = '\0';
			}
		}

	}

	void inputWrapLayer(int& num)
	{
		bool done = false;
		while (!done)
		{
			cin >> num;
			if (cin.fail())
			{
				cin.clear();
				cout << "Invalid Integer, try again: ";
			}
			else {
				done = true;
			}
		}
	}
	
}