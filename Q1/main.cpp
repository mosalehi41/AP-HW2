#include "Map.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int nSize(0);

	// Get the size of the map
	cout << "Enter the size of the map: " << endl;
	cin >> nSize;

	// Instantiate a map of given size
	Map myMap(nSize);

	myMap.showMap();

	myMap.findGreedyRoute();
	myMap.showRoute();

	myMap.findOptimalRoute();
	myMap.showRoute();

	return 0;
}
