//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:			Feb 20th 2020
// Workshop:       	5
//==============================================
#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>
#include <string>

namespace sdds {
	template <typename T>
	class Collection {
	private:
		T* item;
		std::string nameCollection;
		size_t sizeItem;
		void(*_observer)(const Collection<T>&, const T&) { nullptr };
	public:
		Collection(const std::string& name) {
			this->nameCollection = name;
			item = nullptr;
			sizeItem = 0;
		}

		Collection(Collection&) = delete;
		Collection& operator=(Collection&) = delete;

		~Collection() {
			if (item != nullptr) {
				delete[] item;
				item = nullptr;
			}
			
			sizeItem = 0;
			nameCollection = "";
		}
		
		const std::string& name() const {
			return nameCollection;
		}

		size_t size() const {
			return sizeItem;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)){
			_observer = observer;
		}

		Collection<T>& operator+=(const T& item) {
			if (sizeItem > 0) {
				bool found = false;
				for (size_t i = 0; i < sizeItem && !found; i++) {
					if (this->item[i].title() == item.title()) {
						found = true;
					}
				}

				if (!found) {
					T* tempItem;
					tempItem = new T[sizeItem];
					for (size_t i = 0; i < sizeItem; i++) {
						tempItem[i] = this->item[i];
					}
					if (this->item != nullptr) {
						delete[] this->item;
						this->item = nullptr;
					}
					sizeItem++;
					this->item = new T[sizeItem];
					for (size_t i = 0; i < sizeItem - 1; i++) {
						this->item[i] = tempItem[i];
					}
					if (tempItem != nullptr) {
						delete[] tempItem;
						tempItem = nullptr;
					}
					this->item[sizeItem - 1] = item;
					if (_observer != nullptr) {
						_observer(*this, item);
					}
				}
			}
			else {
				sizeItem++;
				if (this->item != nullptr) {
					delete[] this->item;
					this->item = nullptr;
				}
				this->item = new T[sizeItem];
				this->item[0] = item;
			}
			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx >= this->sizeItem || idx < 0) {
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(this->sizeItem) + "] items.");
			}
			else {
				return this->item[idx];
			}
		}

		T* operator[](const std::string& title) const {
			bool found = false;
			size_t foundIdx = 0;
			for (size_t i = 0; i < sizeItem && !found; i++) {
				if (this->item[i].title() == title) {
					found = true;
					foundIdx = i;
				}
			}

			if (found) {
				return &this->item[foundIdx];
			}
			else {
				return nullptr;
			}
		}

		friend std::ostream& operator<<(std::ostream& os, const Collection& src) {
			for (size_t i = 0; i < src.size(); i++) {
				os << src.item[i];
			}
			return os;
		}
	};
}
#endif // !COLLECTION_H
