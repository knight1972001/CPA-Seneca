//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 26th 2020
// Workshop:       	9 (Part 1)
//==============================================
#ifndef _VALIDATE_H
#define _VALIDATE_H
#include "Employee.h"
#include "Student.h"
#include "validate.h"
#include <iostream>

template<class T, class U> 
bool validate(const T& minimum, const U& value, int num, bool* result) {
	int a = 0;
	for (int i = 0; i < num; i++) {
		if (value[i] >= minimum) {
			result[i] = true;
		}
		else {
			result[i] = false;
		}
	}
	for (int i = 0; i < num; i++) {
		if (result[i]) {
			a = 1;
		}
		else {
			a = 0;
			break;
		}
	}
	if (a == 1) {
		return true;
	}
	else {
		return false;
	}
	
}

#endif // !



