#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H
namespace sdds {
	class SpellChecker {
	private:
		std::string m_badWords[6];
		std::string m_goodWords[6];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif // !SPELLCHECKER_H
