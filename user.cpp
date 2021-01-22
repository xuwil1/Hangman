#include "user.h"

using namespace std;


user::user() :account(name,password){
	wins = 0;
	losses = 0;
	winStreak = 0;
	 winPct=0;
	lastPlay="";
}
user::user(string n,string pw):account(n,pw) {
	//name = n;
	//password = pw;
	wins = 0;
	losses = 0;
	winStreak = 0;
	winPct = 0;
	lastPlay = "";
	cout << name << endl;
	cout << wins << endl;
}
user::user(string n, string pw, int w, int l, double wP, int wS,  string lP) : account(n, pw) {
	//name = n;
	//password = pw;
	wins = w;
	losses = l;
	winPct = wP;
	winStreak = wS;
	lastPlay = lP;
}

//returns true if user login information is right otherwise false
bool user::login(string n, string pw) {
	if (name == n && password == pw) {
		cout << name << "\t" << password << endl;
		return true;
	}
	return false;
}
//print user stats
void user::print() {
	cout << setw(10)<<"Name" << setw(10) << "Wins" << setw(10) << "Losses" << setw(10) << "winPct" << setw(20) << "Winstreak" << setw(20) << "Lastplay" << endl;
	cout << setfill(' ');
	cout << setprecision(4);
	cout << setw(10) << getUser() 
		<< setw(10) << getWins() 
		<< setw(10) << getLosses() 
		<< setw(10) << getWinPct() << " %" 
		<< setw(18) << getWinStreak() 
		<< setw(22)<< getLastPlay()<<endl;
}
//print to file "UserAccountHistory.txt" after receiving users
void user::printFile(vector<user> v) {
	ofstream file;
	file.open("UserAccountHistory.txt");
	file << setw(10) << "Name" << setw(10) << "Password"<<setw(10) << "Wins" << setw(10) << "Losses" << setw(10) << "winPct" << setw(20) << "Winstreak" << setw(22) << "Lastplay" << endl;
	for (int i = 0; i < v.size(); ++i) {
		file << setfill(' ');
		file << setw(10) << v[i].getUser() << setw(10) << v[i].getPassword() << setw(10) << v[i].getWins() << setw(10) << v[i].getLosses() << setw(10) << setprecision(4) << v[i].getWinPct() << " %" << setw(18) << v[i].getWinStreak() << setw(22) << v[i].getLastPlay() << endl;
	}
	file.close();
}

//setters and getters
void user::setWins(int w) {
	wins = w;
}
void user::setLosses(int l) {
	losses = l;
}
void user::setWinStreak(int wS) {
	winStreak = wS;
}
void user::setWinPct(double wP) {
	winPct = wP;
}
void user::setLastPlay(string lP) {
	lastPlay = lP;
}
string user::getUser() {
	return name;
}
string user::getPassword() {
	return password;
}
int user::getWins() {
	return wins;
}
int user::getLosses() {
	return losses;
}
int user::getWinStreak() {
	return winStreak;
}
double user::getWinPct() {
	return winPct;
}
string user::getLastPlay() {
	return lastPlay;
}

