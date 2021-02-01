//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:			Jan 27th 2020
// Workshop:       	2
//==============================================

#ifndef STRINGSET_H
#define STRINGSET_H
namespace sdds {
	class StringSet {
	private:
		long unsigned int numOfString;
		std::string* strArr;
	public:
		StringSet();
		StringSet(const char*);
		StringSet(const StringSet& );
		StringSet& operator=(const StringSet& );
		StringSet(StringSet&& );
		StringSet& operator=(StringSet&&);
		size_t size();
		std::string operator[](const size_t);
		~StringSet();
	};
}
#endif // !STRINGSET_H
