// Name:				Long Nguyen
// Seneca Student ID:	155176183
// Seneca email:		lnguyen97@myseneca.ca
// Date of completion:	Apr 8th, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include "LineManager.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	LineManager::LineManager() {
		m_cntCustomerOrder = 0;
		m_firstStation = nullptr;
	}

	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
		ifstream openedFile(file);
		if (!openedFile) {
			throw string("Unable to open [") + file + "] file.";
		}
		else {
			while (!openedFile.eof()) {
				Utilities utility;
				size_t pos = 0;
				bool more = false;
				utility.setDelimiter('|');
				string line;
				string station;
				string nextStation;
				getline(openedFile, line);

				station = utility.extractToken(line, pos, more);
				if (more) {
					nextStation = utility.extractToken(line, pos, more);
				}
				else {
					nextStation = "";
				}

				for (auto i : stations) {
					if (station == i->getItemName()) {
						for (auto item : stations) {
							if (item->getItemName() == nextStation) {
								i->setNextStation(item);
							}
						}
						activeLine.push_back(i);
					}
				}
			}
			openedFile.close();
			m_firstStation = activeLine.front();
			m_cntCustomerOrder = pending.size();
			
		}
	}

	void LineManager::linkStations() {
		for (size_t i = 0; i < activeLine.size(); i++) {
			if (!activeLine[i]->getNextStation()) {
				swap(activeLine[activeLine.size() - 1], activeLine[i]);
				break;
			}
		}
		
		for (size_t i = activeLine.size() - 1; i > 0; i--) {
			Workstation* temp = activeLine[i];
			for (size_t x = 0; x < i; x++) {
				if (temp == activeLine[x]->getNextStation()) {
					swap(activeLine[i - 1], activeLine[x]);
				}
			}
		}
	}

	bool LineManager::run(std::ostream& os) {
		static size_t count = 1;
		os << "Line Manager Iteration: " << count << endl;
		if (!pending.empty()) {
			*activeLine.front() += std::move(pending.front());
			pending.pop_front();
		}

		for (size_t i = 0; i < activeLine.size(); i++) {
			activeLine[i]->fill(os);
		}

		for (size_t i = 0; i < activeLine.size(); i++) {
			activeLine[i]->attemptToMoveOrder();
		}
		count++;
		return completed.size() == m_cntCustomerOrder;
	}
	
	void LineManager::display(std::ostream& os) const {
		for (auto& i : activeLine) {
			i->display(os);
		}
	}

}