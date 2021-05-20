//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 14th 2020
// Workshop:       	MS1
//==============================================
#ifndef _MENU_H
#define _MENU_H
#include "Utils.h"
#include <iostream>


namespace sdds {
	const int MAX_NO_OF_ITEMS = 10;
	class Menu;

	class MenuItem {
	private:
		char* content;
	public:
		MenuItem();
		MenuItem(const char* item);
		MenuItem(const MenuItem& itemSrc) = delete;
		MenuItem& operator=(const MenuItem& itemSrc) = delete;
		std::ostream& display() const;
		~MenuItem();
		friend class Menu;
	};

	class Menu {
	private:
		char* title;
		MenuItem* menuitems[MAX_NO_OF_ITEMS];
		int menu_cnt;
		int indentation;
	public:
		Menu();
		Menu(const char*, int indentt=0);
		Menu(const Menu& other);
		~Menu();
		Menu& operator=(const Menu& other);
		explicit operator bool() const;
		bool isEmpty() const;
		std::ostream& display() const;
		Menu& operator=(const char*);
		void add(const char*);
		Menu& operator<<(const char*);
		void emptyMenuItem();
		int run() const;
		operator int() const;
	};
}
#endif // !_MENU_H
