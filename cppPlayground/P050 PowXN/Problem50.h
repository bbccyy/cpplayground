#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Problem50
{
public:
	double myPow(double x, int n) {
		return n > 0 ? calPow(x, n) : calPow(1.0 / x, 0-((long)n));
	}

	double calPow(double x, long n)
	{
		double ret = 1;
		while (n > 0)
		{
			if (n & 1) //last digit is 1
			{
				ret *= x;
			}
			x *= x;
			n = n >> 1;
		}
		return ret;
	}

	void runTest()
	{
		auto ret = myPow(10, 4);

		cout << "ret = " << ret << endl;
	}
};