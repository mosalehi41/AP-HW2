#pragma once
#include <vector>

using std::vector;

class libVec
{
	public:
		int counter(int n)
		{
			long int nSum(0);

			mVector.reserve(n);
			for (int i = 0; i < n; mVector.push_back(i), nSum += i++);

			return nSum;
		}

	private:
		vector<int> mVector;
};
