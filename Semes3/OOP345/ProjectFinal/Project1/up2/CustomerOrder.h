#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H
#include <iostream>
#include "Station.h"
namespace sdds {
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder {
	private:
		std::string m_name;
		std::string m_product;
		size_t m_cntItem;
		Item** m_lstItem;
		static size_t m_widthField;
	public:
		CustomerOrder();
		CustomerOrder(std::string& string);
		CustomerOrder& operator=(const CustomerOrder& obj) = delete;
		CustomerOrder(const CustomerOrder& obj);
		CustomerOrder(CustomerOrder&& obj) noexcept;
		CustomerOrder& operator=(CustomerOrder&& obj) noexcept;
		~CustomerOrder();

		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};

}
#endif // !CUSTOMERORDER_H
