#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Problem27
{
public:
    int removeElement(vector<int>& nums, int val) {
        int p = 0, q = nums.size() - 1;
        if (q < 0) return p;

        while (p <= q)
        {
            if (nums[p] == val)
            {
                nums[p] = nums[q--];
            }
            else
            {
                ++p;
            }
        }
        return p;
    }

    void runTest()
    {
        vector<int> input = { 0,0, };
        int ret = removeElement(input, 0);

        cout << "ret = " << ret << ": ";
        for (auto v : input)
        {
            cout << v << " ";
        }
        cout << endl;

    }
};