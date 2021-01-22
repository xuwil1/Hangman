#include <iostream>
#include <string>
#pragma once

using namespace std;

class account {

public:
	string name, password;
	account();
	account(string name, string password);
	bool login(string n, string pw);
};