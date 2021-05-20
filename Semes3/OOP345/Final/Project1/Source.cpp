#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <thread>

using namespace std;
constexpr double GST{ 0.13 };
constexpr unsigned CUTOFF_YEAR{ 1900 };




struct Game
{
	std::string description;
	unsigned year = 0;
	double price = 0;
	double price_w_tax = 0;
};

void byName(const std::vector<Game>& games) {
	cout << fixed << setprecision(2);
	cout << "\nGame Price\n";
	for (auto& g : games)
		cout << setw(11) << left << g.description << ": " << setw(3) << right << g.price_w_tax << '\n';
}

void byYear(const vector<Game>& games) {
	cout << fixed << setprecision(2);
	cout << "\nYear Price\n";
	for (auto& g : games)
		cout << setw(5) << left << g.year << ": " << setw(3) << right << g.price_w_tax << endl;
}

void AddGST(std::vector<Game>::iterator begin, std::vector<Game>::iterator end)
{
	std::for_each(begin, end, [&](Game& item) {
		item.price_w_tax = item.price * GST + item.price;
		});
}



class Library {
private:
	vector<Game> games;
	void (*m_ptr)(const vector<Game>& games);
	bool flag;
public:
	Library() {
		flag = false;
	}

	Library& operator+=(const Game& game) {
		if (game.year >= CUTOFF_YEAR) {
			games.push_back(game);
			flag = false;
		}
		else {
			throw std::string("Out of Date");
		}
		return *this;
	}

	void setDisplay(void(*ptr)(const std::vector<Game>& games))
	{
		m_ptr = ptr;
	}

	void display() noexcept {
		if (!flag) {
			std::thread tx1 = std::thread(AddGST, begin(games), end(games));
			std::thread tx2 = std::thread(AddGST, begin(games), end(games));
			tx1.join();
			tx2.join();
		}
		if (m_ptr == nullptr) {
			exit(55);
		}
		m_ptr(games);
	}
};



int main() {
	Game games[]{
		{"Monopoly",1903,22.47},
		{"GoL",1860,19.93},
		{"BattleShip",1914,16.99},
		{"CandyLand",1949,19.21},
		{"Clue",1950,44.99},
		{"Sorry",2013,16.99}
	};

	Library* library = new Library();

	for (const auto& item : games) {
		try {
			*library += item;
		}
		catch (std::string err) {
			cout << err << endl;
		}
	}


	library->setDisplay(byName);
	library->display();

	library->setDisplay(byYear);
	library->display();

	delete library;
}