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
#include "menu.h"

using namespace std;

//function declarations to avoid issues with calling one before it's declared
void Search(string filename);
void ListNumerical(string filename);
void ListHistogram(string filename);

//handles the function calling using a Menu object param
void SwitchStatement(Menu defaultMenu) {
	switch (defaultMenu.GetUserChoice()) {
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

	Menu menu;

	//loop program while not exited
	while (menu.GetUserChoice() != 4) {
		menu.AcceptUserChoice();
		SwitchStatement(menu);
	}

	//added pause to ensure visibility
	system("PAUSE");

	return 0;
}