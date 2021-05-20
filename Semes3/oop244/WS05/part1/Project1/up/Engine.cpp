//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    June 23th 2020
// Workshop:       	5 (Part 1)
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include "Engine.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
	Engine::Engine() {
		this->m_size = 0;
		this->m_type[0] = '\0';
	}

	Engine::Engine(const char* type, const double size) {
		if (type != nullptr && type[0] != '\0')
		{
			this->m_size = size;
			strcpy(this->m_type, type);
		}
		else
		{
			this->m_size = 0;
			this->m_type[0] = '\0';
		}
	}

	double Engine::get() const {
		return this->m_size;
	}

	void Engine::display() const {
		cout << this->m_size << " liters - " << this->m_type << endl;
	}
}