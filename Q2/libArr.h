#pragma once

class libArr
{
	public:
		int counter(int n)
		{
			long int nSum(0);

			mArr = new int[n];
			for (int i = 0; i < n; mArr[i] = i, nSum += i++);

			return nSum;
		}

	private:
		int* mArr;
};
