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
#include <algorithm>

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

	string currentWord;
	int count = 0;
	ifstream groceriesFile;
	vector<string> fileWords;
	vector<int> fileWordsCount;
	int countIterator = 0;

	groceriesFile.open(filename);

	if (!groceriesFile) {
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
		for (string n : fileWords)
		{
			if (n == currentWord)
			{
				//add 1 count to fileWordsCount[countIterator];
				fileWordsCount[countIterator] += 1;
				countIterator++;
			}
			else {
				fileWords.push_back(n);
			}
		}
		
		countIterator = 0;

		for (string m : fileWords)
		{
			cout << m << " " << fileWordsCount[countIterator] << endl;
			countIterator++;
		}
	}

}

void ListHistogram(string filename) {

}


int main() {

	//Search function test
	//Search("Groceries.txt");
	ListNumerical("Groceries.txt");

	system("PAUSE");

	return 0;
}