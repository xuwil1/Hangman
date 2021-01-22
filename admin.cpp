#include "admin.h"

using namespace std;

admin::admin() :account(name, password) {}
admin::admin(string n, string pw) : account(n, pw) {}

bool admin::login(string n, string pw) {
	return account::login(n, pw);
}
//return vector after sorting vector list alphabetically 
vector<string> admin::Sort(vector<string> v) {
	//use function sort from start to end of list
	sort(v.begin(), v.end());
	//call writeFile function
	writeFile(v);
	cout << "List has been sorted" << endl;
	return v;
}
//returns vector after adding new word to list 
vector<string> admin::Add(vector<string> v) {
	//intialize variables
	bool report = false;
	string word;
	//get word user wants to add
	cout << "Please enter a word to be added: " << endl;
	cin >> word;
	//go through list to see if word already exists 
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == word) {
			report = true;
			break;
		}
	}
	if (report == true) {
		cout << "The word '" << word << "' already exists in list!" << endl;
	}
	//if word does not exist in list already, it is added to list
	else {
		cout << "The word '" << word << "' has been added to the list!" << endl;
		v.push_back(word);
		sort(v.begin(), v.end());
		writeFile(v);
	}
	return v;
}
//returns vector after removing user input word if found
vector<string> admin::Delete(vector<string> v) {
	//intialize variables to be used
	vector<string> temp;
	bool report = false;
	string word;
	//get word user wants to delete
	cout << "Please enter a word to be removed: " << endl;
	cin >> word;
	//moves all words to a temp vector
	//skips if user wants to delete word
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == word) {
			report = true;
			continue;
		}
		else {
			temp.push_back(v[i]);
		}
	}
	if (report == true) {
		cout << "The word '" << word << "' has been removed!" << endl;
	}
	else {
		cout << "The word '" << word << "'  not be found in list!" << endl;
	}
	writeFile(temp);
	return temp;
}
//writes to file "WordList.txt" after taking in a vector
void admin::writeFile(vector<string> v) {
	ofstream file;
	file.open("WordList.txt");
	for (int i = 0; i < v.size(); ++i) {
		file << v[i] << endl;
	}
	file.close();
}