#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Problem18
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());

        using vv = vector<vector<int>>;
        vv ret;
        vv tmp;

        int sz = nums.size(), i = 0;
        long subTarget = 0;

        while (i < sz - 3)
        {
            subTarget = (long)target - nums[i];
            threeSum(nums, i + 1, subTarget, tmp);
            for (auto v : tmp)
            {
                v.emplace_back(nums[i]);
                ret.emplace_back(v);
            }
            tmp.clear();
            while (++i < sz - 3 && nums[i] == nums[i - 1]);
        }

        return ret;
    }

    void threeSum(vector<int>& nums, int startIdx, long target, vector<vector<int>>& output)
    {
        int sz = nums.size();

        int i = startIdx, j = 0, k = 0;
        long sum = 0;

        while ( i < sz - 2 )
        {
            j = i + 1;
            k = sz - 1;
            while (j < k)
            {
                sum = (long)nums[i] + (long)nums[j] + (long)nums[k];
                if (sum < target)
                {
                    while (++j < k && nums[j] == nums[j - 1]);
                }
                else if (sum > target)
                {
                    while (--k > j && nums[k] == nums[k + 1]);
                }
                else
                {
                    output.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                    while (++j < k && nums[j] == nums[j - 1]);
                    while (--k > j && nums[k] == nums[k + 1]);
                }
            }
            while (++i < sz - 2 && nums[i] == nums[i - 1]);
        }
    }

    void runTest()
    {
        vector<int> input = { 2,2,2,2,2 };

        auto ret = fourSum(input, 8);

        for (auto v : ret)
        {
            cout << v[0] << "_" << v[1] << "_" << v[2] << "_" << v[3] << endl;
        }
    }
};