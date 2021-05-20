//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:			Feb 5th 2020
// Workshop:       	3
//==============================================

#ifndef SET_H
#define SET_H

namespace sdds {
	template <size_t N, typename T>
	class Set {
	private:
		unsigned int count = 0;
		T collection[N];
	public:
		size_t size() const {
			return count;
		}
		const T& get(size_t idx) const {
			return collection[idx];
		}
		void operator+=(const T& item) {
			if (count < N) {
				collection[count] = item;
				count++;
			}
		}
	};
}
#endif // !SET_H
