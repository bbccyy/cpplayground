#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

eg.
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
*/
class Problem70
{
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        vector<int> tb = vector<int>(n + 2, 0);
        tb[1] = 1;
        for (int i = 2; i < tb.size(); ++i)
        {
            tb[i] = tb[i - 1] + tb[i - 2];
        }
        return tb[tb.size() - 1];
    }

    void runTest()
    {
        int input = 4;
        int ret = climbStairs(input);

        cout << "ret = " << ret << endl;
    }
};