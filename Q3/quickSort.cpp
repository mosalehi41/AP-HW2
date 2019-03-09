/**
* quickSort.cpp
*
* Sorts a vector of Purchases in increasing order.
*
* Algorithm:
* The input vector is devided into two half-vectors
* and each half-vector is sorted recursively. The two sorted
* half-vectors are then combined to give the result.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include "DataBase.h"

using std::vector;
using std::cout;
using std::endl;

using Purchase = DataBase::Purchase;
using Date = DataBase::Purchase::Date;

using funcPtr = bool(Purchase::*) (const Purchase&) const;

/// Below goes the declaration of helper functions
vector<Purchase> appendHalfVectors(const vector<Purchase>&, const vector<Purchase>&, funcPtr);
vector<Purchase>::iterator middleOfVector(const vector<Purchase>&);

/// Sorts a vector of integers in an increasing order using the Quick-Sort algorithm
vector<Purchase> quickSort(vector<Purchase>& inVector, funcPtr x)
{
	// The following vectors contain the First-Half and the Second-Half of the input vector respectively  
	vector<Purchase> firstHalfVector(inVector.begin(), middleOfVector(inVector));
	vector<Purchase> secondHalfVector(middleOfVector(inVector), inVector.end());

	// The recursive procedure is implemented below
	if (inVector.size() != 1)
		return appendHalfVectors(quickSort(firstHalfVector, x), quickSort(secondHalfVector, x), x);

	return inVector;
}


/***********************
*   HELPER FUNCTIONS   *
************************/

/// Appends the SORTED half vectors 
vector<Purchase> appendHalfVectors(const vector<Purchase>& fhv, const vector<Purchase>& shv, funcPtr x)
{
	vector<Purchase> sortedVector;

	// The following line of code prevents Reallocation
	sortedVector.reserve(fhv.size() + shv.size());

	vector<Purchase>::const_iterator i, j;
	for (i = fhv.begin(), j = shv.begin(); i < fhv.end() && j < shv.end(); (*i.*x)(*j) ? i++ : j++)
	{
		sortedVector.push_back((*i.*x)(*j) ? *i : *j);
	}
	(i < fhv.end()) ? sortedVector.insert(sortedVector.end(), i, fhv.end()) : sortedVector.insert(sortedVector.end(), j, shv.end());

	return sortedVector;
}

/// Returns the pointer to the middle of a vector
vector<Purchase>::iterator middleOfVector(const vector<Purchase>& inVector)
{
	return ((const_cast<vector<Purchase>&>(inVector)).begin() + static_cast<int>(floor((inVector.size() + 1) / 2)));
}






