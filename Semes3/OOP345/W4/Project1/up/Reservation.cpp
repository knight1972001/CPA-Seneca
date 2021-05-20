//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:				Feb 11th 2020
// Workshop:       	4
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Reservation.h"

using namespace std;

namespace sdds {
	Reservation::Reservation() {
		numOfPeople = 0;
		day = 0;
		hour = 0;
		//time = TimeOfDay::drink;
		res_id = "";
		name = "";
		email = "";
	}

	Reservation::Reservation(const string& res) {
		string original = res;
		res_id = original.substr(0, original.find(":"));
		//trim id
		while (true) {
			if (res_id[0] != ' ') {
				if (res_id[res_id.length() - 1] != ' ') {
					break;
				}
				else {
					res_id.erase(res_id.length() - 1, res_id.find(' ') + 1);
				}
			}
			else {
				res_id.erase(0, res_id.find(' ') + 1);
			}
		}
		//strcpy(res_id, str_res_id.c_str());

		//cout << "res_id: " << res_id << "test" << endl;


		//delete space
		/*std::string::iterator end_pos = std::remove(original.begin(), original.end(), ' ');
		original.erase(end_pos, original.end());*/


		//cout << "str: " << original << endl;

		//name
		original.erase(0, original.find(":") + 1);
		name = original.substr(0, original.find(","));
		while (true) {
			if (name[0] != ' ') {
				if (name[name.length() - 1] != ' ') {
					break;
				}
				else {
					name.erase(name.length() - 1, name.find(' ') + 1);
				}
			}
			else {
				name.erase(0, name.find(' ') + 1);
			}
		}
		/*cout << "name: " << name << endl;*/
		
		original.erase(remove(original.begin(), original.end(), ' '), original.end());

		//email
		original.erase(0, original.find(",") + 1);
		email = original.substr(0, original.find(","));
		//cout << "email: " << email << endl;

		//people
		original.erase(0, original.find(",") + 1);
		numOfPeople = stoi(original.substr(0, original.find(",")));
		//cout << "People: " << numOfPeople << endl;

		//day
		original.erase(0, original.find(",") + 1);
		day = stoi(original.substr(0, original.find(",")));
		//cout << "day: " << day << endl;

		//hour
		original.erase(0, original.find(",") + 1);
		hour = stoi(original.substr(0, original.find(",")));
		//cout << "hour: " << hour << endl;

		/*if (hour >= 6 && hour <= 9) {
			time = TimeOfDay::morning;
		}
		if (hour >= 11 && hour <= 15) {
			time = TimeOfDay::afternoon;
		}
		if (hour >= 17 && hour <= 21) {
			time = TimeOfDay::evening;
		}*/
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& res){
		os << "Reservation ";
		os << setw(10) << right << res.res_id << ": ";
		os << setw(20) << right << res.name << "  ";
		os << setw(20) << left << "<" + res.email + ">" << "    ";
		/*switch (res.time) {
		case res.TimeOfDay::morning:
			os << "Breakfast ";
			break;
		case res.TimeOfDay::afternoon:
			os << "Lunch ";
			break;
		case res.TimeOfDay::evening:
			os << "Dinner ";
			break;
		case res.TimeOfDay::drink:
			os << "Drinks ";
			break;
		}*/
		if (res.hour >= 6 && res.hour <= 9) {
			os << "Breakfast ";
		}
		else {
			if (res.hour >= 11 && res.hour <= 15) {
				os << "Lunch ";
			}
			else {
				if (res.hour >= 17 && res.hour <= 21) {
					os << "Dinner ";
				}
				else {
					os << "Drinks ";
				}
			}
			
		}
		

		os << "on day " << res.day << " @ " << res.hour << ":00" << " for ";
		if (res.numOfPeople > 1) {
			os << res.numOfPeople << " people." << endl;
		}
		else {
			os << res.numOfPeople << " person." << endl;
		}
		return os;
	}

	Reservation::~Reservation() {}
}