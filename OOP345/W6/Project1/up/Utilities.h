#ifndef UTILITIES_H
#define UTILITIES_H
#include <iostream>
#include <sstream>
#include "Vehicle.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in);
}
#endif // !UTILITIES_H
