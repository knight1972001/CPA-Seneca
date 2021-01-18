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
// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contactHelpers.h"

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
}

// getInt function definition goes here:
int getInt(void)
{
    char nl;
    int i;
    do
    {
        scanf("%d%c", &i, &nl);
        
        if (nl != '\n')
        {
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
            clearKeyboard();
        }
    } while (nl != '\n');
    return i;
}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
    int i;
    do
    {
        i = getInt();
        if (i<min || i >max)
        {
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        }
    } while (i<min || i > max);
    return i;
}

// yes function definition goes here:
int yes(void)
{
    char choice, nl;
    int answer = 0;
    do {
        answer = 0;
        do
        {
            scanf("%c%c", &choice, &nl);
            if (nl != '\n')
            {
                printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
                clearKeyboard();
            }
        } while (nl != '\n');
        if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n')
        {
            if (choice == 'N' || choice == 'n')
            {
                answer = 0;
            }
            else {
                answer = 1;
            }
        }
        else {
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
            answer = 3;
        }
    } while (answer != 0 && answer != 1);
    return answer;
}

// menu function definition goes here:
int menu(void)
{
    int choice;

    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n\n");
    printf("Select an option:> ");
    choice = getIntInRange(0, 6);
    return choice;
}

// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
    int option = 0;
    int choice = 0;
    do
    {
        option = menu();

        switch (option)
        {
        case 1:

            printf("\n<<< Feature 1 is unavailable >>>\n\n");
            pause();
			printf("\n");
            break;

        case 2:

            printf("\n<<< Feature 2 is unavailable >>>\n\n");
            pause();
			printf("\n");
            break;

        case 3:

            printf("\n<<< Feature 3 is unavailable >>>\n\n");
            pause();
			printf("\n");
            break;

        case 4:
            printf("\n<<< Feature 4 is unavailable >>>\n\n");
            pause();
			printf("\n");
            break;

        case 5:
            printf("\n<<< Feature 5 is unavailable >>>\n\n");
            pause();
			printf("\n");
            break;

        case 6:
            printf("\n<<< Feature 6 is unavailable >>>\n\n");
            pause();
			printf("\n");
            break;

        case 0:
            printf("\nExit the program? (Y)es/(N)o: ");
            choice = yes();
			printf("\n");
            break;

        default:
            break;
        }


    } while (choice != 1);
    printf("Contact Management System: terminated\n");
}
// Phone number check
int phonenumbercheck(char phonenumber[])
{
    int scan = 0, i = 0;
    if (strlen(phonenumber) > 1)
    {
        if (phonenumber[0] == '+' || isdigit(phonenumber[0]))
        {
            for (i = 1; i < strlen(phonenumber); i++)
            {
                if (isdigit(phonenumber[i]) || phonenumber[i] == ' ')
                {
                    scan = 1;
                }
                else
                {
                    printf("Not available phone number. Please check and re-type!\n");
                    scan = 0;
                    break;
                }
            }
        }
        else
        {
            printf("Not available Phone Number. First character must not: %c\n", phonenumber[0]);
            scan = 0;
        }
    }
    else {
        if (isdigit(phonenumber[0]))
        {
            scan = 1;
        }
        else
        {
            printf("Not available phone number. Please check and re-type!\n");
            scan = 0;
        }
    }
    return scan;
}

//check to avoid number.
int checkavoidnum(char input[])
{
    int scan = 0, i = 0;
    for (i = 0; i < strlen(input); i++)
    {
        if (isdigit(input[i]))
        {
            printf("This field cannot contain number. Please check!\n");
            scan = 0;
            break;
        }
        else {
            scan = 1;
        }
    }
    return scan;
}