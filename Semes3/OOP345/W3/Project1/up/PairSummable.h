//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:			Feb 5th 2020
// Workshop:       	3
//==============================================

#ifndef PAIRSUMMABLE_H
#define PAIRSUMMABLE_H
#include <iomanip>
#include "Pair.h"
namespace sdds {
	template<class V, class K>
	class PairSummable : public Pair<V, K> {
	private:
		static V initial;
		static size_t minField;
	public:
		PairSummable() : Pair<V, K>() {};

		PairSummable(const K& key, const V& value = initial) : Pair<V, K>(key, value) {
			if (key.size() > minField) {
				minField = key.size();
			}
		}

		bool isCompatibleWith(const PairSummable<V, K>& b) const {
			if (b.key() == this->key()) {
				return true;
			}
			else {
				return false;
			}
		}


		PairSummable<V,K>& operator+=(const PairSummable<V, K>& p) {
			*this = PairSummable(p.key(), this->value() + p.value());
			return *this;
		}

		void display(std::ostream& os) const {
			os.width(minField);
			os << std::left;
			Pair<V, K>::display(os);
			os.width(0);
			os << std::right;
		}
		~PairSummable() {};

	};
		template<> std::string PairSummable<std::string, std::string>::initial = "";
		template<> int PairSummable<int, std::string>::initial = 0;
		template<typename V, typename K>
		size_t PairSummable<V, K>::minField = 0;

		template<> PairSummable<std::string, std::string>&
			PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& b) {
			if (Pair<std::string, std::string>::value() == "") {
				*this = PairSummable(Pair<std::string, std::string>::key(), b.value());
			}
			else {
				*this = PairSummable(Pair<std::string, std::string>::key(), Pair<std::string, std::string>::value() + ", " + b.value());
			}
			return *this;
		}
}
#endif // !PAIRSUMMABLE_H
