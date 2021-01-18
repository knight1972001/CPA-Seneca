#ifndef EVENT_H
#define EVENT_H

extern size_t g_sysClock;

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
