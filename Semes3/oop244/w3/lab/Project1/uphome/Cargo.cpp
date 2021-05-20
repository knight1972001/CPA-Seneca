//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    June 14th 2020
// Workshop:       	3 (Part 2)
//==============================================

#include"Cargo.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
namespace sdds {
	Cargo::Cargo() {
		this->cargoName[0] = '\0';
		this->weight = 0;
	}

	void Cargo::initialize(const char* desc, double weight) {
		if (desc == nullptr || desc[0] == '\0')
		{	
			this->weight = 0;
			this->cargoName[0] = '\0';
		}
		else
		{
			setDesc(desc);
			setWeight(weight);
		}
	}

	const char* Cargo::getDesc() const {
		return this->cargoName;
	}

	double Cargo::getWeight() const {
		return this->weight;
	}

	void Cargo::setDesc(const char* description) {
		cpyDesc(description, this->cargoName);
	}
	
	void Cargo::setWeight(double weight) {
		if (weight > MAX_WEIGHT)
		{
			this->weight = MIN_WEIGHT;
		}
		else {
			if (weight < MIN_WEIGHT)
			{
				this->weight = MIN_WEIGHT;
			}
			else {
				this->weight = weight;
			}
		}
		
	}
	int getDesc(const char* s1)
	{
		int i = 0;
		while (s1[i] != '\0')
		{
			i++;
		}
		return i;
	}

	void cpyDesc(const char* s1, char* s2)
	{
		int a = 0;
		a = getDesc(s1);
		if (a > MAX_DESC) {
			a = MAX_DESC;
		}
		for (int i = 0; i < a; i++)
		{
			s2[i] = s1[i];
			if (i + 1 == a)
			{
				s2[i + 1] = '\0';
			}
		}

	}

}