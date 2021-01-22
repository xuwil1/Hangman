#include "basicFunctions.h"   //Required for basicFunctions
#include <string>

void printMenu() {
	printMessage("Hangman Game ", true, true);
	printMessage("ESE 224 ", false, true);
	printMessage("Group Member: ", false, true);
	printMessage("Willie Xu", false, true);
	printMessage("1. Start new game", false, false);
	printMessage(" 2. Sign in as user ", false, false);
	printMessage("  3. Sign in as admin ", false, true);
}
void  printMenu2() {

	printMessage("1. Play a game", false, false);
	printMessage("2. Check your history", false, true);
	cout << "Please select a number to contiue, enter 'q' to quit:" << endl;
}
void  printMenu3() {
	printMessage("Manage your Word List", true, true);
	printMessage("1.Sort the list aphabetically", false, false);
	printMessage("2. Add a word to the list", false, false);
	printMessage("3. Delete a word from the list", false, true);
	cout << "Please select a number to contiue, enter 'q' to quit:" << endl;
}
void hangMan(int n) {
	if (n == 0) {
		printMessage("", false, false);
		printMessage("", false, false);
		printMessage("", false, false);
	}
	else if (n == 1) {
		printMessage("O", false, false);
		printMessage("", false, false);
		printMessage("", false, false);
	}
	else if (n == 2) {
		printMessage("O", false, false);
		printMessage("|", false, false);
		printMessage("", false, false);
	}
	else if (n == 3) {
		printMessage("O", false, false);
		printMessage("/| ", false, false);
		printMessage("", false, false);
	}
	else if (n == 4) {
		printMessage("O", false, false);
		printMessage("/|\\", false, false);
		printMessage("", false, false);
	}
	else if (n == 4) {
		printMessage("O", false, false);
		printMessage("/|\\", false, false);
		printMessage("", false, false);
	}
	else if (n == 5) {
		printMessage("O", false, false);
		printMessage("/|\\", false, false);
		printMessage("/  ", false, false);
	}
	else if (n == 6) {
		printMessage("O", false, false);
		printMessage("/|\\", false, false);
		printMessage("/ \\", false, false);
	}
}