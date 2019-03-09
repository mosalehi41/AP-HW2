#pragma once
#include <vector>

using std::vector;

class Map
{
	public:
		Map(int);
		~Map();

		void showMap();
		
		void findGreedyRoute();
		void findOptimalRoute();
		void showRoute();

	private:
		int** mMap;
		int mSize;
		
		vector<int> mRoute;

		int mOverallDistance;

		int mOptimalDistance;
		int mCount;
		bool mIsFound;

		void findGreedy(int, int);
		void findOptimal(int, int, int);

		int calcDistance(int, int, int, int);
};
