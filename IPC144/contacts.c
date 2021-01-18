//==============================================
// Name:           Long Nguyen
// Student Number: 155176183
// Email:          lnguyen97@myseneca.ca
// Section:        NII
// Date:           March 19th, 2020
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"
// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these function to use the helper 
//        functions where applicable (ex: yes() and getInt() )

// getName:
void getName(Name* nname)
{
	int choice = 0, scan = 0;
	//first name
	do
	{
		printf("Please enter the contact's first name: ");
		scanf("%[^\n]", nname->firstName);
		clearKeyboard();
		scan = checkavoidnum(nname->firstName);
	} while (scan == 0);

	//middle name
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	choice = yes();
	if (choice == 1)
	{
		
		do
		{
			printf("Please enter the contact's middle initial(s): ");
			fgets(nname->middleInitial, 7, stdin);
			clearKeyboard();
			scan = checkavoidnum(nname->middleInitial);
		} while (scan == 0);
	}

	//lastname
	do
	{
		printf("Please enter the contact's last name: ");
		scanf("%[^\n]", nname->lastName);
		clearKeyboard();
		scan = checkavoidnum(nname->lastName);
	} while (scan == 0);
}

// getAddress:
void getAddress(Address* nAddress)
{
	int scan = 0, choice = 0;

	//street number
	printf("Please enter the contact's street number: ");
	do
	{
		nAddress->streetNumber = getInt();
		if (nAddress->streetNumber < 0)
		{
			printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
		}
	} while (nAddress->streetNumber < 0);

	//Street Name
	do
	{
		printf("Please enter the contact's street name: ");
		scanf("%[^\n]", nAddress->street);
		clearKeyboard();
		scan = checkavoidnum(nAddress->street);
	} while (scan == 0);

	//Apartment Number
	printf("Do you want to enter an apartment number? (y or n): ");
	choice = yes();
	if (choice == 1)
	{
		printf("Please enter the contact's apartment number: ");
		do
		{
			nAddress->apartmentNumber = getInt();
			if (nAddress->apartmentNumber < 0)
			{
				printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
			}
		} while (nAddress->apartmentNumber < 0);
	}

	//postal code
	printf("Please enter the contact's postal code: ");
	fgets(nAddress->postalCode, 8, stdin);
	clearKeyboard();

	//cityname
	do
	{
		printf("Please enter the contact's city: ");
		scanf("%[^\n]", nAddress->city);
		clearKeyboard();
		scan = checkavoidnum(nAddress->city);
	} while (scan == 0);
}



// getNumbers:
// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)
void getNumbers(Numbers* nNumbers)
{
	int scan = 0, choice = 0;
	//cellphone
	do
	{
		printf("Please enter the contact's cell phone number: ");
		scanf("%[^\n]", nNumbers->cell);
		clearKeyboard();
		scan = phonenumbercheck(nNumbers->cell);
	} while (scan == 0);

	//homephone

	printf("Do you want to enter a home phone number? (y or n): ");
	choice = yes();
	if (choice == 1)
	{
		do
		{
			printf("Please enter the contact's home phone number: ");
			scanf("%[^\n]", nNumbers->home);
			clearKeyboard();
			scan = phonenumbercheck(nNumbers->home);
		} while (scan == 0);
	}
	//businessphone
	printf("Do you want to enter a business phone number? (y or n): ");
	choice = yes();
	if (choice == 1)
	{
		do
		{
			printf("Please enter the contact's business phone number: ");
			scanf("%[^\n]", nNumbers->business);
			clearKeyboard();
			scan = phonenumbercheck(nNumbers->business);
		} while (scan == 0);
	}
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

// getContact
void getContact(Contact* nContact)
{
	getName(&nContact->name);
	getAddress(&nContact->address);
	getNumbers(&nContact->numbers);
}