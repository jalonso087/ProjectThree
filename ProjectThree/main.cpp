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

//function declarations to avoid issues with calling one before it's declared
void DisplayMenu();
int AcceptMenuChoice();
void Search(string filename);
void ListNumerical(string filename);
void ListHistogram(string filename);

//displays the menu
void DisplayMenu() {

	cout << endl << "MENU OPTIONS" << endl;
	cout << "1: Search Item Frequency" << endl;
	cout << "2: List Purchased Item Frequencies - Numerical" << endl;
	cout << "3: List Purchased Item Frequencies - Histogram" << endl;
	cout << "4: Exit" << endl;

}

//calls the menu and prompts for user response, then calls the appropriate function
int AcceptMenuChoice() {

	int userChoice = -1;

	DisplayMenu();
	cout << "Your selection: ";
	cin >> userChoice;
	cout << endl;

	switch (userChoice) {
	case 1:
		Search("Groceries.txt");
		break;
	case 2:
		ListNumerical("Groceries.txt");
		break;
	case 3:
		ListHistogram("Groceries.txt");
		break;
	case 4:
		exit(EXIT_SUCCESS);
		break;
	}
}

//search for specific string within the file
void Search(string filename) {

	string searchTerm;
	string currentWord;
	int count = 0;

	//prompt user for term and store into var
	cout << "Enter your search term: ";
	cin >> searchTerm;
	cout << endl;

	//declare an input file stream object
	ifstream groceriesFile;

	//open the grocery file using the name provided as param for function call
	groceriesFile.open(filename);

	//if file does not open, alert the user and exit program
	if (!groceriesFile) {
		cout << "Unable to open file." << endl;
		exit(EXIT_FAILURE);
	}

	//while not end of file, continue looping
	while (!groceriesFile.eof())
	{
		//assign word to currentWord var
		groceriesFile >> currentWord;

		//if the currentWord is the same as searchTerm var, increment the count
		if (currentWord == searchTerm) {
			count++;
		}
	}

	//display searchTerm and count to the user
	cout << searchTerm << " was found " << count << " times" << endl;

}

//function to list each item with a numerical count of occurrences
void ListNumerical(string filename) {

	//declare input file stream object
	ifstream groceriesFile(filename);
	//using a map as dictionary for storing word and occurrence count
	unordered_map<string, int> wordCount;
	string word;

	//if file does not open, alert the user and exit program
	if (!groceriesFile) {
		cout << "Unable to open file." << endl;
		exit(EXIT_FAILURE);
	}

	//while not end of file, continue looping
	while (!groceriesFile.eof()) {

		//assign word from file to word var
		groceriesFile >> word;

		//increment word count for specific word
		wordCount[word]++;
	}

	//using auto& since there are two different var types in the map, string and int
	for (const auto& pair : wordCount) {
		//output the two items in the pair
		cout << pair.first << " " << pair.second << endl;
	}

}

void ListHistogram(string filename) {

	//declare input file stream object
	ifstream groceriesFile(filename);
	//using a map as dictionary for storing word and occurrence count
	unordered_map<string, int> wordCount;
	string word;

	//if file does not open, alert the user and exit program
	if (!groceriesFile) {
		cout << "Unable to open file." << endl;
		exit(EXIT_FAILURE);
	}

	//while not end of file, continue looping
	while (!groceriesFile.eof()) {

		//take the next word in the file and assign to word var
		groceriesFile >> word;

		//increment the word count for specific word
		wordCount[word]++;
	}


	//using auto& since there are two different var types in the map, string and int
	for (const auto& pair : wordCount) {
		//output the word
		cout << pair.first << " ";
		//for as much value is in the int of the pair, output * for each
		for (int i = 0; i < pair.second; ++i)
		{
			cout << "*";
		}

		cout << endl;

	}

}

int main() {

	bool programOpen = true;

	//loop program while not exited
	while (programOpen) {
		AcceptMenuChoice();
	}

	//added pause to ensure visibility
	system("PAUSE");

	return 0;
}