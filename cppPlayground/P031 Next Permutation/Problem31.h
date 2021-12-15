#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Problem31
{
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        bool found = false;
        for (int i = sz - 2; i >= 0; --i)
        {
            if (nums[i] < nums[i + 1])
            {
                found = true;
                int j = binarySearch(nums, i + 1, sz - 1, nums[i]);
                while (nums[j] <= nums[i]) ++j;
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                reverse(nums, i + 1, sz - 1);
                break;
            }
        }
        if (!found) reverse(nums, 0, sz - 1);
        return;
    }

    void reverse(vector<int>& nums, int s, int e)
    {
        int tmp = 0;
        while (s < e)
        {
            tmp = nums[s];
            nums[e] = nums[s];
            nums[e] = tmp;
            ++s;
            --e;
        }
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