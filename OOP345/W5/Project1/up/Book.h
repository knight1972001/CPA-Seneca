#ifndef BOOK_H
#define BOOK_H
#include <iostream>
namespace sdds {
	class Book {
	private:
		std::string author;
		std::string bookTitle;
		std::string countryPublication;
		double priceOfBook;
		size_t yearPublication;
		std::string description;
	public:
		Book();
		Book(const std::string& strBook);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		friend std::ostream& operator<<(std::ostream& os, const Book& book);
	};
}
#endif // !BOOK_H
