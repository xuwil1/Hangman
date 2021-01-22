#include "account.h"

using namespace std;


account::account() {
	name = "";
	password = "";
}
account::account(string n, string pw){
	name = n;
	password = pw;
}
bool account::login(string n, string pw) {
	if (name == n && password == pw) {
		return true;
	}
	cout << "Password entered is invalid!" << endl;
	return false;
}