#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Problem46
{
public:
	vector<vector<int>> output;
public:
    vector<vector<int>> permute(vector<int>& nums) {
		doPermute(nums, nums.size() - 1);
		return output;
    }

	void doPermute(vector<int>& nums, int end)
	{
		if (end == 0)  //bottom case
		{
			output.clear();
			output.emplace_back(vector<int>{ nums[0] });
			return;
		}
		doPermute(nums, end - 1);
		vector<vector<int>> output2;
		for (int i = 0; i < output.size(); ++i)
		{
			auto cur = output[i];
			for (int j = 0; j <= cur.size(); ++j)
			{
				vector<int> tmp = vector<int>(cur.size() + 1);
				tmp[j] = nums[end];
				for (int k = 0, m = 0; k <= cur.size(); ++k)
				{
					if (j == k) continue;
					tmp[k] = cur[m++];
				}
				output2.emplace_back(tmp);
			}
		}
		output.clear();
		output = output2;
		return;
	}

    void runTest()
    {
		vector<int> input = { -1,9,0, 17 };
		auto ret = permute(input);

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