#include "libVec.h"
#include "libArr.h"
#include <iostream>
#include <chrono>

using std::cout;
using std::endl;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

template <class T>
double runTime(int(T::* x) (int), int n)
{
	T myT;

	auto begin(high_resolution_clock::now());

	(myT.*x)(n);

	auto end(high_resolution_clock::now());
	auto t = duration_cast<nanoseconds> (end - begin);

	return  static_cast<double>(t.count()) / 1000000;
}

int main()
{
	int(libArr::* arrPtr) (int) = &libArr::counter;
	int(libVec::* vecPtr) (int) = &libVec::counter;

	for (int n = 1; n <= 1000000 ; n *= 10)
	{
		cout << "n = " << n << " ->" << endl;
		cout << "libArr's counter took " << runTime(arrPtr, n) << " milliseconds to execute."  << endl;
		cout << "libVec's counter took " << runTime(vecPtr, n) << " milliseconds to execute."  << endl;
		cout << "---------------------------------------------" << endl;
	}

	return 0;
}