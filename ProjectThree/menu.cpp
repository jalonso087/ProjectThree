#include "menu.h"

//display Menu via cout for the user
void Menu::DisplayMenu() {
	cout << endl << "MENU OPTIONS" << endl;
	cout << "1: Search Item Frequency" << endl;
	cout << "2: List Purchased Item Frequencies - Numerical" << endl;
	cout << "3: List Purchased Item Frequencies - Histogram" << endl;
	cout << "4: Exit" << endl;
}

//Prompt user to enter their selection and store into userChoice private variable
void Menu::AcceptUserChoice() {
	DisplayMenu();
	cout << "Your selection: ";
	cin >> userChoice;
	cout << endl;
}

//Since userChoice var is private, this is a public function to return the value
int Menu::GetUserChoice() {
	return userChoice;
}