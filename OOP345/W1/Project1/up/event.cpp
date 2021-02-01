//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:			    Jan 20th 2020
// Workshop:       	1
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

unsigned int g_sysClock;

namespace sdds {
	Event::Event() {
		this->time = 0;
		this->description[0] = '\0';
	}

	Event::Event(const char* description, const int time) {
		strcpy(this->description, description);
		this->time = time;
	}

	bool Event::isEmpty() {
		if (description[0] == '\0' || description == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	void Event::display() {
		static int counter = 1;
		int hour = 0, min = 0, second = 0;

		if (isEmpty()) {
			cout << setfill(' ') << setw(2) << counter << ". " << "| No Event |" << endl;
		}
		else {
			hour = time / 3600;
			min = time / 60 % 60;
			second = time % 60;
			cout << setfill(' ') << setw(2) << counter << ". " << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << min << ":" << setfill('0') << setw(2) << second << " => " << description << endl;
		}

		counter++;
	}

	void Event::set(char* description) {
		if (description != nullptr && description[0] != '\0') {
			this->description[0] = '\0';
			strcpy(this->description, description);
			time = g_sysClock;
		}
		else {
			this->description[0] = '\0';
			time = 0;
		}
	}

	void Event::set() {
		this->description[0] = '\0';
		time = 0;
	}
}