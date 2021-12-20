#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Problem35
{
public:
	int searchInsert(vector<int>& nums, int target) {
		int sz = nums.size();
		if (sz == 0) return 0;

		int s = 0, e = sz - 1, m = 0;

		while (s < e)
		{
			m = s + (e - s) / 2;
			if (nums[m] == target)
			{
				s = m;
				break;
			}
			if (nums[m] > target)
			{
				e = m - 1;
			}
			else if (nums[m] < target)
			{
				s = m + 1;
			}
		}
		if (s == sz - 1 && nums[s] < target) return s + 1;
		return s;
	}

	void runTest()
	{
		vector<int> input = { 2 };
		int ret = searchInsert(input, 5);

		cout << "ret = " << ret << endl;
	}
};