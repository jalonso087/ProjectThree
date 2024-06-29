#pragma once
#include <iostream>

using namespace std;

//Menu class that handles all menu functionality
//userChoice default is -1 to ensure invalid entry
class Menu {

private:
	int userChoice = -1;
public:
	void DisplayMenu();
	void AcceptUserChoice();
	int GetUserChoice();
};
