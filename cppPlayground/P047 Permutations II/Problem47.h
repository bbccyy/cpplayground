#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Problem47
{
public:
	vector<vector<int>> output;
	vector<int> cur;
	int sz = 0;
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sz = size(nums);
		unordered_map<int, int> map;
		output.clear();
		cur.clear();
		for (auto x : nums) ++map[x];
		generatePermuation(map);
		return output;
	}

	void generatePermuation(unordered_map<int, int>& map)
	{
		if (size(cur) == sz)
		{
			output.emplace_back(cur);
			return;
		}

		for (auto& elem : map)
		{
			if (elem.second == 0) continue;
			cur.emplace_back(elem.first);
			elem.second--;
			generatePermuation(map);
			elem.second++;
			cur.pop_back();
		}
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
		vector<int> input = { 3,2,1,3 };

		auto ret = permuteUnique(input);

		cout << "ret = " << endl;
		for (int i = 0; i < ret.size(); ++i)
		{
			cout << "[";
			for (int j = 0; j < ret[i].size(); ++j)
			{
				cout << ret[i][j] << " ";
			}
			cout << "]" << endl;
		}
	}
};