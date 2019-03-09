#include <iostream>
#include <fstream>
#include "DataBase.h"

using std::ifstream;
using std::ofstream;

using std::cerr;
using std::cout;
using std::endl;

int main()
{
	ifstream inputFile("database.txt");
	ofstream outputFile("new_database.txt");
	DataBase myDataBase;

	// Close the program if there is a problem opening the file
	if (!inputFile) {
		cerr << "Error opening database.txt for reading." << endl;
		return 0;
	}
	cout << "Reading the file has finished with success." << endl;

	// Fill in the "myDataBase"
	for (string str; std::getline(inputFile, str); myDataBase.addPurchase(str));
    
	// Write the summary to the output file
	cout << "The summary is written to new_database.txt." << endl;
	myDataBase.writeSummary(outputFile);

	return 0;
}
