//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 14th 2020
// Workshop:       	MS1
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Utils.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
namespace sdds {
	void Menu::setTitle(const char* title) {
		if (title != nullptr && title[0] != '\0') {
			this->title = new char[strlen(title)+1];
			strcpy(this->title, title);
		}
		else {
			this->title = nullptr;
		}
	}

	void Menu::setMenuItems(MenuItem* const Items[], int num) {
		if (num > 0) {
			if (num <= MAX_NO_OF_ITEMS) {
				menu_cnt = num;
			}
			else {
				menu_cnt = MAX_NO_OF_ITEMS;
			}
			for (int i = 0; i < menu_cnt; i++) {
				menuitems[i] = new MenuItem(Items[i]->content);
			}
		}
		else {
			for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
				menuitems[i] = nullptr;
			}
			menu_cnt = 0;
		}
	}

	void Menu::setIndentation(int indentation) {
		if (indentation > 0) {
			this->indentation = indentation;
		}
		else {
			this->indentation = 0;
		}
	}

	MenuItem::MenuItem() {
		content = nullptr;
	}

	MenuItem::MenuItem(const char* item) {
		if (item != nullptr && item[0] != '\0')
		{
			this->content = new char[strlen(item) + 1];
			strcpy(this->content, item);
		}
		else {
			this->content = nullptr;
		}
	}

	std::ostream& MenuItem::display() const {
		if (this->content != nullptr && this->content[0] != '\0') {
			cout << this->content << endl;
		}
		return cout;
	}

	MenuItem::~MenuItem() {
		if (this->content != nullptr) {
			delete[] this->content;
			this->content = nullptr;
		}
	}

	Menu::~Menu() {
		if (title != nullptr) {
			delete[] title;
			title = nullptr;
		}

		for (int i = 0; i < this->menu_cnt; i++) {
			if (menuitems != nullptr) {
				delete menuitems[i];
				menuitems[i] = nullptr;
			}
		}
	}

	Menu::Menu() {
		emptyMenu();
	}

	Menu::Menu(const char* title, int indentt) {
		setTitle(title);
		setMenuItems({ nullptr }, 0);
		setIndentation(indentt);
	}

	Menu::Menu(const Menu& other) {
		setTitle(other.title);
		setMenuItems(other.menuitems, other.menu_cnt);
		setIndentation(other.indentation);
	}

	Menu& Menu::operator=(const Menu& other) {
		if (this != &other) {
			delete[] this->title;

			for (int i = 0; i < this->menu_cnt; i++) {
				delete menuitems[i];
				menuitems[i] = nullptr;
			}
			if (other.title != nullptr && other.title[0] != '\0') {
				this->title = new char[strlen(other.title) + 1];
				strcpy(this->title, other.title);
			}
			else {
				this->title = nullptr;
			}
			if (other.menu_cnt > 0 && other.menu_cnt <= MAX_NO_OF_ITEMS) {
				this->menu_cnt = other.menu_cnt;
				for (int i = 0; i < this->menu_cnt; i++) {
					this->menuitems[i] = new MenuItem(other.menuitems[i]->content);
				}
			}
			else {
				for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
					this->menuitems[i] = nullptr;
				}
				this->menu_cnt = 0;
			}
			if (other.indentation > 0) {
				this->indentation = other.indentation;
			}
			else {
				this->indentation = 0;
			}
		}

		return *this;
	}

	void Menu::emptyMenu() {
		setTitle(nullptr);
		setMenuItems({ nullptr }, 0);
		setIndentation(0);
	}

	Menu::operator bool() const {
		if (this->title != nullptr && this->title[0] != '\0' && this->menu_cnt > 0) {
			return true;
		}
		else { return false; }
	}

	bool Menu::isEmpty() const {
		if (this->title == nullptr) {
			return true;
		}
		else { return false; }
	}

	std::ostream& Menu::display() const {
		if (isEmpty()) {
			cout << "Invalid Menu!" << endl;
		}
		else {
			int space = this->indentation * 4;
			cout << setw(space) << right << "" << this->title << endl;


			if (this->menu_cnt > 0) {
				for (int i = 0; i < this->menu_cnt; i++) {
					cout << setw(space) << right << "" << i + 1 << "- ";

					this->menuitems[i]->display();
				}
				cout << setw(space) << right << "" << "> ";
			}
			else {
				cout << "No Items to display!" << endl;
			}
		}

		return cout;
	}


	Menu& Menu::operator=(const char* title) {
		if (title != nullptr && title[0] != '\0') {

			if (this->title != nullptr) {
				delete[] this->title;
				this->title = nullptr;
			}

			this->title = new char[strlen(title) + 1];
			strcpy(this->title, title);
		}
		return *this;
	}

	void Menu::add(const char* content) {
		if (!isEmpty()) {
			if (menu_cnt < MAX_NO_OF_ITEMS) {
				if (content != nullptr && content[0] != '\0') {
					menuitems[menu_cnt] = new MenuItem(content);
					menu_cnt++;
				}
				else {
					delete[] title;
					title = nullptr;
					for (int i = 0; i < menu_cnt; i++) {
						delete menuitems[i];
						menuitems[i] = nullptr;
					}
					emptyMenu();
				}
			}
		}
	}

	Menu& Menu::operator<<(const char* title) {
		add(title);
		return *this;
	}

	int Menu::run() const {
		this->display();
		int input = 0;
		if (this->menuitems[0] != nullptr) {
			input = getIntRanger(this->menu_cnt, 1);
		}
		return input;
	}

	Menu::operator int() const {
		return run();
	}

}