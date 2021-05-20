//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			May 28th 2020
// Workshop:       	1 (Part 2)
//==============================================
#include "Utils.h"

using namespace std;
namespace intFunc {
	void clear(void)
	{
		while (getchar() != '\n');
	}

	int getInt(void)
	{
		int i = 0;
		char nl = 0;
		int check = 0;
		do {
			check = scanf("%d%c", &i, &nl);
			if (check == 0)
			{
				cout << "Invalid Number, try again: ";
				clear();
				continue;
			}
				if (nl != '\n')
				{
					cout << "Invalid trailing characters, try again: ";
					clear();
				}
			
		} while (nl != '\n');
		return i;
	}

	int getIntInRange(int min, int max)
	{
		int i=0;
		do
		{
			i = getInt();
			if (i < min || i > max)
			{
				cout << "Invalid value (" << min << "<=value<=" << max << "), try again: ";
			}
		} while (i < min || i > max);
		return i;
	}

	int checkAvoidNum(char input[])
	{
		int scan = 0, i = 0;
		for (i = 0; i < strlen(input); i++)
		{
			if (isdigit(input[i]))
			{
				cout << "This field cannot contain number. Please check!" << endl;
				scan = 0;
				break;
			}
			else
			{
				scan = 1;
			}
		}
		return scan;
	}

	float average(int input[], int num)
	{
		int i = 0;
		float sum = 0, avg = 0;
		for (i = 0; i < num; i++)
		{
			sum += input[i];
		}
		avg = sum / num;
		return avg;
	}

	void sort(int input[], int num)
	{
		int temp = 0;
		int i = 0, j = 0;
		for (i = 0; i < num - 1; i++)
		{
			for (j = i + 1; j < num; j++)
			{
				if (input[i] < input[j])
				{
					temp = input[i];
					input[i] = input[j];
					input[j] = temp;
				}
			}
		}
	}

	void display(int input[], int num)
	{
		int i = 0;
		for (i = 0; i < num; i++)
		{
			cout << input[i];
			if (i < num - 1)
			{
				cout << ", ";
			}
		}
		cout << endl;
	}

	int checkPass(int input[], int num)
	{
		int i = 0;
		int count = 0;
		for (i = 0; i < num; i++)
		{
			if (input[i] >= 50)
			{
				count++;
			}
		}
		return count;
	}
}