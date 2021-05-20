//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    June 17th 2020
// Workshop:       	4 (Part 1)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include "Saiyan.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {

	Saiyan::Saiyan() {
		this->m_name[0] = '\0';
		this->m_dob = 0;
		this->m_power = 0;
		this->m_super = false;
	}

	Saiyan::Saiyan(const char* name, int dob, int power) {
		if (name != nullptr && dob <= 2020 && power >= 0)
		{
			if (strlen(name) > 0)
			{
				set(name, dob, power);
			}
			else {
				this->m_name[0] = '\0';
				this->m_dob = 0;
				this->m_power = 0;
				this->m_super = false;
			}
		}
		else {
			this->m_name[0] = '\0';
			this->m_dob = 0;
			this->m_power = 0;
			this->m_super = false;
		}
	}

	void Saiyan::set(const char* name, int dob, int power, bool super) {
		strcpy(this->m_name, name);
		this->m_dob = dob;
		this->m_power = power;
		this->m_super = super;
	}

	bool Saiyan::isValid() const {
		if (this->m_name[0] != '\0' && this->m_dob!=0 && this->m_power!=0)
		{
			return true;
		}
		else return false;
	}

	void Saiyan::display() const {
		if (isValid())
		{
			cout << this->m_name << endl;
			cout << "DOB: " << this->m_dob << endl;
			cout << "Power: " << this->m_power << endl;
			if (this->m_super)
			{
				cout << "Super: yes" << endl;
			}
			else {
				cout << "Super: no" << endl;
			}

		}
		else {
			cout << "Invalid Saiyan!" << endl;
		}
	}

	bool Saiyan::fight(const Saiyan& other) const {
		if (this->m_power > other.m_power)
		{
			return true;
		}
		else {
			return false;
		}
	}
}