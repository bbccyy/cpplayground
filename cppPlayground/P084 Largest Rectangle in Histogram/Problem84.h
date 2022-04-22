#pragma once

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.

eg.
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Input: heights = [2,4]
Output: 4

Constraints:
1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

class Problem84
{
public:
    inline int max(int a, int b)
    {
        return a > b ? a : b;
    }

    int largestRectangleArea(vector<int>& heights) {
        //maintain looping invariants

        int sz = heights.size();
        if (sz == 0) return 0;
        if (heights[sz - 1] != 0)
        {
            heights.emplace_back(0);
            ++sz;
        }

        int cm = heights[0];    //current max 
        stack<int> stk; 
        stk.push(0);            //first pivot 





        return cm;
    }


    int largestRectangleAreaSlow(vector<int>& heights) {
        int sz = heights.size();
        int curMax = 0;

        if (heights[sz - 1] != 0)
        {
            heights.emplace_back(0);
            ++sz;
        }

        int tb_sz = 0;
        for (int i = 0; i < sz; ++i)
            tb_sz = max(tb_sz, heights[i]);

        vector<int> tb = vector<int>(tb_sz + 1, -1); //0~104
        int cur = 0, tmp = 0;
        for (int i = 0; i < sz; ++i)
        {
            cur = heights[i];
            tmp = cur;
            while (tmp > 0 && tb[tmp] == -1)
            {
                tb[tmp--] = i;
            }
            for (int j = cur + 1; j <= tb_sz; ++j)
            {
                if (tb[j] != -1)
                {
                    curMax = max(curMax, (i - tb[j]) * j);
                    tb[j] = -1;
                }
            }
        }

        return curMax;
    }

    void runTest()
    {
        vector<int> input = { 2,1,2 };

        auto ret = largestRectangleAreaSlow(input);

        cout << "ret = " << ret;
    }
};