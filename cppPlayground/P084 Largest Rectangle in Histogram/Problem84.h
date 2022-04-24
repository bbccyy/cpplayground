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

    inline int min(int a, int b)
    {
        return a > b ? b : a;
    }

    int largestRectangleArea(vector<int>& heights) {
        //maintain looping invariants

        int sz = heights.size();
        if (sz == 0) return 0;           //corner cases 1
        if (sz == 1) return heights[0];  //corner cases 2
        if (heights[sz - 1] != 0)
        {
            heights.emplace_back(0);
            ++sz;
        }

        int ret = heights[0];    //current max 
        int low = heights[0];    //current lowest height
        stack<int> stk;          //trace point, init with peek, update later while tracing  

        int p = 1, q = 0;        // q ... p
        bool isUp = true;
        while (p < sz)
        {

            if (heights[p] >= heights[p - 1])
            {
                isUp = true;
                ++p;
                continue;
            }
            
            if (isUp)
            {
                isUp = false;
                stk.push(p - 1);
            }

            while (!stk.empty() && heights[stk.top()] >= heights[p])
            {
                q = stk.top();
                while (q > 0 && heights[q] >= heights[p] && (q == stk.top() || heights[q] <= heights[q + 1]))
                {
                    if (heights[q] > heights[p])
                    {
                        ret = max(ret, heights[q] * (p - q));
                        ret = max(ret, heights[p] * (p - q + 1));
                    }
                    else
                        ret = max(ret, heights[p] * (p - q + 1));
                    --q;
                }
                stk.pop();
                if (q >= 0 && heights[q] < heights[p] && heights[q] <= heights[q + 1])
                    break;
                else q = -1;
            }
            
            if (q >= 0) stk.push(q);
            if (stk.empty()) stk.push(0);

            if (stk.top() == 0 && low > 0)
            {
                ret = max(ret, low * p);
            }

            low = min(low, heights[p]);  //refresh low
            ++p;
        }

        return ret;
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

        auto ret1 = largestRectangleAreaSlow(input);
        auto ret2 = largestRectangleArea(input);

        cout << "ret1 = " << ret1 << " ret2 = " << ret2;
    }
};