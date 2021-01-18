#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <occi.h>
#include <cstring>
#include <iomanip>
//#include "helper.h"
using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;
struct Employee {
	int employeeNumber;
	char lastName[50];
	char firstName[50];
	char extension[10];
	char email[100];
	char officecode[10];
	int reportsTo[100];
	char jobTitle[50];
};
//HELPERFUNCTION
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

int getInteger() {
	char input[10];
	int check = 0;

	do
	{
		check = 0;
		cin >> input;
		cin.ignore(1000, '\n');
		int size = strlen(input);
		for (int i = 0; i < size; i++) {
			if (isdigit(input[i])) {
				check = 1;
			}
			else {
				check = 0;
				cout << "Invalid Integer, try again: ";
				break;
			}
		}
	} while (check == 0);
	int back = atoi(input);
	return back;
}

int getIntRanger(int max, int min = 1) {
	int menu = 0;
	do
	{
		menu = getInteger();
		if (menu > max || menu < min)
		{
			cout << "Invalid selection, try again: ";
		}
	} while (menu > max || menu < min);
	return menu;
}

int menu(void) {
	int menu = 0;

	cout << "\n********************* HR Menu *********************" << endl;
	cout << "1) Find Employee" << endl;
	cout << "2) Employees Report" << endl;
	cout << "3) Add Employee" << endl;
	cout << "4) Update Employee" << endl;
	cout << "5) Remove Employee" << endl;
	cout << "0) Exit" << endl;
	cout << "Enter an option(0 - 5) : ";
	do
	{
		menu = getIntRanger(5, 0);
	} while (menu > 5 || menu < 0);

	return menu;
}

void displayAllEmployees(Connection* conn);
void displayEmployee(Connection* conn, Employee emp);
int findEmployee(Connection* conn, int employeeNumber, Employee* emp);
void insertEmployee(Connection* conn, Employee* emp);
// KRISTOFFER ADDED
void updateEmployee(Connection* conn, int employeeNumber);
// END ADD HERE
void deleteEmployee(Connection* con, int employeeNumber);

