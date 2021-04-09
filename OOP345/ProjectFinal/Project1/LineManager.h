// Name:				Long Nguyen
// Seneca Student ID:	155176183
// Seneca email:		lnguyen97@myseneca.ca
// Date of completion:	Apr 8th, 2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef LINEMANAGER_H
#define LINEMANAGER_H
#include <vector>
#include "Workstation.h"
namespace sdds {
	class LineManager {
	private:
		std::vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder;
		Workstation* m_firstStation;
	public:
		LineManager();
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif // !LINEMANAGER_H
