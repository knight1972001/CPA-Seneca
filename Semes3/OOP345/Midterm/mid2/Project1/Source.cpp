#include <iostream>
#include "ControlPanel.h"

using namespace std;
using namespace sdds;

int main() {
	int id[] = { 3,2,6,1,5 };
	char colour[] = { 'b','r','y','g','w' };
	ControlPanel control(id, colour, 5);

	control.changeLED(2, 'l');
}