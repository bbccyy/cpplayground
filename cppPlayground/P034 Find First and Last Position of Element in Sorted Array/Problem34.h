#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Problem34
{
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int retL = binarySearchLeft(nums, target);
        if (retL == -1)
        {
            return vector<int>{ -1, -1 };
        }
        int retR = binarySearchRight(nums, target);
        return vector<int>{ retL, retR };
    }

    int binarySearchRight(vector<int>& nums, int target)
    {
        int sz = nums.size();
        if (sz == 0) return -1;
        int s = 0, e = sz - 1, m = 0;

        while (s < e)
        {
            m = s + (e - s) / 2;
            if (nums[m] == target)
            {
                if (nums[m + 1] != target)
                    return m;
                else
                {
                    s = m + 1;
                }
            }
            else if (nums[m] < target)
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }
        if (s >= sz || nums[s] != target) return -1;
        return s;
    }

    int binarySearchLeft(vector<int>& nums, int target)
    {
        int sz = nums.size();
        if (sz == 0) return -1;
        int s = 0, e = sz - 1, m = 0;

        while (s < e)
        {
            m = s + (e - s + 1) / 2;
            if (nums[m] == target)
            {
                if (nums[m - 1] != target)
                    return m;
                else
                {
                    e = m - 1;
                }
            }
            else if (nums[m] < target)
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }

        if (s >= sz || nums[s] != target) return -1;
        return s;
    }

    void runTest()
    {
        vector<int> input = { 2, 2};
        int target = 9;
        int retLeft = binarySearchLeft(input, target);
        int retRight = binarySearchRight(input, target);

        cout << "ret = " << retLeft << ", " << retRight << endl;
    }
};