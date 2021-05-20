//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 8th 2020
// Workshop:       	6 (Part 1)
//==============================================
#ifndef BASKET_H
#define BASKET_H
#include<iostream>
namespace sdds {
	struct Fruit {
		char m_name[30 + 1];
		double m_qty;
	};

	class Basket {
	private:
		Fruit *m_fruits;
		int m_cnt;
		double m_price;
	public:
		Basket();
		Basket(const Fruit *, int, double);
		explicit operator bool() const;
		Basket& operator+=(Fruit&);
		Basket(const Basket&);
		Basket& operator=(const Basket&);
		void setPrice(double);
		void display(std::ostream& os) const;
		~Basket();
	};
	std::ostream& operator<<(std::ostream&, const Basket&);

}




#endif // !BASKET_H
