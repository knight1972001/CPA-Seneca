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
		this->countCargo = 0;
		obj = nullptr;
	}

	void Train::initialize(const char* name, int id) {		
		
		if (name == nullptr || name[0] == '\0' || id < 0)
		{
			this->id = 0;
			this->countCargo = 0;
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
		if (id < 0 || name[0] == '\0' || name==nullptr)
		{
			return false;
		}
		else return true;
	}

	void Train::loadCargo(Cargo car) {
		/*class Cargo tempCargo[50] = {};
		if (obj != nullptr) {
			for (int i = 0; i < this->countCargo; i++)
			{
				tempCargo[i] = obj[i];
			}
			this->countCargo += 2;
		}
		else {
			this-> countCargo += 1;
		}*/
		
		unloadCargo();
		/*int temp = this->countCargo-1;*/
		//obj = new Cargo[this->countCargo];
		obj = new Cargo[1];
		obj[0].setWeight(car.getWeight());
		obj[0].setDesc(car.getDesc());

		/*for (int i = temp; i < this->countCargo; i++)
		{
			obj[i].setWeight(car.getWeight());
			obj[i].setDesc(car.getDesc());

		}
		if (temp != 0)
		{
			for (int a = 0; a < temp; a++)
			{
				obj[a] = tempCargo[a];

			}
		}*/
		
		
	}

	void Train::unloadCargo() {
		if (obj != nullptr)
		{
			this->countCargo--;
		
			
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
				cout << "Cargo: " << obj[0].getDesc() << endl;
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << "Weight: " << obj[0].getWeight() << endl;
			}
		}
		else {
			cout << "This is an invalid train." << endl;
		}
	}

	bool Train::swapCargo(Train& other) {
		if (this->obj != nullptr && other.obj != nullptr)
		{
			class Cargo temp[1] = {};
			temp[0] = this->obj[0];
			this->unloadCargo();
			this->loadCargo(other.obj[0]);
			other.unloadCargo();
			other.loadCargo(temp[0]);
			return true;
		}
		else {
			return false;
		}
		
	}

	bool Train::increaseCargo(double weight) {
		if (this->obj != nullptr)
		{
			double tempWeight = obj[0].getWeight() + weight;
			if (tempWeight < MAX_WEIGHT)
			{
				obj[0].setWeight(tempWeight);
				
				return true;

			}
			else {
				if (obj[0].getWeight() < MAX_WEIGHT)
				{
					obj[0].setWeight(MAX_WEIGHT);
					return true;
				}
				else {
					return false;
				}
			}
		}
		else
		{
			return false;
		}
		
	}

	bool Train::decreaseCargo(double weight) {
		if (this->obj != nullptr)
		{
			double tempWeight = obj[0].getWeight() - weight;
			if (tempWeight > MIN_WEIGHT)
			{
				obj[0].setWeight(tempWeight);

				return true;

			}
			else {
				if (obj[0].getWeight() > MIN_WEIGHT)
				{
					obj[0].setWeight(MIN_WEIGHT);
					return true;
				}
				else {
					return false;
				}
			}
		}
		else
		{
			return false;
		}
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
		a=getLength(s1);

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