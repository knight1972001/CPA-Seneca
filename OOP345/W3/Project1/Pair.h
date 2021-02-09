//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:			Feb 5th 2020
// Workshop:       	3
//==============================================

#ifndef PAIR_H
#define PAIR_H
#include <iostream>

namespace sdds {
	template <typename V, typename K>
	class Pair {
	private:
		V valueV;
		K keyK;
	public:
		Pair() : valueV{}, keyK{} {};
		Pair(const K& key, const V& value) {
			keyK = key;
			valueV = value;
		}
		const V& value() const {
			return valueV; 
		}
		
		void setValue(const V value) {
			valueV = value;
		}

		const K& key() const {
			 return keyK; 
		}

		virtual void display(std::ostream& os) const {
			os << keyK << " : " << valueV << std::endl;
		}

		friend std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
			pair.display(os);
			return os;
		}
	};
	

}
#endif // !PAIR_H
