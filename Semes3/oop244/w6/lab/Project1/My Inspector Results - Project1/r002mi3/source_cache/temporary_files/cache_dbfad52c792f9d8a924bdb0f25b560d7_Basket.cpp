#include "Basket.h"
#include <iostream>
#include <iomanip>

using namespace std;
namespace sdds {
	Basket::Basket(){
		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0;
	}

	Basket::Basket(const Fruit* fruit, int size, double price) {
		if (fruit != nullptr && size > 0 && price > 0) {
			m_fruits = nullptr;
			m_cnt = 0;
			m_price = 0;
			this->m_cnt = size;
			if (this->m_fruits != nullptr) {
				delete[]this->m_fruits;
				this->m_fruits = nullptr;
			}
			m_fruits = new Fruit[this->m_cnt];
			for (int i = 0; i < this->m_cnt; i++) {
				this->m_fruits[i] = fruit[i];
			}
			this->m_price = price;
		}
		else {
			m_fruits = nullptr;
			m_cnt = 0;
			m_price = 0;
		}
	}

	Basket::operator bool() const {
		if (this->m_fruits != nullptr && this->m_cnt != 0) {
			return true;
		}
		else {
			return false;
		}
	}

	Basket& Basket::operator+=(Fruit& p) {
			Fruit* temp;
			temp = new Fruit[this->m_cnt];

			for (int i = 0; i < this->m_cnt; i++) {
				temp[i] = this->m_fruits[i];
			}

			int count = this->m_cnt + 1;
			if (this->m_fruits != nullptr)
			{
				delete[] this->m_fruits;
				this->m_fruits = nullptr;
			}

			this->m_fruits = new Fruit[count];

			for (int i = 0; i < this->m_cnt; i++) {
				this->m_fruits[i] = temp[i];
			}

			this->m_cnt++;
			this->m_fruits[count - 1] = p;

			if (temp != nullptr) {
				delete[] temp;
				temp = nullptr;
			}
			return *this;

	}

	Basket::Basket(const Basket& other) {
			this->m_cnt = other.m_cnt;
			this->m_price = other.m_price;
			if (other.m_fruits != nullptr) {
				if (this->m_fruits != nullptr) {
					delete[] this->m_fruits;
					this->m_fruits = nullptr;
				}
				this->m_fruits = new Fruit[this->m_cnt];
				for (int i = 0; i < this->m_cnt; i++) {
					this->m_fruits[i] = other.m_fruits[i];
				}
			}
			else {
				this->m_fruits = nullptr;
			}
	}

	Basket& Basket::operator=(const Basket& other){
		if (this != &other) {
			this->m_cnt = other.m_cnt;
			this->m_price = other.m_price;
			if (other.m_fruits != nullptr) {
				if (this->m_fruits != nullptr) {
					delete[] this->m_fruits;
					this->m_fruits = nullptr;
				}
				this->m_fruits = new Fruit[this->m_cnt];
				for (int i = 0; i < this->m_cnt; i++) {
					this->m_fruits[i] = other.m_fruits[i];
				}
			}
			else {
				this->m_fruits = nullptr;
			}
		}
		return *this;
	}

	void Basket::setPrice(double price){
		this->m_price = price;
	}

	Basket::~Basket() {
		if (this->m_fruits != nullptr) {
			delete[] this->m_fruits;
			this->m_fruits = nullptr;
		}
	}

	void Basket::display(std::ostream& os) const {
		if (this->m_fruits != nullptr) {
			os << "Basket Content:" << endl;
			for (int i = 0; i < this->m_cnt; i++) {
				cout.setf(ios::fixed);
				cout.precision(2);
				os << right << setw(10) << this->m_fruits[i].m_name << " : " << this->m_fruits[i].m_qty << "kg" << endl;
			}
			os << "Price: " << this->m_price << endl;
			cout.unsetf(ios::fixed);
			cout.precision(6);
		}
		else {
			os << "The basket is empty!" << endl;
		}
	}

	std::ostream& operator<<(std::ostream& os, const Basket& p) {
		p.display(os);
		return os;
	}
}