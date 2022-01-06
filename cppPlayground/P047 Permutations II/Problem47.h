#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Problem47
{
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {

	}

	void nextPermutation(vector<int>& nums)
	{
		int sz = size(nums);
		int p = 0;
		//find p 
		for (int i = sz - 2; i >= 0; --i)
		{
			if (nums[i] < nums[i + 1])
			{
				p = i;
				break;
			}
		}
		//find next greater value
		for (int i = sz - 1; i >= p; --i)
		{
			if (nums[i] > nums[p])
			{
				auto tmp = nums[i];
				nums[i] = nums[p];
				nums[p] = tmp;
				break;
			}
		}
		reverse(nums.begin() + p + 1, nums.end());
	}

	void runTest()
	{
		vector<int> input = { 1,2,6,8,7,4,3 };

		nextPermutation(input);

		cout << "ret = ";
		for (int i : input)
		{
			cout << i << " ";
		}
		cout << endl;
	}
};