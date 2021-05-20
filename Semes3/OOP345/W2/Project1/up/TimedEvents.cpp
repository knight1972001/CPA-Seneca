//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:			Jan 27th 2020
// Workshop:       	2
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <string>
#include <iomanip>
#include "TimedEvents.h"

using namespace std;

namespace sdds {
	TimedEvents::TimedEvents() {
		static int numOfObjCreated = 0;
		numOfRecord = 0;
		Event->eventName = nullptr;
		Event->unitOfTime = nullptr;
		numOfObjCreated++;
	}

	void TimedEvents::startClock() {
		start = chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		end = chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* eventName) {
		static int numOfEvent = 0;
		Event[numOfEvent].eventName = eventName;
		Event[numOfEvent].unitOfTime = "nanosecond";
		Event[numOfEvent].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		numOfEvent++;
		numOfRecord++;
	}

	void TimedEvents::display(std::ostream& out) const {
		out << "--------------------------" << endl;
		out << "Execution Times:" << endl;
		out << "--------------------------" << endl;
		for (int i = 0; i < numOfRecord; i++) {
			out << setw(21) << left << Event[i].eventName << setw(13) << right << Event[i].duration.count() << " " << Event[i].unitOfTime << endl;
		}
		out << "--------------------------" << endl;
	}

	std::ostream& operator<<(std::ostream& out, const TimedEvents& t) {
		t.display(out);
		return out;
	}

	TimedEvents::~TimedEvents() {}
}