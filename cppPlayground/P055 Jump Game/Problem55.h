#pragma once

#include <iostream>
#include <vector>

using namespace std;

/*
You are given an integer array nums. 
You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/
class Problem55
{
public:
	bool canJump(vector<int>& nums) {
		int sz = size(nums);
		if (sz <= 0) return true;
		int p = 0, d = nums[p], boundary = 0, tmp = 0;
		while (p + d < sz - 1)
		{
			if (d == 0) return false;
			boundary = p;
			for (int i = 1; i <= d; ++i)
			{
				tmp = p + i + nums[p + i];
				boundary = boundary > tmp ? boundary : tmp;
			}
			p = p + d;
			d = boundary - p;
		}
		return true;
	}

	void runTest()
	{
		vector<int> input = { 3,2,1,0,4 };

		auto ret = canJump(input);

		cout << "ret = " << ret << endl;
	}
};