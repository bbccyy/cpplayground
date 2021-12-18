#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Problem33
{
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        int s = 0, e = sz - 1, m = 0;
        while (s < e)
        {
            m = s + (e - s) / 2;
            if (nums[m] == target)
                return m;
            if (nums[m] < nums[e]) 
            {
                if (nums[s] > nums[e]) //m on right rot
                {
                    if (nums[m] > target)
                    {
                        e = m - 1;
                    }
                    else if (nums[e] >= target)
                    {
                        s = m + 1;
                    }
                    else
                    {
                        e = m - 1;
                    }
                }
                else  //fully sorted
                {
                    if (nums[m] > target)
                    {
                        e = m - 1;
                    }
                    else
                    {
                        s = m + 1;
                    }
                }
            }
            else //m on left rot
            {
                if (nums[m] > target)
                {
                    if (nums[s] <= target)
                    {
                        e = m - 1;
                    }
                    else
                    {
                        s = m + 1;
                    }
                }
                else
                {
                    s = m + 1;
                }
            }
        }
        return s;
    }

    void runTest()
    {
        
    }
};