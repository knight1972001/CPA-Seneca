//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:			Feb 5th 2020
// Workshop:       	3
//==============================================
#ifndef SETSUMMABLE_H
#define SETSUMMABLE_H
#include "Set.h"
namespace sdds {
	template<size_t N, typename T>
	class SetSummable : public Set<N, T> {
	public:
		T accumulate(const std::string& filter) const {
			T accumulator(filter);
			for (size_t i = 0; i < (*this).size(); i++) {
				if (accumulator.isCompatibleWith((*this).get(i))){
					accumulator += (*this).get(i);
				}
			}
			return accumulator;
		}
	};
}
#endif // !SETSUMMABLE_H
