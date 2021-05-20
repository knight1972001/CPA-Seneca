#include "Utils.h"
//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 14th 2020
// Workshop:       	MS1
//==============================================
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
int getInt() {
	char input[10];
	int check = 0;

	do
	{
		check = 0;
		cin >> input;
		cin.ignore(1000, '\n');
		int size = strlen(input);
		for (int i = 0; i < size; i++) {
			if (isdigit(input[i])) {
				check = 1;
			}
			else {
				check = 0;
				cout << "Invalid Integer, try again: ";
				break;
			}
		}
	} while (check==0);
	int back = atoi(input);
	return back;
}

int getIntRanger(int max, int min=1) {
	int menu = 0;
	do
	{
		menu = getInt();
		if (menu > max || menu < min)
		{
			cout << "Invalid selection, try again: ";
		}
	} while (menu > max || menu < min);
	return menu;
}