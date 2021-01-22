#include "basicFunctions.h"

void printMessage(string message, bool printTop = true, bool printBottom = true)
{
	if (printTop)
	{
		cout << "+---------------------------------+" << endl;
		cout << "|";
	}
	else
	{
		cout << "|";
	}
	bool front = true;
	for (int i = message.length(); i < 33; i++)
	{
		if (front)
		{
			message = " " + message;
		}
		else
		{
			message = message + " ";
		}
		front = !front;
	}
	cout << message.c_str();

	if (printBottom)
	{
		cout << "|" << endl;
		cout << "+---------------------------------+" << endl;
	}
	else
	{
		cout << "|" << endl;
	}
}

string loadRandomWord(string path)
{
	srand(time(0));
	string word;
	vector<string> v;
	ifstream file(path);
	if (file.is_open())
	{
		while (getline(file, word))
			v.push_back(word);
		word = v[rand() % v.size()];
		file.close();
	}
	return word;
}
//function used to pause screen for program using system("CLS")
void pauseScreen() {
	char input;
	cout << "Please press any key to continue..." << endl;
	cin >> input;
	system("CLS");
}
//function used to create user using a string of text
user create(string word) {
	string buf;                 // Have a buffer string
	stringstream ss(word);       // Insert the string into a stream
	vector<string> tokens; // Create vector to hold our words
	while (ss >> buf) {
		tokens.push_back(buf);
	}
	user temp(tokens[0], tokens[1], stoi(tokens[2]), stoi(tokens[3]), atof(tokens[4].c_str()), stoi(tokens[6]),tokens[7]);
	return temp;
}

vector<string> userText() {
	//intialize variables;
	vector<string> v;
	string word;
	//read in file "UserAccountHistory.txt"
	ifstream file("UserAccountHistory.txt");
	if (file.is_open())
	{
		while (getline(file, word))
			v.push_back(word);
		file.close();
	}
	return v;
}
//login in usng credentials
int login(vector<user> v) {
	//intialize variables
	string use, pass;
	int j = 0;
	bool creds = true;

	while (creds) {
		cout << "Please enter your username:" << endl;
		cin >> use;
		cout << "Please enter your password:" << endl;
		cin >> pass;

		for (int i = 0; i < v.size(); ++i) {
			bool check = v[i].login(use, pass);
			if (check == true) {
				j = i;
				creds = false;
				system("CLS");
				break;
			}
			if (i == v.size() - 1) {
				cout << "Credentials invalid, please try again!" << endl;
			}
		}

	}
	return j;
}