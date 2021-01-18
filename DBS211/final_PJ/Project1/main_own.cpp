#include <iostream>
#include <occi.h>
#include <cstring>
#include <iomanip>
#include "helper.h"
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
	cout << "Enter an option(0 - 5) : " ;
	do
	{
		menu = getIntRanger(5, 0);
	} while (menu > 5 || menu < 0);

	return menu;
}

void displayAllEmployees(Connection* conn);
void displayEmployee(Connection* conn, Employee emp);
int findEmployee(Connection* conn, int employeeNumber, Employee* emp);
void insertEmployee(Connection* conn, struct Employee emp);
//MAIN
int main() {
	Environment* env = nullptr;
	Connection* conn = nullptr;
	string user = "dbs211_202a23";
	string pass = "18153271";
	string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";
	
	try {
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(user, pass, srv);
		cout << "Connection is Successful!" << endl << endl;
		int option = 0;
		int done = 0;
		int employeeNumber = 0;
		while (!done)
		{
			option = menu();
			switch (option)
			{
			case 1:
				cout << "function is not ready" << endl;
				break;

			case 2:
				displayAllEmployees(conn);
				break;

			case 3:
				cout << "function is not ready" << endl;
				break;

			case 4:
				cout << "function is not ready" << endl;
				break;

			case 5:
				cout << "function is not ready" << endl;
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

int findEmployee(Connection* conn, int employeeNumber, Employee* emp) {
	//TO DO
	return 0;
}
void displayEmployee(Connection* conn, Employee emp) {
	//TO DO
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