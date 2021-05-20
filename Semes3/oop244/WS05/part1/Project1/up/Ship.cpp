//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    June 23th 2020
// Workshop:       	5 (Part 1)
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include "Ship.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
	Ship::Ship() {
		this->m_type[0] = '\0';
		this->m_engCnt = 0;
		this->m_power = 0;
	}

	Ship::Ship(const char* type, const Engine* engine, const int engcnt) {
		this->m_type[0] = '\0';
		this->m_engCnt = 0;
		this->m_power = 0;
		if (type != nullptr && strlen(type) > 0 && engine != nullptr && engcnt > 0)
		{
			strcpy(this->m_type, type);
			for (int i = 0; i < engcnt; i++)
			{
				this->m_engines[i] = engine[i];
				this->m_power = this->m_power + engine[i].get()*5;
			}
			this->m_engCnt = engcnt;
		}
		else {
			this->m_type[0] = '\0';
			this->m_engCnt = 0;
			this->m_power = 0;
		}
	}

	Ship& Ship::operator+=(Engine engine) {
		if (this->m_engCnt != 0 && this->m_engines != nullptr && this->m_type != nullptr && strlen(this->m_type) > 0)
		{
			this->m_engines[this->m_engCnt++] = engine;
			this->m_power = this->m_power + engine.get()*5;
			return *this;
		}
		else {
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}
		return *this;
	}

	bool Ship::operator<(double power) const {
		if (this->m_power < power)
		{
			return true;
		}
		else {
			return false;
		}
	}

	void Ship::display() const {
		if (this->m_type != nullptr && this->m_power != 0 && this->m_engCnt > 0)
		{
			cout << this->m_type << " - " << this->m_power << endl;
		}else{
			cout << "No available data" << endl;
		}

		for (int i = 0; i < this->m_engCnt; i++)
		{
			this->m_engines[i].display();
		}
	}

	bool operator<(double power, const Ship& theShip) {
		if (power < theShip.getPower())
		{
			return true;
		}
		else {
			return false;
		}
	}
	double Ship::getPower() const {
		return this->m_power;
	}

}
