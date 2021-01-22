/*----------------------------------------------------------*/
/* Author: Willie Xu ID# 110854683                          */
/* ESE224 Project 1
/* This program illustrates the use of the					 */
/* programmer-defined data type StraightLine                 */
/* filename: Main.cpp										 */

//#include <cstdlib>
#include <iostream>  //Required for cout
#include "basicFunctions.h"   //Required for basicFunctions
#include "print.h"			//used for cleaner code in main
#include "playGame.h"		//part 1 of project
#include "account.h"
#include "user.h"
#include "admin.h"
#include <string>
#include <stdlib.h>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <sstream>

using namespace std;
//void hangMan(int n);
int main() {
	//initialize variables
	char input;

	bool loop = true;
	while (loop) {
		//Create Start menu
		printMenu();
		cout << "Please select an option by entering the associated number, press 'q' to quit:" << endl;
		cin >> input;
		system("CLS");
		//Start new game
		if (input == '1') {
			//string dummy used to avoid warning in IDE
			string dummy=playGame();
			pauseScreen();
		}
		//Login as user
		else if (input == '2') {
			//intialize variables

			vector<user> users;

			//call function userText to create vector v using file "UserAccountHistory.txt"
			vector<string> v = userText();
			//string header = v[0];

			//create users
			for (int i = 1; i < v.size(); ++i) {
				users.push_back(create(v[i]));
			}
			int j = login(users);

			while (true) {
				//print menu
				string temp = "Hello " + users[j].getUser() + "!";
				printMessage(temp, true, true);
				printMenu2();
				cin >> input;
				system("CLS");
				/*system("CLS");*/
				//pauseScreen();
				//play game
				if (input == '1') {

					//load new word from file into string 
					string word = loadRandomWord("WordList.txt");
					users[j].setLastPlay(word);
					bool win=playGame(word);
					//user guesses word correctly
					if (win == true) {
						//add to win
						users[j].setWins(users[j].getWins() + 1);
						//change winstreak
						if (users[j].getWinStreak() < 0) {
							users[j].setWinStreak(0);
						}
						else {
							users[j].setWinStreak(users[j].getWinStreak() + 1);
						}
					}
					else {
						//add to loss
						users[j].setLosses(users[j].getLosses() + 1);
						//change winstreak
						if (users[j].getWinStreak() > 0) {
							users[j].setWinStreak(0);
						}
						else {
							users[j].setWinStreak(users[j].getWinStreak() - 1);
						}
					}
					//calculate winpercent
					double temp = (double)users[j].getWins() / ((double)users[j].getWins() + (double)users[j].getLosses());
					//change winpercent
					users[j].setWinPct(temp);
					//call function printFile to print to file
					users[j].printFile(users);
					pauseScreen();
				}
				//view history
				if (input == '2') {
					users[j].print();
					pauseScreen();

				}
				if (input == 'q') {
					break;
				}
				if (input == 'Q') {
					break;
				}
			}
		}
		//log in as admin
		else if (input == '3') {
			//intialize variables
			string word;
			vector<string> v;
			bool report = false;
			//create admin credentials
			admin admin("admin", "admin12345");
			while (report == false) {
				cout << "Please enter admin password: " << endl;
				cin >> word;
				report=admin.login("admin", word);
			}
			//load words into vector
			ifstream file("WordList.txt");
			if (file.is_open())
			{
				while (getline(file, word))
					v.push_back(word);
				file.close();
			}
			system("CLS");
			while (true) {
				
				printMenu3();
				cin >> input;
				system("CLS");
				//sort list aphabetically
				if (input == '1') {
					v=admin.Sort(v);
					pauseScreen();
				}
				//add word to list
				else if (input == '2') {
					v=admin.Add(v);
					pauseScreen();
				}

				//delete word from list
				else if (input == '3') {
					v=admin.Delete(v);
					pauseScreen();
				}
				else if (input == 'q') {
					break;
				}
				else if (input == 'Q') {
					break;
				}
				else {
					continue;
				}
			}
		}
		else if (input == 'Q') {
			cout << "User input 'q'\nProgram now exiting" << endl;
			loop = false;
		}
		else if (input == 'q') {
			cout << "User input 'q'\nProgram now exiting" << endl;
			loop = false;
		}
	}
	//stop window from closing----------------------------
	cout << "Please press any key to continue..." << endl;
	cin.get();
	cin.get();
	//-----------------------------------------------------
	return 0;	//end of program;
}



