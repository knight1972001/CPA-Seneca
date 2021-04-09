#include <iostream>
#include <occi.h>
#include "helper.h"

using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;
int main(void) {
	//OCCI variables
	Environment* env = nullptr;
	Connection* conn = nullptr;
	//used variables
	string str;
	string user = "dbs311_211a24";
	string pass = "24883484";
	string constr = "myoracle12c.senecacollege.ca:1521/oracle12c";
	
	try {
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(user, pass, constr);
		cout << "Connection is Successful!" << endl;
		//do
		ShoppingCart cart[5];
		bool check = true;
		while (check) {
			if (mainMenu() == 1) {
				int id = 0;
				cout << "Enter the customer ID: ";
				cin >> id;
				if (customerLogin(conn, id) == 1) {
					int productCount = addToCart(conn, cart);
					displayProducts(cart, productCount);
					if (checkout(conn, cart, id, productCount) == 1) {
						cout << "The order is successfully completed." << endl;
					}
					else {
						cout << "Cancelled order!" << endl;
					}
				}
			}
			if(mainMenu()==0) {
				cout << "Good bye!..." << endl;
				check = false;
			}
		}
		//end
		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);
	}
	catch (SQLException& sqlExcp) {
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}

	return 0;
}