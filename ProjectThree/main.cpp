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
#include <vector>
#include <unordered_map>

using namespace std;

void DisplayMenu();
int AcceptMenuChoice();
void Search(string filename);
void ListNumerical(string filename);
void ListHistogram(string filename);

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

	if (!groceriesFile) {
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

	ifstream groceriesFile(filename);
	unordered_map<string, int> wordCount;
	string word;

	if (!groceriesFile) {
		cout << "Unable to open file." << endl;
		exit(EXIT_FAILURE);
	}

	while (!groceriesFile.eof()) {

		groceriesFile >> word;

		wordCount[word]++;
	}

	for (const auto& pair : wordCount) {
		cout << pair.first << " " << pair.second << endl;
	}

}

void ListHistogram(string filename) {

	ifstream groceriesFile(filename);
	unordered_map<string, int> wordCount;
	string word;

	if (!groceriesFile) {
		cout << "Unable to open file." << endl;
		exit(EXIT_FAILURE);
	}

	while (!groceriesFile.eof()) {

		groceriesFile >> word;

		wordCount[word]++;
	}

	for (const auto& pair : wordCount) {
		cout << pair.first << " ";
		for (int i = 0; i < pair.second; ++i)
		{
			cout << "*";
		}

		cout << endl;

	}

}


int main() {

	/*Function Testing*/
	//Search("Groceries.txt");
	//ListNumerical("Groceries.txt");
	//ListHistogram("Groceries.txt");


	system("PAUSE");

	return 0;
}