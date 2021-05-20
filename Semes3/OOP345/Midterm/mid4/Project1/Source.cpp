#include <iostream>
#include "Foo.h"
#include "Foo.cpp"
using namespace std;
int main() {
	cout << ::g_value << " " << Foo::m_shared << endl;
	{
		int* ptr = new int[3];
		ptr[0] = 1;
		ptr[1] = 2;
		ptr[2] = 3;
		for (auto& item : ptr) {
			cout << "Item? ";
			cin >> item;
		}
		delete[] ptr;
	}
	{
		const Foo aFoo(1, "Midterm");
		cout << aFoo.getValue();
		aFoo.update(aFoo);
		cout << process(aFoo).getValue();
	}
}