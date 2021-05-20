#include <iostream>
int getLength(const char* cp) {
	int i = 0;
	while (cp[i] != '\0') {
		i++;
	}
	return i;
}

void cpyString(const char* cp, char*& cref) {
	if (cref != nullptr) {
		delete[] cref;
	}
	cref = new char[getLength(cp)+1];
	
	for (int i = 0; i < getLength(cp); i++)
	{
		cref[i] = cp[i];
		if (i+1 == getLength(cp))
		{
			cref[i + 1] = '\0';
		}
	}
	
}