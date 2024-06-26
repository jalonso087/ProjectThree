/*
* ******************
*	Javier Alonso
*	6/26/24
*	Project 3
* ******************
*/

//use Groceries.txt for the input file to pull data from

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void DisplayMenu() {

	cout << "MENU OPTIONS" << endl;
	cout << "1: Search Item Frequency" << endl;
	cout << "2: List Purchased Item Frequencies - Numerical" << endl;
	cout << "3: List Purchased Item Frequencies - Histogram" << endl;
	cout << "4: Exit" << endl;

}

int AcceptMenuChoice() {

	int userChoice = -1;

	DisplayMenu();
	cout << "Your selection: " << userChoice << endl;

	switch (userChoice) {
	case 1:
		Search("Groceries.txt");
		break;
	case 2:
		//ListNumerical function
		break;
	case 3:
		//ListHistogram function
		break;
	case 4:
		exit(EXIT_SUCCESS);
		break;
	}
}

void Search(/*use Groceries.txt file as input string*/string filename) {

	string searchTerm;
	string currentWord;
	int count = 0;

	cout << "Enter your search term: ";
	cin >> searchTerm;
	cout << endl;

	ifstream groceriesFile;

	groceriesFile.open(filename);

	if (groceriesFile) {
		cout << "Groceries file opened." << endl;
	}
	else {
		cout << "Unable to open file." << endl;
		exit(EXIT_FAILURE);
	}


	while (!groceriesFile.eof())
	{
		groceriesFile >> currentWord;
		if (currentWord == searchTerm) {
			count++;
		}
	}

	cout << searchTerm << " was found " << count << " times" << endl;

}

void ListNumerical(string filename) {

	string currentWord;
	int count = 0;
	ifstream groceriesFile;

	groceriesFile.open(filename);

	if (groceriesFile) {
		cout << "Groceries file opened." << endl;
	}
	else {
		cout << "Unable to open file." << endl;
		exit(EXIT_FAILURE);
	}

	while (!groceriesFile.eof())
	{
		//Need to create a vector of words to hold every word
		//Need to create a vector of count to hold occurrences of each word
		//iterate through the entire file to store all data
		//cout each vector side by side using a for loop 
		// cout vector[i] vector2[i]
		groceriesFile >> currentWord;
	}

}

void ListHistogram(string filename) {

}


int main() {

	//Search function test
	//Search("Groceries.txt");

	system("PAUSE");

	return 0;
}