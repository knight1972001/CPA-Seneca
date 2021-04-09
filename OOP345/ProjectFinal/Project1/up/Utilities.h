// Name:				Long Nguyen
// Seneca Student ID:	155176183
// Seneca email:		lnguyen97@myseneca.ca
// Date of completion:	Mar 21,2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef UTILITIES
#define UTILITIES
#include <iostream>
namespace sdds {
	class Utilities {
	private:
		size_t m_widthField;
		static char m_delimiter;
	public:
		Utilities();
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
}
#endif // !UTILITIES
