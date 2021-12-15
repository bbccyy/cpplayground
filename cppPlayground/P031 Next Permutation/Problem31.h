#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Problem31
{
public:
    void nextPermutation(vector<int>& nums) {

    }

    int binarySearch(vector<int>& nums, int s, int e, int target)
    {
        int m = 0;
        while (s < e)
        {
            m = s + (e - s) / 2;
            if (nums[m] == target)
                return m;
            if (nums[m] < target)
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        return s;
    }

    void runTest()
    {
        
    }
};