#include <iostream>
#include <string>
using namespace std;

int main()
{
	struct newstudent
	{
		int id;
		string name;
	};
	newstudent* newhocsinh;
	int sl = 0;
	cout << "Nhap so luong: ";
	cin >> sl;
	newhocsinh = new newstudent [sl];
	int i = 0;
	for (i = 0; i < sl; i++)
	{
		
		cout << "Hoc sinh thu " << i + 1 << ":" << endl;
		cout << "Nhap ten: ";
		cin.ignore();
		getline(cin, newhocsinh[i].name);
		cout << "Nhap id: ";
		cin >> newhocsinh[i].id;
	}

	for (i = 0; i < sl; i++)
	{
		cout << "Trinh xuat hoc sinh thu " << i+1 << ":" << endl;
		cout << "Ten h.s: " << newhocsinh[i].name << endl;
		cout << "So luong ky tu: " << newhocsinh[i].name.length() << endl;
		cout << "ID Hoc sinh: " << newhocsinh[i].id << endl;
		cout << endl;
	}
}