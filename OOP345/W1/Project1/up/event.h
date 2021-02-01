//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:			    Jan 20th 2020
// Workshop:       	1
//==============================================
#ifndef EVENT_H
#define EVENT_H
#include <cstddef>

extern unsigned int g_sysClock;

namespace sdds {
	class Event {
	private:
		char description[128];
		int time;
	public:
		Event();
		Event(const char*, const int);
		void display();
		void set(char*);
		void set();
		bool isEmpty();
	};
}
#endif
