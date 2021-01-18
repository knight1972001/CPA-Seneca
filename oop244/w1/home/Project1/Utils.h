//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			May 28th 2020
// Workshop:       	1 (Part 2)
//==============================================
#ifndef _PART2_UTILS_H
#define _PART2_UTILS_H
 // !_PART2_UTILS_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

namespace intFunc {
	void clear(void);
	int getInt(void);
	int getIntInRange(int min, int max);
	int checkAvoidNum(char input[]);
	float average(int input[], int num);
	void sort(int input[], int num);
	void display(int input[], int num);
	int checkPass(int input[], int num);
}
#endif