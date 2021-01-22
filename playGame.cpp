#include "playGame.h"

string playGame() {
	char input;
	string lines, guessList, missList;
	int index = 0, tries = 0, wordLength = 0;
	vector<string> guesses;
	vector<string> misses;
	vector<string> correct;
	//load new word from file into string 
	string word = loadRandomWord("WordList.txt");
	wordLength = word.size();
	//cout << word << endl;
	for (int i = 0; i < word.size(); i++) {
		correct.push_back("_");
	}
	while (1) {
		//freshes outputs for correct, guess, and miss list
		lines = "";
		guessList = "";
		missList = "";
		for (int i = 0; i < correct.size(); i++) {
			lines += correct[i] + " ";
		}
		for (int i = 0; i < guesses.size(); i++) {
			guessList += guesses[i] + " ";
		}
		for (int i = 0; i < misses.size(); i++) {
			missList += misses[i] + " ";
		}
		printMessage("Hangman Game ", true, true);
		printMessage("|", false, false);
		hangMan(tries);
		printMessage(lines, true, true);
		cout << "Guesses: " << guessList << endl;
		cout << "Misses: " << missList << endl;
		//Player gets the right word
		if (wordLength == 0) {
			cout << "Congratulations, you won!" << endl;
			return word;
		}
		//player guesses words wrong 6 times
		if (tries == 6) {
			cout << "The correct word was \"" << word << "\"" << endl;;
			cout << "Better luck next time!" << endl;
			return word;
		}
		//takes user input as guess
		cout << "Guess a letter: ";
		cin >> input;
		system("CLS");
		if (input == '1' || input == '2' || input == '3' ||
			input == '4' || input == '5' || input == '6' ||
			input == '7' || input == '8' || input == '9') {
			cout << "NOT VALID" << endl;
			continue;
		}
		else {
			guesses.push_back(string(1, input));
			//int word does contain input letter
			if (word.find(input) <= word.size()) {
				cout << "Good guess!" << endl;
				for (int i = 0; i < word.size(); i++) {
					if (input == word[i]) {
						correct[i] = input;
						wordLength--;
					}
				}
			}
			//if word does not contain input letter
			else {
				tries++;
				cout << "Sorry, you have " << 6 - tries << " left!" << endl;
				misses.push_back(string(1, input));
			}
		}
	}
}

bool playGame(string word) {
	char input;
	string lines, guessList, missList;
	int index = 0, tries = 0, wordLength = 0;
	vector<string> guesses;
	vector<string> misses;
	vector<string> correct;

	wordLength = word.size();
	//cout << word << endl;
	for (int i = 0; i < word.size(); i++) {
		correct.push_back("_");
	}
	while (1) {
		//freshes outputs for correct, guess, and miss list
		lines = "";
		guessList = "";
		missList = "";
		for (int i = 0; i < correct.size(); i++) {
			lines += correct[i] + " ";
		}
		for (int i = 0; i < guesses.size(); i++) {
			guessList += guesses[i] + " ";
		}
		for (int i = 0; i < misses.size(); i++) {
			missList += misses[i] + " ";
		}
		printMessage("Hangman Game ", true, true);
		printMessage("|", false, false);
		hangMan(tries);
		printMessage(lines, true, true);
		cout << "Guesses: " << guessList << endl;
		cout << "Misses: " << missList << endl;
		//Player gets the right word
		if (wordLength == 0) {
			cout << "Congratulations, you won!" << endl;
			return true;
		}
		//player guesses words wrong 6 times
		if (tries == 6) {
			cout << "The correct word was \"" << word << "\"" << endl;;
			cout << "Better luck next time!" << endl;
			return false;
		}
		//takes user input as guess
		cout << "Guess a letter: ";
		cin >> input;
		system("CLS");
		if (input == '1' || input == '2' || input == '3' ||
			input == '4' || input == '5' || input == '6' ||
			input == '7' || input == '8' || input == '9') {
			cout << "NOT VALID" << endl;
			continue;
		}
		else {
			guesses.push_back(string(1, input));
			//int word does contain input letter
			if (word.find(input) <= word.size()) {
				cout << "Good guess!" << endl;
				for (int i = 0; i < word.size(); i++) {
					if (input == word[i]) {
						correct[i] = input;
						wordLength--;
					}
				}
			}
			//if word does not contain input letter
			else {
				tries++;
				cout << "Sorry, you have " << 6 - tries << " left!" << endl;
				misses.push_back(string(1, input));
			}
		}
	}
}