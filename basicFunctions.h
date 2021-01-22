#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include "user.h"

using namespace std;

void printMessage(string, bool, bool);

string loadRandomWord(string);

void pauseScreen();

vector<string> userText();

user create(string word);

int login(vector<user> v);
