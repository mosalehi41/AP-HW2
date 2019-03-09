#include "Map.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;

//*// Implementation of methods goes below //*//

// Prints the map out to console
void Map::showMap()
{
	// Specify the allignment as std::left
	cout << std::left;
	for (int i = 0; i < mSize; i++, cout << endl)
		for (int j = 0; j < mSize; j++)
			cout << std::setw(4) << mMap[i][j];
	cout << endl;
}

// Finds a route using greedy algorithm
void Map::findGreedyRoute()
{
	// Route vector capacity is set, to avoid reallocation
	mRoute.clear();
	mRoute.reserve(4 * (mSize - 1) + 2);

	// Reset members' values
	mOverallDistance = 0;

	// Find the route and print the result
	findGreedy(0, 0);
	cout << "A route is specified using the greedy algorithm (diagonal displacement is permitted)" << endl
		<< "The overall distance is : " << mOverallDistance << endl;
}

// Finds the optimal route in the map
void Map::findOptimalRoute()
{
	// Route vector is filled with enough zeros, to avoid reallocation
	mRoute = vector<int>(4 * (mSize - 1) + 2, 0);

	// Reset members' values
	mOptimalDistance = -1;
	mIsFound = false;
	mCount = 0;

	// Find the route and print the result
	findOptimal(0, 0, 0);
	cout << "A total of " << mCount << " routes have been checked!" << endl
		<< "The optimal distance is : " << mOptimalDistance << endl;
}

// Prints the route out to console
void Map::showRoute()
{
	vector<int>::const_iterator it = mRoute.begin();

	// Specify the allignment as std::left
	cout << std::left;
	for (int i = 0; i < mSize; i++, cout << endl)
		for (int j = 0; j < mSize; j++)
		{
			if (*it == i && *(it + 1) == j)
				cout << std::setw(3) << "@", 
				it += 2;
			else
				cout << std::setw(3) << ".";
		}
	cout << endl;

}

//*// Helper methods are implemented below //*//

// Serves as a helper method to findGreedyRoute()
void Map::findGreedy(int inRow, int inColumn)
{
	int nextRow = (inColumn == mSize - 1) ? inRow + 1 : inRow;
	int nextColumn = (inColumn == mSize - 1) ? inColumn : inColumn + 1;

	// Push the current coordinates to the back of mRoute
	mRoute.push_back(inRow);
	mRoute.push_back(inColumn);

	// If at the end, return.
	if (inRow == mSize - 1 && inColumn == mSize - 1)
		return;
	
	// Check if we've not reached the wall
	if (inRow != mSize - 1 && inColumn != mSize - 1)
	{
		// Look for the adjacent element with least distance from the current element
		int nDistance = calcDistance(nextRow, nextColumn, inRow, inColumn);
		for (int i = nextRow + 1, j = nextColumn; j != inColumn - 1; j--)
		{
			int newDistance = calcDistance(i, j, inRow, inColumn);
			if (newDistance < nDistance)
				nextRow = i, nextColumn = j, nDistance = newDistance;
		}
	}

	// Add the distance to mOverAllDistance and repeat the process for the next element  
	mOverallDistance += calcDistance(nextRow, nextColumn, inRow, inColumn);
	findGreedy(nextRow, nextColumn);
}

// Serves as a helper method to findOptimalRoute()
void Map::findOptimal(int inRow, int inColumn, int inOveralDistance)
{
	int nextRow = (inColumn == mSize - 1) ? inRow + 1 : inRow;
	int nextColumn = (inColumn == mSize - 1) ? inColumn : inColumn + 1;

	// If at the end, check if the calculated overall distance is less than previous values
	if (inRow == mSize - 1 && inColumn == mSize - 1) 
	{
		mCount++;
		mIsFound = false;
		if (inOveralDistance < mOptimalDistance || mOptimalDistance == -1)
			mOptimalDistance = inOveralDistance,
			mIsFound = true;	
	} 
	// Check if we've reached the wall
	else if (inRow == mSize - 1 || inColumn == mSize - 1) 
	{
		// Update mOverAllDistance and call the function for the next element through the wall
		findOptimal(nextRow, nextColumn, inOveralDistance + calcDistance(nextRow, nextColumn, inRow, inColumn));
	} 
	// If at the inside, call the function for the next two adjacent elements
	else 
	{
		findOptimal(nextRow, nextColumn, inOveralDistance + calcDistance(nextRow, nextColumn, inRow, inColumn));
		nextRow++, nextColumn--;

		bool temp = mIsFound;

		findOptimal(nextRow, nextColumn, inOveralDistance + calcDistance(nextRow, nextColumn, inRow, inColumn));

		mIsFound |= temp;
	}
	// If the route is optimal compared to the previuos routes, update the mRoute
	if (mIsFound == true)
		mRoute[2 * (inRow + inColumn)] = inRow,
		mRoute[2 * (inRow + inColumn) + 1] = inColumn;
}

int Map::calcDistance(int firstRow, int firstColumn, int secondRow, int secondColumn)
{
	return abs(mMap[firstRow][firstColumn] - mMap[secondRow][secondColumn]);
}

//*// Constructor and destructors' definition goes below //*//

Map::Map(int inSize) : mSize(inSize), mOverallDistance(0), mOptimalDistance(-1), mCount(0), mIsFound(false)
{
	srand(static_cast<unsigned int>(time(NULL)));

	// Memmory is allocated for the map dynamically
	// and the map is filled with random entries
	mMap = new int*[mSize];
	for (int i = 0; i < mSize; i++) 
	{
		mMap[i] = new int[mSize];
		for (int j = 0; j < mSize; j++)
			mMap[i][j] = rand() % 101;
	}
}

Map::~Map()
{
	// Dynamically allocated memmory is freed!
	for (int i = 0; i < mSize; i++)
		delete mMap[i];
	delete mMap;
}
