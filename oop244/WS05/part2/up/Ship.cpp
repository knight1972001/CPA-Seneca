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
#include <iomanip>
using namespace std;
namespace sdds {
	Ship::Ship() {
		this->m_type = nullptr;
		this->m_engines = nullptr;
		this->m_engCnt = 0;
		this->m_power = 0;
	}

	Ship::Ship(const char* type, const Engine* engine, const int engcnt) {
		/*if (this->m_type != nullptr)
		{
			delete[] this->m_type;
			this->m_type = nullptr;
		}
		if (this->m_engines != nullptr)
		{
			delete[] this->m_engines;
			this->m_engines = nullptr;
		}*/
		this->m_type = nullptr;
		this->m_engCnt = 0;
		this->m_power = 0;
		if (type != nullptr && strlen(type) > 0 && engine != nullptr && engcnt > 0)
		{
			this->m_type = new char[strlen(type)+1];
			strcpy(this->m_type, type);
			this->m_engines = new Engine[engcnt];
			for (int i = 0; i < engcnt; i++)
			{
				this->m_engines[i] = engine[i];
			}
			this->m_engCnt = engcnt;
			setPower();
			
		}
		else {
			this->m_type = nullptr;
			this->m_engines = nullptr;
			this->m_engCnt = 0;
			this->m_power = 0;
		}
	}

	Ship::operator bool() const {
		if (this->m_type != nullptr && this->m_power != 0 && this->m_engCnt > 0 && this->m_engines!=nullptr)
		{
			return true;
		}
		else {
			return false;
		}
	}

	Ship& Ship::operator+=(Engine engine) {
		if (this->m_engCnt != 0 && this->m_engines != nullptr && this->m_type != nullptr && strlen(this->m_type) > 0)
		{
			Engine* temp;
			temp = new Engine[this->m_engCnt];

			for (int i = 0; i < this->m_engCnt; i++) {
				temp[i] = this->m_engines[i];
			}
			int count = this->m_engCnt + 1;
			if (this->m_engines != nullptr)
			{
				delete[] this->m_engines;
				this->m_engines = nullptr;
			}
			this->m_engines = new Engine[count];
			for (int i = 0; i < this->m_engCnt; i++) {
				this->m_engines[i] = temp[i];
			}
			this->m_engCnt++;
			this->m_engines[count-1] = engine;
			setPower();
			if (temp != nullptr) {
				delete[] temp;
				temp = nullptr;
			}
			return *this;
		}
		else {
			cout << "The object is not valid! Engine cannot be added!" << endl;
			return *this;
		}

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
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << this->m_type << " - " << setw(6) << this->m_power << endl;
			cout.unsetf(ios::fixed);
			cout.precision(6);
		}
		else {
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
	void Ship::setPower() {
		this->m_power = 0;
		for (int i = 0; i < this->m_engCnt; i++)
		{
			this->m_power = this->m_power + this->m_engines[i].get();
		}
		this->m_power = this->m_power * 5;
	}
	double Ship::getPower() const {
		return this->m_power;
	}
	Ship::~Ship() {
		if (this->m_engines != nullptr)
		{
			delete[] this->m_engines;
			this->m_engines = nullptr;
		}
		if (this->m_type != nullptr)
		{
			delete[] this->m_type;
			this->m_type = nullptr;
		}

	}
}
