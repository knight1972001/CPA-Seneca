//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:			Feb 20th 2020
// Workshop:       	5
//==============================================
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include "SpellChecker.h"

using namespace std;

namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		/*ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		string line;
		size_t cnt = 0;
		do {
			getline(file, line);
			if (file)
			{
				istringstream iss(line);
				string subs;
				iss >> subs;
				m_badWords[cnt] = subs;
				iss >> subs;
				m_goodWords[cnt] = subs;
				cnt++;
			}
		} while (file);
		file.close();*/

		ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		cnt = 0;
		for (int i = 0; i < 6; i++) {
			countReplace[i] = 0;
		}
		while (!file.eof() && cnt<6) {
			string badWord;
			string goodWord;
			file >> badWord >> goodWord;
			m_badWords[cnt] = badWord;
			m_goodWords[cnt] = goodWord;
			cnt++;
		}
		file.close();
	}

	void SpellChecker::operator()(std::string& text) {
		for (size_t i = 0; i < cnt; i++) {
			while (text.find(m_badWords[i]) != string::npos) {
				text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
				countReplace[i]++;
			}
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const {
		out << "Spellchecker Statistics" << endl;
		for (size_t i = 0; i < cnt; i++) {
			out << setw(15) << right << m_badWords[i] << ": " << countReplace[i] << " replacements" << endl;
		}
	}
}