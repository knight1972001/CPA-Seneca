//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    July 11th 2020
// Lab:				W7(Lab 7)
//==============================================
#include <iostream>
#include <occi.h>
#include <iomanip>
#include <cctype>
using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;

char space(int n) {
	for (int i = 0; i < n; i++) {
		cout << " ";
	}
	char s;
	return s;
}
void printHeader(const char* title)
{
	int i = 0;
	cout << endl;
	while (i < 25) {
		i++;
		cout << "-";
	}
	cout << " " << title << " ";
	while (i < ( 70-strlen(title))) {
		i++;
		cout << "-";
	}
	cout << endl;
}

void printUnderLine(const char* title1 = nullptr, const char* title2 = nullptr, const char* title3 = nullptr, const char* title4 = nullptr, const char* title5=nullptr, const char* title6=nullptr) {
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

int main(void) {
	// OCCI Variables
	Environment* env = nullptr;
	Connection* conn = nullptr;
	// User Variables
	string str;
	string usr = "dbs211_202a23";
	string pass = "18153271";
	string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";

	try {
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(usr, pass, srv);
		cout << "Connection is Successful!" << endl;

		Statement* stmt = conn->createStatement();

		ResultSet* test = stmt->executeQuery("SELECT COUNT(*) FROM (SELECT officecode, city, state, country, postalcode FROM offices ORDER BY officecode)");
		int numberRow = 0;
		while (test->next())
		{
			numberRow = test->getInt(1);
			cout << "ROW: " << numberRow << endl;
			test = nullptr;
			break;
		}

		if (numberRow > 0)
		{
			ResultSet* rs = stmt->executeQuery("SELECT officecode, city, state, country, postalcode FROM offices ORDER BY officecode");

			cout << "The company Offices are: " << endl;
			//cout << "# City		State		Country			Postal Code" << endl;
			printf("%-3s%-15s%-15s%-15s%-10s\n", "#", "City", "State", "Country", "Postal Code");
			while (rs->next()) {
				int count = rs->getInt(1);
				string city = rs->getString(2);
				string state = rs->getString(3);
				string country = rs->getString(4);
				string pc = rs->getString(5);
				//cout << count << " " << city << "		" << state << "		" << country << "		" << pc << endl;
				printf("%-3d%-15s%-15s%-15s%-10s\n", count, city, state, country, pc);

			}
		}
		else {
			cout << " XAMLON" << endl;
		}
		
		
		//conn->terminateStatement(stmt);
		
		////Query 2
		//rs = stmt->executeQuery("SELECT a.EMPLOYEENUMBER,a.FIRSTNAME,a.LASTNAME,b.PHONE,a.EXTENSION FROM EMPLOYEES a FULL OUTER JOIN OFFICES b ON a.OFFICECODE=b.OFFICECODE WHERE b.CITY='San Francisco' ORDER BY a.EMPLOYEENUMBER");
		//printHeader("Report 1 (Employee Report)");
		//printf("%-15s %-15s %-15s %-20s %-15s\n", "Employee ID", "First Name", "Last name", "Phone", "Extension");
		//printUnderLine("Employee ID", "First Name", "Last name", "Phone", "Extension");
		//while (rs->next()) {
		//	int employeeID = rs->getInt(1);
		//	string fname = rs->getString(2);
		//	string lastname = rs->getString(3);
		//	string phone = rs->getString(4);
		//	string ex = rs->getString(5);
		//	printf("%-15d %-15s %-15s %-20s %-15s\n", employeeID, fname, lastname, phone, ex);
		//}

		////Query 3
		//rs = stmt->executeQuery("SELECT DISTINCT a.EMPLOYEENUMBER,a.FIRSTNAME,a.LASTNAME,c.PHONE,a.EXTENSION FROM EMPLOYEES a FULL OUTER JOIN EMPLOYEES b ON a.OFFICECODE=b.OFFICECODE FULL OUTER JOIN OFFICES c ON a.OFFICECODE=c.OFFICECODE WHERE a.EMPLOYEENUMBER=b.REPORTSTO ORDER BY a.EMPLOYEENUMBER");
		//printHeader("Report 2 (Manager Report)");
		//printf("%-15s %-15s %-15s %-20s %-15s\n", "Employee ID", "First Name", "Last name", "Phone", "Extension");
		//printUnderLine("Employee ID", "First Name", "Last name", "Phone", "Extension");
		//while (rs->next()) {
		//	int employeeID = rs->getInt(1);
		//	string fname = rs->getString(2);
		//	string lastname = rs->getString(3);
		//	string phone = rs->getString(4);
		//	string ex = rs->getString(5);
		//	printf("%-15d %-15s %-15s %-20s %-15s\n", employeeID, fname, lastname, phone, ex);
		//}

		//EXCUTE
		conn->terminateStatement(stmt);




		//CONNF
		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);
	}
	catch (SQLException& sqlExcp) {
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
	return 0;
}