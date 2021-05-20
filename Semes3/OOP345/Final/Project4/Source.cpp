#include <string> 
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <thread>

using namespace std;
constexpr unsigned BB_DATE{ 20201206 }; // best before cutoff

struct Flavour
{
	std::string description;
	unsigned bbDate; // best before
	unsigned quantity;
	double unit_price;
	double price;
};

void byDescription(const std::vector<Flavour>& icecreams)
{
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "\nFlavour Price\n";
	for (auto& i : icecreams)
		std::cout << std::setw(16) << std::left << i.description <<
		": " << std::setw(5) << std::right << i.price << '\n';
}

void byBestBefore(const std::vector<Flavour>& icecreams)
{
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "\nBest Before Price\n";
	for (auto& i : icecreams)
		std::cout << std::setw(11) << std::left << i.bbDate <<
		": " << std::setw(5) << std::right << i.price << '\n';
}


void SetPrice(std::vector<Flavour>::iterator begin, std::vector<Flavour>::iterator end) {
	std::for_each(begin, end, [&](Flavour& item) {
		item.price = item.unit_price * item.quantity;
		});
}

class Dessert {
private:
	vector<Flavour> flavours;
	void (*m_ptr)(const vector<Flavour>& flavour);
	bool flag;
public:
	Dessert& operator+=(const Flavour& flavour) {
		if (flavour.bbDate >= BB_DATE) {
			flavours.push_back(flavour);
			flag = false;
		}
		else {
			throw std::string(flavour.description);
		}
		return *this;
	}

	void setDisplay(void(*ptr)(const std::vector<Flavour>& flavours))
	{
		m_ptr = ptr;
	}

	void display() noexcept {
		if (!flag) {
			std::thread tx1 = std::thread(SetPrice, begin(flavours), end(flavours));
			std::thread tx2 = std::thread(SetPrice, begin(flavours), end(flavours));
			tx1.join();
			tx2.join();
			flag = true;
		}
		if (m_ptr == nullptr) {
			exit(55);
		}
		m_ptr(flavours);
	}
};


int main() {
	Flavour icecreams[]{
	{ "Salted Caramel ", 20201221, 1, 3.34 },
	{ "Dulce De Leche ", 20201228, 3, 6.49 },
	{ "Coffee ", 20201204, 2, 3.99 },
	{ "Pralines & Cream", 20201229, 1, 4.99 },
	{ "Strawberry ", 20201201, 3, 3.49 },
	{ "Vanilla ", 20201231, 4, 4.49 }
	};

	Dessert* dessert = new Dessert();
	for (const auto& item : icecreams)
	{
		try {
			*dessert += item;
		}
		catch (std::string err) {
			cout << "Expired: " << err << endl;
		}
	}
	dessert->setDisplay(byDescription);
	dessert->display();

	dessert->setDisplay(byBestBefore);
	dessert->display();

	delete dessert;
}