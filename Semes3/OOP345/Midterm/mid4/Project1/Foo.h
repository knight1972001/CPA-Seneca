#ifndef F
#define F
#include <iostream>
extern double g_value;

class Foo {
	long m_id;
	std::string m_value;

	Foo* m_theBigFoo{};
public:
	static int m_shared;

	Foo(long id, std::string str = "") : m_id{ id }, m_value{ str }
	{}

	void update(Foo& other)
	{
		if (m_id == other.m_id) {
			m_value = m_value + " " + other.m_value;
		}
	}

	std::string getValue() const {
		return m_value;
	}

	Foo& operator+(const Foo& theFoo, std::string val) {
		return *this;
	}

	std::string operator+(std::string, const Foo&);
	decltype("" + Foo(3L, "Hello")) process(const Foo&);
	decltype(Foo(1L, "World") + "") process(Foo&);
};
#endif // !F
