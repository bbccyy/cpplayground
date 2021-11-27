#pragma once

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Problem13 {

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

Input: s = "MCMXCIV"
Output: 1994
*/

public:

    int romanToInt(string s) {

        char ct[] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
        int vt[] = { 1000, 500, 100, 50, 10, 5, 1 };
        
        int ret = 0, sz = s.length();
        if (sz == 0) return ret;
        vector<int> tb = vector<int>(sz);
        for (int i = 0; i < 7; ++i)
        {
            for (int j = 0; j < sz; ++j)
            {
                if (s.at(j) == ct[i])
                {
                    tb[j] = i;
                }
            }
        }
        for (int i = 0; i < sz - 1; ++i)
        {
            if (tb[i] <= tb[i + 1])
            {
                ret += vt[tb[i]];
            }
            else
            {
                ret -= vt[tb[i]];
            }
        }
        ret += vt[tb[sz - 1]];
        return ret;
    }

    void runTest()
    {
        string input = "VIII";
        int ret = romanToInt(input);

        cout << "ret = " << ret << endl;
    }
};