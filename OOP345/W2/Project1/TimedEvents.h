//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:			Jan 27th 2020
// Workshop:       	2
//==============================================

#ifndef TIMEDEVENTS_H
#define TIMEDEVENTS_H
#include <iostream>
#include <chrono>
namespace sdds {
	const int maxRecord = 10;
	class TimedEvents {
	private:
		int numOfRecord = 0;
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point end;
		struct {
			const char* eventName;
			const char* unitOfTime;
			std::chrono::steady_clock::duration duration;
		} Event[maxRecord];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char*);
		void display(std::ostream& out) const;
		~TimedEvents();
	};
	std::ostream& operator<< (std::ostream&, const TimedEvents&);
}
#endif // !TIMEDEVENTS_H
