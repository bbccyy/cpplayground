#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Problem26
{
public:
	int removeDuplicates(vector<int>& nums) {
		int sz = nums.size();
		if (sz == 0) 
			return 0;
		int p = 0, q = 1;
		while (q < sz and nums[p] != nums[q])
		{
			++p;
			++q;
		}
		while (q < sz)
		{
			while (q < sz and nums[p] == nums[q]) q++;
			if (q < sz) nums[++p] = nums[q++];
		}
		return p + 1;
	}

	void runTest()
	{
		vector<int> input = { 1,1,2,2,3,3,4 };
		int ret = removeDuplicates(input);

		cout << "ret = " << ret << ": ";
		for (auto v : input)
		{
			cout << v << " ";
		}
		cout << endl;
	}
};