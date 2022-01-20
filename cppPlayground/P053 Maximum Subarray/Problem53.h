#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Problem53
{
public:
	int maxSubArray(vector<int>& nums) {
		int sz = size(nums);
		int p = 0, sum = 0, max = INT_MIN;
		while (p < sz)
		{
			sum += nums[p++];
			if (max < sum) max = sum;
			if (sum < 0) sum = 0;
		}
		return max;
	}

	void runTest()
	{
		vector<int> input = { -2,1,-3,4,-1,2,1,-5,4 };//[-2,1,-3,4,-1,2,1,-5,4]

		auto ret = maxSubArray(input);

		cout << "ret = " << ret << endl;
	}
};
