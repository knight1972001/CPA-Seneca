#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "header.h"
using namespace std;

int main()
{
	char a[50] = { "hahaha" };
	
	//cin.ignore(2000, '\n');
	Gift pickgift(a);
	cout << "The name is " << pickgift.getName() << endl;
	cout << endl;
}