#ifndef AUTOSHOP_H
#define AUTOSHOP_H
#include <vector>
#include "Vehicle.h"
namespace sdds {
	class Autoshop {
	private:
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
	};
}

#endif // !AUTOSHOP_H
