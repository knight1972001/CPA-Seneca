//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    Aug 2nd 2020
// Workshop:       	MS4
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include "Utils.h"

using namespace std;

char* upperCase(char* plate) {
	int i = 0;
	while (plate[i]!='\0')
	{
		plate[i] = toupper(plate[i]);
		i++;
	}
	return plate;
}

bool compareChar(const char*s1, const char*s2) {
	bool check = false;
	
	if (strlen(s1) == strlen(s2)) {
		char* cloneS1 = new char[strlen(s1) + 1];
		char* cloneS2 = new char[strlen(s2) + 1];

		strcpy(cloneS1, s1);
		strcpy(cloneS2, s2);

		cloneS1 = upperCase(cloneS1);
		cloneS2 = upperCase(cloneS2);
		int count = strlen(s1);
		for (int i = 0; i < count; i++) {
			if (cloneS1[i] == cloneS2[i]) {
				check = true;
			}
			else {
				check = false;
				break;
			}
		}
		delete[] cloneS1;
		delete[] cloneS2;
	}
	else {
		check = false;
	}
	return check;
}

bool yn() {
	bool result = false;
	string option;
	int check = 0;
	do {
		cin >> option;
		cin.ignore(1000,'\n');
		if (option == "Y" || option == "y") {
			check = 1;
			result = true;
		}
		else {
			if (option == "N" || option == "n") {
				check = 0;
				result = false;
			}
			else {
				check = 2;
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}
		}
		
	} while (check == 2);
	return result;
}

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
	} while (check == 0);
	int back = atoi(input);
	return back;
}

int getIntRanger(int max, int min = 1) {
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

