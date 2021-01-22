#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>    
#include "account.h"
#pragma once

using namespace std;

class admin : public account {
public:
	admin();
	admin(string name, string password);
	bool login(string n, string pw);
	vector<string> Sort(vector<string> v);
	vector<string> Add(vector<string> v);
	vector<string> Delete(vector<string> v);
	void writeFile(vector<string> v);
};