#pragma once

#include <iostream>
#include <string>

using namespace std;

class Problem32
{
public:
    int longestValidParentheses(string s) {

        int sz = s.length();
        int ret = 0;
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
                    ret = (j - i) > ret ? (j - i) : ret;
                }
                else
                {
                    for (int p = i + 1; p < j - 1; p += 2)
                    {
                        if (tb[i][p] && tb[p + 1][j])
                        {
                            tb[i][j] = true;
                            ret = (j - i) > ret ? (j - i) : ret;
                            break;
                        }
                    }
                }

                //inc
                i++;
                j++;
            }
        }

        return ret == 0 ? 0 : ret + 1;
    }

    void runTest()
    {
    
    }
};