#include <iostream>
#include <stdexcept>
#include "ControlPanel.h"
using namespace std;
namespace sdds {
	ControlPanel::ControlPanel() {
		indicators = nullptr;
		numOfIndicators = 0;
	}

	ControlPanel::ControlPanel(int* ids, char* ledColours, size_t numOfIndicators) {
		if (ids == nullptr || ledColours == nullptr || numOfIndicators == 0) {
			this->indicators = nullptr;
			this->numOfIndicators = 0;
			throw std::invalid_argument("invalid_argument");
		}else{
			if (indicators != nullptr) {
				delete[] indicators;
				indicators = nullptr;
			}
			indicators = new Indicator[numOfIndicators];
			this->numOfIndicators = numOfIndicators;
			for (size_t i = 0; i < numOfIndicators; i++) {
				indicators[i].id = ids[i];
				indicators[i].ledColour = ledColours[i];
			}
		}
	}

	void ControlPanel::changeLED(int ids, char ledColours) {
		if (indicators != nullptr) {
			bool found = false;
			size_t flag = 0;
			for (size_t i = 0; i < numOfIndicators && !found; i++) {
				if (indicators[i].id == ids) {
					found = true;
					flag = i;
				}
			}
			if (found) {
				indicators[flag].ledColour = ledColours;
			}
			else {
				throw "LED not found";
			}
		}
		else {
			std::exit(40);
		}
	}

	ControlPanel::~ControlPanel() {
		if (indicators != nullptr) {
			delete[] indicators;
			indicators = nullptr;
		}
	}
}