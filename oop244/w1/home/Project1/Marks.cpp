//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			May 28th 2020
// Workshop:       	1 (Part 2)
//==============================================
#include "Marks.h"

using namespace intFunc;
using namespace std;

void markstat(void)
{
	char name[50];
	int scan = 0;
	int num = 0;
	int mark[100];
	int i = 0, pass=0;
	float avg = 0;
	cout << "Mark Stats Program." << endl;
	cout << endl;
	do
	{
		scan = 0;
		cout << "Please enter the assessment name: ";
		scanf("%[^\n]", name);
		clear();
		scan = checkAvoidNum(name);
	} while (scan==0);

	cout << "Please enter the number of marks: ";
	num = getIntInRange(5, 50);

	cout << "Please enter " << num << " marks (0<=Mark<=100):" << endl;
	
	for (i = 0; i < num; i++)
	{
		cout << i + 1 << "> ";
		mark[i] = getIntInRange(0, 100);
	}
	cout << "Thank you..." << endl;
	cout << "Assessment Name: " << name << endl;
	cout << "----------------" << endl;
	sort(mark, num);
	avg = average(mark, num);
	pass = checkPass(mark, num);
	display(mark,num);
	printf("Average: %1.1f\n", avg);
	cout << "Number of Passing Marks: " << pass << endl;
}