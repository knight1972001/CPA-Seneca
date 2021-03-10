#include <string>
#include "Foo.h"
using namespace std;

double g_value = 1.2;
int Foo::m_shared = 10;

string operator+(string val, const Foo& theFoo) {
	return val;
}

decltype("" + Foo(3L, "Hello")) process(const Foo&) {
	return "Hello" + Foo(30L, "World");
}
decltype(Foo(1L, "World") + "") process(Foo&) {
	return Foo(10L, "Hello") + "World";
}

std::string Foo::operator+(std::string, const Foo&)
{
	return std::string();
}
