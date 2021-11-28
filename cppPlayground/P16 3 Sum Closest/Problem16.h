#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Problem16
{
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int sz = nums.size(), d = 0, sum = 0, best = 0x7FFFFFFF, ret = 0;
        for (int i = 0; i < sz - 2; ++i)
        {
            while (i > 0 && i < sz - 2 && nums[i] == nums[i - 1]) ++i;

            int left = i + 1, right = sz - 1;
            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                d = sum - target;
                if (abs(d) < best)
                {
                    best = abs(d);
                    ret = sum;
                }
                if (d > 0)
                {
                    --right;
                }
                else if (d < 0)
                {
                    ++left;
                }
                else
                {
                    return ret;
                }
            }
        }

        return ret;
    }

    void runTest()
    {
        
        vector<int> input = { -1,2,1,-4 };

        int ret = threeSumClosest(input, 1);

        cout << "ret = " << ret << endl;
    }
};
