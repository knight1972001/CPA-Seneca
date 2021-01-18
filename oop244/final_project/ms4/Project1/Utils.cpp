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

