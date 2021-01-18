//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
//==============================================
#include <iostream>
#include <cstring>
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
using namespace std;

void convert(const char* input, char* output) {
	int count = 0;
	for (int i = 0, a=0; i < strlen(input); i++,a++)
	{
		output[a] = input[i];
		if (input[i] == '1')
		{
			count++;
			if (count == 5)
			{
				a++;
				output[a]='0';
				count = 0;
			}
		}
		else {
			count = 0;
		}
	}
}

void finish(const char* input,const char *flag,char* output) {
	int i = 0;
	for (i = 0; i < strlen(flag); i++)
	{
		output[i] = flag[i];
	}
	int count = 0;
	while (count < strlen(input))
	{
		output[i] = input[count];
		count++;
		i++;
	}

	for (int a=0; a < strlen(flag); a++)
	{
		output[i] = flag[a];
		i++;
		
	}
}

int main()
{
	char flag[9] = "01111110";
	char input[50] = "011111101111110";
	char stuffing[50] = {};
	char done[100] = {};
	/*cout << "Input string: ";
	cin >> input;*/
	convert(input, stuffing);
	cout << YELLOW << "Before Stuffing: " << input << " -- " << strlen(input) << "characters" RESET << endl;
	cout << YELLOW << "After  Stuffing: " << RED << stuffing << YELLOW << " -- " << strlen(stuffing) << "characters" RESET << endl;
	finish(stuffing, flag, done);
	cout << YELLOW << "After framing: " << RESET;
	int changecolorA = 0, changecolorB=0;
	int i = 0;
	for (changecolorA = 0; changecolorA < strlen(flag); changecolorA++,i++)
	{
		
		cout << BLUE << done[i] << RESET;
	}
	for (changecolorB = 0; changecolorB < strlen(stuffing); changecolorB++,i++)
	{
		cout << YELLOW << done[i] << RESET;
	}
	for (changecolorA = 0; changecolorA < strlen(flag); changecolorA++, i++)
	{
		cout << BLUE << done[i] << RESET;
	}
	cout << endl;
	return 0;
}