//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 28th 2020
// Workshop:       	MS3
//==============================================
#ifndef READWRITE
#define READWRITE
#include <iostream>
namespace sdds {
	class ReadWritable {
	private:
		bool m_csvIO;
	public:
		ReadWritable();
		bool isCsv() const;
		void setCsv(bool value);
		virtual std::istream& read(std::istream& istr = std::cin) = 0;
		virtual std::ostream& write(std::ostream& ostr = std::cout)const = 0;
		virtual ~ReadWritable();
	};
	std::ostream& operator<<(std::ostream& ostr, const ReadWritable& rw);
	std::istream& operator>>(std::istream& istr, ReadWritable& rw);
}
#endif // !READWRITE
