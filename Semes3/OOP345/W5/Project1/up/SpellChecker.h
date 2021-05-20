//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:			Feb 20th 2020
// Workshop:       	5
//==============================================
#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H
namespace sdds {
	class SpellChecker {
	private:
		std::string m_badWords[6];
		std::string m_goodWords[6];
		size_t cnt;
		size_t countReplace[6];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif // !SPELLCHECKER_H
