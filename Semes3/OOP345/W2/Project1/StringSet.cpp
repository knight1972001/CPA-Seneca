//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:			Jan 27th 2020
// Workshop:       	2
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "StringSet.h"

using namespace std;

namespace sdds {
	StringSet::StringSet() {
		strArr = nullptr;
		numOfString = 0;
	}

	StringSet::StringSet(const char* name) {
		ifstream fileptr(name);
		int count = 0;
		string bufferOne;
		if (fileptr.is_open())
		{
			while (!fileptr.eof() && fileptr.good())
			{
				getline(fileptr, bufferOne, ' ');
				bufferOne.clear();
				count++;
			}
			this->numOfString = count;
			if (fileptr.eof())
			{
				fileptr.clear();
				fileptr.seekg(0, fileptr.beg);
			}

			strArr = new string[count];
			int index = 0;
			while (!fileptr.eof() && fileptr.good())
			{
				getline(fileptr, strArr[index], ' ');
				index++;
			}
		}
	}
	StringSet::StringSet(const StringSet& obj)
	{
		strArr = nullptr;
		*this = obj;
	}

	StringSet& StringSet::operator=(const StringSet& obj)
	{
		if (this != &obj && obj.strArr!=nullptr)
		{
			this->numOfString = obj.numOfString;
			delete[]this->strArr;
			this->strArr = nullptr;
			this->strArr = new string[obj.numOfString];
			for (long unsigned int i = 0; i < obj.numOfString; i++)
			{
				this->strArr[i] = obj.strArr[i];
			}
		}
		return *this;
	}

	StringSet::StringSet(StringSet&& obj)
	{
		this->strArr = nullptr;
		*this = move(obj);
	}

	StringSet& StringSet::operator=(StringSet&& obj)
	{
		if (this != &obj)
		{
			this->numOfString = obj.numOfString;
			obj.numOfString = 0;
			if (this->strArr != nullptr)
			{
				delete[]this->strArr;
				strArr = nullptr;
			}
			this->strArr = obj.strArr;
			obj.strArr = nullptr;
		}
		return *this;
	}

	size_t StringSet::size() {
		return this->numOfString;
	}

	std::string StringSet::operator[](const size_t i) {
		if ((i >= 0 && i < numOfString) && strArr != nullptr) {
			/*cout << "i la: " << i << endl;
			cout << "numOfString la: " << numOfString << endl;*/
			return strArr[i];
		}
		else {
			return "";
		}
	}

	StringSet::~StringSet() {
		if (this->strArr != nullptr) {
			delete[]this->strArr;
			this->strArr = nullptr;
		}
	}
}