//MAIN
int main() {
	Environment* env = nullptr;
	Connection* conn = nullptr;
	string user = "dbs211_202a23";
	string pass = "18153271";
	string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";

	//KRSITOFFER ADDED

	Employee* emp = nullptr;
	emp = new Employee[1];
	int check = 0;

	//END ADD HERE

	try {
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(user, pass, srv);
		cout << "Connection is Successful!" << endl << endl;
		int option = 0;
		int done = 0;
		int employeeNumber = 0;
		//KRISTOFFER ADDED
		int ext = 0;
		// END ADD HERE

		while (!done)
		{
			option = menu();
			switch (option)
			{
			case 1:
				//KRISTOFFER ADDED

				cout << "Enter Employee Number: ";
				cin >> employeeNumber;

				check = findEmployee(conn, employeeNumber, emp);

				if (check == 1)
				{
					displayEmployee(conn, *emp);
				}
				else
				{
					cout << "Employee " << employeeNumber << " does not exist." << endl;
				}

				//END ADD HERE
				break;

			case 2:
				displayAllEmployees(conn);
				break;

			case 3:
				check = 0;
				Employee addNew;
				cout << "\n-------------- New Employee Information -------------" << endl;
				cout << "Employee Number: ";
				addNew.employeeNumber = getInteger();
				cout << "Last Name: ";
				cin >> addNew.lastName;
				cin.ignore();
				cout << "First Name: ";
				cin >> addNew.firstName;
				cin.ignore();
				cout << "Extension: ";
				cin >> addNew.extension;
				cin.ignore();
				cout << "Email: ";
				cin >> addNew.email;
				cin.ignore();
				cout << "Office Code: 1" << endl;
				strcpy(addNew.officecode, "1");
				cout << "Manager ID: 1002" << endl;
				addNew.reportsTo[0] = 1002;
				cout << "Job Title: ";
				do {
					cin >> addNew.jobTitle;
					cin.ignore();
					if (strcmp(addNew.jobTitle, "Cashier") != 0 && strcmp(addNew.jobTitle, "President") != 0 && strcmp(addNew.jobTitle, "VP Sales") != 0 && strcmp(addNew.jobTitle, "VP Marketing") != 0 && strcmp(addNew.jobTitle, "Sales Manager (APAC)") != 0 && strcmp(addNew.jobTitle, "Sale Manager (EMEA)") != 0 && strcmp(addNew.jobTitle, "Sales Manager (NA)") != 0 && strcmp(addNew.jobTitle, "Sales Rep") != 0) {
						cout << "Invaild Job Title! Type again: ";
					}
				} while (strcmp(addNew.jobTitle, "Cashier") != 0 && strcmp(addNew.jobTitle, "President") != 0 && strcmp(addNew.jobTitle, "VP Sales") != 0 && strcmp(addNew.jobTitle, "VP Marketing") != 0 && strcmp(addNew.jobTitle, "Sales Manager (APAC)") != 0 && strcmp(addNew.jobTitle, "Sale Manager (EMEA)") != 0 && strcmp(addNew.jobTitle, "Sales Manager (NA)") != 0 && strcmp(addNew.jobTitle, "Sales Rep") != 0);

				check = findEmployee(conn, addNew.employeeNumber, &addNew);
				if (check == 1) {
					cout << "\nAn employee with the same employee number exists." << endl;
				}
				else {
					insertEmployee(conn, &addNew);
				}
				break;

			case 4:
				// KRISTOFFER ADDED
				cout << "Enter Employee Number: ";
				cin >> employeeNumber;

				check = findEmployee(conn, employeeNumber, emp);

				if (check == 1)
				{
					cout << "Last Name: " << emp->lastName << endl;
					cout << "First Name: " << emp->firstName << endl;
					updateEmployee(conn, employeeNumber);
				}
				else
				{
					cout << "Employee " << employeeNumber << " does not exist." << endl;
				}

				break;
				// END ADD HERE

			case 5:
				
				cout << "Employee Number: ";
				cin >> employeeNumber;

				check = findEmployee(conn, employeeNumber, emp);

				if (check == 1)
				{

				
					deleteEmployee(conn, employeeNumber);

					
				}
				else
				{
					cout << "Employee " << employeeNumber << " does not exist." << endl;
				}

				break;

			case 0:
				env->terminateConnection(conn);
				Environment::terminateEnvironment(env);
				cout << "Exiting...";
				done = 1;
			}
		}
	}
	catch (SQLException& sqlExcp) {
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
	return 0;
}

void insertEmployee(Connection* conn, Employee* emp) {
	try {
		Statement* stmt = conn->createStatement();
		stmt->setSQL("INSERT INTO EMPLOYEES VALUES (:1,:2,:3,:4,:5,:6,:7,:8)");
		stmt->setInt(1, emp->employeeNumber);
		stmt->setString(2, emp->lastName);
		stmt->setString(3, emp->firstName);
		stmt->setString(4, emp->extension);
		stmt->setString(5, emp->email);
		stmt->setString(6, emp->officecode);
		stmt->setInt(7, emp->reportsTo[0]);
		stmt->setString(8, emp->jobTitle);
		stmt->executeUpdate();
		cout << "\nThe new employee is added successfully." << endl;

	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}


}

int findEmployee(Connection* conn, int employeeNumber, Employee* emp) {
	//TO DO

	//KRISTOFFER ADDED

	int result = 0;

	try
	{
		Statement* stmt = conn->createStatement("SELECT * FROM employees WHERE employeenumber = :1");
		stmt->setInt(1, employeeNumber);
		ResultSet* rs = stmt->executeQuery();

		if (!rs->next())
		{
			result = 0;
		}
		else
		{
			result = 1;

			emp->employeeNumber = rs->getInt(1);
			strcpy(emp->lastName, rs->getString(2).c_str());
			strcpy(emp->firstName, rs->getString(3).c_str());
			strcpy(emp->extension, rs->getString(4).c_str());
			strcpy(emp->email, rs->getString(5).c_str());
			strcpy(emp->officecode, rs->getString(6).c_str());
			emp->reportsTo[1] = rs->getInt(7);
			strcpy(emp->jobTitle, rs->getString(8).c_str());

		}
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}

	return result;

	//END ADD HERE
}
void displayEmployee(Connection* conn, Employee emp) {
	//TO DO

	//KRISTOFFER ADDED

	cout << endl;
	cout << "-------------- Employee Information -------------" << endl;
	cout << "Employee Number: " << emp.employeeNumber << endl;
	cout << "Last Name: " << emp.lastName << endl;
	cout << "First Name: " << emp.firstName << endl;
	cout << "Extension: " << emp.extension << endl;
	cout << "Email: " << emp.email << endl;
	cout << "Office Code: " << emp.officecode << endl;
	cout << "Manager ID: " << emp.reportsTo[1] << endl;
	cout << "Job Title: " << emp.jobTitle << endl;

	//END ADD HERE
}

void displayAllEmployees(Connection* conn) {
	try {
		Statement* stmt = conn->createStatement();
		ResultSet* test = stmt->executeQuery("SELECT COUNT(*) FROM (SELECT DISTINCT a.EMPLOYEENUMBER, a.FIRSTNAME || ' ' || a.LASTNAME AS \"Employee Name\", a.Email, c.PHONE, a.EXTENSION ,b.FIRSTNAME || ' ' || b.LASTNAME AS \"Manager Name\" FROM EMPLOYEES a FULL OUTER JOIN EMPLOYEES b ON a.REPORTSTO=b.EMPLOYEENUMBER FULL OUTER JOIN OFFICES c ON a.OFFICECODE = c.OFFICECODE WHERE a.EMPLOYEENUMBER IS NOT NULL ORDER BY a.EMPLOYEENUMBER)");
		int numberRow = 0;
		while (test->next())
		{
			numberRow = test->getInt(1);
			test = nullptr;
			break;
		}
		if (numberRow > 0) {
			ResultSet* rs = stmt->executeQuery("SELECT DISTINCT a.EMPLOYEENUMBER, a.FIRSTNAME || ' ' || a.LASTNAME AS \"Employee Name\", a.Email, c.PHONE, a.EXTENSION ,b.FIRSTNAME || ' ' || b.LASTNAME AS \"Manager Name\" FROM EMPLOYEES a FULL OUTER JOIN EMPLOYEES b ON a.REPORTSTO=b.EMPLOYEENUMBER FULL OUTER JOIN OFFICES c ON a.OFFICECODE = c.OFFICECODE WHERE a.EMPLOYEENUMBER IS NOT NULL ORDER BY a.EMPLOYEENUMBER");
			cout << endl;
			cout << left << setw(15) << "--" << setw(20) << "-------------" << setw(35) << "-----" << setw(25) << "-----" << setw(15) << "---------" << setw(25) << "------------" << endl;
			cout << left << setw(15) << "ID" << setw(20) << "Employee Name" << setw(35) << "Email" << setw(25) << "Phone" << setw(15) << "Extension" << setw(25) << "Manager Name" << endl;
			cout << left << setw(15) << "--" << setw(20) << "-------------" << setw(35) << "-----" << setw(25) << "-----" << setw(15) << "---------" << setw(25) << "------------" << endl;

			while (rs->next()) {
				int employeeID = rs->getInt(1);
				string ename = rs->getString(2);
				string email = rs->getString(3);
				string phone = rs->getString(4);
				string extension = rs->getString(5);
				string mname = rs->getString(6);
				cout << left << setw(15) << employeeID << setw(20) << ename << setw(35) << email << setw(25) << phone << setw(15) << extension << setw(25) << mname << endl;
			}
		}
		else {
			cout << "There is no employees’ information to be displayed" << endl;
		}
	}
	catch (SQLException& sqlExcp) {
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}


}

// KRISTOFFER ADDED
void updateEmployee(Connection* conn, int employeeNumber)
{
	try
	{
		char ext[10] = { 0 };
		cout << "Extension: ";
		cin >> ext;

		Statement* stmt = conn->createStatement("UPDATE employees SET extension = :1 WHERE employeenumber = :2");
		stmt->setString(1, ext);
		stmt->setInt(2, employeeNumber);
		stmt->executeUpdate();

		cout << "The employee's extension is updated succesfully." << endl;

	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
}



void deleteEmployee(Connection* conn, int employeeNumber)
{
	
		try {
			
				Statement* stmt = conn->createStatement("DELETE FROM employees WHERE employeenumber = :1");
				stmt->setInt(1,employeeNumber);
				stmt->executeUpdate();
			
				cout << "Employee with ID " << employeeNumber << " is deleted sucessfully." << endl;
			

		}
		catch (SQLException& err) {
			cout << err.getErrorCode() << ": " << err.getMessage();
		}
}
	

// END ADD HERE