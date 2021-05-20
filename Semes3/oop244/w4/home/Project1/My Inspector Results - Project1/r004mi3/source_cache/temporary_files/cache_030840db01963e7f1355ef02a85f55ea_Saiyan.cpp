//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    June 19th 2020
// Workshop:       	4 (Part 2)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include "Saiyan.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
namespace sdds {

	Saiyan::Saiyan() {
		this->m_name = nullptr;
		this->m_level = 0;
		this->m_dob = 0;
		this->m_power = 0;
		this->m_super = false;
	}

	Saiyan::Saiyan(const char* name, int dob, int power, int level, bool super) {
		if (name != nullptr && dob <= 2020 && power >= 0 && level >=0)
		{
			this->m_name = nullptr;
			this->m_level = 0;
			this->m_dob = 0;
			this->m_power = 0;
			this->m_super = false;
			if (strlen(name) > 0)
			{
				set(name, dob, power,level,super);
			}
		}
		else {
			this->m_name = nullptr;
			this->m_level = 0;
			this->m_dob = 0;
			this->m_power = 0;
			this->m_super = false;
		}
	}

	void Saiyan::set(const char* name, int dob, int power, int level, bool super) {
		
		int a = strlen(name) + 1;
		this->m_name = new char[a];
		strcpy(this->m_name, name);
		this->m_level = level;
		this->m_dob = dob;
		this->m_power = power;
		this->m_super = super;
	}

	bool Saiyan::isValid() const {
		if (this->m_name!=nullptr && this->m_dob != 0 && this->m_power != 0 && this->m_level>=0)
		{
			return true;
		}
		else return false;
	}

	void Saiyan::display() const {
		if (isValid())
		{
			cout << this->m_name << endl;
			cout << right <<setw(10) << "DOB: " << this->m_dob << endl;
			cout << right << setw(10) << "Power: " << this->m_power << endl;
			if (this->m_super)
			{
				cout << right << setw(10) << "Super: " << "yes" << endl;
				cout << right << setw(10) << "Level: " << this->m_level << endl;
			}
			else {
				cout << right << setw(10) << "Super: " << "no" << endl;
			}
		}
		else {
			cout << "Invalid Saiyan!" << endl;
		}
	}
	

	bool Saiyan::fight(Saiyan& other) {
		if (this->isValid() && other.isValid())
		{
			if (this->m_super == true)
			{
				
					this->m_power *= (1+0.1*this->m_level);
			}
			if (other.m_super == true)
			{
				for (int i = 0; i < other.m_level; i++)
				{
					other.m_power *= (1 + 0.1 * other.m_level);
				}
			}

			if (this->m_power > other.m_power)
			{
				return true;
			}
			else {
				return false;
			}
		}
		else {
			cout << "Invalid Saiyan!" << endl;
			return false;
		}
		
	}
	Saiyan::~Saiyan() {
		if (this->m_name != nullptr)
		{
			delete[] this->m_name;
			this->m_name = nullptr;
		}
	}
}