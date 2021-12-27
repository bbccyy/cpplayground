#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Problem41
{
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz = nums.size();
        int p = 0, q = sz - 1;
        while (p <= q)
        {
            if (nums[p] <= 0 || nums[p] > q + 1)
            {
                nums[p] = nums[q];
                --q;
            }
            else if (nums[p] == p + 1)
            {
                ++p;
            }
            else
            {
                int tmp = nums[p];
                if (nums[tmp - 1] == tmp)
                {
                    ++p;
                }
                else
                {
                    nums[p] = nums[tmp - 1];
                    nums[tmp - 1] = tmp;
                }
            }
        }
        for (int i = 0; i < sz; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return sz + 1;
    }

    void runTest()
    {
        vector<int> input = { 1,2,2,1,3,1,0,4,0 };

        int ret = firstMissingPositive(input);

        cout << "ret = " << ret << endl;
    }
};