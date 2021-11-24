
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Problem11 {

public:
	int maxArea(vector<int>& height)
	{
		int p = 0, q = height.size() - 1;
		int max = 0, cur = 0, l = 0, r = 0;
		while (p < q)
		{
			if ((l = height[p]) < (r = height[q]))
			{
				cur = l * (q - p);
				while (++p < q && height[p] < l);
			}
			else 
			{
				cur = r * (q - p);
				while (--q > p && height[q] < r);
			}

			max = max > cur ? max : cur;
		}

		return max;
	}

	void runTest()
	{
		vector<int> input = { 4,3,2,1,4,1,7,2,3,1,2,3,45,5 };
		int ret = maxArea(input);

		cout << "ret = " << ret << endl;
	}
};