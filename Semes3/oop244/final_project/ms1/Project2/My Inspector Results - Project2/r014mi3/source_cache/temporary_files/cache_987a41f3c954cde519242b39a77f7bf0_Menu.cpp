#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Utils.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
namespace sdds {
	MenuItem::MenuItem(){
		content = nullptr;
	}

	MenuItem::MenuItem(const char* item){
		if (item != nullptr && item[0] != '\0')
		{
			if (this->content != nullptr) {
				delete[] this->content;
				this->content = nullptr;
			}
			this->content = new char[strlen(item)+1];
			strcpy(this->content, item);
		}
		else {
			this->content = nullptr;
		}
	}

	std::ostream& MenuItem::display() const{
		if (this->content != nullptr && this->content[0] != '\0') {
			cout << this->content << endl;
		}
		return cout;
	}

	MenuItem::~MenuItem(){
		if (this->content != nullptr) {
			delete[] this->content;
			this->content = nullptr;
		}

		cout << endl;
		cout << "DA XOA MENUITEM" << endl;
	}

	Menu::~Menu() {
		if(this->title!=nullptr){
			delete[] this->title;
			this->title = nullptr;
		}
			
		for (int i = 0; i < this->menu_cnt; i++) {
			if (this->menuitems != nullptr) {
				delete this->menuitems[i];
				this->menuitems[i] = nullptr;
			}
		}
		cout << endl;
		cout << "DA XOA MENU" << endl;
	}

	Menu::Menu(){
		this->title = nullptr;
		this->indentation = 0;
		emptyMenuItem();
	}

	Menu::Menu(const char* title, int indentt){
		if (title != nullptr && title[0] != '\0' && indentt >= 0 && indentt <= 4) {
			
			if (this->title != nullptr) {
				delete[] this->title;
				this->title = nullptr;
			}

			this->title = new char[strlen(title) + 1];
			strcpy(this->title, title);
			this->indentation = indentt;
			emptyMenuItem();
		}
		else {
			this->title = nullptr;
			this->indentation = 0;
			emptyMenuItem();
		}
	}

	Menu::Menu(const Menu& other){
		if (other.title != nullptr && other.title[0] != '\0' && other.indentation >= 0 && other.indentation <= 4) {
			
			this->title = nullptr;
			delete[] this->title;
			this->title = nullptr;

			this->title = new char[strlen(other.title) + 1];
			strcpy(this->title, other.title);

			this->indentation = other.indentation;

			if (other.menu_cnt > 0 && other.menu_cnt <= MAX_NO_OF_ITEMS) {
			
				this->menu_cnt = other.menu_cnt;

				for (int i = 0; i < this->menu_cnt; i++) {
					this->menuitems[i] = new MenuItem(other.menuitems[i]->content);
				}
			}
		}
		else {
			this->title = nullptr;
			this->indentation = 0;
			emptyMenuItem();
		}
	}

	Menu& Menu::operator=(const Menu& other){
		if (other.title != nullptr && other.title[0] != '\0' && other.indentation >= 0 && other.indentation <= 4)
		{
			delete[] this->title;
			this->title = nullptr;
			for (int i = 0; i < this->menu_cnt; i++) {
				delete this->menuitems[i];
				this->menuitems[i] = nullptr;
			}

			this->title = new char[strlen(other.title) + 1];
			strcpy(this->title, other.title);
			

			if (other.menu_cnt > 0 && other.menu_cnt <= MAX_NO_OF_ITEMS) {

				this->menu_cnt = other.menu_cnt;
				for (int i = 0; i < this->menu_cnt; i++) {
					this->menuitems[i] = new MenuItem(other.menuitems[i]->content);
				}
				this->indentation = other.indentation;
			}
			else {
				emptyMenuItem();
			}
		}
		else {
			this->title = nullptr;
			this->indentation = 0;
			emptyMenuItem();
		}
		return *this;
	}

	void Menu::emptyMenuItem(){
		for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
			if (this->menuitems[i] != nullptr) {
				delete this->menuitems[i];
			}
			this->menuitems[i] = nullptr;
		}
		this->menu_cnt = 0;
	}

	Menu::operator bool() const{
		if (this->title != nullptr && this->title[0] != '\0' && this->menu_cnt > 0) {
			return true;
		}
		else { return false; }
	}

	bool Menu::isEmpty() const{
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
			cout << setw(space) << right <<""<< this->title << endl;


			if (this->menu_cnt>0) {
				for (int i = 0; i < this->menu_cnt; i++) {
					cout << setw(space) << right << i + 1 << "- ";

					this->menuitems[i]->display();
				}
				cout << "> ";
			}
			else {
				cout << "No Items to display!" << endl;
			}
		}

		return cout;
	}


	Menu& Menu::operator=(const char* title){
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
			if (this->menu_cnt < MAX_NO_OF_ITEMS) {
				if (content != nullptr && content[0] != '\0') {
					this->menuitems[this->menu_cnt] = new MenuItem(content);
					this->menu_cnt++;
				}
				else {
					delete[] this->title;
					this->title = nullptr;
					for (int i = 0; i < this->menu_cnt; i++) {
						delete this->menuitems[i];
						this->menuitems[i] = nullptr;
					}
					this->title = nullptr;
					this->indentation = 0;
					emptyMenuItem();
				}
			}
		}
	}

	Menu& Menu::operator<<(const char* title){
		add(title);
		return *this;
	}

	int Menu::run() const{
		this->display();
		int input = 0;
		if (this->menuitems[0] != nullptr) {
			input = getIntRanger(this->menu_cnt, 1);
		}
		return input;
	}

	Menu::operator int() const{
		return run();
	}

}