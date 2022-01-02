#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Problem45
{
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();  //at least 1

        int p = 0, localMax = 0, nextI = 0, cur = 0;
        int ct = 0;

        while (p < sz - 1)
        {
            if (p + nums[p] >= sz - 1)
            {
                return ct + 1;
            }
            nextI = 0;
            localMax = 0;
            for (int i = 1; i + p < sz && i <= nums[p]; ++i)
            {
                cur = i + nums[i + p];
                if (localMax < cur)
                {
                    nextI = i;
                    localMax = cur;
                }
            }
            p = p + nextI;
            ct++;
        }

        return ct;
    }

    void runTest()
    {
        vector<int> input = { 1, 1, 1, 1 };

        int ret = jump(input);

        cout << "ret = " << ret << endl;
    }
};