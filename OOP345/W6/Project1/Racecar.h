#ifndef RACECAR_H
#define RACECAR_H
#include "Car.h"
namespace sdds {
	class Racecar : public Car {
	private:
		double m_booster;
	public:
		Racecar();
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}
#endif // !RACECAR_H
