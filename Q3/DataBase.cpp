#include "DataBase.h"
#include <iostream>
#include <vector>
#include <algorithm>


using std::vector;

using std::cout;
using std::endl;

using Purchase = DataBase::Purchase;
using Date = DataBase::Purchase::Date;

// quickSort() is declared for later use
vector<Purchase> quickSort(vector<Purchase>&, bool(Purchase::*) (const Purchase&) const);

//*// Implementation of methods goes below //*//

// Adds informations of a purchase to the database
void DataBase::addPurchase(string inString)
{
	// Retrieve informations from an input string
	string dateString(inString, 1, 10);
	int productID = std::stoi(string(inString, 19, 21));
	int costumerID = std::stoi(string(inString, 23, 26));

	// Push the extracted information to the back of purchase list
	mPurchaseList.push_back(Purchase(Date(dateString), productID, costumerID));
}

// Writes a summary of the database into a file
void DataBase::writeSummary(ofstream& inFileStream)
{
	// Copy purchase list to vectors in order for faster computation
	vector<Purchase> firstVector(mPurchaseList.begin(), mPurchaseList.end());
	vector<Purchase> secondVector(firstVector);
	
	// Sort the "firstVector" regarding the "mDateProductID"
	firstVector = quickSort(firstVector, &Purchase::cmpDateProduct);
	// Sort the "secondVector" regarding the "mDateCostumerID"
	secondVector = quickSort(firstVector, &Purchase::cmpDateCostumer);

	int nProductCount = 1, nCostumerCount = 1;
	for (auto i = firstVector.begin() + 1, j = secondVector.begin() + 1; i != firstVector.end(); i++, j++)
	{
		// add to count, if a new "mDateProductID" is found
		if (i->getDateProductID() != (i - 1)->getDateProductID())
			nProductCount++;
		// add to count, if a new "mDateCostumerID" is found
		if (j->getDateCostumerID() != (j - 1)->getDateCostumerID())
			nCostumerCount++;

		// If at the end ...
		if (i == firstVector.end() - 1)
			// Print the result
			inFileStream << i->getDate().c_str() << " " << nProductCount << " " << nCostumerCount << endl;
		// If a new date appears ...
		else if (i->getDate() != (i + 1)->getDate())
		{
			// Print the result and reset the counters
			inFileStream << i->getDate().c_str() << " " << nProductCount << " " << nCostumerCount << endl;
			nProductCount = 0;
			nCostumerCount = 0;
		}
	}
}

// Compares two objects in terms of "mDateProductID"
bool Purchase::cmpDateProduct(const Purchase& inPurchase) const
{
	return mDateProductID <= inPurchase.mDateProductID;
}

// Compares two objects in terms of "mDateCostumerID"
bool Purchase::cmpDateCostumer(const Purchase& inPurchase) const
{
	return mDateCostumerID <= inPurchase.mDateCostumerID;
}

//*// Constructor and destructors' definition goes below //*//

Purchase::Purchase(Date inDate, int inProductID, int inCostumerID) : mDate(inDate)
{
	mDateProductID = mDate.mDateValue * 1000 + inProductID;
	mDateCostumerID = mDate.mDateValue * 10000 + inCostumerID;
}

Date::Date(string inString) : mDateString("[" + inString + "]")
{
	// Remove all occurrences of '-' in inString
	inString.erase(std::remove(inString.begin(), inString.end(), '-'), inString.end());

	mDateValue = std::stoi(inString);
}

