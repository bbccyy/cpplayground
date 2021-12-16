#pragma once

#include <iostream>
#include <string>

using namespace std;

class Problem32
{
public:
    int longestValidParentheses(string s) {

        int sz = s.length();
        vector<vector<bool>> tb = vector<vector<bool>>(sz);
        for (int i= 0; i < sz; ++i)
            tb[i] = vector<bool>(sz);

        for (int i = 1; i < sz; ++i)
            tb[i][i - 1] = true;

        for (int k = 2; k <= sz; k+=2)
        {
            int i = 0, j = i + k - 1;
            while (j < sz)
            {
                //do something
                if (tb[i + 1][j - 1] && s[i] == '(' && s[j] == ')')
                {
                    tb[i][j] = true;
                }
                else
                {

                }

                //inc
                i++;
                j++;
            }
        }

    }

    void runTest()
    {
    
    }
};