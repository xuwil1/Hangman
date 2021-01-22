#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "account.h"
#include <iostream>
#include <iomanip>

#pragma once

using namespace std;

class user : public account {
private:
	int wins,losses,winStreak;
	double winPct;
	string lastPlay;
public:
	user();
	user(string name, string password);
	user(string name, string password, int wins, int losses, double winPct, int winstreak, string lastPlay);
	void setWins(int wins);
	void setLosses(int losses);
	void setWinStreak(int winStreak);
	void setWinPct(double winPct);
	void setLastPlay(string lastPlay);
	int getWins();
	int getLosses();
	int getWinStreak();
	double getWinPct();
	string getUser();
	string getPassword();
	string getLastPlay();
	//void login(string name, string password);
	bool login(string name, string password);
	void print();
	void printFile(vector<user> v);
};
