#pragma once

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Problem15 {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ret;
        if (nums.size() < 3) return ret;

        sort(nums.begin(), nums.end());
        unordered_map<int, int> tb = unordered_map<int, int>(nums.size());
        for (auto num : nums)
        {
            if (tb.count(num) > 0)
            {
                tb[num] += 1;
            }
            else
            {
                tb[num] = 1;
            }
        }

        int i = 0, j = nums.size() - 1, rest = 0;
        while (j > 1 && nums[j] >= 0)
        {
            i = 0;
            while (i < j && nums[i] <= 0)
            {
                rest = 0 - nums[i] - nums[j];
                if (rest >= nums[i] && rest <= nums[j])
                {
                    if (tb.count(rest) > 0)
                    {
                        if ((rest == nums[i] || rest == nums[j]))
                        {

                            if (rest == 0 && tb[rest] > 2)
                            {
                                vector<int> tmp = { 0, 0, 0 };
                                ret.emplace_back(tmp);
                            }
                            else if (rest != 0 && tb[rest] > 1)
                            {
                                vector<int> tmp = { nums[i], rest ,nums[j] };
                                ret.emplace_back(tmp);
                            }
                        }
                        else
                        {
                            vector<int> tmp = { nums[i], rest ,nums[j] };
                            ret.emplace_back(tmp);
                        }
                    }
                }
                while (i < j && nums[i] == nums[i + 1]) ++i;
                ++i;
            }
            while (j > 1 && nums[j] == nums[j - 1]) --j;
            --j;
        }

        return ret;
    }

    void runTest()
    {
        vector<int> input = {-1,0,1,0};

        auto ret = threeSum(input);

        for (auto v : ret)
        {
            cout << "ret = " << v[0] << "_" << v[1] << "_" << v[2] << endl;
        }
        
    }
};
