//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    June 10th 2020
// Workshop:       	3 (Part 1)
//==============================================

#include "Train.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
	Train::Train() {
		this->name[0] = '\0';
		this->id = 0;
		obj = nullptr;
	}

	void Train::initialize(const char* name, int id) {

		if (name == nullptr || name[0] == '\0' || id < 0)
		{
			this->id = 0;
			this->name[0] = '\0';
		}
		else
		{
			this->id = id;
			this->obj = nullptr;
			cpyString(name, this->name);
		}
	}

	bool Train::isValid() const {
		if (id < 0 || name[0] == '\0' || name == nullptr)
		{
			return false;
		}
		else return true;
	}

	void Train::loadCargo(Cargo car) {
		unloadCargo();
		obj = new Cargo[1];
		obj[0].weight = car.weight;
		cpyString(car.cargoName, obj[0].cargoName);
	}

	void Train::unloadCargo() {
		if (obj != nullptr)
		{
			delete[] obj;
			obj = nullptr;
		}
	}

	void Train::display() const {
		cout << "***Train Summary***" << endl;
		if (isValid())
		{
			cout << "Name: " << name << endl;
			cout << "ID: " << id << endl;
			if (obj == nullptr) {
				cout << "No cargo on this train." << endl;
			}
			else {
				cout << "Cargo: " << obj[0].cargoName << endl;
				cout << "Weight: " << obj[0].weight << endl;
			}
		}
		else {
			cout << "This is an invalid train." << endl;
		}
	}

	bool Train::swapCargo(Train& other) {

	}


	int getLength(const char* s1)
	{
		int i = 0;
		while (s1[i] != '\0')
		{
			i++;
		}
		return i;
	}

	void cpyString(const char* s1, char* s2)
	{
		int a = 0;
		a = getLength(s1);

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