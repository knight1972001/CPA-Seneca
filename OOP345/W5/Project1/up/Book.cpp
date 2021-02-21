#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Book.h"

using namespace std;

namespace sdds {
	Book::Book() {
		author = "";
		bookTitle = "";
		countryPublication = "";
		yearPublication = 0;
		priceOfBook = 0;
	}

	Book::Book(const std::string& strBook) {
		string original = strBook;
		author = original.substr(0, original.find(","));
		//trim author
		while (true) {
			if (author[0] != ' ') {
				if (author[author.length() - 1] != ' ') {
					break;
				}
				else {
					author.erase(author.length() - 1, author.find(' ') + 1);
				}
			}
			else {
				author.erase(0, author.find(' ') + 1);
			}
		}

		//Title
		original.erase(0, original.find(",") + 1);
		bookTitle = original.substr(0, original.find(","));
		while (true) {
			if (bookTitle[0] != ' ') {
				if (bookTitle[bookTitle.length() - 1] != ' ') {
					break;
				}
				else {
					bookTitle.erase(bookTitle.length() - 1, bookTitle.find(' ') + 1);
				}
			}
			else {
				bookTitle.erase(0, bookTitle.find(' ') + 1);
			}
		}

		//countryPublication
		original.erase(0, original.find(",") + 1);
		countryPublication = original.substr(0, original.find(","));
		while (true) {
			if (countryPublication[0] != ' ') {
				if (countryPublication[countryPublication.length() - 1] != ' ') {
					break;
				}
				else {
					countryPublication.erase(countryPublication.length() - 1, countryPublication.find(' ') + 1);
				}
			}
			else {
				countryPublication.erase(0, countryPublication.find(' ') + 1);
			}
		}

		//price
		original.erase(0, original.find(",") + 1);
		priceOfBook = stod(original.substr(0, original.find(",")));

		//year
		original.erase(0, original.find(",") + 1);
		yearPublication = stoi(original.substr(0, original.find(",")));

		//description
		original.erase(0, original.find(",") + 1);
		description = original;
		while (true) {
			if (description[0] != ' ') {
				if (description[description.length() - 1] != ' ') {
					break;
				}
				else {
					description.erase(description.length() - 1, description.find(' ') + 1);
				}
			}
			else {
				description.erase(0, description.find(' ') + 1);
			}
		}
	}

	const std::string& Book::title() const {
		return bookTitle;
	}

	const std::string& Book::country() const {
		return countryPublication;
	}

	const size_t& Book::year() const {
		return yearPublication;
	}

	double& Book::price() {
		return priceOfBook;
	}

	std::ostream& operator<<(std::ostream& os, const Book& book) {
		os << setw(20) << right << book.author << " |";
		os << " " << setw(22) << right << book.bookTitle << " |";
		os << " " << setw(5) << right << book.countryPublication << " |";
		os << " " << setw(4) << right << book.yearPublication << " |";
		os << " " << setw(6) << right << setprecision(2) << fixed << book.priceOfBook << " |";
		os << " " << left << book.description << endl;
		os << setw(0) << left;
		return os;
	}
}