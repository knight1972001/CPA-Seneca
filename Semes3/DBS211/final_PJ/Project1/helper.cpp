#include"helper.h"
#include <iostream>
using namespace std;

void printHeader(const char* title)
{
	int i = 0;
	cout << endl;
	while (i < 25) {
		i++;
		cout << "-";
	}
	cout << " " << title << " ";
	while (i < (70 - strlen(title))) {
		i++;
		cout << "-";
	}
	cout << endl;
}

void printUnderLine(const char* title1, const char* title2, const char* title3, const char* title4, const char* title5, const char* title6) {
	if (title1 != nullptr) {
		int t1 = strlen(title1);
		for (int i = 0; i < t1; i++) {
			cout << "-";
		}
		for (int i = 15; i > t1; i--) {
			cout << " ";
		}
		cout << " ";
	}

	if (title2 != nullptr) {
		int t2 = strlen(title2);
		for (int i = 0; i < t2; i++) {
			cout << "-";
		}
		for (int i = 15; i > t2; i--) {
			cout << " ";
		}
		cout << " ";
	}

	if (title3 != nullptr) {
		int t3 = strlen(title3);
		for (int i = 0; i < t3; i++) {
			cout << "-";
		}
		for (int i = 15; i > t3; i--) {
			cout << " ";
		}
		cout << " ";
	}

	if (title4 != nullptr) {
		int t4 = strlen(title4);
		for (int i = 0; i < t4; i++) {
			cout << "-";
		}
		for (int i = 20; i > t4; i--) {
			cout << " ";
		}
		cout << " ";
	}

	if (title5 != nullptr) {
		int t5 = strlen(title5);
		for (int i = 0; i < t5; i++) {
			cout << "-";
		}
		for (int i = 15; i > t5; i--) {
			cout << " ";
		}
		cout << " ";
	}

	if (title6 != nullptr) {
		int t6 = strlen(title6);
		for (int i = 0; i < t6; i++) {
			cout << "-";
		}
		for (int i = 15; i > t6; i--) {
			cout << " ";
		}
		cout << " ";
	}
	cout << endl;
}